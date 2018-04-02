/********************************************************************************
** Form generated from reading UI file 'selection.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SELECTION_H
#define UI_SELECTION_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Selection
{
public:
    QWidget *centralwidget;
    QPushButton *Regenerate;
    QPushButton *Project;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *Selection)
    {
        if (Selection->objectName().isEmpty())
            Selection->setObjectName(QStringLiteral("Selection"));
        Selection->resize(800, 600);
        centralwidget = new QWidget(Selection);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        Regenerate = new QPushButton(centralwidget);
        Regenerate->setObjectName(QStringLiteral("Regenerate"));
        Regenerate->setGeometry(QRect(340, 220, 99, 27));
        Project = new QPushButton(centralwidget);
        Project->setObjectName(QStringLiteral("Project"));
        Project->setGeometry(QRect(340, 300, 99, 27));
        Selection->setCentralWidget(centralwidget);
        menubar = new QMenuBar(Selection);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 25));
        Selection->setMenuBar(menubar);
        statusbar = new QStatusBar(Selection);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        Selection->setStatusBar(statusbar);

        retranslateUi(Selection);

        QMetaObject::connectSlotsByName(Selection);
    } // setupUi

    void retranslateUi(QMainWindow *Selection)
    {
        Selection->setWindowTitle(QApplication::translate("Selection", "MainWindow", 0));
        Regenerate->setText(QApplication::translate("Selection", "2D to 3D", 0));
        Project->setText(QApplication::translate("Selection", "3D to 2D", 0));
    } // retranslateUi

};

namespace Ui {
    class Selection: public Ui_Selection {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SELECTION_H
