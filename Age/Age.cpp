#include <iostream>

bool varible();
void ShowVariable();
float showValeur();


int main() {

	std::cout << showValeur() << '\n';

	do
	{
		ShowVariable();

	} while (true);
}

bool varible()
{
	bool variable{};
	int choise;
	std::cout << "Veuillez mettre un ou deux ";
	std::cin >> choise;
	if (choise == 1)
	{
		variable = true;
	}
	else if (choise == 2)
	{
		variable = false;
	}
	else
	{
		std::cout << "Veuillez mettre un ou deux";
	}
	return variable;
}

void ShowVariable()
{
	bool variable = varible();
	if (variable)
	{
		std::cout << "La variable est true\n";
	}
	else
	{
		std::cout << "La variable est false\n";
	}

}

float showValeur()
{
	float valeur = 80.567f;
	return valeur;
}
