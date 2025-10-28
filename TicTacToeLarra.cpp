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
