/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

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
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QLabel *frontView;
    QLabel *TopView;
    QLabel *sideView;
    QLabel *Isometric;
    QSlider *xSlider;
    QSlider *ySlider;
    QSlider *zSlider;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *label_7;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1095, 794);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        frontView = new QLabel(centralWidget);
        frontView->setObjectName(QStringLiteral("frontView"));
        frontView->setGeometry(QRect(10, 10, 250, 250));
        TopView = new QLabel(centralWidget);
        TopView->setObjectName(QStringLiteral("TopView"));
        TopView->setGeometry(QRect(10, 350, 250, 250));
        sideView = new QLabel(centralWidget);
        sideView->setObjectName(QStringLiteral("sideView"));
        sideView->setGeometry(QRect(350, 10, 250, 250));
        Isometric = new QLabel(centralWidget);
        Isometric->setObjectName(QStringLiteral("Isometric"));
        Isometric->setGeometry(QRect(350, 350, 250, 250));
        xSlider = new QSlider(centralWidget);
        xSlider->setObjectName(QStringLiteral("xSlider"));
        xSlider->setGeometry(QRect(900, 150, 160, 29));
        xSlider->setOrientation(Qt::Horizontal);
        ySlider = new QSlider(centralWidget);
        ySlider->setObjectName(QStringLiteral("ySlider"));
        ySlider->setGeometry(QRect(900, 200, 160, 29));
        ySlider->setOrientation(Qt::Horizontal);
        zSlider = new QSlider(centralWidget);
        zSlider->setObjectName(QStringLiteral("zSlider"));
        zSlider->setGeometry(QRect(900, 250, 160, 29));
        zSlider->setOrientation(Qt::Horizontal);
        label_5 = new QLabel(centralWidget);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(825, 160, 67, 17));
        label_6 = new QLabel(centralWidget);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(825, 210, 67, 17));
        label_7 = new QLabel(centralWidget);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(825, 260, 67, 17));
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(120, 290, 80, 17));
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(460, 290, 80, 17));
        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(120, 630, 80, 17));
        label_4 = new QLabel(centralWidget);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(460, 630, 150, 17));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1095, 25));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        frontView->setText(QApplication::translate("MainWindow", "TextLabel", 0));
        TopView->setText(QApplication::translate("MainWindow", "TextLabel", 0));
        sideView->setText(QApplication::translate("MainWindow", "TextLabel", 0));
        Isometric->setText(QApplication::translate("MainWindow", "TextLabel", 0));
        label_5->setText(QApplication::translate("MainWindow", "    x-axis", 0));
        label_6->setText(QApplication::translate("MainWindow", "    y-axis", 0));
        label_7->setText(QApplication::translate("MainWindow", "    z-axis", 0));
        label->setText(QApplication::translate("MainWindow", "Front View", 0));
        label_2->setText(QApplication::translate("MainWindow", "Side View", 0));
        label_3->setText(QApplication::translate("MainWindow", "Top View", 0));
        label_4->setText(QApplication::translate("MainWindow", "Isometric Projection", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
