/********************************************************************************
** Form generated from reading UI file 'ostatok.ui'
**
** Created by: Qt User Interface Compiler version 5.15.16
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef OSTATOK_H
#define OSTATOK_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
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

class Ui_W_ostatok
{
public:
    QVBoxLayout *verticalLayout;
    QFrame *F_tipPanel;
    QGridLayout *gridLayout;
    QLabel *L_title;
    QPushButton *PB_reset;
    QPushButton *PB_find;
    QPushButton *PB_analize;
    QLineEdit *LE_before;
    QSpacerItem *horizontalSpacer_2;
    QLineEdit *LE_after;
    QPushButton *PB_print;
    QPushButton *PB_delete;
    QTableWidget *TW_ostatok;

    void setupUi(QWidget *W_ostatok)
    {
        if (W_ostatok->objectName().isEmpty())
            W_ostatok->setObjectName(QString::fromUtf8("W_ostatok"));
        W_ostatok->resize(658, 617);
        verticalLayout = new QVBoxLayout(W_ostatok);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        F_tipPanel = new QFrame(W_ostatok);
        F_tipPanel->setObjectName(QString::fromUtf8("F_tipPanel"));
        F_tipPanel->setMinimumSize(QSize(0, 100));
        F_tipPanel->setFrameShape(QFrame::StyledPanel);
        F_tipPanel->setFrameShadow(QFrame::Raised);
        gridLayout = new QGridLayout(F_tipPanel);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        L_title = new QLabel(F_tipPanel);
        L_title->setObjectName(QString::fromUtf8("L_title"));
        L_title->setStyleSheet(QString::fromUtf8("font-size:24px;\n"
"font-weight:bold;"));
        L_title->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(L_title, 0, 1, 1, 4);

        PB_reset = new QPushButton(F_tipPanel);
        PB_reset->setObjectName(QString::fromUtf8("PB_reset"));
        PB_reset->setStyleSheet(QString::fromUtf8("font-size:15px;\n"
"font-weight:bold;"));

        gridLayout->addWidget(PB_reset, 2, 5, 1, 1);

        PB_find = new QPushButton(F_tipPanel);
        PB_find->setObjectName(QString::fromUtf8("PB_find"));
        PB_find->setCursor(QCursor(Qt::PointingHandCursor));
        PB_find->setStyleSheet(QString::fromUtf8("font-size:15px;\n"
"font-weight:bold;"));

        gridLayout->addWidget(PB_find, 2, 0, 1, 1);

        PB_analize = new QPushButton(F_tipPanel);
        PB_analize->setObjectName(QString::fromUtf8("PB_analize"));
        PB_analize->setCursor(QCursor(Qt::PointingHandCursor));
        PB_analize->setStyleSheet(QString::fromUtf8("font-size:15px;\n"
"font-weight:bold;"));

        gridLayout->addWidget(PB_analize, 2, 1, 1, 1);

        LE_before = new QLineEdit(F_tipPanel);
        LE_before->setObjectName(QString::fromUtf8("LE_before"));

        gridLayout->addWidget(LE_before, 2, 2, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_2, 2, 4, 1, 1);

        LE_after = new QLineEdit(F_tipPanel);
        LE_after->setObjectName(QString::fromUtf8("LE_after"));

        gridLayout->addWidget(LE_after, 2, 3, 1, 1);

        PB_print = new QPushButton(F_tipPanel);
        PB_print->setObjectName(QString::fromUtf8("PB_print"));
        PB_print->setCursor(QCursor(Qt::PointingHandCursor));
        PB_print->setStyleSheet(QString::fromUtf8("font-size:15px;\n"
"font-weight:bold;"));

        gridLayout->addWidget(PB_print, 1, 5, 1, 1);

        PB_delete = new QPushButton(F_tipPanel);
        PB_delete->setObjectName(QString::fromUtf8("PB_delete"));
        PB_delete->setCursor(QCursor(Qt::PointingHandCursor));
        PB_delete->setStyleSheet(QString::fromUtf8("font-size:15px;\n"
"font-weight:bold;"));

        gridLayout->addWidget(PB_delete, 1, 0, 1, 1);


        verticalLayout->addWidget(F_tipPanel);

        TW_ostatok = new QTableWidget(W_ostatok);
        if (TW_ostatok->columnCount() < 4)
            TW_ostatok->setColumnCount(4);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        TW_ostatok->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        TW_ostatok->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        TW_ostatok->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        TW_ostatok->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        TW_ostatok->setObjectName(QString::fromUtf8("TW_ostatok"));
        TW_ostatok->setHorizontalScrollBarPolicy(Qt::ScrollBarAsNeeded);
        TW_ostatok->horizontalHeader()->setCascadingSectionResizes(false);
        TW_ostatok->horizontalHeader()->setProperty("showSortIndicator", QVariant(false));
        TW_ostatok->horizontalHeader()->setStretchLastSection(true);

        verticalLayout->addWidget(TW_ostatok);


        retranslateUi(W_ostatok);

        QMetaObject::connectSlotsByName(W_ostatok);
    } // setupUi

    void retranslateUi(QWidget *W_ostatok)
    {
        W_ostatok->setWindowTitle(QCoreApplication::translate("W_ostatok", "Form", nullptr));
        L_title->setText(QCoreApplication::translate("W_ostatok", "\320\236\321\201\321\202\320\260\321\202\320\276\320\272", nullptr));
        PB_reset->setText(QCoreApplication::translate("W_ostatok", "\320\241\320\261\321\200\320\276\321\201\320\270\321\202\321\214", nullptr));
        PB_find->setText(QCoreApplication::translate("W_ostatok", "\320\235\320\260\320\271\321\202\320\270", nullptr));
        PB_analize->setText(QCoreApplication::translate("W_ostatok", "\320\220\320\275\320\260\320\273\320\270\320\267", nullptr));
        PB_print->setText(QCoreApplication::translate("W_ostatok", "\320\277\320\265\321\207\320\260\321\202\321\214", nullptr));
        PB_delete->setText(QCoreApplication::translate("W_ostatok", "\321\203\320\264\320\260\320\273\320\270\321\202\321\214", nullptr));
        QTableWidgetItem *___qtablewidgetitem = TW_ostatok->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("W_ostatok", "\320\277\321\200\320\276\320\264\321\203\320\272\321\202", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = TW_ostatok->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("W_ostatok", "\320\224\320\260\321\202\320\260", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = TW_ostatok->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("W_ostatok", "\320\236\321\201\321\202\320\260\321\202\320\276\320\272", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = TW_ostatok->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("W_ostatok", "\320\270\320\267\320\274\320\265\321\200\320\265\320\275\320\270\320\265", nullptr));
    } // retranslateUi

};

namespace Ui {
    class W_ostatok: public Ui_W_ostatok {};
} // namespace Ui

QT_END_NAMESPACE

#endif // OSTATOK_H
