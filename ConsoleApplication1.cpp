//lIBRERIAS

#include <iostream>
#include <stdlib.h>
#include <windows.h>
#include<time.h>

//std

using namespace std;

//VARIABLES GLOBALES

int diamantes[13];

int corazones[13];

int treboles[13];

int picas[13];


string title = "|| Bienvendio al CASINO TO GOLFO ||";


int choosePalo;

int chooseNum;

bool disponible = true;

//VARIABLES USER


string userName;

int userPoint = 0;

//VARIABLES CRUPIER

string nameCrupier = "Esteban";

int croupierPoint = 0;

int crupierPlaying = 0;

void arrayValores(int(&palos)[13]) {
	for (int i = 0; i < 13; i++)
	{
		palos[i] = 1;
	}
}
void welcome(string& name) {
	cout << title;
	cout << "Como te llamas?: ";
	cin >> name;

}
int repartirCartasUser(int& points, string name) {

	int choosePalo = rand() % 4;

	int chooseNum = rand() % (13);


	do {
		if (choosePalo == 0 && diamantes[chooseNum] == 1) {
			diamantes[chooseNum] = 0;
		}
		else if (choosePalo == 1 && picas[chooseNum] == 1) {
			picas[chooseNum] = 0;

		}
		else if (choosePalo == 2 && treboles[chooseNum] == 1) {
			treboles[chooseNum] = 0;

		}
		else if (choosePalo == 3 && corazones[chooseNum] == 1) {
			corazones[chooseNum] = 0;
		}
		else
		{
			disponible = false;
			choosePalo = rand() % 4;
			chooseNum = rand() % (13);
		}
	} while (disponible);

	int valor;
		if (chooseNum == 0) {
			cout << " Que valor quieres? :";
			
			cin >> valor;
			if (valor == 11) {
				valor = 11;
			}
			else {
				valor = 1;
			}
		}
		else if (chooseNum >= 1 && chooseNum <= 9) {
			valor = chooseNum + 1;

		}
		else if (chooseNum >= 10) {

			valor = 10;
		}



	switch (choosePalo)
	{
	case 0: {
		if (chooseNum == 0) {
			cout << "\nAl " << name << " le ha tocado un A de Diamantes \n";
		}
		else if (chooseNum == 10)
		{
			cout << "\nAl " << name << " le ha tocado un J de Diamantes \n";
		}
		else if (chooseNum == 11)
		{
			cout << "\nAl " << name << " le ha tocado un Q de Diamantes \n";
		}
		else if (chooseNum == 12)
		{
			cout << "\nAl " << name << " le ha tocado un K de Diamantes \n";
		}
		else
		{
			cout << "\nAl " << name << " le ha tocado " << (chooseNum + 1) << " de Diamante";
		}
		points += chooseNum;
		break;
	}
	case 1: {
		if (chooseNum == 0) {
			cout << "\nAl " << name << " le ha tocado un A de Picas \n";
		}
		else if (chooseNum == 10)
		{
			cout << "\nAl " << name << " le ha tocado un J de Picas \n";
		}
		else if (chooseNum == 11)
		{
			cout << "\nAl " << name << " le ha tocado un Q de Picas \n";
		}
		else if (chooseNum == 12)
		{
			cout << "\nAl " << name << " le ha tocado un K de Picas \n";
		}
		else
		{
			cout << "\nAl " << name << " le ha tocado " << (chooseNum + 1) << " de Picas";
		}
		points += chooseNum;
		break;
	}
	case 2: {
		if (chooseNum == 0) {
			cout << "\nAl " << name << " le ha tocado un A de Treboles \n";
		}
		else if (chooseNum == 10)
		{
			cout << "\nAl " << name << " le ha tocado un J de Treboles \n";
		}
		else if (chooseNum == 11)
		{
			cout << "\nAl " << name << " le ha tocado un Q de Treboles \n";
		}
		else if (chooseNum == 12)
		{
			cout << "\nAl " << name << " le ha tocado un K de Treboles \n";
		}
		else
		{
			cout << "\nAl " << name << " le ha tocado " << (chooseNum + 1) << " de Treboles";
		}
		points += chooseNum;
		break;
	}
	case 3: {
		if (chooseNum == 0) {
			cout << "\nAl " << name << " le ha tocado un A de Corazones \n";
		}
		else if (chooseNum == 10)
		{
			cout << "\nAl " << name << " le ha tocado un J de Corazones \n";
		}
		else if (chooseNum == 11)
		{
			cout << "\nAl " << name << " le ha tocado un Q de Corazones \n";
		}
		else if (chooseNum == 12)
		{
			cout << "\nAl " << name << " le ha tocado un K de Corazones \n";
		}
		else
		{
			cout << "\nAl " << name << " le ha tocado " << (chooseNum + 1) << " de Corazones";
		}
		points += chooseNum;
		break;
	}


	default:
		break;
	}
	return points;
}

