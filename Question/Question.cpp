#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>

using namespace std;

// Structure pour repr�senter une question et ses r�ponses
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
    cout << "Votre r�ponse : ";
    int reponse;
    cin >> reponse;
    return reponse == q.reponseCorrecte;
}

int main() {
    // Initialisation du g�n�rateur de nombres al�atoires
    srand(time(0));

    // Liste de questions
    Question questions[20] = {
        {"Quelle est la capitale du Japon ?", {"Tokyo", "P�kin", "S�oul", "Bangkok"}, 1},
        {"Qui a �crit 'Romeo et Juliette' ?", {"William Shakespeare", "Charles Dickens", "Jane Austen", "Mark Twain"}, 1},
        {"Quel est l'�l�ment chimique symbolis� par 'Fe' ?", {"Fer", "Fluor", "Argon", "Fossile"}, 1},
        {"Combien de continents y a-t-il sur Terre ?", {"5", "6", "7", "8"}, 2},
        {"Quelle est la plus grande plan�te du syst�me solaire ?", {"Jupiter", "Saturne", "Uranus", "Neptune"}, 0},
        {"Qui a peint 'La Joconde' ?", {"Leonardo da Vinci", "Vincent van Gogh", "Pablo Picasso", "Claude Monet"}, 0},
        {"Quelle est la monnaie du Japon ?", {"Yen", "Dollar", "Euro", "Livre"}, 0},
        {"Combien de c�t�s a un hexagone ?", {"5", "6", "7", "8"}, 1},
        {"Quel est l'animal national de l'Australie ?", {"Kangourou", "Koala", "Dingo", "�meu"}, 0},
        {"Quelle est la plus longue rivi�re du monde ?", {"Le Nil", "L'Amazone", "Le Mississippi", "Le Yangts�"}, 1},
        // Ajoutez d'autres questions ici
        {"Quelle est la capitale de la France ?", {"Londres", "Paris", "Berlin", "Rome"}, 1},
        {"Quelle est la couleur du ciel par temps clair ?", {"Bleu", "Vert", "Rouge", "Jaune"}, 0},
        {"Quel est le symbole chimique de l'eau ?", {"H2O", "CO2", "O2", "HCl"}, 0},
        {"Combien de lettres compte l'alphabet fran�ais ?", {"25", "26", "27", "28"}, 1},
        {"Quel est l'instrument de mesure de la temp�rature ?", {"Thermom�tre", "Barom�tre", "M�t�oroscope", "P�se-personne"}, 0},
        {"Quelle est la monnaie du Royaume-Uni ?", {"Euro", "Dollar", "Yen", "Livre"}, 3},
        {"Combien de couleurs y a-t-il dans un arc-en-ciel ?", {"5", "6", "7", "8"}, 2},
        {"Quel est le plus haut sommet du monde ?", {"Mont Everest", "Mont Kilimandjaro", "Mont Fuji", "Mont Blanc"}, 0},
        {"Quel est l'oc�an le plus vaste ?", {"Atlantique", "Pacifique", "Indien", "Arctique"}, 1},
        {"Qui a d�couvert l'Am�rique ?", {"Christophe Colomb", "Marco Polo", "Vasco de Gama", "Ferdinand Magellan"}, 0}
    };

    // Variables pour le score et le nombre de questions pos�es
    int score = 0;
    int nombreQuestions = 0;

    // Boucle pour poser les questions
    for (int i = 0; i < 20; ++i) {
        // Choisir une question al�atoire
        int indexQuestion = rand() % 20;
        Question q = questions[indexQuestion];

        // Poser la question et v�rifier la r�ponse
        if (poserQuestion(q)) {
            cout << "Bonne r�ponse !" << endl;
            score++;
        }
        else {
            cout << "Mauvaise r�ponse." << endl;
        }

        // Incr�menter le nombre de questions pos�es
        nombreQuestions++;
    }

    // Afficher le score final
    cout << "Fin du jeu !" << endl;
    cout << "Score final : " << score << "/" << nombreQuestions << endl;

    // �teindre l'ordinateur si le score est inf�rieur � 10
    if (score < 10) {
        cout << "Votre score est trop bas. L'ordinateur va s'�teindre." << endl;
        // Code pour �teindre l'ordinateur
    }

    return 0;
}
