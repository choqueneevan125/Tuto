#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>

using namespace std;

// Structure pour représenter une question et ses réponses
struct Question {
    string question;
    string reponses[4];
    int reponseCorrecte;
};

// Fonction pour poser une question
bool poserQuestion(Question q) {
    cout << q.question << endl;
    for (int i = 0; i < 4; ++i) {
        cout << i + 1 << ". " << q.reponses[i] << endl;
    }
    cout << "Votre réponse : ";
    int reponse;
    cin >> reponse;
    return reponse == q.reponseCorrecte;
}

int main() {
    // Initialisation du générateur de nombres aléatoires
    srand(time(0));

    // Liste de questions
    Question questions[20] = {
        {"Quelle est la capitale du Japon ?", {"Tokyo", "Pékin", "Séoul", "Bangkok"}, 1},
        {"Qui a écrit 'Romeo et Juliette' ?", {"William Shakespeare", "Charles Dickens", "Jane Austen", "Mark Twain"}, 1},
        {"Quel est l'élément chimique symbolisé par 'Fe' ?", {"Fer", "Fluor", "Argon", "Fossile"}, 1},
        {"Combien de continents y a-t-il sur Terre ?", {"5", "6", "7", "8"}, 2},
        {"Quelle est la plus grande planète du système solaire ?", {"Jupiter", "Saturne", "Uranus", "Neptune"}, 0},
        {"Qui a peint 'La Joconde' ?", {"Leonardo da Vinci", "Vincent van Gogh", "Pablo Picasso", "Claude Monet"}, 0},
        {"Quelle est la monnaie du Japon ?", {"Yen", "Dollar", "Euro", "Livre"}, 0},
        {"Combien de côtés a un hexagone ?", {"5", "6", "7", "8"}, 1},
        {"Quel est l'animal national de l'Australie ?", {"Kangourou", "Koala", "Dingo", "Émeu"}, 0},
        {"Quelle est la plus longue rivière du monde ?", {"Le Nil", "L'Amazone", "Le Mississippi", "Le Yangtsé"}, 1},
        // Ajoutez d'autres questions ici
        {"Quelle est la capitale de la France ?", {"Londres", "Paris", "Berlin", "Rome"}, 1},
        {"Quelle est la couleur du ciel par temps clair ?", {"Bleu", "Vert", "Rouge", "Jaune"}, 0},
        {"Quel est le symbole chimique de l'eau ?", {"H2O", "CO2", "O2", "HCl"}, 0},
        {"Combien de lettres compte l'alphabet français ?", {"25", "26", "27", "28"}, 1},
        {"Quel est l'instrument de mesure de la température ?", {"Thermomètre", "Baromètre", "Météoroscope", "Pèse-personne"}, 0},
        {"Quelle est la monnaie du Royaume-Uni ?", {"Euro", "Dollar", "Yen", "Livre"}, 3},
        {"Combien de couleurs y a-t-il dans un arc-en-ciel ?", {"5", "6", "7", "8"}, 2},
        {"Quel est le plus haut sommet du monde ?", {"Mont Everest", "Mont Kilimandjaro", "Mont Fuji", "Mont Blanc"}, 0},
        {"Quel est l'océan le plus vaste ?", {"Atlantique", "Pacifique", "Indien", "Arctique"}, 1},
        {"Qui a découvert l'Amérique ?", {"Christophe Colomb", "Marco Polo", "Vasco de Gama", "Ferdinand Magellan"}, 0}
    };

    // Variables pour le score et le nombre de questions posées
    int score = 0;
    int nombreQuestions = 0;

    // Boucle pour poser les questions
    for (int i = 0; i < 20; ++i) {
        // Choisir une question aléatoire
        int indexQuestion = rand() % 20;
        Question q = questions[indexQuestion];

        // Poser la question et vérifier la réponse
        if (poserQuestion(q)) {
            cout << "Bonne réponse !" << endl;
            score++;
        }
        else {
            cout << "Mauvaise réponse." << endl;
        }

        // Incrémenter le nombre de questions posées
        nombreQuestions++;
    }

    // Afficher le score final
    cout << "Fin du jeu !" << endl;
    cout << "Score final : " << score << "/" << nombreQuestions << endl;

    // Éteindre l'ordinateur si le score est inférieur à 10
    if (score < 10) {
        cout << "Votre score est trop bas. L'ordinateur va s'éteindre." << endl;
        // Code pour éteindre l'ordinateur
    }

    return 0;
}
