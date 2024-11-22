#include <guiController.h>
#include <qmutex.h>



gui::docuGuiController::docuGuiController(QMainWindow* parent) : QMainWindow(parent)
{
   UiMainWindow = new Ui::MainWindow;
   UiMainWindow->setupUi(this);   
   mute = new QMutex;
  
}
gui::docuGuiController::~docuGuiController()
{
    delete UiMainWindow;
    delete mute;
}
bool gui::docuGuiController::startGui()
{
    this->show();

    return true;
}

