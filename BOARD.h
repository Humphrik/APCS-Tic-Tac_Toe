#ifndef BOARD_H_INCLUDED
#define BOARD_H_INCLUDED

class aBoard {
public:
    aBoard(int grid[3][3]);
    aBoard();
    void updateGrid(int pos, int turn);
    bool checkWin();
    bool isEmpty(int i);
    int playerTurn;
    int grid[3][3];

};

class pBoard::aBoard {
public:
    void printGrid();
    void takeTurn();
    // Will call updateGrid with user inputs.
};

class aiPlayer {
public:
    int aiTurn;
    int bestMove(int turn; int depth, aBoard board);
};





#endif // BOARD_H_INCLUDED
