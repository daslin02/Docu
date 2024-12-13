#ifndef FM_H
#define FM_h
#include <fstream>

#include <nlohmann-json/json.hpp>

#include <string>
#include <QString>



using json = nlohmann::json;

namespace FM {

struct dataItem
{
    int typeTable = -1;
    int id = -1;
    std::string name = "Undefined";
    std::string data = "Undefined";
    std::string unit = "Undefined";
    std::string count = "Undefined";
    std::string price = "Undefined";
    std::string suplier = "Undefined";
};

extern int primaryKey;
extern std::string currentPath  ;

extern std::ofstream lastFile;
extern std::string currentFile;

void addProduct(QString name , QString data , QString price 
        , QString unit , QString count , QString suplier);

void addProduct(std::string name , std::string data , std::string price 
        , std::string unit , std::string count , std::string suplier);
bool findElement(const std::string& path , std::string name);

//bool pushPrihod(std::string name,std::string count , std::string unit ,std::string data , std::string price , std::string suplier);
bool pushPrihod(QString name,QString count, QString unit ,QString  data , QString price , QString suplier);

//bool pushRashod(std::string name,std::string count , std::string unit ,std::string data , std::string price , std::string suplier);
bool pushRashod(QString name,QString count ,QString unit ,QString  data , QString price , QString suplier);;
void removeElement(int id , int typetable);
std::vector<FM::dataItem> loadTable();
bool findFile( const std::string& path);
bool createFile(const std::string& path);
bool setCurentPath(const std::string& path);
bool fileIsEmpty(const std::string& path);
int getPrimaryKey();
int newPrimaryKey();
}

#endif
