/********************************************************************************
** Form generated from reading UI file 'main.ui'
**
** Created by: Qt User Interface Compiler version 5.15.15
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef MAIN_H
#define MAIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include <qmainwindow.h>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QHBoxLayout *horizontalLayout;
    QFrame *F_ToolPanel;
    QVBoxLayout *verticalLayout;
    QPushButton *PB_prihod;
    QPushButton *PB_rashod;
    QPushButton *PB_ostatok;
    QPushButton *PB_analize;
    QSpacerItem *verticalSpacer;
    QStackedWidget *SW_stacked;
    QWidget *home;
    QWidget *prihod;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(800, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        horizontalLayout = new QHBoxLayout(centralwidget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        F_ToolPanel = new QFrame(centralwidget);
        F_ToolPanel->setObjectName(QString::fromUtf8("F_ToolPanel"));
        F_ToolPanel->setMinimumSize(QSize(150, 0));
        F_ToolPanel->setStyleSheet(QString::fromUtf8("background : #8aa632;\n"
""));
        F_ToolPanel->setFrameShape(QFrame::StyledPanel);
        F_ToolPanel->setFrameShadow(QFrame::Raised);
        verticalLayout = new QVBoxLayout(F_ToolPanel);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        PB_prihod = new QPushButton(F_ToolPanel);
        PB_prihod->setObjectName(QString::fromUtf8("PB_prihod"));
        PB_prihod->setMinimumSize(QSize(50, 30));
        PB_prihod->setCursor(QCursor(Qt::PointingHandCursor));
        PB_prihod->setStyleSheet(QString::fromUtf8("background: #038b71;\n"
"color:black;\n"
"font-weight:bold;\n"
"font-size:15px"));

        verticalLayout->addWidget(PB_prihod);

        PB_rashod = new QPushButton(F_ToolPanel);
        PB_rashod->setObjectName(QString::fromUtf8("PB_rashod"));
        PB_rashod->setMinimumSize(QSize(50, 30));
        PB_rashod->setCursor(QCursor(Qt::PointingHandCursor));
        PB_rashod->setStyleSheet(QString::fromUtf8("background: #038b71;\n"
"color:black;\n"
"font-weight:bold;\n"
"font-size:15px\n"
""));

        verticalLayout->addWidget(PB_rashod);

        PB_ostatok = new QPushButton(F_ToolPanel);
        PB_ostatok->setObjectName(QString::fromUtf8("PB_ostatok"));
        PB_ostatok->setMinimumSize(QSize(50, 30));
        PB_ostatok->setCursor(QCursor(Qt::PointingHandCursor));
        PB_ostatok->setStyleSheet(QString::fromUtf8("background: #038b71;\n"
"color:black;\n"
"font-weight:bold;\n"
"font-size:15px"));

        verticalLayout->addWidget(PB_ostatok);

        PB_analize = new QPushButton(F_ToolPanel);
        PB_analize->setObjectName(QString::fromUtf8("PB_analize"));
        PB_analize->setMinimumSize(QSize(50, 30));
        PB_analize->setCursor(QCursor(Qt::PointingHandCursor));
        PB_analize->setStyleSheet(QString::fromUtf8("background: #038b71;\n"
"color:black;\n"
"font-weight:bold;\n"
"font-size:15px"));

        verticalLayout->addWidget(PB_analize);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);


        horizontalLayout->addWidget(F_ToolPanel);

        SW_stacked = new QStackedWidget(centralwidget);
        SW_stacked->setObjectName(QString::fromUtf8("SW_stacked"));
        home = new QWidget();
        home->setObjectName(QString::fromUtf8("home"));
        SW_stacked->addWidget(home);
        prihod = new QWidget();
        prihod->setObjectName(QString::fromUtf8("prihod"));
        SW_stacked->addWidget(prihod);

        horizontalLayout->addWidget(SW_stacked);

        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        PB_prihod->setText(QCoreApplication::translate("MainWindow", "\320\237\321\200\320\270\321\205\320\276\320\264", nullptr));
        PB_rashod->setText(QCoreApplication::translate("MainWindow", "\320\240\320\260\321\201\321\205\320\276\320\264", nullptr));
        PB_ostatok->setText(QCoreApplication::translate("MainWindow", "\320\236\321\201\321\202\320\260\321\202\320\276\320\272", nullptr));
        PB_analize->setText(QCoreApplication::translate("MainWindow", "\320\220\320\275\320\260\320\273\320\270\320\267", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui



QT_END_NAMESPACE

#endif // MAIN_H
