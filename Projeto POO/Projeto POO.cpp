// Projeto POO.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include "Grafo.h"

int main() {
    cout << "Start of program!" << endl;
	Grafo myGrafo;

	myGrafo.Load("grafo1.txt","manco.txt");
	cout << "End of program!" << endl;
}
