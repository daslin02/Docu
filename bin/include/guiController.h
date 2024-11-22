#include <qmainwindow.h>
#include <QMutex>
#include <QThread>

#include <main.h>
#include <qtmetamacros.h>
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
    
private :
    QMutex* mute;
    Ui::MainWindow* UiMainWindow;
    void runAllEvent();
};

}
