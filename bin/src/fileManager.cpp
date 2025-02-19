#include <fileManager.h>
#include <fstream>
#include <iostream>
#include <ostream>
#include <qcontainerfwd.h>
#include <qdatetime.h>
#include <qlogging.h>
#include <string>
#include <vector>


int FM::primaryKey = -1;
std::string FM::currentPath = std::filesystem::current_path().string();
std::string FM::currentFile = std::filesystem::current_path().string()+"/save/save.json";
void FM::addProduct(QString name , QString data , QString price 
        , QString unit , QString count , QString suplier)
{
    std::string Sname ,Sdata , Sunit , Sprice , Ssuplier;
    int Scount;
    Sname = name.toStdString();
    Sdata = data.toStdString();
    Sunit = unit.toStdString();
    Scount = count.toInt();
    Sprice = price.toStdString();
    Ssuplier = suplier.toStdString();

    json js = json::array();
    if (!FM::findFile(currentPath))
    {
        return;
    }
    if (currentFile != "")
    {

        std::ifstream outfile(currentFile);
        if (!fileIsEmpty(currentFile))
        {
            outfile >> js ; 
        }
        outfile.close();

        json item; 
        item["name"] = Sname;


        json prihod = json::array();
        prihod.push_back(
                {{"id" , getPrimaryKey()+1},
                {"data" , Sdata} ,
                {"price" , Sprice} ,
                {"count" , Scount},
                    {"unit" , Sunit}, 
                {"suplier" , Ssuplier}}  );

        json rashod = json::array();
        item["prihod"] = {prihod};
        item["rashod"] = {rashod};
        js.push_back(item);
        
        std::ofstream file(currentFile);
        file << js.dump(4);
        file.close();
        return;
    }   
}

void FM::addProduct(std::string name , std::string data , std::string price 
        , std::string unit , std::string count , std::string suplier)
{

    json js = json::array();
    if (!FM::findFile(currentPath))
    {
        return;
    }
    if (currentPath != "")
    {
        std::ifstream outfile(currentPath);
        if (!fileIsEmpty(currentPath))
        {
            outfile >> js ; 
        }
        outfile.close();
        
        json item; 
        item["name"] = name;


        json prihod = json::array();
        prihod.push_back(
                { {"id" , getPrimaryKey()+1}, 
                {"data" , data} ,
                {"price" , price} ,
                {"count" , count},
                    {"unit" , unit}, 
                {"suplier" , suplier}}  );

        item["prihod"] = {prihod};
        item["rashod"] = {};
        js.push_back(item);
        
        std::ofstream file(currentPath);
        file << js.dump(4);
        file.close();
    }    


}
bool FM::pushPrihod(QString name, QString count,QString unit ,QString  data , QString price , QString suplier)
{
    std::string Sname , Sdata , Sunit , Sprice , Ssuplier;
    int Scount;
    Sname = name.toStdString();
    Sdata = data.toStdString(); 
    Sunit= unit.toStdString();
    Scount = count.toInt();
    Sprice = price.toStdString();
    Ssuplier = suplier.toStdString();


    json js ;
    std::ifstream outfile(currentFile);
    if (!fileIsEmpty(currentFile))
    {
        outfile >> js ; 
    }
    outfile.close();
    for ( auto& product : js)
    {
        if (product["name"] == Sname)
        {
            product["prihod"][0].push_back(
            {
                    {"id" , getPrimaryKey()+1},
                {"data", Sdata},
                {"price", Sprice},
                {"count", Scount},
                {"unit", Sunit},
                {"suplier", Ssuplier}
            });

            std::ofstream file(currentFile);
            file << js.dump(4);
            file.close();
    
            return true;
        }
    }
    return false;
}

