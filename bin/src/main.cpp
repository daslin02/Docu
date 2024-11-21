#include <main.h>
#include <qcontainerfwd.h>
#include <qmainwindow.h>
#include <qobject.h>
#include <qpushbutton.h>
#include <pyController.h>


void baseStyle(Ui::MainWindow* ui)
{
    ui->prihod->setStyleSheet("background:red;");
    ui->home->setStyleSheet("background:White;");
}
void runEvent(Ui::MainWindow* ui , QMainWindow* win)
{

    QObject::connect(ui->PB_analize , &QPushButton::clicked , win , []()
            {
               generate(QStringList() <<  QString("-add") << "patato" << QString("100") << "kg" << "huevo kukuevo" <<";" << "tomato" << QString("20.5") << "count" << "huevo kukuevo"); 
            }); 

}

