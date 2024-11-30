#include "browserWidget.h"
#include "main.h"
#include "ostatok.h"
#include "prihod.h"
#include "prihodWidget.h"
#include "rashod.h"
#include <algorithm>
#include <cinttypes>
#include <functional>
#include <guiController.h>
#include <qcontainerfwd.h>
#include <qdebug.h>
#include <qlayoutitem.h>
#include <qlist.h>
#include <qlogging.h>
#include <qpushbutton.h>
#include <qset.h>
#include <qstandarditemmodel.h>
#include <qtablewidget.h>
#include <qwidget.h>



gui::docuGuiController::docuGuiController(QMainWindow* parent) : QMainWindow(parent)
{

   UiMainWindow = new Ui::MainWindow;
   UiMainWindow->setupUi(this);   
   PointOverlay = new QMutex;
   this->setMinimumSize(QSize(700,700));
   this->setWindowTitle("Docu");
}
gui::docuGuiController::~docuGuiController()
{

    delete UiMainWindow;
    addOverlay->end(); 
    delete PointOverlay;
    if (dialogPrihod->isVisible())
    {
        dialogPrihod->close();
    } 
    delete dialogPrihod; 
    delete uiAdd;
    
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
    uiAdd = new Ui::dialogPrihod;
    uiAdd->setupUi(dialogPrihod);
   
    dialogPrihod->setStyleSheet("background:#1c1f20;");
    dialogPrihod->resize(500 , 500);
    dialogPrihod->move(100 , 100);

    dialogFind = new QWidget(this);
    uiFind = new Ui::browserWidget;
    uiFind->setupUi(dialogFind);


    dialogFind->setStyleSheet("background:#1c1f20;");
    dialogFind->resize(500 , 500);
    dialogFind->move(100 , 100);

    //conect close event 
    connect(uiAdd->PB_closed , &QPushButton::clicked ,this,&docuGuiController::closeDialogPrihod); 
    dialogPrihod->close(); 
    
    this->runAllEvent(); 
    
   
    this->show();
    
    addOverlay = new gui::Overlay(this ,dialogPrihod  );
    addOverlay->start();
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
    
    connect(UiRashod->PB_add  , &QPushButton::clicked , this , &docuGuiController::showDialogPrihod);
   

    connect(UiPrihod->PB_delete  , &QPushButton::clicked , this , &docuGuiController::delElement);
    
    connect(UiRashod->PB_delete  , &QPushButton::clicked , this , &docuGuiController::delElement);

    connect(uiAdd->PB_add , &QPushButton::clicked , this , &docuGuiController::addElement);
}
    
void gui::docuGuiController::showDialogPrihod()
{
    QRect overlayGeometry = dialogPrihod->geometry();
   
    int centerX =  overlayGeometry.x() + overlayGeometry.width() / 2 ;
    int centerY =  overlayGeometry.y() + overlayGeometry.height() / 2 ;
    
    QSize center = this->centerPoint();

    dialogPrihod->move(center.width() - centerX/2, center.height() - centerY/2);
    
    
    addOverlay->go();
    dialogPrihod->raise();
    dialogPrihod->show();    
}
void gui::docuGuiController::closeDialogPrihod()
{
    addOverlay->stop();
    dialogPrihod->close();
}

void gui::docuGuiController::swapPrihod()
{
    isActive = PRIHOD;
    UiMainWindow->SW_stacked->setCurrentIndex(PRIHOD);
} 
void gui::docuGuiController::swapOstatok()
{
    isActive = OSTATOK;
    UiMainWindow->SW_stacked->setCurrentIndex(OSTATOK);
} 
void gui::docuGuiController::swapRashod()
{
    isActive = RASHOD;
    UiMainWindow->SW_stacked->setCurrentIndex(RASHOD);
}
void gui::docuGuiController::delElement()
{
    QTableWidget* table;
    switch (isActive) {
    case PRIHOD:
        table = UiPrihod->TW_prihod;  
        break;
    case OSTATOK:
        return;
        break;
    case RASHOD:
         table = UiRashod->TW_rashod;
         break;
    }

   QList<QTableWidgetItem*> selectedItem = table->selectedItems();
   if(selectedItem.isEmpty())
   {
       return;
   } 
   QSet<int> rowsToDel;
   for(QTableWidgetItem* item : selectedItem )
   {
       rowsToDel.insert(item->row());
   }
   QList<int> sorted = rowsToDel.values();
   std::sort(sorted.begin() , sorted.end() , std::greater<int>());

   for (int i : sorted)
   {
       table->removeRow(i);
   }

}
void gui::docuGuiController:: addElement()
{
    if (!isFullValue())
    {
        return;
    }
    QTableWidget* table;
    switch (isActive) {
    case PRIHOD:
        table = UiPrihod->TW_prihod;  
        break;
    case OSTATOK:
        return;
        break;
    case RASHOD:
         table = UiRashod->TW_rashod;
         break;
    }
    int rows = table->rowCount()  ; 
    table->insertRow(rows);
    table->setItem(rows, 0 , new QTableWidgetItem(uiAdd->LE_name->text()));
    table->setItem(rows , 1 , new QTableWidgetItem(uiAdd->DE_data->text()));
    table->setItem(rows , 2 , new QTableWidgetItem(uiAdd->LE_count->text()));
    table->setItem(rows,3 , new QTableWidgetItem(uiAdd->LE_unit->text())); 
    table->setItem(rows, 4 , new QTableWidgetItem(uiAdd->LE_price->text()));
    table->setItem(rows,5 , new QTableWidgetItem(uiAdd->LE_suplier->text()));
}
bool gui::docuGuiController::isFullValue()
{
    int IsAccept = 0 ;
    if(!uiAdd->LE_name->text().isEmpty())
    {
        IsAccept++;
    }
    if(!uiAdd->DE_data->text().isEmpty())
    {
        IsAccept++;
    } 
    if(!uiAdd->LE_count->text().isEmpty())
    {
        IsAccept++;
    }
    if(!uiAdd->LE_unit->text().isEmpty())
    {
        IsAccept++;
    }
    if(!uiAdd->LE_price->text().isEmpty())
    {
        IsAccept++;
    }
    if(!uiAdd->LE_suplier->text().isEmpty())
    {
        IsAccept++;
    }
    return IsAccept == 6;
}

// class Overlay:
gui::Overlay::Overlay(docuGuiController* docus,
        QWidget* overlays , QObject* parent) :
        QThread(parent) , overlay(overlays) ,docu(docus)
{
   docu->setCentral();
}
gui::Overlay::~Overlay()
{
    delete docu;
    delete overlay;
    closed= true;
}
void gui::Overlay::end()
{
    closed = true; 
}
void gui::Overlay::run()
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
void gui::Overlay::go()
{
    running = true;
}
void gui::Overlay::stop()
{
    running = false;
}

