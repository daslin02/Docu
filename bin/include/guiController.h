#include "browserWidget.h"
#include <qmainwindow.h>
#include <QMutex>
#include <QThread>

#include <qmutex.h>
#include <qobject.h>
#include <qsize.h>
#include <qstandarditemmodel.h>
#include <qthread.h>
#include <qvariant.h>
#include <qwidget.h>
#include <rashod.h>
#include <prihod.h>
#include <ostatok.h>

#include <iostream>
#include <main.h>
#include <suplier.h>
#include <pyController.h>
#include <prihodWidget.h>
#include <QStandardItemModel>

namespace gui {


#define PRIHOD 0 
#define OSTATOK 1 
#define RASHOD 2 

extern QStandardItemModel* rashodModel;
extern QStandardItemModel* prihodModel;
extern QStandardItemModel* ostatokModel;

class Overlay; 
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
   QSize getCentral();
   void setCentral();

   bool isFullValue();
   void addElement();
   void delElement();
private :
    QWidget* prihod;
    Ui::W_prihod* UiPrihod;

    QWidget* rashod;
    Ui::W_rashod* UiRashod;
    
    QWidget* ostatok;
    Ui::W_ostatok* UiOstatok;

    int isActive = 0;
    QWidget* dialogPrihod;
    Ui::dialogPrihod* uiAdd;
    
    QWidget* dialogFind;
    Ui::browserWidget* uiFind;
    
    QMutex* PointOverlay;
    Overlay* findOverlay;
    Overlay* addOverlay;
    Ui::MainWindow* UiMainWindow;
    QSize central;
    void runAllEvent();
};

class Overlay : public QThread
{
public:
    explicit Overlay(docuGuiController* docu, QWidget* overlay ,   QObject* parent = nullptr);
    ~Overlay();
    void go();
    void end();
    void stop();
    void run() override;
private:
    docuGuiController* docu;
    QWidget* overlay;
    bool closed = false;
    bool running  = false;
};
}
