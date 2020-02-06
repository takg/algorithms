#include "eightqueens.h"
#include <iostream>
#include <algorithm>

bool operator == (const Point& lhs, const Point& rhs) {
    return lhs.getX() == rhs.getX() && lhs.getY() == rhs.getY();
}

bool EightQueens::checkBoardFilledWithEightQueens(const std::vector<Point>& board) const
{
    return board.size() == BOARD_WIDTH;
}

void EightQueens::recursiveSolution(
        std::vector<Point> board)
{
    Point point(0, 0);

    while (point.isValid())
    {
        if ( canQueenBePlaced(board, point) ) {
            board.push_back(point);

            if (checkBoardFilledWithEightQueens(board)) {
                if (isUniqueSolution(board)) {
                    solution.push_back(std::vector<Point>(board));
                    //print(board);
                }
            }
            point++;
            recursiveSolution(board);
            board.pop_back();
        }
        point++;
    }

    return;
}

bool EightQueens::canQueenBePlaced(
        const std::vector<Point>& board,
        const Point& point) const
{
    bool returnFlag = true;

    for (auto point1: board)
    {
        if (point1.getX() == point.getX() ||
                point1.getY() == point.getY() ||
                ( (point1.getX() - point.getX()) == (point1.getY() - point.getY()) ) ||
                ( (point1.getX() - point.getX()) == (point.getY() - point1.getY()) )
                ) {
            returnFlag = false;
            break;
        }

   }

    return returnFlag;
}

void EightQueens::print(const std::vector<Point>& board){
    static int index = 0;
    ++index;
    std::cout << "\n solution " << index << std::endl;
    for (auto x: board) {
        std::cout << x.getX() << " " << x.getY() << std::endl;
    }
}

void EightQueens::run() {
    std::vector<Point> board;

    for (int x = 0; x < BOARD_WIDTH; ++x) {
        for (int y = 0; y < BOARD_HEIGHT; ++y) {
            Point point(x, y);
            board.push_back(point);
            recursiveSolution(board);
            board.pop_back();
        }
    }

}

bool EightQueens::isUniqueSolution(const std::vector<Point>& board) const {
    for (auto soln: solution) {        bool flag = true;

        for (auto x: soln) {
            if (std::find(board.begin(), board.end(), x) == board.end()) {
                flag = false;
                break;
            }
        }

        if (flag) { // there is the same solution already in the vector
            return false;
        }
    }
    return true;
}
