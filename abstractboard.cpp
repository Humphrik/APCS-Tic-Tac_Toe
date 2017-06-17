#include "BOARD.h"
#include <iostream>
using namespace std;

aBoard::aBoard(int preset[3][3], int turn) {
    for(int i = 0; i < 9; i++)
        grid[i/3][i%3] = preset[i/3][i%3];
    playerTurn = turn;
}

aBoard::aBoard() {
    for(int i = 0; i < 9; i++)
        grid[i/3][i%3] = 0;
    playerTurn = 1;
}

int aBoard::checkWin() {
    for(int i = 0; i < 3; i++) {
        if(( grid[0][i] != 0 && grid[0][i] == grid[1][i] && grid[1][i] == grid[2][i])
           || (grid[i][0] != 0 && grid[i][0] == grid[i][1] && grid[i][1] == grid[i][2]))
           return grid[0][i];
    }
    if ((grid[0][0] != 0 && grid[0][0] == grid[1][1] && grid[1][1] == grid[2][2])
            || (grid [0][2] != 0 && grid[0][2] == grid[1][1] && grid[1][1] == grid[2][0]))
            return grid[1][1];
    else return 0;
}

void aBoard::updateGrid(int pos, int turn) {
    grid[pos/3][pos%3] = turn;
    // checkWin();
}

bool aBoard::isEmpty(int i) {
    return (grid[i/3][i%3] == 0);
}

bool aBoard::checkDraw() {
    for(int i = 0; i < 9; i++)
        if(grid[i/3][i%3] == 0)
            return false;
    return checkWin() == 0;
}

int aBoard::score(int depth, int turn) {
    int winner = checkWin();
    if(winner == turn)
        return 10-depth;
    else if(winner == turn*-1) {
        return depth-10;
    }
    return 0;

}
/////////////////////////////////

int pBoard::checkWin() {
    return aBoard::checkWin();
}

void pBoard::printGrid() {
    for(int i = 0; i < 9; i++) {
        if(i == 3 || i == 6)
            cout << endl << "_____" << endl;
        switch(grid[i/3][i%3]) {
        case 0:
            cout << " ";
            break;
        case 1:
            cout << "X";
            break;
        case -1:
            cout << "O";
            break;
        }
        if(i%3 != 2) {
                cout << "|";
        }
    }
    cout << endl;
}

void pBoard::takeTurn(int turn) {
    std::cout << "Please input a number 1-8" << endl;
    int input = -1;
    while(input < 0 || input > 8 || !isEmpty(input))
        std::cin >> input;
    aBoard::updateGrid(input, turn);
}

bool pBoard::isEmpty(int i) {
    return aBoard::isEmpty(i);
}