int repartirCartasCrupier(int& points, string name) {
	int choosePalo = rand() % 4;

	int chooseNum = rand() % (13);


	do {
		if (choosePalo == 0 && diamantes[chooseNum] == 1) {
			diamantes[chooseNum] = 0;
		}
		else if (choosePalo == 1 && picas[chooseNum] == 1) {
			picas[chooseNum] = 0;

		}
		else if (choosePalo == 2 && treboles[chooseNum] == 1) {
			treboles[chooseNum] = 0;

		}
		else if (choosePalo == 3 && corazones[chooseNum] == 1) {
			corazones[chooseNum] = 0;
		}
		else
		{
			disponible = false;
			choosePalo = rand() % 4;
			chooseNum = rand() % (14);
		}
	} while (disponible);

	int valor;
	if (chooseNum == 0) {
		cout << " Que valor quieres? :";

		cin >> valor;
		if (valor == 11) {
			valor = 11;
		}
		else {
			valor = 1;
		}
	}
	else if (chooseNum >= 1 && chooseNum <= 9) {
		valor = chooseNum + 1;

	}
	else if (chooseNum >= 10) {

		valor = 10;
	}



	switch (choosePalo)
	{
	case 0: {
		if (chooseNum == 0) {
			cout << "\nAl " << name << " le ha tocado un A de Diamantes \n";
		}
		else if (chooseNum == 10)
		{
			cout << "\nAl " << name << " le ha tocado un J de Diamantes \n";
		}
		else if (chooseNum == 11)
		{
			cout << "\nAl " << name << " le ha tocado un Q de Diamantes \n";
		}
		else if (chooseNum == 12)
		{
			cout << "\nAl " << name << " le ha tocado un K de Diamantes \n";
		}
		else
		{
			cout << "\nAl " << name << " le ha tocado " << (chooseNum + 1) << " de Diamante";
		}
		points += chooseNum;
		break;
	}
	case 1: {
		if (chooseNum == 0) {
			cout << "\nAl " << name << " le ha tocado un A de Picas \n";
		}
		else if (chooseNum == 10)
		{
			cout << "\nAl " << name << " le ha tocado un J de Picas \n";
		}
		else if (chooseNum == 11)
		{
			cout << "\nAl " << name << " le ha tocado un Q de Picas \n";
		}
		else if (chooseNum == 12)
		{
			cout << "\nAl " << name << " le ha tocado un K de Picas \n";
		}
		else
		{
			cout << "\nAl " << name << " le ha tocado " << (chooseNum + 1) << " de Picas";
		}
		points += chooseNum;
		break;
	}
	case 2: {
		if (chooseNum == 0) {
			cout << "\nAl " << name << " le ha tocado un A de Treboles \n";
		}
		else if (chooseNum == 10)
		{
			cout << "\nAl " << name << " le ha tocado un J de Treboles \n";
		}
		else if (chooseNum == 11)
		{
			cout << "\nAl " << name << " le ha tocado un Q de Treboles \n";
		}
		else if (chooseNum == 12)
		{
			cout << "\nAl " << name << " le ha tocado un K de Treboles \n";
		}
		else
		{
			cout << "\nAl " << name << " le ha tocado " << (chooseNum + 1) << " de Treboles";
		}
		points += chooseNum;
		break;
	}
	case 3: {
		if (chooseNum == 0) {
			cout << "\nAl " << name << " le ha tocado un A de Corazones \n";
		}
		else if (chooseNum == 10)
		{
			cout << "\nAl " << name << " le ha tocado un J de Corazones \n";
		}
		else if (chooseNum == 11)
		{
			cout << "\nAl " << name << " le ha tocado un Q de Corazones \n";
		}
		else if (chooseNum == 12)
		{
			cout << "\nAl " << name << " le ha tocado un K de Corazones \n";
		}
		else
		{
			cout << "\nAl " << name << " le ha tocado " << (chooseNum + 1) << " de Corazones";
		}
		points += chooseNum;
		break;
	}


	default:
		break;
	}
	return points;
}


int main() {


	srand(time(NULL));

	bool userPlays = true;
	bool crupierPlay = true;

	//INICIO DEL BLACKJACK Y BIENVENIDA


	welcome(userName);

	for (int i = 0; i < 2; i++)
	{
		userPoint = repartirCartasUser(userPoint, userName);
	}

	croupierPoint = repartirCartasCrupier(croupierPoint, nameCrupier);
	cout << croupierPoint;

	while (userPlays) {
		cout << "\nQuieres otra carta? [1] Si / [2] No : ";
		int option;
		cin >> option;
		if (option == 2) {
			cout << "\nFin de tu turno\n";
			userPlays = false;
		}
		else {
			userPoint = repartirCartasUser(userPoint, userName);
		}
	}

	while (crupierPlay && croupierPoint < 21) {
		if (croupierPoint < 18) {
			croupierPoint = repartirCartasCrupier(croupierPoint, nameCrupier);
		}
		else {
			crupierPlay = false;
		}
	}

	cout << userName << "\n tiene " << userPoint << " puntos\n";
	cout << nameCrupier << " \ntiene " << croupierPoint << " puntos\n";


	if (userPoint > croupierPoint || (croupierPoint > 21 && userPoint < 21)) {
		cout << userName << " ha ganado";
	}
	else if (userPoint < croupierPoint || (croupierPoint < 21 || userPoint > 21)) {
		cout << userName << " ha perdido";
	}
	else
	{
		cout << "Empate";
	}
}

