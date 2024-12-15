#include <guiController.h>
#include <fileManager.h>

#include <qlogging.h>
#include <string>

#include <qmainwindow.h>

int main (int arg , char *argv[])
{
    QApplication app(arg,argv);
    gui::docuGuiController window;
    window.startGui();
    if (!FM::fileIsEmpty(FM::currentFile))
    {
        window.loadFile();
    }
    else 
    {
        bool result = FM::createFile(FM::currentPath+"/save/save.json");
        if(!result)
        {
            qDebug() << "no createFile";
            window.loadFile();
        }
    }
    
    std::string path = FM::currentPath + "/save/save.json";
    return app.exec() ;
}
