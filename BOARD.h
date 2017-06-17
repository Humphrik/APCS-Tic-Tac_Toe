#ifndef BOARD_H_INCLUDED
#define BOARD_H_INCLUDED

#include <vector>

using namespace std;

class aBoard {
// A hypothetical board state. Used by the AI.
public:
    int playerTurn; // Who is playing?
    int grid[3][3]; // 3x3 Tic-Tac-Toe board.

    aBoard(int grid[3][3], int turn); // Board w/ preset values.
    aBoard(); // A blank board.

    int checkWin(); // Return winning player's turn, if any.
    int score(int depth, int aiTurn); // For use in AI.
    void updateGrid(int pos, int turn); // Place an X or O on board.
    bool isEmpty(int i); // Is the given position empty (no X or O)?
    bool checkDraw(); // Is every square filled, but no winner found?

};

class pBoard: public aBoard {
// A real, observable board; the actual game.
public:
    int checkWin(); // See aBoard::checkWin().
    void printGrid(); // Print the current board state to console.
    void takeTurn(int turn); // Prompt user to place an X or O.
    bool isEmpty(int i); // See aBoard::isEmpty();
};

class aiPlayer {
// Decides the best move for a computer to make via minimax.
public:
    aiPlayer(int turn); // Makes AI for X or O player.
    int aiTurn; // Is the AI playing first or second?
    int choice; // The AI's recommended move (updated by bestMove).
    int findMax(vector<int> vec); // Find maximum value's index in vector.
    int findMin(vector<int> vec); // Find minimum value's index in vector.
    int bestMove(int turn, int depth, aBoard board); // Recursive minimax process.
};





#endif // BOARD_H_INCLUDED
