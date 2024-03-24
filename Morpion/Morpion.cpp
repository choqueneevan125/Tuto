#include <iostream>
#include <vector>

using namespace std;

// Fonction pour afficher la grille du jeu
void afficherGrille(const vector<vector<char>>& grille) {
    for (const auto& ligne : grille) {
        for (char casee : ligne) {
            cout << casee << " ";
        }
        cout << endl;
    }
}

// Fonction pour vérifier si un joueur a gagné
bool verifierGagnant(const vector<vector<char>>& grille, char symbole) {
    // Vérification des lignes et des colonnes
    for (int i = 0; i < 3; ++i) {
        if (grille[i][0] == symbole && grille[i][1] == symbole && grille[i][2] == symbole) {
            return true; // Ligne i
        }
        if (grille[0][i] == symbole && grille[1][i] == symbole && grille[2][i] == symbole) {
            return true; // Colonne i
        }
    }

    // Vérification des diagonales
    if (grille[0][0] == symbole && grille[1][1] == symbole && grille[2][2] == symbole) {
        return true; // Diagonale principale
    }
    if (grille[0][2] == symbole && grille[1][1] == symbole && grille[2][0] == symbole) {
        return true; // Diagonale secondaire
    }

    return false;
}

// Fonction principale du jeu
int main() {
    vector<vector<char>> grille(3, vector<char>(3, '.')); // Initialise la grille du jeu

    char joueur = 'X'; // Symbole du premier joueur
    int casesRestantes = 9; // Nombre de cases restantes sur la grille

    cout << "Bienvenue dans le jeu de Tic-Tac-Toe !" << endl;

    while (casesRestantes > 0) {
        afficherGrille(grille);

        // Demande au joueur de choisir une case
        int ligne, colonne;
        cout << "Joueur " << joueur << ", entrez la ligne et la colonne (de 0 a 2) : ";
        cin >> ligne >> colonne;

        // Vérifie si la case est valide et disponible
        if (ligne >= 0 && ligne < 3 && colonne >= 0 && colonne < 3 && grille[ligne][colonne] == '.') {
            grille[ligne][colonne] = joueur;
            casesRestantes--;

            // Vérifie si le joueur a gagné
            if (verifierGagnant(grille, joueur)) {
                afficherGrille(grille);
                cout << "Le joueur " << joueur << " a gagne !" << endl;
                return 0; // Fin du jeu
            }

            // Passe au prochain joueur
            joueur = (joueur == 'X') ? 'O' : 'X';
        }
        else {
            cout << "Case invalide ou deja occupee. Veuillez reessayer." << endl;
        }
    }

    // Si aucune case n'est disponible et aucun joueur n'a gagné, c'est un match nul
    cout << "Match nul !" << endl;

    return 0;
}
