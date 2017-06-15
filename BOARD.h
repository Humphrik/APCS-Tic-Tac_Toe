#ifndef BOARD_H_INCLUDED
#define BOARD_H_INCLUDED

class aBoard {
public:
    int playerTurn;
    int grid[3][3];

    aBoard(int grid[3][3], int turn);
    aBoard();

    int checkWin();
    void updateGrid(int pos, int turn);
    bool isEmpty(int i);
    bool checkDraw();

};

class pBoard: public aBoard {
public:
    int checkWin();
    void printGrid();
    void takeTurn(int turn);
    // Will call updateGrid with user inputs.
};

class aiPlayer {
public:
    aiPlayer(int turn);
    int aiTurn;
    int findMax(int arr[]);
    int findMin(int arr[]);
    int bestMove(int turn, int depth, aBoard board);
};





#endif // BOARD_H_INCLUDED
