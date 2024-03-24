#include <iostream>
#include <vector>

using namespace std;

// Fonction pour afficher le plateau de jeu
void printBoard(const vector<char>& board) {
    cout << " " << board[0] << " | " << board[1] << " | " << board[2] << endl;
    cout << "---|---|---" << endl;
    cout << " " << board[3] << " | " << board[4] << " | " << board[5] << endl;
    cout << "---|---|---" << endl;
    cout << " " << board[6] << " | " << board[7] << " | " << board[8] << endl;
}

// Fonction pour vérifier s'il y a un gagnant
bool checkForWin(const vector<char>& board, char player) {
    return ((board[0] == player && board[1] == player && board[2] == player) ||
        (board[3] == player && board[4] == player && board[5] == player) ||
        (board[6] == player && board[7] == player && board[8] == player) ||
        (board[0] == player && board[3] == player && board[6] == player) ||
        (board[1] == player && board[4] == player && board[7] == player) ||
        (board[2] == player && board[5] == player && board[8] == player) ||
        (board[0] == player && board[4] == player && board[8] == player) ||
        (board[2] == player && board[4] == player && board[6] == player));
}

// Fonction pour vérifier s'il y a égalité
bool checkForTie(const vector<char>& board) {
    for (char cell : board) {
        if (cell != 'X' && cell != 'O') {
            return false;
        }
    }
    return true;
}

int main() {
    vector<char> board = { '1', '2', '3', '4', '5', '6', '7', '8', '9' }; // Plateau de jeu initial
    char currentPlayer = 'X'; // Joueur actuel

    cout << "Bienvenue dans le jeu de Morpion (Tic-Tac-Toe) !" << endl;
    cout << "Joueur X commence." << endl;

    while (true) {
        printBoard(board);

        // Le joueur choisit une case
        int choice;
        cout << "Joueur " << currentPlayer << ", veuillez choisir une case (1-9) : ";
        cin >> choice;
        choice--; // Ajuste pour l'index du tableau

        // Vérifie si la case est valide et non occupée
        if (choice < 0 || choice >= 9 || board[choice] == 'X' || board[choice] == 'O') {
            cout << "Case invalide ou déjà occupée. Veuillez choisir à nouveau." << endl;
            continue;
        }

        // Place le symbole du joueur sur la case choisie
        board[choice] = currentPlayer;

        // Vérifie s'il y a un gagnant ou une égalité
        if (checkForWin(board, currentPlayer)) {
            printBoard(board);
            cout << "Le joueur " << currentPlayer << " a gagné !" << endl;
            break;
        }
        else if (checkForTie(board)) {
            printBoard(board);
            cout << "Match nul !" << endl;
            break;
        }

        // Change de joueur
        currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
    }

    return 0;
}
