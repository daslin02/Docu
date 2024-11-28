#include <fstream>
#include <filesystem>
#include <nlohmann-json/json.hpp>
#include <string>
#include <QString>
using json = nlohmann::json;

std::string currentPath = std::filesystem::current_path() ;

std::ofstream lastFile;
std::ofstream currentFile;

void addProduct(QString name , QString data , QString price 
        , QString unit , QString count , QString suplier);
