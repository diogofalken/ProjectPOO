// Projeto POO.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include "Grafo.h"

int main() {
    cout << "Start of program!" << endl;
	Grafo myGrafo;

	myGrafo.Load("grafo_1.txt","pessoas.txt");
	cout << "End of program!" << endl;
}
