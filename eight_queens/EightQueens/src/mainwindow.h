#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "eightqueens.h"
#include <QMainWindow>
#include <QLabel>
#include <QString>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    void setSolutions(std::vector<std::vector<Point>>& soln);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    QLabel* label[BOARD_WIDTH][BOARD_HEIGHT];
    QLabel* solutionLabel;
    int index;
    std::vector<std::vector<Point>> solution;

    void setBoard(int index, bool showIcon);

public slots:
    void showNextSolution();
    void showPrevSolution();
};
#endif // MAINWINDOW_H
