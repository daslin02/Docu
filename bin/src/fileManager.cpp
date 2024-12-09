#include <fileManager.h>
#include <fstream>
#include <iostream>
#include <iterator>
#include <ostream>
#include <qcontainerfwd.h>
#include <qlogging.h>
#include <string>
#include <vector>

#define DATA_SIZE 100


std::string FM::currentPath = std::filesystem::current_path().string();
std::string FM::currentFile = std::filesystem::current_path().string()+"/save/save.json";
void FM::addProduct(QString name , QString data , QString price 
        , QString unit , QString count , QString suplier)
{
    std::string Sname ,Sdata , Sunit , Scount , Sprice , Ssuplier;
    Sname = name.toStdString();
    Sdata = data.toStdString();
    Sunit = unit.toStdString();
    Scount = count.toStdString();
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
                {{"data" , Sdata} ,
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
                {{"data" , data} ,
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
    std::string Sname , Sdata , Sunit , Scount , Sprice , Ssuplier;
    Sname = name.toStdString();
    Sdata = data.toStdString(); 
    Sunit= unit.toStdString();
    Scount = count.toStdString();
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
    std::string Sname , Sdata , Sunit , Scount , Sprice , Ssuplier;
    Sname = name.toStdString();
    Sdata = data.toStdString(); 
    Sunit= unit.toStdString();
    Scount = count.toStdString();
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
    if (!file)
    {
        std::cerr << "error is open " << std::endl;
        return false ; 
    }
    file.close();

    return FM::findFile(path) ; 
}

bool FM::findElement(const std::string& path , std::string name)
{
   if (!path.empty())
   { 
    json js ;
    std::ifstream outfile(path);
    if (!fileIsEmpty(path))
    {
        outfile >> js ; 
    }
    outfile.close();
    for (const auto& product : js)
    {
        if (product["name"] == name)
        {
            return true;
        }
    }
   }
   return false;
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
std::vector<FM::dataItem> FM::loadTable() // laod data from jsonFile
{    
    json js ;
    std::ifstream outfile(currentFile);
    outfile >> js ; 
    outfile.close(); 
    std::vector<dataItem> table ; 
    for (auto& product : js)
    {
        int point = 0 ;
        dataItem items[DATA_SIZE] ;  
        for (auto& prihodArray : product["prihod"])
        {
            for(auto& prihodItem : prihodArray)
            { 
            // 0 this is PRIHOD macros for guiController
                table.push_back({0 ,product["name"] ,
                        prihodItem["data"] , prihodItem["unit"] , prihodItem["count"],
                        prihodItem["price"] , prihodItem["suplier"]
                        });
            }
        }
        for (auto& rashodArray : product["rashod"])
        {
            for (auto& rashodItem : rashodArray)
            {
                if (rashodItem.is_object())
                {
                // 2 this is RASHOD for guiController
                table.push_back({2 ,product["name"] ,
                     rashodItem["data"] , rashodItem["unit"] , rashodItem["count"],
                        rashodItem["price"] , rashodItem["suplier"]
                        });
            
                }      
            }
        }

    }
    return table;
}
