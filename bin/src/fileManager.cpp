#include <fileManager.h>
#include <fstream>
#include <iostream>
#include <qcontainerfwd.h>
#include <string>



std::string FM::currentPath = std::filesystem::current_path().string();

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
    if (currentPath != "")
    {
        std::ifstream outfile(currentPath);
        if (!fileIsEmpty(currentPath))
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
                {"suplier" , Ssuplier}}  );

        item["prihod"] = {prihod};
        js.push_back(item);
        
        std::ofstream file(currentPath);
        file << js.dump(4);
        file.close();
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
                {"suplier" , suplier}}  );

        item["prihod"] = {prihod};
        item["rashod"] = {};
        js.push_back(item);
        
        std::ofstream file(currentPath);
        file << js.dump(4);
        file.close();
    }    


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
