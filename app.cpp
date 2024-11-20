#include <main.h>
#include <qapplication.h>
#include <qcontainerfwd.h>
#include <qmainwindow.h>
#include <iostream>
#include <qobject.h>
#include <qpushbutton.h>
#include <pyController.h>

int main (int arg , char *argv[])
{

    QApplication app(arg,argv);
    Ui::MainWindow ui;
    QMainWindow window;
    ui.setupUi(&window);
    baseStyle(&ui);

    generate(QStringList());
    
    QObject::connect(ui.PB_prihod , &QPushButton::clicked , &window , [ &ui]()
            {
                ui.SW_stacked->setCurrentIndex(1);
                
            });
    window.show();
    return app.exec() ;
}
