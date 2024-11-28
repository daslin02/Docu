#include "main.h"
#include "ostatok.h"
#include "prihod.h"
#include "prihodWidget.h"
#include "rashod.h"
#include <guiController.h>
#include <qdebug.h>
#include <qlogging.h>
#include <qmainwindow.h>
#include <qmutex.h>
#include <qnamespace.h>
#include <qobject.h>
#include <qpushbutton.h>
#include <qsize.h>
#include <qthread.h>
#include <qvariant.h>
#include <qwidget.h>



gui::docuGuiController::docuGuiController(QMainWindow* parent) : QMainWindow(parent)
{

   UiMainWindow = new Ui::MainWindow;
   UiMainWindow->setupUi(this);   
   PointOverlay = new QMutex;
   baseStyle(UiMainWindow);
   this->setMinimumSize(QSize(700,700));
   runEvent(UiMainWindow, this); 
}
gui::docuGuiController::~docuGuiController()
{

    delete UiMainWindow;
    posOverlay->end(); 
    delete PointOverlay;
    if (dialogPrihod->isVisible())
    {
        dialogPrihod->close();
    } 
    delete dialogPrihod; 
    delete uiDialogPrihod;
    
    delete UiPrihod;
    delete  prihod;
    
    delete rashod;
    delete UiRashod;
    
    delete ostatok;
    delete UiOstatok;
}
bool gui::docuGuiController::startGui()
{
    while(UiMainWindow->SW_stacked->count() > 0)
    {
        QWidget* widget = UiMainWindow->SW_stacked->widget(0);
        UiMainWindow->SW_stacked->removeWidget(widget);
        delete widget;
    }
    prihod = new QWidget();
    ostatok = new QWidget();
    rashod = new QWidget();
    
    UiPrihod = new Ui::W_prihod();
    UiOstatok = new Ui::W_ostatok();
    UiRashod = new Ui::W_rashod();


    UiPrihod->setupUi(prihod);
    UiOstatok->setupUi(ostatok);
    UiRashod->setupUi(rashod);
   
    UiMainWindow->SW_stacked->addWidget(prihod);
    UiMainWindow->SW_stacked->addWidget(ostatok);
    UiMainWindow->SW_stacked->addWidget(rashod);
  
    dialogPrihod = new QWidget(this);
    uiDialogPrihod = new Ui::dialogPrihod;
    uiDialogPrihod->setupUi(dialogPrihod);
   
    dialogPrihod->setStyleSheet("background:#1c1f20;");
    dialogPrihod->resize(500 , 500);
    dialogPrihod->move(100 , 100);
    
    //conect close event 
    connect(uiDialogPrihod->PB_closed , &QPushButton::clicked ,this,&docuGuiController::closeDialogPrihod); 
    dialogPrihod->close(); 


    this->runAllEvent(); 
    this->show();
    
    posOverlay = new gui::positionOverlay(this ,dialogPrihod , uiDialogPrihod  );
    posOverlay->start();
    return true;
}
QSize gui::docuGuiController::centerPoint()
{
    QRect geometry = this->geometry();
    int centerX =  geometry.x() + geometry.width() / 2 ;
    int centerY =  geometry.y() + geometry.height() / 2 ;
    return QSize(centerX , centerY);
}
QSize gui::docuGuiController::getCentral()
{
    return central;
}
void gui::docuGuiController::setCentral()
{
    central = centerPoint();
}
void gui::docuGuiController::runAllEvent()
{
    //conect swap widget in stacked widget
    connect(UiMainWindow->PB_prihod , &QPushButton::clicked , this , &docuGuiController::swapPrihod);
    connect(UiMainWindow->PB_ostatok , &QPushButton::clicked , this , &docuGuiController::swapOstatok);
    connect(UiMainWindow->PB_rashod , &QPushButton::clicked , this , &docuGuiController::swapRashod);

   //conect dialog form
    connect(UiPrihod->PB_add  , &QPushButton::clicked , this , &docuGuiController::showDialogPrihod);
}

void gui::docuGuiController::showDialogPrihod()
{
    QRect overlayGeometry = dialogPrihod->geometry();
   
    int centerX =  overlayGeometry.x() + overlayGeometry.width() / 2 ;
    int centerY =  overlayGeometry.y() + overlayGeometry.height() / 2 ;
    
    QSize center = this->centerPoint();

    dialogPrihod->move(center.width() - centerX/2, center.height() - centerY/2);
    
    
    posOverlay->go();
    dialogPrihod->raise();
    dialogPrihod->show();    
}
void gui::docuGuiController::closeDialogPrihod()
{
    posOverlay->stop();
    dialogPrihod->close();
}

void gui::docuGuiController::swapPrihod()
{
    UiMainWindow->SW_stacked->setCurrentIndex(0);
} 
void gui::docuGuiController::swapOstatok()
{
    UiMainWindow->SW_stacked->setCurrentIndex(1);
} 
void gui::docuGuiController::swapRashod()
{
    UiMainWindow->SW_stacked->setCurrentIndex(2);
}



// class positionOverlay:
gui::positionOverlay::positionOverlay(docuGuiController* docus,
        QWidget* overlays , Ui::dialogPrihod* ui  , QObject* parent) :
        QThread(parent) , overlay(overlays) , uiOverlay(ui) , docu(docus)
{
   docu->setCentral();
}
gui::positionOverlay::~positionOverlay()
{
    delete docu;
    delete uiOverlay;
    delete overlay;
    closed= true;
}
void gui::positionOverlay::end()
{
    closed = true; 
}
void gui::positionOverlay::run()
{
    
    while(true)
    {
        QThread::msleep(1);
        if (running)
        {
            QSize center = docu->centerPoint();
            QSize last = docu->getCentral();
            if (last.width() != center.width() || last.height() != center.height())
            {
                docu->setCentral();
                int X = overlay->geometry().x() + overlay->geometry().width()/2;
                int Y = overlay->geometry().y() + overlay->geometry().height()/2;
                overlay->move(center.width()-X/2 , center.height()-Y/2);
            }    
        }
        if(closed)
        {
            break;
        }
    }
}
void gui::positionOverlay::go()
{
    running = true;
}
void gui::positionOverlay::stop()
{
    running = false;
}

