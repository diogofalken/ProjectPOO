#include "pch.h"
#include "Grafo.h"


Grafo::Grafo() {

}

Grafo::~Grafo() {

}

bool Grafo::Load(const string &fich_grafo, const string &fich_pessoas) {

}

int Grafo::ContarNos() {

}

int Grafo::ContarArcos() {
	return -1;
}

int Grafo::Memoria() {
	return -1;
}

list<int> *Grafo::NoMaisArcos() {
	return NULL;
}

bool Grafo::Adjacencia(int v1, int v2) {
	return false;
}

list<int> *Grafo::Caminho(int v1, int v2, double &custo_total) {
	return NULL;
}

list<int> *Grafo::VerticesIsolados() {
	return NULL;
}

bool Grafo::Search(int v) {
	return false;
}

bool Grafo::RemoverVertice(int v) {
	return false;
}

bool Grafo::RemoverAresta(int v1, int v2) {
	return false;
}

void Grafo::EscreverXML(const string &s) {

}

bool Grafo::LerXML(const string &s) {
	return false;
}

list<int> *Grafo::DevolveVerticesTipo(const string &tipo) {
	return NULL;
}

list<int> *Grafo::CaminhoMinimo(int v1, int v2, double &custo_total) {
	return NULL;
}

list<int> *Grafo::CaminhoMaximo(int v1, int v2, double &custo_total) {
	return NULL;
}

bool Grafo::PossivelCaminho(int v1, int v2, int TipoFronteira) {
	return false;
}

void Grafo::FronteirasMenosVisitadas(list<int> &Lv) {

}

void Grafo::SitiosInacessiveisAPartirDe(int V1, list<int> &Lv) {

}
