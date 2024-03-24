#include <iostream>
#include <vector>
using namespace std;

// Définition de la taille du plateau de jeu
const int ROWS = 6;
const int COLS = 7;

// Définition des symboles des joueurs
const char EMPTY = ' ';
const char PLAYER1 = 'X';
const char PLAYER2 = 'O';

// Structure du plateau de jeu
struct Board {
    vector<vector<char>> cells;

    // Constructeur pour initialiser le plateau vide
    Board() : cells(ROWS, vector<char>(COLS, EMPTY)) {}

    // Afficher le plateau de jeu
    void display() {
        cout << "  1 2 3 4 5 6 7\n";
        cout << "---------------\n";
        for (int i = 0; i < ROWS; ++i) {
            cout << "| ";
            for (int j = 0; j < COLS; ++j) {
                cout << cells[i][j] << " ";
            }
            cout << "|\n";
        }
        cout << "---------------\n";
    }

    // Vérifier si une colonne est pleine
    bool isColumnFull(int col) {
        return cells[0][col] != EMPTY;
    }

    // Placer un jeton dans une colonne
    bool placeToken(int col, char token) {
        if (col < 0 || col >= COLS || isColumnFull(col)) {
            return false;
        }
        for (int i = ROWS - 1; i >= 0; --i) {
            if (cells[i][col] == EMPTY) {
                cells[i][col] = token;
                return true;
            }
        }
        return false;  // Colonne pleine (normalement non atteint)
    }

    // Vérifier s'il y a un gagnant
    bool checkWinner(char token) {
        // Vérification des lignes
        for (int i = 0; i < ROWS; ++i) {
            for (int j = 0; j <= COLS - 4; ++j) {
                if (cells[i][j] == token &&
                    cells[i][j + 1] == token &&
                    cells[i][j + 2] == token &&
                    cells[i][j + 3] == token) {
                    return true;
                }
            }
        }
        // Vérification des colonnes
        for (int i = 0; i <= ROWS - 4; ++i) {
            for (int j = 0; j < COLS; ++j) {
                if (cells[i][j] == token &&
                    cells[i + 1][j] == token &&
                    cells[i + 2][j] == token &&
                    cells[i + 3][j] == token) {
                    return true;
                }
            }
        }
        // Vérification des diagonales (descendantes)
        for (int i = 0; i <= ROWS - 4; ++i) {
            for (int j = 0; j <= COLS - 4; ++j) {
                if (cells[i][j] == token &&
                    cells[i + 1][j + 1] == token &&
                    cells[i + 2][j + 2] == token &&
                    cells[i + 3][j + 3] == token) {
                    return true;
                }
            }
        }
        // Vérification des diagonales (ascendantes)
        for (int i = 3; i < ROWS; ++i) {
            for (int j = 0; j <= COLS - 4; ++j) {
                if (cells[i][j] == token &&
                    cells[i - 1][j + 1] == token &&
                    cells[i - 2][j + 2] == token &&
                    cells[i - 3][j + 3] == token) {
                    return true;
                }
            }
        }
        return false;
    }
};

int main() {
    Board board;
    bool player1Turn = true;  // true pour le joueur 1, false pour le joueur 2

    cout << "Bienvenue dans le jeu de Puissance 4!\n";

    while (true) {
        // Afficher le plateau de jeu
        board.display();

        // Demander au joueur actuel de choisir une colonne
        int col;
        char currentPlayerToken = (player1Turn ? PLAYER1 : PLAYER2);
        cout << "Joueur " << (player1Turn ? "1 (X)" : "2 (O)") << ", choisissez une colonne (1-7): ";
        cin >> col;
        col--;  // ajuster pour l'index de 0 à 6

        // Placer le jeton dans la colonne choisie
        if (col >= 0 && col < COLS && board.placeToken(col, currentPlayerToken)) {
            // Vérifier s'il y a un gagnant
            if (board.checkWinner(currentPlayerToken)) {
                // Afficher le plateau de jeu final
                board.display();
                cout << "Félicitations! Le joueur " << (player1Turn ? "1 (X)" : "2 (O)") << " a gagné!\n";
                break;  // Sortir de la boucle de jeu
            }
            // Passer au tour du prochain joueur
            player1Turn = !player1Turn;
        }
        else {
            cout << "Colonne invalide ou pleine. Essayez à nouveau.\n";
        }
    }

    cout << "Merci d'avoir joué!\n";

    return 0;
}

