#include "main.h"
#include "ostatok.h"
#include "prihod.h"
#include "rashod.h"
#include <guiController.h>
#include <qmutex.h>
#include <qpushbutton.h>
#include <qwidget.h>



gui::docuGuiController::docuGuiController(QMainWindow* parent) : QMainWindow(parent)
{
   UiMainWindow = new Ui::MainWindow;
   UiMainWindow->setupUi(this);   
   mute = new QMutex;
   baseStyle(UiMainWindow);
  runEvent(UiMainWindow, this); 
}
gui::docuGuiController::~docuGuiController()
{
    delete UiMainWindow;
    delete mute;
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
   
   this->runAllEvent(); 
    this->show();

    return true;
}
void gui::docuGuiController::runAllEvent()
{
    connect(UiMainWindow->PB_prihod , &QPushButton::clicked , this , &docuGuiController::swapPrihod);
    connect(UiMainWindow->PB_ostatok , &QPushButton::clicked , this , &docuGuiController::swapOstatok);
    connect(UiMainWindow->PB_rashod , &QPushButton::clicked , this , &docuGuiController::swapRashod);
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
