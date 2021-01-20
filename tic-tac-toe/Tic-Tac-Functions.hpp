#ifndef Tic_Tac_Functions_hpp
#define Tic_Tac_Functions_hpp

#include <stdio.h>
//global constants
const int LENGTH = 9;
const char X = 'X';
const char O = 'O';
const char EMPTY = ' ';

//functions
void showInstructions();
void initializeBoard(char boardArr[], int SIZE);
void displayBoard(const char  boardArr[], int SIZE);
void getMove(char boardArr[], int getMove,int &playerTurn);
bool checkWin(const char boardArr[], int SIZE);
bool checkTie(const char boardArr[]);
bool PlayAgain();
int dataValidation(int &validatingNum);
char dataValidation(char &validatingChar);

#endif /* Tic_Tac_Functions_hpp */
