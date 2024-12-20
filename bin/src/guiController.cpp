#include "browserWidget.h"
#include "main.h"
#include "ostatok.h"
#include "prihod.h"
#include "prihodWidget.h"
#include "rashod.h"
#include <guiController.h>
#include <qcontainerfwd.h>
#include <qlogging.h>
#include <qpushbutton.h>
#include <qtablewidget.h>
#include <string>
#include <vector>
#include <fileManager.h>


gui::docuGuiController::docuGuiController(QMainWindow* parent) : QMainWindow(parent)
{

   UiMainWindow = new Ui::MainWindow;
   UiMainWindow->setupUi(this);   
   PointOverlay = new QMutex;
   this->setMinimumSize(QSize(700,700));
   this->setWindowTitle("Docu");
}
gui::docuGuiController::~docuGuiController()
{

    delete UiMainWindow;
    addOverlay->end(); 
    findOverlay->end();
    delete PointOverlay;
    if (dialogPrihod->isVisible())
    {
        dialogPrihod->close();
    } 
    delete dialogPrihod; 
    delete uiAdd;

    delete dialogFind;
    delete uiFind;
    
    delete UiPrihod;
    delete  prihod;
    
    delete rashod;
    delete UiRashod;
    
    delete ostatok;
    delete UiOstatok;
}