bool FM::pushRashod(QString name, QString count,QString unit ,QString  data , QString price , QString suplier)
{
    std::string Sname , Sdata , Sunit ,  Sprice , Ssuplier;
    int Scount;
    Sname = name.toStdString();
    Sdata = data.toStdString(); 
    Sunit= unit.toStdString();
    Scount = count.toInt();
    Sprice = price.toStdString();
    Ssuplier = suplier.toStdString();


    json js ;
    std::ifstream outfile(currentFile);
    if (!fileIsEmpty(currentFile))
    {
        outfile >> js ; 
    }
    outfile.close();
    for ( auto& product : js)
    {
        if (product["name"] == Sname)
        {
            json newPrihod = 
            {
                    {"id" , getPrimaryKey()+1},
                {"data" , Sdata},
                {"price" , Sprice},
                {"count", Scount},
                {"unit" , Sunit},
                {"suplier" , Ssuplier}
            };
            product["rashod"][0].push_back(newPrihod);
   
            std::ofstream file(currentFile);
            file << js.dump(4);
            file.close();

            return true;
        }
    }
    return false;
}
bool FM::fileIsEmpty(const std::string& path)
{
     std::ifstream file(path);

    return file.peek() == std::ifstream::traits_type::eof();
}
bool FM::findFile(const std::string& path)
{
    std::ifstream file(path);
    if (file.is_open())
    {
        file.close();
        return true;
    }
    file.close();
    return false;
}
bool FM::createFile(const std::string& path)
{
    std::ofstream file(path);
    if (!file.is_open())
    {
        std::cerr << "error is open " << std::endl;
        file.close();
        return false ; 
    }
    file.close();
    return FM::findFile(path) ; 
}

std::vector<FM::dataItem> FM::findElement( std::string element , int typeTable)
{
    std::vector<dataItem> data;
    json js ;
    std::ifstream outfile(currentFile);
    if (!fileIsEmpty(currentFile))
    {
        outfile >> js ; 
    }
    std::string table = "prihod";
    if(typeTable == 2) {table = "rashod";} 
    outfile.close();
    for (const auto& product : js)
    {
       for(auto& arr_product : product[table])
       {
           for (auto& arr : arr_product)
           {
                if (element == arr["count"])
                {
                    data.push_back({typeTable , arr["id"] , product["name"] , arr["data"],
                            arr["unit"] , arr["count"] , arr["price"] , arr["suplier"]
                            });
                }
                else if(element == product["name"])
                {
                    data.push_back({typeTable , arr["id"] , product["name"] , arr["data"],
                            arr["unit"] , arr["count"] , arr["price"] , arr["suplier"]
                            });
                }
                else if (element == arr["suplier"])
                {
                    data.push_back({typeTable , arr["id"] , product["name"] , arr["data"],
                            arr["unit"] , arr["count"] , arr["price"] , arr["suplier"]
                            });

                }
                else if (element == arr["price"]) 
                {
                    data.push_back({typeTable , arr["id"] , product["name"] , arr["data"],
                            arr["unit"] , arr["count"] , arr["price"] , arr["suplier"]
                            });
                }
                else if (element == arr["data"])
                {
                    data.push_back({typeTable , arr["id"] , product["name"] , arr["data"],
                            arr["unit"] , arr["count"] , arr["price"] , arr["suplier"]
                            });
                }
                else if(element == arr["unit"])
                {
                    data.push_back({typeTable , arr["id"] , product["name"] , arr["data"],
                            arr["unit"] , arr["count"] , arr["price"] , arr["suplier"]
                            });
                }
           }
       }
    }
   return data;
}
bool FM::setCurentPath(const std::string &path)
{
    if (FM::findFile(path))
    {
         currentPath = path; 
         return true;
    }   
   return false; 
}
std::vector<FM::dataItem> FM::loadTable(int typeTable) // load data from jsonFile
{   
    json js ;
    std::ifstream outfile(currentFile);
    outfile >> js ; 
    outfile.close(); 
    std::vector<dataItem> table ;
    for (auto& product : js)
    {
        if (typeTable == -1 || typeTable == 0 ) // full or prihod 0 is this priho
        {
            for (auto& prihodArray : product["prihod"])
            {
                for(auto& prihodItem : prihodArray)
                { 
                // 0 this is PRIHOD macros for guiController
                    table.push_back({0 ,prihodItem["id"],product["name"] ,
                            prihodItem["data"] , prihodItem["unit"] , prihodItem["count"],
                            prihodItem["price"] , prihodItem["suplier"]
                            });
                }
            }
        }
        if(typeTable == -1 || typeTable == 2)
        {
            
            for (auto& rashodArray : product["rashod"])
            {
                for (auto& rashodItem : rashodArray)
                {
                    if (rashodItem.is_object())
                    {
                    // 2 this is RASHOD for guiController
                    table.push_back({2 ,rashodItem["id"],product["name"] ,
                         rashodItem["data"] , rashodItem["unit"] , rashodItem["count"],
                            rashodItem["price"] , rashodItem["suplier"]
                            });
            
                     }      
                }
            }
        }

    }
    return table;
}

