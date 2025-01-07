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
    #ifdef _WIN32
        QString runFile = pyPath+"/win-convertor/convertor.exe";
        qDebug() << "is windows" ; 
    #elif defined(__linux__)
        QString runFile = pyPath+"/linux-convertor/convertor";
        qDebug() << "is linux" ;
    #endif
    QString outputFile = pyPath+"/save/analize.docx";
    QString filePath = pyPath+"/save/analize.json";
    qDebug() << "outputFile: " + outputFile ;
    qDebug() << "filePath: "+ filePath;
    qDebug() << "runFile: " + runFile;
    genJson.start(runFile, QStringList() << filePath
            << outputFile);
    genJson.waitForFinished();
    QByteArray data = genJson.readAllStandardOutput();
    qDebug() << QString::fromUtf8(data);
}