void gui::docuGuiController::loadFile()
{
    systemEdit = true;
    std::vector<FM::dataItem> dates = FM::loadTable();
    QTableWidget *table ;
    for (FM::dataItem data : dates)
    {
        if (data.typeTable == PRIHOD)
        {
            table = UiPrihod->TW_prihod;
        }
        else {
            table = UiRashod->TW_rashod;
        }
        int rows = table->rowCount();
        table->insertRow(rows);
        table->setItem(rows, 0, new QTableWidgetItem(QString::number(data.id)));
        table->setItem(rows, 1, new QTableWidgetItem(QString::fromStdString(data.name)));
        table->setItem(rows , 2 , new QTableWidgetItem(QString::fromStdString(data.data)));
        table->setItem(rows , 3 , new QTableWidgetItem(QString::number(data.count)));
        table->setItem(rows,4 , new QTableWidgetItem(QString::fromStdString(data.unit))); 
        table->setItem(rows, 5 , new QTableWidgetItem(QString::fromStdString(data.price)));
        table->setItem(rows,6 , new QTableWidgetItem(QString::fromStdString( data.suplier)));
    }
    systemEdit = false;
}
bool gui::docuGuiController::startGui()
{
    // removve element stacked Widget
    while(UiMainWindow->SW_stacked->count() > 0)
    {
        QWidget* widget = UiMainWindow->SW_stacked->widget(0);
        UiMainWindow->SW_stacked->removeWidget(widget);
        delete widget;
    }
    //inicializayion widget and ui 
    prihod = new QWidget();
    ostatok = new QWidget();
    rashod = new QWidget();
    
    UiPrihod = new Ui::W_prihod();
    UiOstatok = new Ui::W_ostatok();
    UiRashod = new Ui::W_rashod();


    UiPrihod->setupUi(prihod);
    UiOstatok->setupUi(ostatok);
    UiRashod->setupUi(rashod);
   
    UiMainWindow->SW_stacked->addWidget(prihod);
    UiMainWindow->SW_stacked->addWidget(ostatok);
    UiMainWindow->SW_stacked->addWidget(rashod);
  
    dialogPrihod = new QWidget(this);
    uiAdd = new Ui::dialogPrihod;
    uiAdd->setupUi(dialogPrihod);
   
    dialogPrihod->setStyleSheet("background:#1c1f20;");
    dialogPrihod->resize(500 , 500);
    dialogPrihod->move(100 , 100);

    dialogFind = new QWidget(this);
    uiFind = new Ui::browserWidget;
    uiFind->setupUi(dialogFind);


    dialogFind->setStyleSheet("background:#1c1f20;");
    dialogFind->resize(500 , 500);
    dialogFind->move(100 , 100);
   

    //close all menu
    dialogPrihod->close(); 
    dialogFind->close();    
    this->runAllEvent(); 
    
   
    this->show();
    
    addOverlay = new gui::Overlay(this ,dialogPrihod  );
    addOverlay->start();
    findOverlay = new gui::Overlay(this ,dialogFind  );
    findOverlay->start();
    return true;
}
QSize gui::docuGuiController::centerPoint()
{
    QRect geometry = this->geometry();
    int centerX =  geometry.x() + geometry.width() / 2 ;
    int centerY =  geometry.y() + geometry.height() / 2 ;
    return QSize(centerX , centerY);
}
QSize gui::docuGuiController::getCentral()
{
    return central;
}
void gui::docuGuiController::setCentral()
{
    central = centerPoint();
}
void gui::docuGuiController::runAllEvent()
{
    //conect close event 
    connect(uiAdd->PB_closed , &QPushButton::clicked ,this,&docuGuiController::closeDialogPrihod); 
    //conect close event find menu
    connect(uiFind->PB_closedFind , &QPushButton::clicked ,this,&docuGuiController::closeDialogFind); 
    connect(uiFind->PB_closedReplace , &QPushButton::clicked ,this,&docuGuiController::closeDialogFind); 

    //conect swap widget in stacked widget
    connect(UiMainWindow->PB_prihod , &QPushButton::clicked , this , &docuGuiController::swapPrihod);
    connect(UiMainWindow->PB_ostatok , &QPushButton::clicked , this , &docuGuiController::swapOstatok);
    connect(UiMainWindow->PB_rashod , &QPushButton::clicked , this , &docuGuiController::swapRashod);

   //conect dialog form
    connect(UiPrihod->PB_add  , &QPushButton::clicked , this , &docuGuiController::showDialogPrihod);
    
    connect(UiRashod->PB_add  , &QPushButton::clicked , this , &docuGuiController::showDialogPrihod);
   

    connect(UiPrihod->PB_delete  , &QPushButton::clicked , this , &docuGuiController::delElement);
    
    connect(UiRashod->PB_delete  , &QPushButton::clicked , this , &docuGuiController::delElement);

    connect(uiAdd->PB_add , &QPushButton::clicked , this , &docuGuiController::addElement);

    //conect find menu 
    connect(UiRashod->PB_find  , &QPushButton::clicked , this , &docuGuiController::showDialogFind);
    
    connect(UiRashod->PB_find  , &QPushButton::clicked , this , &docuGuiController::showDialogFind);
  // from prihod 
    connect(UiPrihod->PB_find  , &QPushButton::clicked , this , &docuGuiController::showDialogFind);
    
    connect(UiPrihod->PB_find  , &QPushButton::clicked , this , &docuGuiController::showDialogFind);
    //from ostatok 
    connect(UiOstatok->PB_find  , &QPushButton::clicked , this , &docuGuiController::showDialogFind);
    
    connect(UiOstatok->PB_find  , &QPushButton::clicked , this , &docuGuiController::showDialogFind);

    //conect event replace and find functional

    connect(uiFind->PB_find , &QPushButton::clicked , this , &docuGuiController::findElement);
    connect(uiFind->PB_replace , &QPushButton::clicked , this , &docuGuiController::replaceElement);
    //reset Find
    connect(UiPrihod->PB_reset , &QPushButton::clicked , this , &docuGuiController::resetFind);
    connect(UiRashod->PB_reset , &QPushButton::clicked , this , &docuGuiController::resetFind);
    connect(UiOstatok->PB_reset , &QPushButton::clicked , this , &docuGuiController::resetFind);
//connect analizate
    connect(UiOstatok->PB_analize , &QPushButton::clicked , this , &docuGuiController::analize);
    //edit item for table 
    connect(UiRashod->TW_rashod , &QTableWidget::itemChanged , this , &docuGuiController::onItemchange);
    connect(UiPrihod->TW_prihod , &QTableWidget::itemChanged , this , &docuGuiController::onItemchange);
    // crate save
    connect(UiMainWindow->PB_File , &QPushButton::clicked , this , &docuGuiController::generate );
}
void gui::docuGuiController::generate()
{
    py::generate(QStringList());
}    
void gui::docuGuiController::showDialogPrihod()
{
    QRect overlayGeometry = dialogPrihod->geometry();
   
    int centerX =  overlayGeometry.x() + overlayGeometry.width() / 2 ;
    int centerY =  overlayGeometry.y() + overlayGeometry.height() / 2 ;
    
    QSize center = this->centerPoint();

    dialogPrihod->move(center.width() - centerX/2, center.height() - centerY/2);
    
    
    addOverlay->go();
    dialogPrihod->raise();
    dialogPrihod->show();    
}
void gui::docuGuiController::closeDialogPrihod()
{
    addOverlay->stop();
    dialogPrihod->close();
}
// Find menu on visible
void gui::docuGuiController::showDialogFind()
{
    QRect overlayGeometry = dialogFind->geometry();
   
    int centerX =  overlayGeometry.x() + overlayGeometry.width() / 2 ;
    int centerY =  overlayGeometry.y() + overlayGeometry.height() / 2 ;
    
    QSize center = this->centerPoint();

    dialogFind->move(center.width() - centerX/2, center.height() - centerY/2);
    
    
    findOverlay->go();
    dialogFind->raise();
    dialogFind->show();    
}
void gui::docuGuiController::closeDialogFind()
{
    findOverlay->stop();
    dialogFind->close();
}

