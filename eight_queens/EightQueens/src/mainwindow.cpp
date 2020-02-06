#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QGridLayout>
#include <iostream>
#include <QPushButton>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setFixedSize(450, 500);
    this->setWindowIcon(QIcon(":/images/queen.png"));
    QGridLayout *layout = new QGridLayout();
    centralWidget()->setLayout(layout);

    QPushButton* button = new QPushButton("");
    button->setFixedSize(50, 50);
    button->setIcon(QIcon(":/images/previous.png"));
    button->setIconSize(QSize(50, 50));
    button->setToolTip("Previous");
    connect(button, SIGNAL(clicked()), this, SLOT(showPrevSolution()));
    layout->addWidget(button, 0, 0);

    layout->addWidget(new QLabel("Solution"), 0, 3);
    solutionLabel = new QLabel("1/1");
    layout->addWidget(solutionLabel, 0, 4);

    button = new QPushButton("");
    button->setFixedSize(50, 50);
    button->setIcon(QIcon(":/images/next.png"));
    button->setIconSize(QSize(50, 50));
    button->setToolTip("Next");
    connect(button, SIGNAL(clicked()), this, SLOT(showNextSolution()));
    layout->addWidget(button, 0, 7);

    for (int i = 0 ; i < BOARD_WIDTH; ++i) {
        for (int j = 0 ; j < BOARD_HEIGHT; ++j) {
            this->label[i][j] = new QLabel("");
            this->label[i][j]->setFixedSize(50, 50);
            this->label[i][j]->setStyleSheet("border: 1px solid black");
            this->label[i][j]->setScaledContents(true);
            layout->addWidget(this->label[i][j], i+1, j);
        }
    }

    index = -1;
}

void MainWindow::setSolutions(std::vector<std::vector<Point>>& soln) {
    solution = soln;
    showNextSolution();
}

void MainWindow::setBoard(int index, bool showIcon) {
    //std::cout << "index " << index << std::endl;
    solutionLabel->setText(QString::number(index+1) + " / " + QString::number(solution.size()));
    if (index >= 0 && index < solution.size()) {
        const std::vector<Point>& board = solution[index];
        //EightQueens::print(board);

        for (auto x : board) {
            auto item = this->label[x.getX()][x.getY()];
            if (showIcon) {
                item->setPixmap(QPixmap(":/images/queen.png"));
            } else {
                item->setPixmap(QPixmap(""));
            }
        }
    }
}

void MainWindow::showNextSolution() {
    int size = solution.size();
    if (size-1 <= index) {
        return;
    }

    setBoard(index, false);
    index++;
    setBoard(index, true);
}

void MainWindow::showPrevSolution() {
    if (index < 1) {
        return;
    }

    setBoard(index, false);
    index--;
    setBoard(index, true);
}

MainWindow::~MainWindow()
{
    delete ui;
}