void FM::removeElement(int id , int typeTable)
{
    
    if (fileIsEmpty(currentFile))
    {
        return;
    }
   
    json js;
    std::fstream outFile(currentFile);
    outFile >> js;
    outFile.close();
    int point = 0;
    std::string table = "prihod" ;
    if (typeTable == 2 ) {table = "rashod";}
   
    std::ofstream file(currentFile);
    for (auto& product : js)
    {
        point = 0;
       if (product[table][0].size() > 0 )
       { 
           for (auto& arr : product[table][0] )
            {
                if (arr["id"] == id)
                {
                    product[table][0].erase(point);
                    file << js.dump(4);
                    file.close();
                    return;
                }
                point++;
            }
       } 
    }
}
int FM::getPrimaryKey()
{
    if (fileIsEmpty(currentFile))
    {
        return -1;
    }
    if (primaryKey != -1)
    {
        return primaryKey;
    }
    json js;
    std::fstream outFile(currentFile);
    outFile >> js;
    outFile.close();
    int max = 0;
    for (auto& product : js)
    {
        for (auto& prihodArray : product["prihod"])
        {
            for(auto& prihodItem : prihodArray)
            { 
                if (prihodItem["id"] > max)
                {
                    max = prihodItem["id"];
                }        
            }
        }
        for (auto& rashodArray : product["rashod"])
        {
            for (auto& rashodItem : rashodArray)
            { 
                if (rashodItem["id"] > max)
                {
                    max = rashodItem["id"];
                }        
            }
        }

    }
    primaryKey = max+1;
    return primaryKey;
}
int FM::newPrimaryKey()
{
    FM::primaryKey++;
    return primaryKey;
}
std::vector<FM::analizeData> FM::analize(QDate before , QDate after)
{
    std::vector<FM::analizeData> data ;
    if (fileIsEmpty(currentFile))
    {
        return data;
    }
    json js;
    std::fstream outFile(currentFile);
    outFile >> js;
    outFile.close();
    for (auto& product : js)
    {
        std::cout << "iteration product" << std::endl;
        for (auto& arr : product["prihod"][0])
        {
            std::cout << "-------------iteration prihod---------------" << std::endl;
            bool isFind = false;
            for (analizeData& i : data)
            {
                if (i.name == product["name"])
                {
                    std::string calendar = arr["data"]; 
                    QDate dates = QDate::fromString( QString::fromStdString(calendar) , "dd.MM.yyyy");
                    if(before <= dates && after >= dates) \
                    {
                        isFind = true;
                        i.surplus += arr["count"].get<int>();
                    }
                }
            }
            if (!isFind)
            {
                std::string calendar = arr["data"]; 
                QDate dates = QDate::fromString( QString::fromStdString(calendar) , "dd.MM.yyyy");
                std::cout << "before: " << before.toString().toStdString() << " | data: " << calendar << " | after: " << after.toString().toStdString() << std::endl; 
                std::cout << "\tbefore < dates : " << (before < dates) << std::endl;
                std::cout << "\tafter > dates : " << (after >  dates) << std::endl;
                if(before <= dates && after >= dates) 
                {
                    std::cout << "prihod add - data: "<< dates.toString("dd.MM.yyyy").toStdString() << std::endl;
                    data.push_back({product["name"] ,
                          after.toString("dd.MM.yyyy").toStdString() , arr["count"] ,
                            arr["unit"]});
                }       
            }
        }
        for (auto& arr : product["rashod"][0])
        {
            std::cout << "------------------iteration rashod-----------------" << std::endl;
            bool isFind = false;
            for (analizeData& i : data)
            {
                if (i.name == product["name"]) 
                {
                    std::string calendar = arr["data"]; 
                    QDate dates = QDate::fromString( QString::fromStdString(calendar) , "dd.MM.yyyy");
                    if(before <= dates && after >= dates) \
                    {
                        isFind = true;
                        i.surplus -= arr["count"].get<int>();
                    }
                }
            }
            if (!isFind)
            {
                std::string calendar = arr["data"];
                QDate dates = QDate::fromString( QString::fromStdString(calendar) , "dd.MM.yyyy");
                if(before < dates && after > dates) 
                {
                    std::cout << "rashod add " << std::endl;
                    data.push_back({product["name"] ,
                          after.toString("dd.MM.yyyy").toStdString() , -arr["count"].get<int>() ,
                            arr["unit"]});
                }       
            }
         }
     }
        for (analizeData i : data)
        {
            std::cout << "name: "<< i.name <<" | data: " << i.data << " | surplus: " << i.surplus << std::endl;
        }
        std::cout << data.size() << std::endl;
        return data;
    }

