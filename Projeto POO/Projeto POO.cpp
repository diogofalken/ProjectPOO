// Projeto POO.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include "Grafo.h"

int main() {
    cout << "Start of program!" << endl;
	Grafo myGrafo;

	myGrafo.Load("grafo_2.txt","pessoas.txt");

	///* TESTES */
	//list<int> *lista_fronteiras_nos = myGrafo.NoMaisArcos();

	////ShowGrafo
	////myGrafo.mostrarGrafo();
	//cout << "Vertices: " << myGrafo.ContarNos() << " Arestas: " << myGrafo.ContarArcos() << endl;
	//cout << "Memoria ocupada (Bytes): " << myGrafo.Memoria() << endl;
	//cout << "----------------------" << endl;
	//cout << "Vertices com mais arcos" << endl;

	//for (list<int>::iterator it = lista_fronteiras_nos->begin(); it != lista_fronteiras_nos->end(); it++) {
	//	cout << (*it) << endl;
	//}

	//if (myGrafo.Adjacencia(1, 3) == true) {
	//	cout << "Sao adjacentes" << endl;
	//}
	//else {
	//	cout << "rekt" << endl;
	//}
	
	cout << "End of program!" << endl;
}
