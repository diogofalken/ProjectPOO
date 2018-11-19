#pragma once
#include "pch.h"
#include "Fronteira.h"
#include "Arestas.h"

class Grafo {
private:
	unsigned int n_vertices;
	unsigned int n_arestas;
	// Usamos um map de modo a guardar o vertice e os caminhos possiveis atraves de uma lista (contem o vertice e o custo desse caminho)
	map<int, list<Arestas*>> myGrafo;
	list<Fronteira*> lista_fronteiras;

	// Da return de uma variavel do tipo Fronteira_vizinha criada tendo em conta o tipo de fronteira
	Arestas fronteira_arestas(int vertice, int x_pos, int y_pos, int tipo, int _custo = 0);

	// Encontra uma fronteira atraves do numero do vertice
	Fronteira* encontrarFronteira(int vertice);

	// Cria e retorna uma fronteira do tipo especificado
	Fronteira* fronteira_vertice_principal(int vertice, int x_pos, int y_pos, int tipo);

	// Mostra lista das fronteiras
	void mostrarFronteiras();

	// Mostra o grafo
	void mostrarGrafo();
	
	// Funcao recursiva para encontrar o caminho
	list<int> *Caminho(int source, int destination, list<int> visited, list<int> *caminho, double &custo_total);

	int CaminhoMaximo(int v1, int v2, vector<int> visited, list<int> *caminho, double &custo_total);

	int minDistance(vector<int> dist, vector<bool> sptSet);

	void CopiarCaminhoParent(vector<int> parent, int j, list<int> *caminho);
public:
	// Implemente o construtor do Grafo;
	Grafo();

	// Implemente o destrutor do Grafo;
	~Grafo();

	// Carregar os dados de ficheiros (do grafo e de pessoas);
	bool Load(const string &fich_grafo, const string &fich_pessoas);

	// Contar o numero de nos/fronteiras do grafo;
	int ContarNos();

	// Contar o numero de arestas/arcos do grafo;
	int ContarArcos();

	// Determinar toda a memoria ocupada;
	int Memoria();

	// Determinar qual o no/fronteira que tem mais arcos/aresta, se existirem vários devolve uma lista deles;
	list<int> *NoMaisArcos();

	// Verificar se um no é adjacente de outro nó do Grafo;
	bool Adjacencia(int v1, int v2);

	// Determinar um caminho(nao interessa se e o mais rapido!, e qualquer um!) de um no/fronteira para outro.... //devolvendo o custo total;
	list<int> *Caminho(int v1, int v2, double &custo_total);
	//bool Caminho(int v1, int v2, double &custo_total);

	// Determinar quais os vertices que estao isolados (Um vertice e se nao existe nenhum caminho ate ele!);
	list<int> *VerticesIsolados();

	// Verificar se um dado vertice existe
	bool Search(int v);

	// Remover um dado vertice, tambem sera necessario remover todas as arestas;
	bool RemoverVertice(int v);

	// Remover a aresta que liga 2 vertices;
	bool RemoverAresta(int v1, int v2);

	// Gravar para ficheiro em formato XML todas as informacoes do Grafo;
	void EscreverXML(const string &s);

	// Ler de um ficheiro em formato XML todo o Grafo (antes de ler deve ser apagado tudo o que estiver no Grafo); Se leu corretamente devolve //true, senão devolve false;
	bool LerXML(const string &s);

	// Devolver uma lista de todos os vertices/fronteiras de um dado tipo;
	list<int> *DevolveVerticesTipo(const string &tipo);

	// Determinar o caminho minimo entre 2 nos, devolvendo o custo total;
	list<int> *CaminhoMinimo(int source, int destination, double &custo_total);
	//int CaminhoMinimo(int v1, int v2, double &custo_total);
	
	// Determinar o caminho maximo entre 2 nos (passando somente uma vez em cada vertice), devolvendo o custo total;
	//list<int> *CaminhoMaximo(int v1, int v2, double &custo_total);
	void CaminhoMaximo(int v1, int v2, double &custo_total);

	// Sera possivel ir de uma fronteira(v1) a outra(v2), passando somente por fronteiras de um dado tipo?
	bool PossivelCaminho(int v1, int v2, int TipoFronteira);

	// Assumindo que todas as pessoas (do ficheiro) andaram em viagem, qual foi a fronteira com menos trafego/visitas? (No caso de serem varias,// deve devolver uma lista com as fronteiras);
	void FronteirasMenosVisitadas(list<int> &Lv);

	//Dada uma fronteira (v1), determinar todas as fronteiras onde nao e possivel chegar apartir de v1. Deve devolver uma lista dessas fronteiras!;
	void SitiosInacessiveisAPartirDe(int V1, list<int> &Lv);
};

