#include <iostream>
#include "BOARD.h";

using namespace std;

int main()
{
    char playerFirst;
    while(playerFirst != 'y' && playerFirst != 'n') {
        cout << "Would you like to go first? y/n" << endl;
        cin >> playerFirst;
        if(playerFirst == 'n')
            playerTurn = -1;
    }
}


