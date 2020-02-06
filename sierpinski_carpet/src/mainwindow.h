#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsItem>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    QGraphicsScene graphicsScene;
    QGraphicsItem *carpet;

public slots:
    void onDraw();
    void drawSierpinski(
            const int level,
            const QPoint& point1,
            const QPoint& point2);
};
#endif // MAINWINDOW_H
