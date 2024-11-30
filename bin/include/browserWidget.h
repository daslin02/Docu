/********************************************************************************
** Form generated from reading UI file 'browserWidget.ui'
**
** Created by: Qt User Interface Compiler version 5.15.15
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef BROWSERWIDGET_H
#define BROWSERWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_browserWidget
{
public:
    QHBoxLayout *horizontalLayout;
    QTabWidget *TW_findReplace;
    QWidget *W_find;
    QGridLayout *gridLayout;
    QPushButton *PB_find;
    QFrame *F_centerFind;
    QHBoxLayout *horizontalLayout_2;
    QLabel *L_find;
    QLineEdit *LE_find;
    QFrame *F_topFind;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer;
    QPushButton *PB_closedFind;
    QWidget *W_Replace;
    QVBoxLayout *verticalLayout;
    QFrame *F_topReplace;
    QHBoxLayout *horizontalLayout_5;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *PB_closedReplace;
    QFrame *F_centerReplace;
    QGridLayout *gridLayout_2;
    QLineEdit *LE_findReplace;
    QLabel *L_replace;
    QLabel *L_findreplace;
    QLineEdit *LE_replace;
    QPushButton *PB_replace;

    void setupUi(QWidget *browserWidget)
    {
        if (browserWidget->objectName().isEmpty())
            browserWidget->setObjectName(QString::fromUtf8("browserWidget"));
        browserWidget->resize(400, 300);
        horizontalLayout = new QHBoxLayout(browserWidget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        TW_findReplace = new QTabWidget(browserWidget);
        TW_findReplace->setObjectName(QString::fromUtf8("TW_findReplace"));
        W_find = new QWidget();
        W_find->setObjectName(QString::fromUtf8("W_find"));
        gridLayout = new QGridLayout(W_find);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        PB_find = new QPushButton(W_find);
        PB_find->setObjectName(QString::fromUtf8("PB_find"));
        PB_find->setCursor(QCursor(Qt::PointingHandCursor));
        PB_find->setStyleSheet(QString::fromUtf8("border:2px solid white;\n"
"padding:  5px;\n"
"border-radius: 10px;\n"
"background: #A8E4A0;\n"
"color: black;\n"
"font-size: 16px;\n"
"font-weight:bold;"));

        gridLayout->addWidget(PB_find, 2, 0, 1, 1);

        F_centerFind = new QFrame(W_find);
        F_centerFind->setObjectName(QString::fromUtf8("F_centerFind"));
        F_centerFind->setFrameShape(QFrame::StyledPanel);
        F_centerFind->setFrameShadow(QFrame::Raised);
        horizontalLayout_2 = new QHBoxLayout(F_centerFind);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        L_find = new QLabel(F_centerFind);
        L_find->setObjectName(QString::fromUtf8("L_find"));
        L_find->setStyleSheet(QString::fromUtf8("font-size: 16px;\n"
"font-weight:bold;"));

        horizontalLayout_2->addWidget(L_find);

        LE_find = new QLineEdit(F_centerFind);
        LE_find->setObjectName(QString::fromUtf8("LE_find"));
        LE_find->setMinimumSize(QSize(50, 40));

        horizontalLayout_2->addWidget(LE_find);


        gridLayout->addWidget(F_centerFind, 1, 0, 1, 1);

        F_topFind = new QFrame(W_find);
        F_topFind->setObjectName(QString::fromUtf8("F_topFind"));
        F_topFind->setMaximumSize(QSize(16777215, 50));
        F_topFind->setStyleSheet(QString::fromUtf8("border:none;"));
        F_topFind->setFrameShape(QFrame::StyledPanel);
        F_topFind->setFrameShadow(QFrame::Raised);
        horizontalLayout_3 = new QHBoxLayout(F_topFind);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalSpacer = new QSpacerItem(248, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer);

        PB_closedFind = new QPushButton(F_topFind);
        PB_closedFind->setObjectName(QString::fromUtf8("PB_closedFind"));
        PB_closedFind->setCursor(QCursor(Qt::PointingHandCursor));
        PB_closedFind->setStyleSheet(QString::fromUtf8("border:2px solid white;\n"
"padding:  5px;\n"
"border-radius: 10px;\n"
"background: #EE204D;\n"
"color: black;\n"
"font-size: 16px;\n"
"font-weight:bold;"));

        horizontalLayout_3->addWidget(PB_closedFind);


        gridLayout->addWidget(F_topFind, 0, 0, 1, 1);

        TW_findReplace->addTab(W_find, QString());
        W_Replace = new QWidget();
        W_Replace->setObjectName(QString::fromUtf8("W_Replace"));
        verticalLayout = new QVBoxLayout(W_Replace);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        F_topReplace = new QFrame(W_Replace);
        F_topReplace->setObjectName(QString::fromUtf8("F_topReplace"));
        F_topReplace->setMaximumSize(QSize(16777215, 50));
        F_topReplace->setStyleSheet(QString::fromUtf8("border:none;"));
        F_topReplace->setFrameShape(QFrame::StyledPanel);
        F_topReplace->setFrameShadow(QFrame::Raised);
        horizontalLayout_5 = new QHBoxLayout(F_topReplace);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        horizontalSpacer_2 = new QSpacerItem(248, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_2);

        PB_closedReplace = new QPushButton(F_topReplace);
        PB_closedReplace->setObjectName(QString::fromUtf8("PB_closedReplace"));
        PB_closedReplace->setCursor(QCursor(Qt::PointingHandCursor));
        PB_closedReplace->setStyleSheet(QString::fromUtf8("border:2px solid white;\n"
"padding:  5px;\n"
"border-radius: 10px;\n"
"background: #EE204D;\n"
"color: black;\n"
"font-size: 16px;\n"
"font-weight:bold;"));

        horizontalLayout_5->addWidget(PB_closedReplace);


        verticalLayout->addWidget(F_topReplace);

        F_centerReplace = new QFrame(W_Replace);
        F_centerReplace->setObjectName(QString::fromUtf8("F_centerReplace"));
        F_centerReplace->setFrameShape(QFrame::StyledPanel);
        F_centerReplace->setFrameShadow(QFrame::Raised);
        gridLayout_2 = new QGridLayout(F_centerReplace);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        LE_findReplace = new QLineEdit(F_centerReplace);
        LE_findReplace->setObjectName(QString::fromUtf8("LE_findReplace"));
        LE_findReplace->setMinimumSize(QSize(50, 40));

        gridLayout_2->addWidget(LE_findReplace, 1, 2, 1, 1);

        L_replace = new QLabel(F_centerReplace);
        L_replace->setObjectName(QString::fromUtf8("L_replace"));
        L_replace->setStyleSheet(QString::fromUtf8("font-size: 16px;\n"
"font-weight:bold;"));

        gridLayout_2->addWidget(L_replace, 2, 0, 1, 1);

        L_findreplace = new QLabel(F_centerReplace);
        L_findreplace->setObjectName(QString::fromUtf8("L_findreplace"));
        L_findreplace->setStyleSheet(QString::fromUtf8("font-size: 16px;\n"
"font-weight:bold;"));

        gridLayout_2->addWidget(L_findreplace, 1, 0, 1, 1);

        LE_replace = new QLineEdit(F_centerReplace);
        LE_replace->setObjectName(QString::fromUtf8("LE_replace"));
        LE_replace->setMinimumSize(QSize(50, 40));

        gridLayout_2->addWidget(LE_replace, 2, 2, 1, 1);


        verticalLayout->addWidget(F_centerReplace);

        PB_replace = new QPushButton(W_Replace);
        PB_replace->setObjectName(QString::fromUtf8("PB_replace"));
        PB_replace->setCursor(QCursor(Qt::PointingHandCursor));
        PB_replace->setStyleSheet(QString::fromUtf8("border:2px solid white;\n"
"padding:  5px;\n"
"border-radius: 10px;\n"
"background: #A8E4A0;\n"
"color: black;\n"
"font-size: 16px;\n"
"font-weight:bold;"));

        verticalLayout->addWidget(PB_replace);

        TW_findReplace->addTab(W_Replace, QString());

        horizontalLayout->addWidget(TW_findReplace);


        retranslateUi(browserWidget);

        TW_findReplace->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(browserWidget);
    } // setupUi

    void retranslateUi(QWidget *browserWidget)
    {
        browserWidget->setWindowTitle(QCoreApplication::translate("browserWidget", "Form", nullptr));
        PB_find->setText(QCoreApplication::translate("browserWidget", "\320\235\320\260\320\271\321\202\320\270", nullptr));
        L_find->setText(QCoreApplication::translate("browserWidget", "\320\235\320\260\320\271\321\202\320\270:", nullptr));
        PB_closedFind->setText(QCoreApplication::translate("browserWidget", "\320\227\320\260\320\272\321\200\321\213\321\202\321\214", nullptr));
        TW_findReplace->setTabText(TW_findReplace->indexOf(W_find), QCoreApplication::translate("browserWidget", "Tab 1", nullptr));
        PB_closedReplace->setText(QCoreApplication::translate("browserWidget", "\320\227\320\260\320\272\321\200\321\213\321\202\321\214", nullptr));
        L_replace->setText(QCoreApplication::translate("browserWidget", "\320\227\320\260\320\274\320\265\320\275\320\270\321\202\321\214: ", nullptr));
        L_findreplace->setText(QCoreApplication::translate("browserWidget", "\320\235\320\260\320\271\321\202\320\270:", nullptr));
        PB_replace->setText(QCoreApplication::translate("browserWidget", "\320\227\320\260\320\274\320\265\320\275\320\270\321\202\321\214", nullptr));
        TW_findReplace->setTabText(TW_findReplace->indexOf(W_Replace), QCoreApplication::translate("browserWidget", "Tab 2", nullptr));
    } // retranslateUi

};

namespace Ui {
    class browserWidget: public Ui_browserWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // BROWSERWIDGET_H
