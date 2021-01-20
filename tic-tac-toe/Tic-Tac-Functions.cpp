#include "Tic-Tac-Functions.hpp"
#include <iostream>
using std::cout;
using std::cin;

//largest number possible
const unsigned long LARGE = std::numeric_limits<std::streamsize>::max();
const char END_LINE = '\n';


//functions
void showInstructions()
{
    cout << "Welcome to Tic-Tac-Toe!\n\n";
    cout << "Enter a number within the range 0-8\n";
}
void initializeBoard(char boardArr[], int SIZE)
{
    for (int i = 0; i < SIZE; i++) {
        boardArr[i] = EMPTY;
    }
}
void displayBoard(const char boardArr[], int SIZE)
{
    for (int i = 0; i < SIZE; i++) {
        cout << "|" << boardArr[i];
        if ((i + 1) % 3 == 0) {
            cout << "|";
            cout << '\n';
        }
    }
}
void getMove(char boardArr[], int getMove, int &playerTurn)
{
    if (playerTurn == 1) {
        //validate index is not occupied
        while (((boardArr[getMove] == X || boardArr[getMove] == O) && boardArr[getMove] != EMPTY)) {
            cout << "Spot already taken! Choose another: ";
            cin >> getMove;
            getMove = dataValidation(getMove);
        }
        boardArr[getMove] = X;
        playerTurn = 0;
    }
    
    else {
        while (((boardArr[getMove] == X || boardArr[getMove] == O) && boardArr[getMove] != EMPTY)) {
            cout << "Spot already taken! Choose another: ";
            cin >> getMove;
            getMove = dataValidation(getMove);
        }
        boardArr[getMove] = O;
        playerTurn = 1;
    }
}
bool checkWin(const char boardArr[], int SIZE)
{
    bool win = false;
    for (int i = 0; i < SIZE and !win; i++) {
        //Horizontal check
        if ((boardArr[0] == X and boardArr[1] == X and boardArr[2] == X) or
            (boardArr[3] == X and boardArr[4] == X and boardArr[5] == X) or
            (boardArr[6] == X and boardArr[7] == X and boardArr[8] == X) or
            (boardArr[0] == X and boardArr[3] == X and boardArr[6] == X) or
            (boardArr[1] == X and boardArr[4] == X and boardArr[7] == X) or
            (boardArr[2] == X and boardArr[5] == X and boardArr[8] == X) or
            (boardArr[0] == X and boardArr[4] == X and boardArr[8] == X) or
            (boardArr[2] == X and boardArr[4] == X and boardArr[6] == X))
        {
            cout << "\nPlayer 1 has WON! Congrats!\n\n";
            win = true;
        }
        //Horizontal check
        if ((boardArr[0] == O and boardArr[1] == O and boardArr[2] == O) or
            (boardArr[3] == O and boardArr[4] == O and boardArr[5] == O) or
            (boardArr[6] == O and boardArr[7] == O and boardArr[8] == O) or
            (boardArr[0] == O and boardArr[3] == O and boardArr[6] == O) or
            (boardArr[1] == O and boardArr[4] == O and boardArr[7] == O) or
            (boardArr[2] == O and boardArr[5] == O and boardArr[8] == O) or
            (boardArr[0] == O and boardArr[4] == O and boardArr[8] == O) or
            (boardArr[2] == O and boardArr[4] == O and boardArr[6] == O))
        {
            cout << "\nPlayer 2 has WON! Congrats!\n\n";
            win = true;
        }
    }
    
    return win;
}

bool checkTie(const char boardArr[])
{
    if (boardArr[0] != EMPTY and boardArr[1] != EMPTY and boardArr[2] != EMPTY and boardArr[3] != EMPTY and boardArr[4] != EMPTY and boardArr[5] != EMPTY and boardArr[6] != EMPTY and boardArr[7] != EMPTY and boardArr[8] != EMPTY)
    {
        cout << "We have a tie!\n";
        return true;
    }
    else
        return false;
}
bool PlayAgain()
{
    char answer;
    cout << "Would you like to play Again? (y/n): ";
    cin >> answer;
    dataValidation(answer);
    if (answer == 'y')
        return true;
    else
        return false;
}

int dataValidation(int &validatingNum)
{
    while (cin.fail() || (validatingNum > 8 || validatingNum < 0))
    {
        cout << "Enter a number within the range 0 - 8: ";
        cin.clear();
        cin.ignore(LARGE, END_LINE);
        cin >> validatingNum;
    }
    
    return validatingNum;
}
char dataValidation(char &validatingChar)
{
    while (validatingChar != 'y' && validatingChar != 'n')
    {
        cout << "Try again: ";
        cin.clear();
        cin.ignore(LARGE, END_LINE);
        cin >> validatingChar;
        validatingChar = tolower(validatingChar);
    }
    
    return validatingChar;
}

