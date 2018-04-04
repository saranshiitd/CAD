/********************************************************************************
** Form generated from reading UI file 'showprojections.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SHOWPROJECTIONS_H
#define UI_SHOWPROJECTIONS_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QSlider>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ShowProjections
{
public:
    QWidget *centralwidget;
    QLabel *Isometric;
    QSlider *zSlider;
    QSlider *ySlider;
    QLabel *label_6;
    QLabel *TopView;
    QSlider *xSlider;
    QLabel *label_4;
    QLabel *sideView;
    QLabel *label_3;
    QLabel *label_7;
    QLabel *frontView;
    QLabel *label_2;
    QLabel *label;
    QLabel *label_5;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *ShowProjections)
    {
        if (ShowProjections->objectName().isEmpty())
            ShowProjections->setObjectName(QStringLiteral("ShowProjections"));
        ShowProjections->resize(1266, 823);
        centralwidget = new QWidget(ShowProjections);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        Isometric = new QLabel(centralwidget);
        Isometric->setObjectName(QStringLiteral("Isometric"));
        Isometric->setGeometry(QRect(410, 360, 360, 320));
        zSlider = new QSlider(centralwidget);
        zSlider->setObjectName(QStringLiteral("zSlider"));
        zSlider->setGeometry(QRect(905, 260, 160, 29));
        zSlider->setOrientation(Qt::Horizontal);
        ySlider = new QSlider(centralwidget);
        ySlider->setObjectName(QStringLiteral("ySlider"));
        ySlider->setGeometry(QRect(905, 210, 160, 29));
        ySlider->setOrientation(Qt::Horizontal);
        label_6 = new QLabel(centralwidget);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(830, 220, 67, 17));
        TopView = new QLabel(centralwidget);
        TopView->setObjectName(QStringLiteral("TopView"));
        TopView->setGeometry(QRect(15, 360, 360, 320));
        xSlider = new QSlider(centralwidget);
        xSlider->setObjectName(QStringLiteral("xSlider"));
        xSlider->setGeometry(QRect(905, 160, 160, 29));
        xSlider->setOrientation(Qt::Horizontal);
        label_4 = new QLabel(centralwidget);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(460, 680, 150, 17));
        sideView = new QLabel(centralwidget);
        sideView->setObjectName(QStringLiteral("sideView"));
        sideView->setGeometry(QRect(410, 20, 360, 320));
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(120, 680, 80, 17));
        label_7 = new QLabel(centralwidget);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(830, 270, 67, 17));
        frontView = new QLabel(centralwidget);
        frontView->setObjectName(QStringLiteral("frontView"));
        frontView->setGeometry(QRect(15, 20, 360, 320));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(465, 330, 80, 17));
        label = new QLabel(centralwidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(125, 330, 80, 17));
        label_5 = new QLabel(centralwidget);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(830, 170, 67, 17));
        ShowProjections->setCentralWidget(centralwidget);
        menubar = new QMenuBar(ShowProjections);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 1266, 25));
        ShowProjections->setMenuBar(menubar);
        statusbar = new QStatusBar(ShowProjections);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        ShowProjections->setStatusBar(statusbar);

        retranslateUi(ShowProjections);

        QMetaObject::connectSlotsByName(ShowProjections);
    } // setupUi

    void retranslateUi(QMainWindow *ShowProjections)
    {
        ShowProjections->setWindowTitle(QApplication::translate("ShowProjections", "MainWindow", 0));
        Isometric->setText(QApplication::translate("ShowProjections", "TextLabel", 0));
        label_6->setText(QApplication::translate("ShowProjections", "    y-axis", 0));
        TopView->setText(QApplication::translate("ShowProjections", "TextLabel", 0));
        label_4->setText(QApplication::translate("ShowProjections", "Isometric Projection", 0));
        sideView->setText(QApplication::translate("ShowProjections", "TextLabel", 0));
        label_3->setText(QApplication::translate("ShowProjections", "Top View", 0));
        label_7->setText(QApplication::translate("ShowProjections", "    z-axis", 0));
        frontView->setText(QApplication::translate("ShowProjections", "TextLabel", 0));
        label_2->setText(QApplication::translate("ShowProjections", "Side View", 0));
        label->setText(QApplication::translate("ShowProjections", "Front View", 0));
        label_5->setText(QApplication::translate("ShowProjections", "    x-axis", 0));
    } // retranslateUi

};

namespace Ui {
    class ShowProjections: public Ui_ShowProjections {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SHOWPROJECTIONS_H
