#include <cstdio>
#include <pyController.h>
#include <qcontainerfwd.h>
#include <qdebug.h>
#include <qfloat16.h>
#include <qlogging.h>
#include <qobject.h>
#include <qprocess.h>
#include <filesystem>

QString pyPath = QString::fromStdString(std::filesystem::current_path())  ;
void py::generate(QStringList argument)
{
    QProcess genJson;
    QString genJsonPath = pyPath+"/script/convertor.py";
    QString outputFile = pyPath+"/save/analize.docx";
    QString filePath = pyPath+"/save/save.json";
    genJson.start(QString("python"), QStringList() << genJsonPath  << filePath
            << outputFile << argument);

    genJson.waitForFinished();
    QByteArray data = genJson.readAllStandardOutput();
    qDebug() << QString::fromUtf8(data);
}
