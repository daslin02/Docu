/********************************************************************************
** Form generated from reading UI file 'prihod.ui'
**
** Created by: Qt User Interface Compiler version 5.15.15
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef PRIHOD_H
#define PRIHOD_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_W_prihod
{
public:
    QVBoxLayout *verticalLayout;
    QFrame *F_tipPanel;
    QGridLayout *gridLayout;
    QLabel *L_post;
    QPushButton *PB_find;
    QDateEdit *DE_data;
    QLineEdit *LE_post;
    QSpacerItem *horizontalSpacer;
    QPushButton *PB_add;
    QPushButton *PB_delete;
    QSpacerItem *horizontalSpacer_2;
    QLabel *L_data;
    QSpacerItem *horizontalSpacer_3;
    QTableWidget *TW_prihod;

    void setupUi(QWidget *W_prihod)
    {
        if (W_prihod->objectName().isEmpty())
            W_prihod->setObjectName(QString::fromUtf8("W_prihod"));
        W_prihod->resize(855, 617);
        verticalLayout = new QVBoxLayout(W_prihod);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        F_tipPanel = new QFrame(W_prihod);
        F_tipPanel->setObjectName(QString::fromUtf8("F_tipPanel"));
        F_tipPanel->setMinimumSize(QSize(0, 100));
        F_tipPanel->setFrameShape(QFrame::StyledPanel);
        F_tipPanel->setFrameShadow(QFrame::Raised);
        gridLayout = new QGridLayout(F_tipPanel);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        L_post = new QLabel(F_tipPanel);
        L_post->setObjectName(QString::fromUtf8("L_post"));
        L_post->setMinimumSize(QSize(0, 30));
        L_post->setStyleSheet(QString::fromUtf8("font-size:15px;\n"
"font-weight:bold;"));
        L_post->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(L_post, 2, 4, 1, 1);

        PB_find = new QPushButton(F_tipPanel);
        PB_find->setObjectName(QString::fromUtf8("PB_find"));
        PB_find->setCursor(QCursor(Qt::PointingHandCursor));
        PB_find->setStyleSheet(QString::fromUtf8("font-size:15px;\n"
"font-weight:bold;"));

        gridLayout->addWidget(PB_find, 2, 2, 1, 1);

        DE_data = new QDateEdit(F_tipPanel);
        DE_data->setObjectName(QString::fromUtf8("DE_data"));
        DE_data->setMinimumSize(QSize(0, 30));

        gridLayout->addWidget(DE_data, 0, 6, 1, 1);

        LE_post = new QLineEdit(F_tipPanel);
        LE_post->setObjectName(QString::fromUtf8("LE_post"));
        LE_post->setMinimumSize(QSize(0, 30));

        gridLayout->addWidget(LE_post, 2, 6, 1, 1);

        horizontalSpacer = new QSpacerItem(20, 20, QSizePolicy::Maximum, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 0, 5, 1, 1);

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

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_2, 2, 3, 1, 1);

        L_data = new QLabel(F_tipPanel);
        L_data->setObjectName(QString::fromUtf8("L_data"));
        L_data->setMinimumSize(QSize(0, 30));
        L_data->setStyleSheet(QString::fromUtf8("font-size:15px;\n"
"font-weight:bold;"));
        L_data->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(L_data, 0, 4, 1, 1);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_3, 2, 7, 1, 1);


        verticalLayout->addWidget(F_tipPanel);

        TW_prihod = new QTableWidget(W_prihod);
        if (TW_prihod->columnCount() < 4)
            TW_prihod->setColumnCount(4);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        TW_prihod->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        TW_prihod->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        TW_prihod->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        TW_prihod->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        if (TW_prihod->rowCount() < 2)
            TW_prihod->setRowCount(2);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        TW_prihod->setVerticalHeaderItem(0, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        TW_prihod->setVerticalHeaderItem(1, __qtablewidgetitem5);
        TW_prihod->setObjectName(QString::fromUtf8("TW_prihod"));
        TW_prihod->setHorizontalScrollBarPolicy(Qt::ScrollBarAsNeeded);
        TW_prihod->horizontalHeader()->setCascadingSectionResizes(false);
        TW_prihod->horizontalHeader()->setProperty("showSortIndicator", QVariant(false));
        TW_prihod->horizontalHeader()->setStretchLastSection(true);

        verticalLayout->addWidget(TW_prihod);


        retranslateUi(W_prihod);

        QMetaObject::connectSlotsByName(W_prihod);
    } // setupUi

    void retranslateUi(QWidget *W_prihod)
    {
        W_prihod->setWindowTitle(QCoreApplication::translate("W_prihod", "Form", nullptr));
        L_post->setText(QCoreApplication::translate("W_prihod", "\320\237\320\276\321\201\321\202\320\260\320\262\321\211\320\270\320\272:", nullptr));
        PB_find->setText(QCoreApplication::translate("W_prihod", "\320\235\320\260\320\271\321\202\320\270", nullptr));
        PB_add->setText(QCoreApplication::translate("W_prihod", "\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214", nullptr));
        PB_delete->setText(QCoreApplication::translate("W_prihod", "\320\243\320\264\320\260\320\273\320\270\321\202\321\214", nullptr));
        L_data->setText(QCoreApplication::translate("W_prihod", "\320\224\320\260\321\202\320\260:", nullptr));
        QTableWidgetItem *___qtablewidgetitem = TW_prihod->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("W_prihod", "\320\277\321\200\320\276\320\264\321\203\320\272\321\202", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = TW_prihod->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("W_prihod", "\320\272\320\276\320\273-\320\262\320\276", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = TW_prihod->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("W_prihod", "\320\270\320\264. \320\230\320\267\320\274\320\265\321\200\320\265\320\275\320\270\321\217", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = TW_prihod->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("W_prihod", "\321\206\320\265\320\275\320\260", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = TW_prihod->verticalHeaderItem(0);
        ___qtablewidgetitem4->setText(QCoreApplication::translate("W_prihod", "1", nullptr));
        QTableWidgetItem *___qtablewidgetitem5 = TW_prihod->verticalHeaderItem(1);
        ___qtablewidgetitem5->setText(QCoreApplication::translate("W_prihod", "2", nullptr));
    } // retranslateUi

};

namespace Ui {
    class W_prihod: public Ui_W_prihod {};
} // namespace Ui

QT_END_NAMESPACE

#endif // PRIHOD_H