#include "BOARD.h"
#include <iostream>
#include <vector>

using namespace std;

aiPlayer::aiPlayer(int turn) {
    // Makes AI for X or O player.
    aiTurn = turn;
}

int aiPlayer::findMax(vector<int> vec) {
    // Find maximum value's index in vector.
    int maxInt = vec.at(0);
    int maxIndex = 0;
    for(int i = 0; i < vec.size(); i++) {
        //std::cout << arr[i] << std::endl;
        if(vec.at(i) > maxInt) {
            maxInt = vec.at(i);
            maxIndex = i;
        }
    }
    return maxIndex;
}

int aiPlayer::findMin(vector<int> vec) {
    // Find minimum value's index in vector.
    int minInt = vec.at(0);
    int minIndex = 0;
    for(int i = 0; i < vec.size(); i++) {
        //std::cout << arr[i] << std::endl;
        if(vec.at(i) < minInt) {
            minInt = vec.at(i);
            minIndex = i;
        }
    }
    return minIndex;
}




int aiPlayer::bestMove(int turn, int depth, aBoard board) {
    // Recursive minimax process.
    if(board.checkDraw() || board.checkWin() != 0)
        // Return a score if in a terminal state (win/loss/draw).
        return board.score(depth, aiTurn);
    vector<int> scores;
    // Scores of corresponding moves
    vector<int> moves;
    // Possible moves that can be made.
    for(int i = 0; i < 9; i++)
        // Fills moves vector with possible moves.
        if(board.isEmpty(i))
           moves.push_back(i);
    for(int i = 0; i < moves.size(); i++) {
        // For each move, make the move on a new board and determine score.
        aBoard tempBoard(board.grid, turn);
        tempBoard.updateGrid(moves.at(i), turn);
        scores.push_back(bestMove(-turn, depth+1, tempBoard));
    }
    if(turn == aiTurn) {
        // If on AI's turn, find maximum score and corresponding move.
        int maxScoreIndex = findMax(scores);
        choice = moves.at(maxScoreIndex);
        return scores.at(maxScoreIndex);
    }
   else {
        // Otherwise find minimum score and corresponding move.
        int minScoreIndex = findMin(scores);
        choice = moves.at(minScoreIndex);
        return scores.at(minScoreIndex);
   }
}
