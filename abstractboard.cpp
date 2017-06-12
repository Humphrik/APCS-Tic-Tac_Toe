#include "BOARD.h"

aBoard::aBoard(int preset[3][3], int turn) {
    grid = preset;
    playerTurn = turn;
}

aBoard::aBoard() {
    grid = {0,0,0,0,0,0,0,0,0};
    playerTurn = 1;
}

bool aBoard::checkWin() {
    for(int i = 0; i < 3; i++) {
        if(( grid[0][i] != 0 && grid[0][i] == grid[1][i] && grid[1][i] == grid[2][i])
           || (grid[i][0] != 0 && grid[i][0] == grid[i][1] && grid[i][1] == grid[i][2]))
           return true;
    }
    return ((grid[0][0] != 0 && grid[0][0] == grid[1][1] && grid[1][1] == grid[2][2])
            || (grid [0][2] != 0 && grid[0][2] == grid[1][1] && grid[1][1] == grid[2][0]));
}

void aBoard::updateGrid(int pos, int turn) {
    grid[pos/3][pos%3] = turn;
    checkWin();
}

bool isEmpty(int i) {
    return (grid[i/3][i%3] == 0);
}
/////////////////////////////////
pBoard::pBoard() {}

void pBoard::printGrid() {
    for(int i = 0; i < 9; i++) {
        if(i == 3 || i == 6)
            cout << endl << "_____";
        switch(grid[i/3][i%3]) {
        case 0:
            cout << " "
            break;
        case 1:
            cout << "X";
            break;
        case 2:
            cout << "O";
            break;
        }
        cout << "|";
    }
}

void pBoard::takeTurn() {
    cout << "Please input a number 1-8";
    int input;
    cin >> input;
    updateGrid(input, playerTurn);
    printGrid();
}
