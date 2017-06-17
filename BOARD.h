#ifndef BOARD_H_INCLUDED
#define BOARD_H_INCLUDED

#include <vector>

using namespace std;

class aBoard {
public:
    int playerTurn;
    int grid[3][3];

    aBoard(int grid[3][3], int turn);
    aBoard();
    int checkWin();
    int score(int depth, int aiTurn);
    void updateGrid(int pos, int turn);
    bool isEmpty(int i);
    bool checkDraw();

};

class pBoard: public aBoard {
public:
    int checkWin();
    void printGrid();
    void takeTurn(int turn);
    bool isEmpty(int i);
    // Will call updateGrid with user inputs.
};

class aiPlayer {
public:
    aiPlayer(int turn);
    int aiTurn;
    int choice;
    int findMax(vector<int> vec);
    int findMin(vector<int> vec);
    int bestMove(int turn, int depth, aBoard board);
};





#endif // BOARD_H_INCLUDED
