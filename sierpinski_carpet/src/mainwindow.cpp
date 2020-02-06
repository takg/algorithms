#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>
#include <ostream>

std::ostream& operator << (std::ostream& os, const QPoint& p) {
    os << p.x() << "," << p.y() ;
    return os;
}

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowIcon(QIcon(":/images/carpet.png"));
    connect(ui->btnDraw, SIGNAL(clicked()), this, SLOT(onDraw()));
    ui->graphicsView->setScene(&graphicsScene);
    carpet = NULL;
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::onDraw()
{
    ui->graphicsView->hide();
    graphicsScene.clear();

    QPolygonF polygon;
    QPoint point1 = QPoint(10, 10);
    QPoint point4 = QPoint(ui->graphicsView->width()-10, ui->graphicsView->height()-10);
    int width = (point4.x()-point1.x());
    QPoint point2 = point1 + QPoint(width, 0);
    QPoint point3 = point4 - QPoint(width, 0);

    polygon << point1 << point2 << point4 << point3;
    std::cout << "\n" << point1 << " " << point2 << " " << point3 << " " << point4 <<std::endl;

    QGraphicsPolygonItem * item = new QGraphicsPolygonItem(polygon);
    item->setBrush(QBrush(Qt::black,Qt::SolidPattern));
    carpet = item;

    graphicsScene.addItem(item);

    // initial the recursive sierpinski
    drawSierpinski(ui->txtLevel->text().toInt(), point1, point4);

    ui->graphicsView->show();
}

void MainWindow::drawSierpinski(
                                const int level,
                                const QPoint& point1,
                                const QPoint& point4)
{
    if ( level == 0 )
    {
        return;
    }

    QPolygonF polygon;

    int width = (point4.x()-point1.x())/3;
    int height = (point4.y()-point1.y())/3;

    QPoint point_a =  point1 + QPoint(width, height);
    QPoint point_b = point_a + QPoint(width, 0);
    QPoint point_c = point_a + QPoint(0, height);
    QPoint point_d = point_c + QPoint(width, 0);

    polygon << point_a << point_b << point_d << point_c;

    QGraphicsPolygonItem * item = new QGraphicsPolygonItem(polygon, carpet);
    item->setBrush(QBrush(Qt::red, Qt::SolidPattern));
    graphicsScene.addItem(item);

    // draw the carpet for 1st square
    drawSierpinski( level-1, point1 , point_a );
    // draw the carpet for 2nd square
    drawSierpinski( level-1, point1 + QPoint(width, 0), point_a + QPoint(width, 0));
    // draw the carpet for 3rd square
    drawSierpinski( level-1, point1 + 2*QPoint(width, 0), point_a + 2*QPoint(width, 0) );
    // draw the carpet for 4th square
    drawSierpinski( level-1, point_a - QPoint(width, 0), point_c );
    // draw the carpet for 6th square
    drawSierpinski( level-1, point_b , point_d + QPoint(width, 0));
    // draw the carpet for 7th square
    drawSierpinski( level-1, point_c - QPoint(width, 0) , point_c + QPoint(0, height));
    // draw the carpet for 8th square
    drawSierpinski( level-1, point_c , point_d + QPoint(0, height));
    // draw the carpet for 9th square
    drawSierpinski( level-1, point_d , point4);

    return;
}
