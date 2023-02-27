// blackjackdefinitivo.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//
using namespace std;
//Librerias
#include <iostream>
#include <iostream>
#include <stdlib.h>
#include <windows.h>
#include<time.h>

//Variables
bool diamantes[13];

bool corazones[13];

bool treboles[13];

bool picas[13];


string title = "|| BIENVENIDO AL CASINO TO GOLFO ||";


int choosePalo;

int chooseNum;

//VARIABLES USER

string userName;

int userPoint = 0;

//VARIABLES CRUPIER

string nameCrupier = "Esteban";

int croupierPoint = 0;

//Funciones

void welcome() {
	cout << "\t \t\t\t\t "<< title << "\n\n";

	cout << "\tCual es tu nombre?: ";
	cin >> userName;

	cout << "\tComenzamos " << userName <<"\n\n";
}

void arrayValores(bool(&palos)[13]) {
	for (int i = 0; i < 13; i++)
	{
		palos[i] = true;
	}
}

void checkNum (string name, int& card, int& point, string palo) {
	int valorA;
	if (name == "Esteban") {
		if (card == 0)
		{
			if (point + 11 > 21)
			{
				point += 1;
			}
			else
			{
				point += 11;
			}
		}
		else if (card >= 10 && card <= 12)
		{
			if (card == 10)
			{
				cout << "\n\tA  " << name << " le ha tocado una J" << " de " << palo << "\n\n";
			}
			else if (card == 11)
			{
				cout << "\n\tA  " << name << " le ha tocado una Q" << " de " << palo << "\n\n";
			}
			else if (card == 12)
			{
				cout << "\n\tA  " << name << " le ha tocado una K" << " de " << palo << "\n\n";
			}
			point += 10;

		}
		else
		{
			cout << "\n\tA " << name << " le ha tocado " << card + 1 << " de " << palo << "\n\n";
			point += card + 1;

		}
	}
	else{
		if (card == 0)
		{
			cout << "\n\tTe ha tocado un AS de " << palo << "\n\t\tQue valor quieres asignar ? : ";
			cin >> valorA;
			if (valorA == 1)
			{
				point += 1;

			}
			else if (valorA == 11)
			{
				point += 11;

			}
		}
		else if (card >= 10 && card <= 12)
		{
			if (card == 10)
			{
				cout << "\n\tA  " << name << " le ha tocado una J" << " de " << palo << "\n\n";
			}
			else if (card == 11)
			{
				cout << "\n\tA  " << name << " le ha tocado una Q" << " de " << palo << "\n\n";
			}
			else if (card == 12)
			{
				cout << "\n\tA  " << name << " le ha tocado una K" << " de " << palo << "\n\n";
			}
			point += 10;

		}
		else
		{
			cout << "\n\tA " << name << " le ha tocado " << card + 1 << " de " << palo << "\n\n";
			point += card + 1;

		}
		}
	}

void avalibleCard(int& card, string& palo) {
	srand(time(NULL));
	int choosePalo = rand() % 4;

	int chooseNum = rand() % (13);

	bool disponible = true;

	while (disponible)
	{
		if (choosePalo == 0 && diamantes[chooseNum] == true)
		{
			diamantes[chooseNum] = false;
			card = chooseNum;
			palo = " Diamante";
		
			disponible = false;
		}
		else if (choosePalo == 1 && picas[chooseNum] == true)
		{
			picas[chooseNum] = false;
			card = chooseNum;
			palo = " Picas";
			disponible = false;
		}
		else if (choosePalo == 2 && treboles[chooseNum] == true)
		{
			treboles[chooseNum] = false;
			card = chooseNum;
			palo = " Treboles";
			disponible = false;
		}
		else if (choosePalo == 3 && corazones[chooseNum] == true)
		{
			corazones[chooseNum] = false;
			card = chooseNum;
			palo = " Corazones";
			disponible = false;
		}
		else
		{
			choosePalo = rand() % 4;

			chooseNum = rand() % (13);

		}
	}
}

int main()
{
	welcome();

	arrayValores(diamantes);
	arrayValores(treboles);
	arrayValores(corazones);
	arrayValores(picas);

	int valor;

	string palo;

	cout << "\n\tRepartimos las primeras cartas\n\n";

	for (size_t i = 0; i < 2; i++)
	{
		avalibleCard(valor, palo);

		checkNum(userName, valor, userPoint, palo);
	}

	avalibleCard(valor, palo);
	checkNum(nameCrupier ,valor, croupierPoint, palo);

	cout << "\n\tCrupier tiene " << croupierPoint;

	bool userPlays = true;

	while (userPlays)
	{
		cout << "\n\t\tQuieres otra carta? [1]Si / [2]No: ";
		int option;
		cin >> option;
		if (option == 1)
		{
			avalibleCard(valor, palo);
			checkNum(userName, valor, userPoint, palo);
		}
		else
		{
			userPlays = false;
		}
		
	}


	bool crupierPlays = true;

	while (croupierPoint < 21 && crupierPlays)
	{
		if (croupierPoint < 18)
		{
			avalibleCard(valor, palo);
			checkNum(nameCrupier, valor, croupierPoint, palo);
		}
		else
		{
			crupierPlays = false;
		}
	}

	cout << "\n\tEl crupier tiene " << croupierPoint << " puntos\n\n";

	cout << "\n\tEl " << userName<<" tiene " << userPoint << " puntos\n\n";

	bool userWin = true;

	bool empate = false;

	if (userPoint > 21)
	{
		userWin = false;
	}
	else if (croupierPoint > 21)
	{
		userWin = true;
	}
	else if (userPoint > croupierPoint && userPoint <= 21)
	{
		userWin = true;
	}
	else if (croupierPoint > userPoint && croupierPoint <= 21)
	{
		userWin = false;
	}

	if (userWin && !empate)
	{
		cout <<"\t\t" << userName << " ha ganado";
	}
	else if (!userWin && !empate)
	{
		cout << "\t\t" << userName << " ha perdido";
	}
	else
	{
		cout << "\t\t" << "Han empatado";
	}

}