FM::dataItem FM::getId(int id )
{
    json js ;
    std::ifstream outfile(currentFile);
    if (!fileIsEmpty(currentFile))
    {
        outfile >> js ; 
    }
    outfile.close();
    for (auto& product : js)
    {
        for (auto& arr : product["prihod"][0])
        {
            if (id == arr["id"] )
            {
                return {0 , arr["id"] , product["name"] , arr["data"] ,
                    arr["unit"] , arr["count"] ,arr["price"],arr["suplier"] };
            }
        }
        for (auto& arr : product["rashod"][0])
        {
            if (id == arr["id"] )
            {
                return {0 , arr["id"] , product["name"] , arr["data"] ,
                    arr["unit"] , arr["count"] ,arr["price"],arr["suplier"] };
            }
        }
    }

    return dataItem{};
}
bool FM::setId(FM::dataItem value )
{
    json js ;
    std::ifstream outfile(currentFile);
    if (!fileIsEmpty(currentFile))
    {
        outfile >> js ; 
    }
    else
    {
        return 0;
    }
    outfile.close();
    for (auto& product : js)
    {
        for (auto& arr : product["prihod"][0])
        {
            if (value.id == arr["id"] )
            {
                product["name"] = value.name;
                arr["data"] = value.data;
                arr["price"] = value.price;
                arr["count"] = value.count;
                arr["unit"] = value.unit;
                arr["suplier"] = value.suplier;

                std::ofstream file(currentFile);
                file << js.dump(4);
                file.close();
                return 1;
            }
        }
        for (auto& arr : product["rashod"][0])
        {
            if (value.id == arr["id"] )
            {
                product["name"] = value.name;
                arr["data"] = value.data;
                arr["price"] = value.price;
                arr["count"] = value.count;
                arr["unit"] = value.unit;
                arr["suplier"] = value.suplier;
                
                std::ofstream file(currentFile);
                file << js.dump(4);
                file.close();

                return 1;
            }
        }
    }

    return 0;
}
void FM::print(std::vector<FM::analizeData> data) 
{
    json js;
    
    for (const auto& item : data) {
        json entry;
        entry["name"] = item.name;
        entry["data"] = item.data;
        entry["surplus"] = item.surplus;
        entry["unit"] = item.unit;
        js.push_back(entry);
    }
    std::ofstream outFile(FM::currentPath+"/save/analize.json");
    outFile << js.dump(4); 
    outFile.close();
}

