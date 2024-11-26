#include <qmainwindow.h>
#include <QMutex>
#include <QThread>

#include <qmutex.h>
#include <qobject.h>
#include <qsize.h>
#include <qthread.h>
#include <qwidget.h>
#include <rashod.h>
#include <prihod.h>
#include <ostatok.h>

#include <iostream>
#include <main.h>
#include <suplier.h>
#include <pyController.h>
#include <prihodWidget.h>


namespace gui {

class positionOverlay; 
class docuGuiController :public QMainWindow
{
public:
     explicit   docuGuiController(QMainWindow* parent = nullptr) ;
    ~docuGuiController();
    bool startGui();
public slots:
   void swapPrihod();
   void swapOstatok();
   void swapRashod();   
   void showDialogPrihod();
   void closeDialogPrihod();
   QSize centerPoint();
private :
    QWidget* prihod;
    Ui::W_prihod* UiPrihod;

    QWidget* rashod;
    Ui::W_rashod* UiRashod;
    
    QWidget* ostatok;
    Ui::W_ostatok* UiOstatok;

    QWidget* dialogPrihod;
    Ui::dialogPrihod* uiDialogPrihod;

    QMutex* PointOverlay;
    positionOverlay* posOverlay;
    Ui::MainWindow* UiMainWindow;
    void runAllEvent();
};

class positionOverlay : public QThread
{
public:
    explicit positionOverlay(docuGuiController* docu, QWidget* overlay ,Ui::dialogPrihod*  ui,   QObject* parent = nullptr);
    ~positionOverlay();
   // explicit positionOverlay(QWidget* overlay ,QObject*  ui,   QObject* parent = nullptr);
    //explicit positionOverlay(QWidget* overlay ,QObject*  ui,   QObject* parent = nullptr);
    void go();
    void stop();
    void run() override;
private:
    docuGuiController* docu;
    Ui::dialogPrihod* uiOverlay;
    QWidget* overlay;
    bool closed = false;
    bool running  = false;
};
}
