#include <guiController.h>
#include <fileManager.h>

#include <iostream>
#include <string>

#include <qmainwindow.h>

int main (int arg , char *argv[])
{
    QApplication app(arg,argv);
    gui::docuGuiController window;
    window.startGui();
    
    std::string path = FM::currentPath + "/save/save.json";
    return app.exec() ;
}
