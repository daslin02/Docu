/********************************************************************************
** Form generated from reading UI file 'rashod.ui'
**
** Created by: Qt User Interface Compiler version 5.15.15
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef RASHOD_H
#define RASHOD_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_W_rashod
{
public:
    QVBoxLayout *verticalLayout;
    QFrame *F_tipPanel;
    QGridLayout *gridLayout;
    QPushButton *PB_accept;
    QPushButton *PB_add;
    QPushButton *PB_delete;
    QPushButton *PB_find;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *PB_reset;
    QLabel *L_title;
    QTableWidget *TW_rashod;

    void setupUi(QWidget *W_rashod)
    {
        if (W_rashod->objectName().isEmpty())
            W_rashod->setObjectName(QString::fromUtf8("W_rashod"));
        W_rashod->resize(658, 609);
        verticalLayout = new QVBoxLayout(W_rashod);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        F_tipPanel = new QFrame(W_rashod);
        F_tipPanel->setObjectName(QString::fromUtf8("F_tipPanel"));
        F_tipPanel->setMinimumSize(QSize(0, 100));
        F_tipPanel->setFrameShape(QFrame::StyledPanel);
        F_tipPanel->setFrameShadow(QFrame::Raised);
        gridLayout = new QGridLayout(F_tipPanel);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        PB_accept = new QPushButton(F_tipPanel);
        PB_accept->setObjectName(QString::fromUtf8("PB_accept"));
        PB_accept->setCursor(QCursor(Qt::PointingHandCursor));
        PB_accept->setStyleSheet(QString::fromUtf8("font-size:15px;\n"
"font-weight:bold;"));

        gridLayout->addWidget(PB_accept, 2, 4, 1, 1);

        PB_add = new QPushButton(F_tipPanel);
        PB_add->setObjectName(QString::fromUtf8("PB_add"));
        PB_add->setCursor(QCursor(Qt::PointingHandCursor));
        PB_add->setStyleSheet(QString::fromUtf8("font-size:15px;\n"
"font-weight:bold;"));

        gridLayout->addWidget(PB_add, 2, 0, 1, 1);

        PB_delete = new QPushButton(F_tipPanel);
        PB_delete->setObjectName(QString::fromUtf8("PB_delete"));
        PB_delete->setCursor(QCursor(Qt::PointingHandCursor));
        PB_delete->setStyleSheet(QString::fromUtf8("font-size:15px;\n"
"font-weight:bold;"));

        gridLayout->addWidget(PB_delete, 2, 1, 1, 1);

        PB_find = new QPushButton(F_tipPanel);
        PB_find->setObjectName(QString::fromUtf8("PB_find"));
        PB_find->setCursor(QCursor(Qt::PointingHandCursor));
        PB_find->setStyleSheet(QString::fromUtf8("font-size:15px;\n"
"font-weight:bold;"));

        gridLayout->addWidget(PB_find, 2, 2, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_2, 2, 3, 1, 1);

        PB_reset = new QPushButton(F_tipPanel);
        PB_reset->setObjectName(QString::fromUtf8("PB_reset"));
        PB_reset->setCursor(QCursor(Qt::PointingHandCursor));
        PB_reset->setStyleSheet(QString::fromUtf8("font-size:15px;\n"
"font-weight:bold;"));

        gridLayout->addWidget(PB_reset, 2, 5, 1, 1);

        L_title = new QLabel(F_tipPanel);
        L_title->setObjectName(QString::fromUtf8("L_title"));
        L_title->setStyleSheet(QString::fromUtf8("font-size:24px;\n"
"font-weight:bold;"));
        L_title->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(L_title, 0, 2, 1, 2);


        verticalLayout->addWidget(F_tipPanel);

        TW_rashod = new QTableWidget(W_rashod);
        if (TW_rashod->columnCount() < 7)
            TW_rashod->setColumnCount(7);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        TW_rashod->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        TW_rashod->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        TW_rashod->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        TW_rashod->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        TW_rashod->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        TW_rashod->setHorizontalHeaderItem(5, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        TW_rashod->setHorizontalHeaderItem(6, __qtablewidgetitem6);
        TW_rashod->setObjectName(QString::fromUtf8("TW_rashod"));
        TW_rashod->setHorizontalScrollBarPolicy(Qt::ScrollBarAsNeeded);
        TW_rashod->horizontalHeader()->setCascadingSectionResizes(false);
        TW_rashod->horizontalHeader()->setProperty("showSortIndicator", QVariant(false));
        TW_rashod->horizontalHeader()->setStretchLastSection(true);

        verticalLayout->addWidget(TW_rashod);


        retranslateUi(W_rashod);

        QMetaObject::connectSlotsByName(W_rashod);
    } // setupUi

    void retranslateUi(QWidget *W_rashod)
    {
        W_rashod->setWindowTitle(QCoreApplication::translate("W_rashod", "Form", nullptr));
        PB_accept->setText(QCoreApplication::translate("W_rashod", "\320\237\321\200\320\270\320\274\320\265\320\275\320\270\321\202\321\214", nullptr));
        PB_add->setText(QCoreApplication::translate("W_rashod", "\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214", nullptr));
        PB_delete->setText(QCoreApplication::translate("W_rashod", "\320\243\320\264\320\260\320\273\320\270\321\202\321\214", nullptr));
        PB_find->setText(QCoreApplication::translate("W_rashod", "\320\235\320\260\320\271\321\202\320\270", nullptr));
        PB_reset->setText(QCoreApplication::translate("W_rashod", "\320\241\320\261\321\200\320\276\321\201\320\270\321\202\321\214", nullptr));
        L_title->setText(QCoreApplication::translate("W_rashod", "\320\240\320\260\321\201\321\205\320\276\320\264", nullptr));
        QTableWidgetItem *___qtablewidgetitem = TW_rashod->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("W_rashod", "id", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = TW_rashod->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("W_rashod", "\320\277\321\200\320\276\320\264\321\203\320\272\321\202", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = TW_rashod->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("W_rashod", "\320\264\320\260\321\202\320\260", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = TW_rashod->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("W_rashod", "\320\272\320\276\320\273-\320\262\320\276", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = TW_rashod->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QCoreApplication::translate("W_rashod", "\320\270\320\264. \320\230\320\267\320\274\320\265\321\200\320\265\320\275\320\270\321\217", nullptr));
        QTableWidgetItem *___qtablewidgetitem5 = TW_rashod->horizontalHeaderItem(5);
        ___qtablewidgetitem5->setText(QCoreApplication::translate("W_rashod", "\321\206\320\265\320\275\320\260", nullptr));
        QTableWidgetItem *___qtablewidgetitem6 = TW_rashod->horizontalHeaderItem(6);
        ___qtablewidgetitem6->setText(QCoreApplication::translate("W_rashod", "\320\236\321\202\320\277\321\200\320\260\320\262\320\273\320\265\320\275\320\275\320\276", nullptr));
    } // retranslateUi

};

namespace Ui {
    class W_rashod: public Ui_W_rashod {};
} // namespace Ui

QT_END_NAMESPACE

#endif // RASHOD_H
