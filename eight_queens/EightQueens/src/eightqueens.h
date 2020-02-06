#ifndef EIGHTQUEENS_H
#define EIGHTQUEENS_H

#include <vector>

const int BOARD_WIDTH = 8;
const int BOARD_HEIGHT = 8;
const int INVALID_POSITION = -1;

class Point {
private:
    int x;
    int y;

public:
    Point(int x1, int y1): x(x1), y(y1) {}
    bool isValid() { return x != INVALID_POSITION;}
    int getX() const { return x;}
    int getY() const { return y;}
    Point& operator++ (int) {
        ++y;

        if (y == BOARD_HEIGHT) { // covered all the places on the board
            y = 0;
            ++x;
        }
        if (x == BOARD_WIDTH){
            x = y = INVALID_POSITION;
        }

        return *this;
    }

    Point& operator ++ () {
        return this->operator++(int());
    }

};

bool operator == (const Point& lhs, const Point& rhs);

class EightQueens
{
public:
    EightQueens() {}
    ~EightQueens() {}
    void run();
    std::vector<std::vector<Point>>& getSolutions() {return solution;};
    static void print(const std::vector<Point>& board);

private:
    std::vector<std::vector<Point>> solution;

    bool checkBoardFilledWithEightQueens(const std::vector<Point>& board) const;
    bool canQueenBePlaced(
            const std::vector<Point>& board,
            const Point& point) const;
    void recursiveSolution(std::vector<Point> board);
    bool isUniqueSolution(const std::vector<Point>& board) const;
};

#endif // EIGHTQUEENS_H