void gui::docuGuiController::swapPrihod()
{
    isActive = PRIHOD;
    UiMainWindow->SW_stacked->setCurrentIndex(PRIHOD);
} 
void gui::docuGuiController::swapOstatok()
{
    isActive = OSTATOK;
    UiMainWindow->SW_stacked->setCurrentIndex(OSTATOK);
} 
void gui::docuGuiController::swapRashod()
{
    isActive = RASHOD;
    UiMainWindow->SW_stacked->setCurrentIndex(RASHOD);
}
void gui::docuGuiController::delElement()
{
    QTableWidget* table;
    switch (isActive) {
    case PRIHOD:
        table = UiPrihod->TW_prihod;  
        break;
    case OSTATOK:
        return;
        break;
    case RASHOD:
         table = UiRashod->TW_rashod;
         break;
    }
    systemEdit = true;
   QList<QTableWidgetItem*> selectedItem = table->selectedItems();
   if(selectedItem.isEmpty())
   {
       return;
   } 
   QSet<int> rowsToDel;
   for(QTableWidgetItem* item : selectedItem )
   {
       rowsToDel.insert(item->row());
   }
   QList<int> sorted = rowsToDel.values();
   std::sort(sorted.begin() , sorted.end() , std::greater<int>());

   for (int i : sorted)
   {
       FM::removeElement(table->item(i , 0)->text().toInt() , isActive);
       table->removeRow(i);
   }
    systemEdit = false;
}
void gui::docuGuiController::resetFind()
{

    QTableWidget* table;
    switch (isActive) {
    case PRIHOD:
        table = UiPrihod->TW_prihod;  
        break;
    case OSTATOK:
        table = UiOstatok->TW_ostatok;
        break;
    case RASHOD:
         table = UiRashod->TW_rashod;
         break;
    }
    systemEdit = true ;
    if(isActive != OSTATOK)
    {
        table->setRowCount(0);
        std::vector<FM::dataItem> datas = FM::loadTable(isActive);
        for (FM::dataItem data : datas)
        {
        int rows = table->rowCount();       
        table->insertRow(rows);
        table->setItem(rows, 0, new QTableWidgetItem(QString::number(data.id)));
        table->setItem(rows, 1, new QTableWidgetItem(QString::fromStdString(data.name)));
        table->setItem(rows , 2 , new QTableWidgetItem(QString::fromStdString(data.data)));
        table->setItem(rows , 3 , new QTableWidgetItem(QString::number(data.count)));
        table->setItem(rows,4 , new QTableWidgetItem(QString::fromStdString(data.unit))); 
        table->setItem(rows, 5 , new QTableWidgetItem(QString::fromStdString(data.price)));
        table->setItem(rows,6 , new QTableWidgetItem(QString::fromStdString( data.suplier)));
        }
    }
    else 
    {
        table->setRowCount(0);
        for (FM::analizeData data : analizeData)
        {
            int rows = table->rowCount();
            table->insertRow(rows);
            table->setItem(rows, 0, new QTableWidgetItem(QString::fromStdString(data.name)));
            table->setItem(rows, 1, new QTableWidgetItem(QString::fromStdString(data.data)));
            table->setItem(rows, 2, new QTableWidgetItem(QString::number(data.surplus)));
            table->setItem(rows, 3, new QTableWidgetItem(QString::fromStdString(data.unit)));
        }
    }
    systemEdit = false;
}
void gui::docuGuiController:: findElement()
{
    if (uiFind->LE_find->text().isEmpty()) 
    {
        return ; 
    }
    systemEdit = true;
    QTableWidget* table;
    switch (isActive) {
    case PRIHOD:
        table = UiPrihod->TW_prihod;  
        break;
    case OSTATOK:
        table = UiOstatok->TW_ostatok;
        break;
    case RASHOD:
         table = UiRashod->TW_rashod;
         break;
    }
    if(isActive != OSTATOK)
    {
        std::vector<FM::dataItem> datas = FM::findElement(uiFind->LE_find->text().toStdString(), isActive);   
        table->setRowCount(0); 
        for (FM::dataItem data : datas)
        {
           int rows = table->rowCount();       
           table->insertRow(rows);
            table->setItem(rows, 0, new QTableWidgetItem(QString::number(data.id)));
            table->setItem(rows, 1, new QTableWidgetItem(QString::fromStdString(data.name)));
            table->setItem(rows , 2 , new QTableWidgetItem(QString::fromStdString(data.data)));
            table->setItem(rows , 3 , new QTableWidgetItem(QString::number(data.count)));
            table->setItem(rows,4 , new QTableWidgetItem(QString::fromStdString(data.unit))); 
            table->setItem(rows, 5 , new QTableWidgetItem(QString::fromStdString(data.price)));
            table->setItem(rows,6 , new QTableWidgetItem(QString::fromStdString( data.suplier)));
        }
    }
    else
    {
       std::vector<FM::analizeData> find ;
       for (int rows = 0 ; rows < table->rowCount() ; rows++)
       {
            QString name  = table->item(rows, 0)->text();
            QString data  = table->item(rows, 1)->text();
            QString surplus  = table->item(rows, 2)->text();
            QString unit  = table->item(rows, 3)->text();
            QString element = uiFind->LE_find->text();
            if (element[0] == QString(">") || element[0] == QString("<"))
            {
                QString convert = element.mid(1);
                bool isInt = false;
                convert.toInt(&isInt);
                if (isInt)
                {
                    if ((surplus.toInt() > convert.toInt()) && element[0] == QString(">"))
                    {
                        find.push_back({name.toStdString() , data.toStdString() , surplus.toInt() , unit.toStdString()});
                    }
                    else if ((surplus.toInt() < convert.toInt()) && element[0] == QString("<"))
                    {
                        find.push_back({name.toStdString() , data.toStdString() , surplus.toInt() , unit.toStdString()});
                    }
                }
            }
            else if (element == name)
            {
               find.push_back({name.toStdString() , data.toStdString() , surplus.toInt() , unit.toStdString()});
            }
            else if (element == data)
            {
               find.push_back({name.toStdString() , data.toStdString() , surplus.toInt() , unit.toStdString()});
            }
            else if (element.toInt() == surplus.toInt())
            {
               find.push_back({name.toStdString() , data.toStdString() , surplus.toInt() , unit.toStdString()});
            }
            else if (element == unit)
            {
               find.push_back({name.toStdString() , data.toStdString() , surplus.toInt() , unit.toStdString()});
            }
       }
     table->setRowCount(0);
     for (FM::analizeData data : find)
     {
        int rows = table->rowCount();
        table->insertRow(rows);
        table->setItem(rows, 0, new QTableWidgetItem(QString::fromStdString(data.name)));
        table->setItem(rows, 1, new QTableWidgetItem(QString::fromStdString(data.data)));
        table->setItem(rows, 2, new QTableWidgetItem(QString::number(data.surplus)));
        table->setItem(rows, 3, new QTableWidgetItem(QString::fromStdString(data.unit)));
     }  
    }
    systemEdit = false;
}
void gui::docuGuiController::analize()
{
    systemEdit = true;
    QTableWidget* table = UiOstatok->TW_ostatok;
    analizeData.clear();
    std::vector<FM::analizeData> datas = FM::analize();
    table->setRowCount(0);
    for (FM::analizeData data : datas)
    {
        analizeData.push_back(data);
        int rows = table->rowCount();
        table->insertRow(rows);
        table->setItem(rows, 0, new QTableWidgetItem(QString::fromStdString(data.name)));
        table->setItem(rows, 1, new QTableWidgetItem(QString::fromStdString(data.data)));
        table->setItem(rows, 2, new QTableWidgetItem(QString::number(data.surplus)));
        table->setItem(rows, 3, new QTableWidgetItem(QString::fromStdString(data.unit)));
    }
    systemEdit = false;
}
void gui::docuGuiController:: addElement()
{
    if (!isFullValue())
    {
        return;
    }
    QTableWidget* table;
    switch (isActive) {
    case PRIHOD:
        table = UiPrihod->TW_prihod;  
        break;
    case OSTATOK:
        return;
        break;
    case RASHOD:
         table = UiRashod->TW_rashod;
         break;
    }
    systemEdit = true;
    std::vector<FM::dataItem> isFind = FM::findElement(uiAdd->LE_name->text().toStdString() , -1);
    
    if(isFind.size() > 0)
    {
        if(isActive==PRIHOD)
        {
            FM::pushPrihod(uiAdd->LE_name->text() , uiAdd->LE_count->text() 
                    , uiAdd->LE_unit->text(),uiAdd->DE_data->text() ,
                    uiAdd->LE_price->text() , uiAdd->LE_suplier->text()
                    );
        }
        else
        {
            FM::pushRashod(uiAdd->LE_name->text() , uiAdd->LE_count->text() 
                    , uiAdd->LE_unit->text(),uiAdd->DE_data->text() ,
                    uiAdd->LE_price->text() , uiAdd->LE_suplier->text());     
        }   
    }
    else
    {
        if (isActive == PRIHOD)
        {
        FM::addProduct(uiAdd->LE_name->text() , uiAdd->DE_data->text() 
                , uiAdd->LE_price->text() , uiAdd->LE_unit->text() ,
                uiAdd->LE_count->text() , uiAdd->LE_suplier->text() ); 
        }
        else {
            systemEdit = false;
            return;
        }
    }
    int rows = table->rowCount()  ; 
    table->insertRow(rows);
    table->setItem(rows, 0 , new QTableWidgetItem(QString::number(FM::newPrimaryKey())));
    table->setItem(rows, 1 , new QTableWidgetItem(uiAdd->LE_name->text()));
    table->setItem(rows , 2 , new QTableWidgetItem(uiAdd->DE_data->text()));
    table->setItem(rows , 3 , new QTableWidgetItem(uiAdd->LE_count->text()));
    table->setItem(rows,4 , new QTableWidgetItem(uiAdd->LE_unit->text())); 
    table->setItem(rows, 5 , new QTableWidgetItem(uiAdd->LE_price->text()));
    table->setItem(rows,6 , new QTableWidgetItem(uiAdd->LE_suplier->text()));

    // remove value in lineEditor
    uiAdd->LE_name->clear();
    uiAdd->LE_count->clear();
    uiAdd->LE_price->clear();
    uiAdd->LE_suplier->clear();
    systemEdit = false;
}
void gui::docuGuiController:: replaceElement()
{

    if (uiFind->LE_findReplace->text().isEmpty() || uiFind->LE_replace->text().isEmpty()
            || isActive == OSTATOK) 
    {
        return ; 
    }
    QTableWidget* table;
    switch (isActive) {
    case PRIHOD:
        table = UiPrihod->TW_prihod;  
        break;
    case OSTATOK:
        return;
        break;
    case RASHOD:
         table = UiRashod->TW_rashod;
         break;
    }
}
void gui::docuGuiController::onItemchange(QTableWidgetItem* item)
{
    if (systemEdit) return;
    QTableWidget* table;
    switch (isActive) {
    case PRIHOD:
        table = UiPrihod->TW_prihod;  
        break;
    case OSTATOK:
        return;
        break;
    case RASHOD:
         table = UiRashod->TW_rashod;
         break;
    }
    if (item->column() != 0)
    {
        int row = item->row();  
        int id = table->item(row, 0)->text().toInt();
        std::string name = table->item(row, 1)->text().toStdString();
        std::string data = table->item(row, 2)->text().toStdString();
        int count = table->item(row, 3)->text().toInt();
        std::string unit = table->item(row, 4)->text().toStdString();
        std::string price = table->item(row, 5)->text().toStdString();
        std::string suplier = table->item(row, 6)->text().toStdString();
        FM::setId({isActive,id , name ,
            data , unit , count , price ,suplier });
    }
}
bool gui::docuGuiController::isFullValue()
{
    int IsAccept = 0 ;
    if(!uiAdd->LE_name->text().isEmpty())
    {
        IsAccept++;
    }
    if(!uiAdd->DE_data->text().isEmpty())
    {
        IsAccept++;
    } 
    if(!uiAdd->LE_count->text().isEmpty())
    {
        IsAccept++;
    }
    if(!uiAdd->LE_unit->text().isEmpty())
    {
        IsAccept++;
    }
    if(!uiAdd->LE_price->text().isEmpty())
    {
        IsAccept++;
    }
    if(!uiAdd->LE_suplier->text().isEmpty())
    {
        IsAccept++;
    }
    return IsAccept == 6;
}
int gui::docuGuiController::getActive()
{
    return isActive;
}

// class Overlay:
gui::Overlay::Overlay(docuGuiController* docus,
        QWidget* overlays , QObject* parent) :
        QThread(parent) , overlay(overlays) ,docu(docus)
{
   docu->setCentral();
}
gui::Overlay::~Overlay()
{
    delete docu;
    delete overlay;
    closed= true;
}
void gui::Overlay::end()
{
    closed = true; 
}
void gui::Overlay::run()
{
    
    while(true)
    {
        QThread::msleep(1);
        if (running)
        {
            QSize center = docu->centerPoint();
            QSize last = docu->getCentral();
            if (last.width() != center.width() || last.height() != center.height())
            {
                docu->setCentral();
                int X = overlay->geometry().x() + overlay->geometry().width()/2;
                int Y = overlay->geometry().y() + overlay->geometry().height()/2;
                overlay->move(center.width()-X/2 , center.height()-Y/2);
            }    
        }
        if(closed)
        {
            break;
        }
    }
}
void gui::Overlay::go()
{
    running = true;
}
void gui::Overlay::stop()
{
    running = false;
}
