#include "BOARD.h"
#include <iostream>

aiPlayer::aiPlayer(int turn) {
    aiTurn = turn;
}

int aiPlayer::findMax(int arr[9]) {
    for(int i = 0; i < 9; i++)
        std::cout << arr[i] << std::endl;
    int maxInt = arr[0];
    for(int i = 0; i < 9; i++)
        if(arr[i] > maxInt)
            maxInt = arr[i];
    return maxInt;
}

int aiPlayer::findMin(int arr[9]) {
    int minInt = arr[0];
    for(int i = 0; i < 9; i++)
        if(arr[i] < minInt)
            minInt = arr[i];
    return minInt;
}

int aiPlayer::bestMove(int turn, int depth, aBoard board) {
    std::cout << "Depth: " << depth;
    int scores[9];
    return findMax(scores);
    for(int i = 0; i < 9; i++) {
        aBoard tempBoard(board.grid, turn);
        if(tempBoard.checkDraw())
            scores[i] = 0;
        else if(tempBoard.isEmpty(i)) {
            tempBoard.updateGrid(i, turn);
            int winner = tempBoard.checkWin();
            if(winner != 0) {
                scores[i] = 10-depth;
                if(winner != aiTurn)
                    scores[i] *= -1;
            }
            else
                scores[i] = bestMove(turn*-1, depth+1, tempBoard);
        }
        }
    if(turn == aiTurn)
            return findMax(scores);
    return findMin(scores);

    }

