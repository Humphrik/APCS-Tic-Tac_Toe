#include "BOARD.h"
#include <iostream>
using namespace std;

aBoard::aBoard(int preset[3][3], int turn) {
    // Board w/ preset values.
    for(int i = 0; i < 9; i++)
        grid[i/3][i%3] = preset[i/3][i%3];
    playerTurn = turn;
}

aBoard::aBoard() {
    // A blank board.
    for(int i = 0; i < 9; i++)
        grid[i/3][i%3] = 0;
    playerTurn = 1;
}

int aBoard::checkWin() {
    // Return winning player's turn, if any.
    for(int i = 0; i < 3; i++) {
        if (grid[0][i] != 0 && grid[0][i] == grid[1][i] && grid[1][i] == grid[2][i])
            // A vertical win.
            return grid[0][i];
        if (grid[i][0] != 0 && grid[i][0] == grid[i][1] && grid[i][1] == grid[i][2])
            // A horizontal win.
            return grid[i][0];
    }
    if ((grid[0][0] != 0 && grid[0][0] == grid[1][1] && grid[1][1] == grid[2][2])
            || (grid [0][2] != 0 && grid[0][2] == grid[1][1] && grid[1][1] == grid[2][0]))
            // Either diagonal win.
            return grid[1][1];
    else return 0;
}

void aBoard::updateGrid(int pos, int turn) {
    // Place an X or O on board.
    grid[pos/3][pos%3] = turn;
}

bool aBoard::isEmpty(int i) {
    // Is the given position empty (no X or O)?
    return (grid[i/3][i%3] == 0);
}

bool aBoard::checkDraw() {
    // Is every square filled, but no winner found?
    for(int i = 0; i < 9; i++)
        if(grid[i/3][i%3] == 0)
            return false;
    return checkWin() == 0;
}

int aBoard::score(int depth, int turn) {
    // For use in AI.
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
    // See aBoard::checkWin();
    return aBoard::checkWin();
}

void pBoard::printGrid() {
    // Print the current board state to console.
    for(int i = 0; i < 9; i++) {
        if(i == 3 || i == 6)
            // Dividers for rows.
            cout << endl << "_____" << endl;
        switch(grid[i/3][i%3]) {
        case 0:
            // Empty square is a space.
            cout << " ";
            break;
        case 1:
            // 1 = X or first player.
            cout << "X";
            break;
        case -1:
            // -1 = O or second player.
            cout << "O";
            break;
        }
        if(i%3 != 2)
                // Dividers for columns.
                cout << "|";
    }
    cout << endl;
}

void pBoard::takeTurn(int turn) {
    // Prompt user to place an X or O.
    std::cout << "Please input a number 0-8" << endl;
    // 0 = top left, 8 = bottom right. input = grid[i/3][i%3]
    int input = -1;
    while(input < 0 || input > 8 || !isEmpty(input))
        // Must be an empty square between 0 and 8.
        std::cin >> input;
    aBoard::updateGrid(input, turn);
    // See aBoard::updateGrid();
}

bool pBoard::isEmpty(int i) {
    // See aBoard::isEmpty();
    return aBoard::isEmpty(i);
}
