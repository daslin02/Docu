#include <guiController.h>
#include <fileManager.h>

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
    
    std::string path = FM::currentPath + "/save/save.json";
    return app.exec() ;
}
