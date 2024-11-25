#include <complex>
#include <cstdio>
#include <pyController.h>
#include <qcontainerfwd.h>
#include <qdebug.h>
#include <qfloat16.h>
#include <qlogging.h>
#include <qobject.h>
#include <qprocess.h>
#include <iostream>
#include <filesystem>
#include <string>

QString pyPath = QString::fromStdString(std::filesystem::current_path())  ;
void generate(QStringList argument)
{
    QProcess genJson;
    QString genJsonPath = pyPath+"/script/genJson.py";
    QString savePath = pyPath+"/save/save.json";
    qDebug() << genJsonPath ; 
    genJson.start(QString("python"), QStringList() << genJsonPath  << savePath << argument);

    genJson.waitForFinished();
    QByteArray data = genJson.readAllStandardOutput();
    qDebug() << QString::fromUtf8(data);
}
