#ifndef FM_H
#define FM_H
#include <fstream>

#include <nlohmann-json/json.hpp>

#include <string>
#include <QString>
#include <vector>



using json = nlohmann::json;

namespace FM {

struct dataItem
{
    int typeTable = -1;
    int id = -1;
    std::string name = "Undefined";
    std::string data = "Undefined";
    std::string unit = "Undefined";
    int count = 0;
    std::string price = "Undefined";
    std::string suplier = "Undefined";
};
struct analizeData
{
    std::string name ;
    std::string data;
    int surplus = 0;
    std::string unit;
};

extern int primaryKey;
extern std::string currentPath  ;

extern std::ofstream lastFile;
extern std::string currentFile;

void addProduct(QString name , QString data , QString price 
        , QString unit , QString count , QString suplier);

void addProduct(std::string name , std::string data , std::string price 
        , std::string unit , std::string count , std::string suplier);
bool pushPrihod(QString name,QString count, QString unit ,QString  data , QString price , QString suplier);
bool pushRashod(QString name,QString count ,QString unit ,QString  data , QString price , QString suplier);;
void removeElement(int id , int typetable);

std::vector<FM::dataItem> findElement( std::string element , int typeTable);
FM::dataItem getId(int id );
bool setId(dataItem value);

std::vector<FM::dataItem> loadTable(int typetable = -1);
std::vector<FM::analizeData> analize();

bool findFile( const std::string& path);
bool createFile(const std::string& path);
bool setCurentPath(const std::string& path);
bool fileIsEmpty(const std::string& path);

int getPrimaryKey();
int newPrimaryKey();
}

#endif
