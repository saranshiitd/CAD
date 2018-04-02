#ifndef SHOWPROJECTIONS_H
#define SHOWPROJECTIONS_H
#include <string>
#include <QMainWindow>

namespace Ui {
class ShowProjections;
}

class ShowProjections : public QMainWindow
{
    Q_OBJECT

public:

    explicit ShowProjections(QWidget *parent = 0);
    float angleX, angleY, angleZ;
    std::string objfileName;
    ~ShowProjections();

private slots:
    void on_xSlider_valueChanged(int value);

    void on_ySlider_valueChanged(int value);

    void on_zSlider_valueChanged(int value);

private:
    Ui::ShowProjections *ui;
};

#endif // SHOWPROJECTIONS_H
