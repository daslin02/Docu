#include <pyController.h>
#include <qcontainerfwd.h>
#include <qobject.h>
#include <qprocess.h>

QString pyPath = "/mnt/files/C++Project/Docu/script/genJson.py";
void generate(QStringList argument)
{
    QProcess genJson;
    genJson.start(QString("python"), QStringList() << pyPath << 
            " 100" );

}
