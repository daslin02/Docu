#include <main.h>
#include <pyController.h>

#include <iostream>

#include <qapplication.h>
#include <qcontainerfwd.h>
#include <qmainwindow.h>
#include <qobject.h>
#include <qpushbutton.h>

int main (int arg , char *argv[])
{

    QApplication app(arg,argv);
    Ui::MainWindow ui;
    QMainWindow window;
    ui.setupUi(&window);
    baseStyle(&ui);

//    generate(QStringList());
    runEvent(&ui, &window);    
    
    QObject::connect(ui.PB_prihod , &QPushButton::clicked , &window , [ &ui]()
            {
                ui.SW_stacked->setCurrentIndex(1);
                
            });
    window.show();
    return app.exec() ;
}
