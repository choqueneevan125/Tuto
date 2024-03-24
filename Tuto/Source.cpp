#include <iostream>
#include <iomanip>
#include <windows.h>
using namespace std;
// Les signature = 8 fonction
void ShowResult(double result);
double addition();
double retirer();
double multiply();
double diviser();
double reset();
void Calculator();
void TemperatureConvert();
void VitessteCovert();
void VitesseCalcul();
void NonbreaDeviner();


int main() {
	double result = 0;
	int choise;

	do
	{
		std::cout << "1. Voir le resultat\n";
		std::cout << "2. Ajouter\n";
		std::cout << "3. Retirer\n";
		std::cout << "4. multiplier\n";
		std::cout << "5. Diviser\n";
		std::cout << "6. remettre a zero\n";
		std::cout << "7. Calculatrice\n";
		std::cout << "8. Conversion de temperature\n";
		std::cout << "9. Conversion de vitesse\n";
		std::cout << "10 Calcul de vitesse\n";
		cout << "11. quitter\n";

		// user inputs
		std::cin >> choise;

		switch (choise)
		{
			// Affiche le resultat
		case 1: ShowResult(result);
			break;
			//  addition de la varible qui est dans la fonction addition
		case 2: result += addition();
			// Montre le resultat
				ShowResult(result);
				break;
				//  soustraction de la varible qui est dans la fonction retirer
		case 3: result -= retirer();
			// Montre le resultat
			ShowResult(result);
			break;
			//  multiplication de la varible qui est dans la fonction multiply
		case 4: result *= multiply();
			// Montre le resultat
			ShowResult(result);
			break;
			//  division de la varible qui est dans la fonction diviser
		case 5: result /= diviser();
			// Montre le resultat
			ShowResult(result);
			break;
			// Remet a zero l variable result
		case 6: result = reset();
			// Montre le resultat
			ShowResult(result);
			break;
			// execute le code Calculator
		case 7: Calculator();
			break;
		case 8: TemperatureConvert();
			break;
			// Affiche un texte et quitte le logiciel
		case 9: VitessteCovert();
			break;
		case 10: VitesseCalcul();
			break;
		case 11: NonbreaDeviner();
			break;
		case 12: std::cout << "Au revoir";
			// Fais un temp de pose
			Sleep(500);
			break;
		default: cout << "Error\n";
			break;

		}
		//Si ce n'est pas egal a 8 on continu
	} while (choise != 12);

}

// La definition de fonction
// Affiche le resultat
void ShowResult(double result) {
	std::cout << "Le resultat est " << std::setprecision(2) << std::fixed << result << '\n';
	

}
//Met le nombre des addition dans une variable
double addition() {
	double amont = 0;
	std::cout << "Entrer une valeur: ";
	std::cin >> amont;
	return amont;
}
//Met le nombre des soustraction dans une variable
double retirer() {
	double amont = 0;
	std::cout << "Entrer une valeur: ";
	std::cin >> amont;
	return amont;

}
//Met le nombre des multiplication dans une variable
double multiply() {
	double amont = 0;
	std::cout << "Entrer une valeur: ";
	std::cin >> amont;
	return amont;

}
//Met le nombre des divisions dans une variable
double diviser() {
	double amont = 0;
	std::cout << "Entrer une valeur: ";
	std::cin >> amont;
	return amont;

}
//Met le nombre 0 dans une variable
double reset() {
	double amont = 0;
	return amont;

}
// Petite calculatrice console (Vous pouvez faire ca avec n'importe quoi)
void Calculator() {
	// Variable
	char op;
	double num1{};
	double num2{};
	double result;
	// execute en boucle le code
	do
	{
		std::cout << "********* CALCULATOR *********\n";
		std::cout << "Enter either (+ - * /ou e pour revenir au menu): ";
		std::cin >> op;
		// Si
		if (op != 'e' && op != 'E' && op == '+' || op == '-' || op == '*' || op == '/')
		{
			std::cout << "Enter #1 : ";
			std::cin >> num1;
			std::cout << "Enter #2 : ";
			std::cin >> num2;

		}

		switch (op)
		{
		case '+':
			// Addition
			result = num1 + num2;
			cout << '\n';
			std::cout << "Le resultat est " << result << '\n';
			break;
		case '-':
			// Soustraction
			result = num1 - num2;
			cout << '\n';
			std::cout << "Le resultat est " << result << '\n';
			break;
			// multiplication
		case '*':
			result = num1 * num2;
			cout << '\n';
			std::cout << "Le resultat est " << result << '\n';
			break;
			// Division
		case '/':
			result = num1 / num2;
			cout << '\n';
			std::cout << "Le resultat est " << result << '\n';
			break;
			// Retour au menu
		case 'e': case 'E': std::cout << "Au revoir";
			cout << '\n';
			break;

		}

	} while (op != 'e' && op != 'E');
	
}
// Code de conversion de température
void TemperatureConvert()
{
	double temp;
	char unit;

	do
	{
		cout << "***** Temperature conversion *****\n";
		cout << "F = Fahrenheit\n";
		cout << "C = Celsius\n";
		cout << "Pour quitter appuyer sue E\n";
		cout << "What unit would you like to convert to: ";
		cin >> unit;

		if (unit == 'F' || unit == 'f')
		{
			cout << "Enter the temperature in celcius: ";
			cin >> temp;

			temp = (1.8 * temp) + 32.0;
			cout << '\n';
			cout << "Temperature is: " << temp << " F\n";
			cout << "************************************\n";

		}

		else if (unit == 'C' || unit == 'c')
		{
			cout << "Enter the temperature in Fahrenheit: ";
			cin >> temp;

			temp = (temp - 32) / 1.8;
			cout << '\n';
			cout << "Temperature is: " << temp << " C\n";
			cout << "************************************\n";

		}
		else if (unit == 'E' || unit == 'e')
		{
			std::cout << "Au revoir\n";
			cout << "************************************\n";
			Sleep(500);

		}
		else {
			cout << "Please enter in only C or F\n";
		}

	} while (unit != 'E' && unit != 'e');
}

