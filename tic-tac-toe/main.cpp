#include <iostream>
#include "Tic-Tac-Functions.hpp"

using std::cout;
using std::cin;

int main()
{
    //outer repeat loop
    do {
        //display instructions
        showInstructions();
        bool win,tie;
        int playerInput, playerTurn = 1;
        char board[LENGTH];
        initializeBoard(board, LENGTH);
        
        //inner game loop
        do {
            //display board
            displayBoard(board, LENGTH);
            //get next move
            cout << "Choose your position within 0-8: ";
            cin >> playerInput;
            dataValidation(playerInput);
            getMove(board, playerInput, playerTurn);
            //check win
            win = checkWin(board, LENGTH);
            //check for tie
            tie = checkTie(board);
        } while (!win and !tie);
        //display final board and congratulate winner
        displayBoard(board, LENGTH);
        
        if (tie)
        {
            cout <<"The game was a tie.\n\n\n";
        }
    } while (PlayAgain());
    cout <<"Thank you for player Tic-Tac-Toe!\n\n\n";
    return 0;
}
