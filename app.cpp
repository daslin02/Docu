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
    
    //baseStyle(&ui);
    std::string path = FM::currentPath + "/save/save.json";
    FM::setCurentPath(path);
    FM::addProduct(std::string("Potato") , "12.08.2006" , "12" , "kg" , "100" , "kto-to");
    //    generate(QStringList());
    FM::addProduct(std::string("tomato") , "9.12.1996" , "67" , "ht" , "43" , "kto-to");
    std::cout <<  FM::findElement(path, "Potato") << std::endl; 
    //runEvent(&ui, &window);    
    
   // QObject::connect(ui.PB_prihod , &QPushButton::clicked , &window , [ &ui]()
     //       {
         //       ui.SW_stacked->setCurrentIndex(1);
                
       //     });
    return app.exec() ;
}
