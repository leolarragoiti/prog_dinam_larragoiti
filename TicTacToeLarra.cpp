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

// =========================
// FUNCION PRINCIPAL
// =========================
int main() {
    char board[3][3];
    char currentPlayer;
    int opcionMenu;

    do {
        // Menú principal
        cout << "===== TIC TAC TOE =====\n";
        cout << "1. Jugar\n";
        cout << "2. Salir\n";
        cout << "Selecciona una opcion: ";
        cin >> opcionMenu;

        if (opcionMenu == 2) {
            cout << "Saliendo del juego...\n";
            break;
        }

        if (opcionMenu != 1) {
            cout << "Opcion invalida.\n\n";
            continue;
        }

        // Inicializa el tablero y jugador inicial
        initBoard(board);
        currentPlayer = 'X';

        bool gameOver = false;

        while (!gameOver) {
            // Mostrar tablero actual
            printBoard(board);

            // Pedir jugada
            int row, col;
            cout << "Turno de jugador " << currentPlayer << endl;
            cout << "Ingresa fila (1-3): ";
            cin >> row;
            cout << "Ingresa columna (1-3): ";
            cin >> col;

            // Convertir a índice 0-2
            row--;
            col--;

            // Intentar movimiento
            if (!makeMove(board, row, col, currentPlayer)) {
                cout << "Movimiento invalido. Intenta de nuevo.\n";
                continue; // vuelve a pedir jugada al mismo jugador
            }

            // ¿Ganó este jugador?
            if (checkWin(board, currentPlayer)) {
                printBoard(board);
                cout << ">>> El jugador " << currentPlayer << " GANA! <<<\n\n";
                gameOver = true;
            }
            // ¿Empate?
            else if (checkDraw(board)) {
                printBoard(board);
                cout << ">>> EMPATE <<<\n\n";
                gameOver = true;
            }
            else {
                // Cambiar de jugador
                switchPlayer(currentPlayer);
            }
        }

        // Preguntar si quieren volver a jugar
        char otra;
        cout << "Desean jugar otra vez? (s/n): ";
        cin >> otra;
        if (otra == 's' || otra == 'S') {
            opcionMenu = 1; // repetir sin salir al menú
        } else {
            opcionMenu = 2; // salir
        }

    } while (opcionMenu == 1);

    cout << "Gracias por jugar :)\n";
    return 0;
}

// =========================
// FUNCIONES
// =========================

// Llena el tablero con espacios en blanco
void initBoard(char board[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            board[i][j] = ' ';
        }
    }
}

// Imprime el tablero bonito
void printBoard(const char board[3][3]) {
    cout << "\n   1   2   3\n";
    for (int i = 0; i < 3; i++) {
        cout << i + 1 << "  ";
        for (int j = 0; j < 3; j++) {
            cout << board[i][j];
            if (j < 2) cout << " | ";
        }
        cout << "\n";
        if (i < 2) cout << "  ---+---+---\n";
    }
    cout << "\n";
}

// Intenta colocar la ficha del jugador actual
// Regresa true si se pudo colocar, false si fue inválido
bool makeMove(char board[3][3], int row, int col, char player) {
    // Validar rango
    if (row < 0 || row > 2 || col < 0 || col > 2) {
        return false;
    }
    // Validar que la casilla esté libre
    if (board[row][col] != ' ') {
        return false;
    }
    // Hacer la jugada
    board[row][col] = player;
    return true;
}

// Revisa si 'player' ganó
bool checkWin(const char board[3][3], char player) {
    // Revisar filas
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == player &&
            board[i][1] == player &&
            board[i][2] == player) {
            return true;
        }
    }

    // Revisar columnas
    for (int j = 0; j < 3; j++) {
        if (board[0][j] == player &&
            board[1][j] == player &&
            board[2][j] == player) {
            return true;
        }
    }

    // Revisar diagonales
    if (board[0][0] == player &&
        board[1][1] == player &&
        board[2][2] == player) {
        return true;
    }

    if (board[0][2] == player &&
        board[1][1] == player &&
        board[2][0] == player) {
        return true;
    }

    // Si nada anterior se cumplió, no ganó
    return false;
}

// Revisa si el tablero está lleno y nadie ganó
bool checkDraw(const char board[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] == ' ') {
                return false; // aún hay huecos, no es empate
            }
        }
    }
    return true; // no hay huecos -> empate
}

// Cambia 'X' <-> 'O'
void switchPlayer(char &player) {
    if (player == 'X')
        player = 'O';
    else
        player = 'X';
}