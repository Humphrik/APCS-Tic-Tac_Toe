#include <iostream>
#include "BOARD.h"

using namespace std;

int main()
{
    char playerFirst;
    int playerTurn = 1;
    while(playerFirst != 'y' && playerFirst != 'n') {
        cout << "Would you like to go first? y/n" << endl;
        cin >> playerFirst;
        if(playerFirst == 'n')
            playerTurn = -1;
    }
    pBoard gameBoard;
    aiPlayer computer(playerTurn*-1);
    int currentTurn = 1;
    for(int i = 0; gameBoard.checkWin() == 0 && i < 9; i++, currentTurn*=-1) {
        gameBoard.printGrid();
        if(currentTurn == playerTurn)
            gameBoard.takeTurn(currentTurn);
        else
            cout << computer.bestMove(currentTurn, 1, gameBoard);
            //gameBoard.updateGrid(computer.bestMove(currentTurn, 1, gameBoard), currentTurn);
            //gameBoard.takeTurn(currentTurn);
    }
    gameBoard.printGrid();
    if(gameBoard.checkWin() == playerTurn)
        cout << "Player wins!";
    else if(gameBoard.checkWin() != 0)
        cout << "Computer wins!";
    else
        cout << "Its a draw!";
}


