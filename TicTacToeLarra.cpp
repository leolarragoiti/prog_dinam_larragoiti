#include <iostream>
using namespace std;

// =========================
// PROTOTIPOS (DECLARACIÓN)
// =========================
void initBoard(char board[3][3]);
void printBoard(const char board[3][3]);
bool makeMove(char board[3][3], int row, int col, char player);
bool checkWin(const char board[3][3], char player);
bool checkDraw(const char board[3][3]);
void switchPlayer(char &player);
