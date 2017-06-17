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
    aiPlayer computer(-playerTurn);
    int currentTurn = 1;
    for(int i = 0; gameBoard.checkWin() == 0 && i < 9; i++, currentTurn*=-1) {
        gameBoard.printGrid();
        if(currentTurn == playerTurn)
            gameBoard.takeTurn(currentTurn);
        else {
            int dump = computer.bestMove(currentTurn, 1, gameBoard);
            gameBoard.updateGrid(computer.choice, currentTurn);
            // Replace the 2 lines above with the one below for 2P.
            // gameBoard.takeTurn(currentTurn);
        }
        cout << "\n\n";
    }
    gameBoard.printGrid();
    cout << gameBoard.checkDraw() << "!!!!!!!!!!!!!!" << endl;
    if(gameBoard.checkWin() == playerTurn)
        cout << "Player wins!";
    else if(gameBoard.checkWin() != 0)
        cout << "Computer wins!";
    else
        cout << "Its a draw!";
}


