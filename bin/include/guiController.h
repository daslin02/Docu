#include <qmainwindow.h>
#include <QMutex>
#include <QThread>

#include <rashod.h>
#include <prihod.h>
#include <ostatok.h>

#include <iostream>
#include <main.h>
#include <suplier.h>
#include <pyController.h>


namespace gui {

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
private :
    QWidget* prihod;
    Ui::W_prihod* UiPrihod;

    QWidget* rashod;
    Ui::W_rashod* UiRashod;
    
    QWidget* ostatok;
    Ui::W_ostatok* UiOstatok;
   
    QMutex* mute;
    Ui::MainWindow* UiMainWindow;
    void runAllEvent();
};

}