void VitessteCovert()
{
	double vitesse;
	char unit;

	do
	{
		cout << "***** Temperature conversion *****\n";
		cout << "M = m/s\n";
		cout << "K = km/h\n";
		cout << "Pour quitter appuyer sue E\n";
		cout << "What unit would you like to convert to: ";
		cin >> unit;

		if (unit == 'M' || unit == 'm')
		{
			cout << "Entrer une vitesse en km/h: ";
			cin >> vitesse;

			vitesse = vitesse / 3.6;
			cout << '\n';
			cout << "Votre vitesse est: " << vitesse << " m/s\n";
			cout << 'n';

		}

		else if (unit == 'K' || unit == 'k')
		{
			cout << "Entrer une vitesse en m/s: ";
			cin >> vitesse;

			vitesse = vitesse * 3.6;
			cout << '\n';
			cout << "Votre vitesse est: " << vitesse << " km/h\n";
			cout << '\n';
		}

		else if (unit == 'E' || unit == 'e')
		{
			std::cout << "Au revoir\n";
			cout << "************************************\n";
			Sleep(500);
		}
		else {
			cout << "Please enter in only K or M\n";
		}

	} while (unit != 'E' && unit != 'e');


}

void VitesseCalcul()
{
	double vitesse;
	double temp;
	double distance;
	char choise;

	do
	{
		cout << "Calcul de vitesse\n";
		cout << "V. Vitesse\n";
		cout << "t. temp\n";
		cout << "d. distance\n";
		cout << "e. retour au menu\n";
		cout << "Quelle est votre choix: ";
		cin >> choise;

		if (choise == 'v' || choise == 'V')
		{
			cout << "Quelle est la distance: (en km) ";
			cin >> distance;
			cout << "En combien de temp (en heure): ";
			cin >> temp;
			vitesse = distance / temp;
			cout << '\n';
			cout << "La vitesse moyenne est " << vitesse << " km/h\n";
			cout << '\n';
		}

		else if (choise == 't' || choise == 'T')
		{
			cout << "Quelle est votre vitesse (en km/h): ";
			cin >> vitesse;
			cout << "Quelle est la distance (en km): ";
			cin >> distance;

			temp = distance / vitesse;
			cout << '\n';
			cout << "Le temp = " << temp << " h\n";
			cout << '\n';
		}

		else if (choise == 'd' || choise == 'D')
		{
			cout << "Quelle est votre vitesse (en km/h): ";
			cin >> vitesse;
			cout << "Quelle est votre temp (en heure): ";
			cin >> temp;

			distance = vitesse * temp;
			cout << '\n';
			cout << "La distance est = " << distance << " km\n";
			cout << '\n';
		}
		else if (choise == 'e' || choise == 'E')
		{
			cout << "Retour au menu\n";
			cout << '\n';
		}
		else
		{
			cout << "Error\n";
			cout << '\n';
		}

	} while (choise != 'e' && choise != 'E');
}

void NonbreaDeviner()
{
	srand(time(0));

	// Génération d'un nombre aléatoire entre 1 et 100
	int nombreADeviner = rand() % 100 + 1;

	int tentative;
	int essais = 0;
	bool trouve = false;

	cout << "Bienvenue dans le jeu de devinette !\n";
	cout << "Devinez le nombre entre 1 et 100.\n";

	do {
		cout << "Entrez votre proposition : ";
		cin >> tentative;
		essais++;

		if (tentative < nombreADeviner) {
			cout << "Le nombre mystere est plus grand !\n";
		}
		else if (tentative > nombreADeviner) {
			cout << "Le nombre mystere est plus petit !\n";
		}
		else {
			trouve = true;
		}
	} while (!trouve);

	cout << "Bravo ! Vous avez devine le nombre mystere en " << essais << " essais.\n";

	
}

// Le prochain tuto sera d'améliorer le code et d'ajouter de nouveaux contenue, on va commencer maintenant par ajouter la fonction
// Le tuto n°4 on va crée un jeu de console en ajoutant une nouvelle fonction qui va s'appeller Games
// Le tuto n°5 consistera a apprendre les base du C++
// Le tuto n°6 consisterra a compiler le code C++ et retrouver son executable

// Petit tuto pour commenter il faut mettre 2 slash et son commentaire
// Et pour commenter sur plusieur ligne c'est slash et axterix puis a la derniere ligne du commentaire c'est asterix et slash

/*
	Exemple de commentaire
	Hello
*/

// Exemple de commentaire

