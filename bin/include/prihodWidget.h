/********************************************************************************
** Form generated from reading UI file 'prihodWidget.ui'
**
** Created by: Qt User Interface Compiler version 5.15.15
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef PRIHODWIDGET_H
#define PRIHODWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_dialogPrihod
{
public:
    QVBoxLayout *verticalLayout;
    QFrame *F_head;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *PB_closed;
    QFrame *F_main;
    QGridLayout *gridLayout;
    QLineEdit *LE_name;
    QDateEdit *DE_data;
    QLabel *L_name;
    QLabel *L_count;
    QLabel *L_price;
    QLabel *L_suplier;
    QLineEdit *LE_suplier;
    QLabel *l_unit;
    QLineEdit *LE_count;
    QLabel *L_data;
    QLineEdit *LE_unit;
    QLineEdit *LE_price;
    QPushButton *PB_add;

    void setupUi(QWidget *dialogPrihod)
    {
        if (dialogPrihod->objectName().isEmpty())
            dialogPrihod->setObjectName(QString::fromUtf8("dialogPrihod"));
        dialogPrihod->resize(495, 438);
        dialogPrihod->setMaximumSize(QSize(600, 600));
        verticalLayout = new QVBoxLayout(dialogPrihod);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(-1, 9, -1, -1);
        F_head = new QFrame(dialogPrihod);
        F_head->setObjectName(QString::fromUtf8("F_head"));
        F_head->setMaximumSize(QSize(16777215, 50));
        F_head->setStyleSheet(QString::fromUtf8("border:none;"));
        F_head->setFrameShape(QFrame::StyledPanel);
        F_head->setFrameShadow(QFrame::Raised);
        horizontalLayout = new QHBoxLayout(F_head);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(-1, 9, -1, -1);
        horizontalSpacer = new QSpacerItem(366, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        PB_closed = new QPushButton(F_head);
        PB_closed->setObjectName(QString::fromUtf8("PB_closed"));
        PB_closed->setCursor(QCursor(Qt::PointingHandCursor));
        PB_closed->setStyleSheet(QString::fromUtf8("border:2px solid white;\n"
"padding:  5px;\n"
"border-radius: 10px;\n"
"background: #EE204D;\n"
"color: black;\n"
"font-size: 16px;\n"
"font-weight:bold;"));

        horizontalLayout->addWidget(PB_closed);


        verticalLayout->addWidget(F_head);

        F_main = new QFrame(dialogPrihod);
        F_main->setObjectName(QString::fromUtf8("F_main"));
        F_main->setFrameShape(QFrame::StyledPanel);
        F_main->setFrameShadow(QFrame::Raised);
        gridLayout = new QGridLayout(F_main);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        LE_name = new QLineEdit(F_main);
        LE_name->setObjectName(QString::fromUtf8("LE_name"));
        LE_name->setMinimumSize(QSize(0, 35));
        LE_name->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(LE_name, 0, 1, 1, 1);

        DE_data = new QDateEdit(F_main);
        DE_data->setObjectName(QString::fromUtf8("DE_data"));
        DE_data->setMinimumSize(QSize(0, 35));
        DE_data->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(DE_data, 4, 1, 1, 1);

        L_name = new QLabel(F_main);
        L_name->setObjectName(QString::fromUtf8("L_name"));
        L_name->setMinimumSize(QSize(0, 35));
        L_name->setStyleSheet(QString::fromUtf8("font-size:14px;\n"
"font-weight:bold;"));

        gridLayout->addWidget(L_name, 0, 0, 1, 1);

        L_count = new QLabel(F_main);
        L_count->setObjectName(QString::fromUtf8("L_count"));
        L_count->setMinimumSize(QSize(0, 35));
        L_count->setStyleSheet(QString::fromUtf8("font-size:14px;\n"
"font-weight:bold;"));

        gridLayout->addWidget(L_count, 1, 0, 1, 1);

        L_price = new QLabel(F_main);
        L_price->setObjectName(QString::fromUtf8("L_price"));
        L_price->setMinimumSize(QSize(0, 35));
        L_price->setStyleSheet(QString::fromUtf8("font-size:14px;\n"
"font-weight:bold;"));

        gridLayout->addWidget(L_price, 3, 0, 1, 1);

        L_suplier = new QLabel(F_main);
        L_suplier->setObjectName(QString::fromUtf8("L_suplier"));
        L_suplier->setMinimumSize(QSize(0, 35));
        L_suplier->setStyleSheet(QString::fromUtf8("font-size:14px;\n"
"font-weight:bold;"));

        gridLayout->addWidget(L_suplier, 5, 0, 1, 1);

        LE_suplier = new QLineEdit(F_main);
        LE_suplier->setObjectName(QString::fromUtf8("LE_suplier"));
        LE_suplier->setMinimumSize(QSize(0, 35));
        LE_suplier->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(LE_suplier, 5, 1, 1, 1);

        l_unit = new QLabel(F_main);
        l_unit->setObjectName(QString::fromUtf8("l_unit"));
        l_unit->setMinimumSize(QSize(0, 35));
        l_unit->setStyleSheet(QString::fromUtf8("font-size:14px;\n"
"font-weight:bold;"));

        gridLayout->addWidget(l_unit, 2, 0, 1, 1);

        LE_count = new QLineEdit(F_main);
        LE_count->setObjectName(QString::fromUtf8("LE_count"));
        LE_count->setMinimumSize(QSize(0, 35));
        LE_count->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(LE_count, 1, 1, 1, 1);

        L_data = new QLabel(F_main);
        L_data->setObjectName(QString::fromUtf8("L_data"));
        L_data->setMinimumSize(QSize(0, 35));
        L_data->setStyleSheet(QString::fromUtf8("font-size:14px;\n"
"font-weight:bold;"));

        gridLayout->addWidget(L_data, 4, 0, 1, 1);

        LE_unit = new QLineEdit(F_main);
        LE_unit->setObjectName(QString::fromUtf8("LE_unit"));
        LE_unit->setMinimumSize(QSize(0, 35));
        LE_unit->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(LE_unit, 2, 1, 1, 1);

        LE_price = new QLineEdit(F_main);
        LE_price->setObjectName(QString::fromUtf8("LE_price"));
        LE_price->setMinimumSize(QSize(0, 35));
        LE_price->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(LE_price, 3, 1, 1, 1);


        verticalLayout->addWidget(F_main);

        PB_add = new QPushButton(dialogPrihod);
        PB_add->setObjectName(QString::fromUtf8("PB_add"));
        PB_add->setCursor(QCursor(Qt::PointingHandCursor));
        PB_add->setStyleSheet(QString::fromUtf8("border:2px solid white;\n"
"padding:  5px;\n"
"border-radius: 10px;\n"
"background: #A8E4A0;\n"
"color: black;\n"
"font-size: 16px;\n"
"font-weight:bold;"));

        verticalLayout->addWidget(PB_add);


        retranslateUi(dialogPrihod);

        QMetaObject::connectSlotsByName(dialogPrihod);
    } // setupUi

    void retranslateUi(QWidget *dialogPrihod)
    {
        dialogPrihod->setWindowTitle(QCoreApplication::translate("dialogPrihod", "Form", nullptr));
        PB_closed->setText(QCoreApplication::translate("dialogPrihod", "\320\267\320\260\320\272\321\200\321\213\321\202\321\214", nullptr));
        LE_name->setText(QString());
        LE_name->setPlaceholderText(QCoreApplication::translate("dialogPrihod", "\320\237\321\200\320\276\320\264\321\203\320\272\321\202", nullptr));
        L_name->setText(QCoreApplication::translate("dialogPrihod", "\320\237\321\200\320\276\320\264\321\203\320\272\321\202", nullptr));
        L_count->setText(QCoreApplication::translate("dialogPrihod", "\320\232\320\276\320\273-\320\262\320\276", nullptr));
        L_price->setText(QCoreApplication::translate("dialogPrihod", "\320\246\320\265\320\275\320\260", nullptr));
        L_suplier->setText(QCoreApplication::translate("dialogPrihod", "\320\237\320\276\321\201\321\202\320\260\320\262\321\211\320\270\320\272", nullptr));
        LE_suplier->setPlaceholderText(QCoreApplication::translate("dialogPrihod", "\320\237\320\276\321\201\321\202\320\260\320\262\321\211\320\270\320\272", nullptr));
        l_unit->setText(QCoreApplication::translate("dialogPrihod", "\320\230\320\264.\320\270\320\267\320\274\320\265\321\200.", nullptr));
        LE_count->setPlaceholderText(QCoreApplication::translate("dialogPrihod", "\320\232\320\276\320\273-\320\262\320\276", nullptr));
        L_data->setText(QCoreApplication::translate("dialogPrihod", "\320\224\320\260\321\202\320\260", nullptr));
        LE_unit->setPlaceholderText(QCoreApplication::translate("dialogPrihod", "\320\230\320\264.\320\270\320\267\320\274\320\265\321\200.", nullptr));
        LE_price->setPlaceholderText(QCoreApplication::translate("dialogPrihod", "\320\246\320\265\320\275\320\260", nullptr));
        PB_add->setText(QCoreApplication::translate("dialogPrihod", "\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214", nullptr));
    } // retranslateUi

};

namespace Ui {
    class dialogPrihod: public Ui_dialogPrihod {};
} // namespace Ui

QT_END_NAMESPACE

#endif // PRIHODWIDGET_H
