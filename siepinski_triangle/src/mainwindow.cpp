#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPolygon>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->btnDraw, SIGNAL(clicked()), this, SLOT(onDraw()));
    ui->graphicsView->setScene(&graphicsScene);
    centralTriangle = NULL;
    this->setWindowIcon(QIcon(":/images/triangle.gif"));
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

    polygon << point1 << point2 << point3;
    QGraphicsPolygonItem * item = new QGraphicsPolygonItem(polygon);
    item->setBrush(QBrush(Qt::black,Qt::SolidPattern));
    centralTriangle = item;

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
    QPoint point_12 =  (point1+point2)/2;
    QPoint point_23 = (point2+point3)/2;
    QPoint point_31 = (point3+point1)/2;
    polygon << point_12 << point_23 << point_31;

    QGraphicsPolygonItem * item = new QGraphicsPolygonItem(polygon, centralTriangle);
    item->setBrush(QBrush(Qt::red,Qt::SolidPattern));
    graphicsScene.addItem(item);

    // draw the next level - upper triangle
    drawSierpinski( level-1, point1 , point_12 , point_31 );
    // draw the next level - lower left triangle
    drawSierpinski( level-1, point_12 , point2 , point_23 );
    // draw the next level - lower right triangle
    drawSierpinski( level-1, point_23 , point_31 , point3 );

    return;
}
