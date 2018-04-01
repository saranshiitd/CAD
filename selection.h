#ifndef SELECTION_H
#define SELECTION_H

#include <QMainWindow>

namespace Ui {
class Selection;
}

class Selection : public QMainWindow
{
    Q_OBJECT

public:
    explicit Selection(QWidget *parent = 0);
    ~Selection();

private slots:
    void on_Regenerate_clicked();

    void on_Project_clicked();

private:
    Ui::Selection *ui;
};

#endif // SELECTION_H
