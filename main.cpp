#include <iostream>
#include "BOARD.h"

using namespace std;

int main()
{
    char playerFirst;
    int playerTurn = 1;
    // turn 1: 'X' or 'first', turn -1: 'O' or 'second'.
    while(playerFirst != 'y' && playerFirst != 'n') {
        // Prompts user to choose X (first) or O (second).
        cout << "Would you like to go first? y/n" << endl;
        cin >> playerFirst;
        if(playerFirst == 'n')
            playerTurn = -1;
    }
    pBoard gameBoard;
    aiPlayer computer(-playerTurn);
    // Initializes board and computer player.

    // Add line below to include a player-helping AI:
    // aiPlayer advice(playerTurn);

    int currentTurn = 1;
    while(gameBoard.checkWin() == 0 && !gameBoard.checkDraw()) {
        // While the game is not completed.
        gameBoard.printGrid();
        if(currentTurn == playerTurn) {
            // For the player's turn:

            // Add 2 lines below to prompt ideal move for the player:
            // advice.bestMove(currentTurn, 1, gameBoard);
            // cout << "Recommended move: " << advice.choice << endl;

            gameBoard.takeTurn(currentTurn);
        }
        else {
            // For the computers turn:
            computer.bestMove(currentTurn, 1, gameBoard);
            gameBoard.updateGrid(computer.choice, currentTurn);
            // Replace the 2 lines above with the one below for 2P:
            // gameBoard.takeTurn(currentTurn);
        }
        cout << "\n\n";
        currentTurn*=-1;
        // Switches turn between computer and player.
    }
    gameBoard.printGrid();
    if(gameBoard.checkWin() == playerTurn)
        cout << "Player wins!";
    else if(gameBoard.checkWin() != 0)
        cout << "Computer wins!";
    else
        cout << "Its a draw!";
    // Print the results of the game.
}


