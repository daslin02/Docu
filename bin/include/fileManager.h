#include <fstream>
#include <filesystem>
#include <iostream>

#include <nlohmann-json/json.hpp>

#include <string>
#include <QString>


using json = nlohmann::json;

namespace FM {


extern std::string currentPath  ;

extern std::ofstream lastFile;
extern std::string currentFile;

void addProduct(QString name , QString data , QString price 
        , QString unit , QString count , QString suplier);

void addProduct(std::string name , std::string data , std::string price 
        , std::string unit , std::string count , std::string suplier);
bool findElement(const std::string& path , std::string name);

bool findFile( const std::string& path);
bool createFile(const std::string& path);
bool setCurentPath(const std::string& path);
bool fileIsEmpty(const std::string& path);
}
