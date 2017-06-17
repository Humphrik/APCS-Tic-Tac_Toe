#include "BOARD.h"
#include <iostream>
#include <vector>

using namespace std;

aiPlayer::aiPlayer(int turn) {
    aiTurn = turn;
}

int aiPlayer::findMax(vector<int> vec) {
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
    if(board.checkDraw() || board.checkWin() != 0) {
        return board.score(depth, aiTurn);
    }
    depth += 1;
    vector<int> scores;
    vector<int> moves;
    for(int i = 0; i < 9; i++)
        if(board.isEmpty(i))
           moves.push_back(i);
   //11 cout << moves.size() << "! ";
    for(int i = 0; i < moves.size(); i++) {
        aBoard tempBoard(board.grid, turn);
        tempBoard.updateGrid(moves.at(i), turn);
        scores.push_back(bestMove(-turn, depth, tempBoard));
    }
  if(depth == 2) {
    for(int i = 0; i < moves.size(); i++)
        cout << moves.at(i) << ", " << endl;
    cout << endl;
    for(int i = 0; i < scores.size(); i++)
        cout << scores.at(i) << ", " << endl;
  }
    if(turn == aiTurn) {
        int maxScoreIndex = findMax(scores);
        choice = moves.at(maxScoreIndex);
        return scores.at(maxScoreIndex);
    }
   else {
        int minScoreIndex = findMin(scores);
        choice = moves.at(minScoreIndex);
        return scores.at(minScoreIndex);
   }
}
