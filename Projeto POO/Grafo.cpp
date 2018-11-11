#include "pch.h"
#include "Grafo.h"
#include "Uteis.h"
#include "Arestas.h"
#include "FOficial.h"
#include "FTipo1.h"
#include "FTipo2.h"


#define DELIMITADOR_FICHEIRO "//-------------------"

//-------------------------------------------------------------------
//Método: Grafo
//Parametros:
// Entrada:
//
// Retorno:
//
//-------------------------------------------------------------------
Grafo::Grafo() {
	
}

//-------------------------------------------------------------------
//Método: Load
//Parametros:
// Entrada:
//     fich_grafo: Ficheiro dos dados do Grafo
//     fich_pessoas: Ficheiro das pessoas que querem fazer as viagens entre as fronteiras
// Retorno:
//    true/false, mediante a leitura correcta!
//-------------------------------------------------------------------
bool Grafo::Load(const string &fich_grafo, const string &fich_pessoas) {
	// Abrir o ficheiro
	ifstream in_file(fich_grafo);

	// Variaveis auxiliares
	string buffer, aux_buffer;
	int x, y, vertice, tipo, parametro = 0, index = 0;

	// Verificar se o ficheiro foi aberto corretamente  
	if (!Uteis::FicheiroAberto(&in_file)) {
		cout << "Nao foi possivel abrir o ficheiro " << fich_grafo << endl;
		return false;
	}

	// Retirar os vertices
	getline(in_file, buffer);
	n_vertices = atoi(buffer.c_str());

	// Retirar as arestas
	getline(in_file, buffer);
	n_arestas = atoi(buffer.c_str());

	while (!in_file.eof()) {
		getline(in_file, buffer);
		aux_buffer = buffer;
		stringstream ss(buffer);
		parametro = 0;
		
		// Se a string for igual ao Delimitador de Arestas/Vertices parar
		if (aux_buffer == DELIMITADOR_FICHEIRO) {
			break;
		}

		while (getline(ss, buffer, ';')) {
			stringstream aux(buffer);
			if (parametro == 0) {
				aux >> vertice;
			}
			if (parametro == 1) {
				aux >> x;
			}
			if (parametro == 2) {
				aux >> y;
			}
			if (parametro == 3) {
				aux >> tipo;
			}
			parametro++;
		}
		Fronteira *current = fronteira_vertice_principal(vertice, x, y, tipo);
		lista_fronteiras.push_back(current);
	}
	
	// Verificar se os vertices estao corretos no ficheiro
	// TODO: Depois MUDAR
	n_vertices = lista_fronteiras.size();
	if (lista_fronteiras.size() != n_vertices) {
		system("cls");
		cout << "Ficheiro nao esta com o formato certo" << endl;
		exit(1);
	}
	mostrarFronteiras();

	// Variaveis auxiliares para as arestas
	int vertice_origem, vertice_destino, _custo, aux_arestas = 0;
	while (!in_file.eof()) {
		getline(in_file, buffer);
		aux_buffer = buffer;
		stringstream ss(buffer);
		parametro = 0;

		while (getline(ss, buffer, ';')) {
			stringstream aux(buffer);
			if (parametro == 0) {
				aux >> vertice_origem;
			}
			if (parametro == 1) {
				aux >> vertice_destino;
			}
			if (parametro == 2) {
				aux >> _custo;
			}
			parametro++;
		}
		Arestas *aux = new Arestas();
		aux->setCusto(_custo);
		aux->setVertice(encontrarFronteira(vertice_destino));
		// Se o vertice nao existir
		if ( aux->getVertice()->getVertice() == NULL) {
			cout << "ERROR" << endl;
			exit(1);
		}
		myGrafo[vertice_origem].push_back(aux);
		
		// Colocar o mesmo caminho no vertice oposto
		Arestas *aux1 = new Arestas();
		aux1->setCusto(_custo);
		aux1->setVertice(encontrarFronteira(vertice_origem));
		myGrafo[vertice_destino].push_back(aux1);
		aux_arestas++;
	}

	// Verificar se as arestas estao corretas no ficheiro
	//TODO: DEPOIS MUDAR
	n_arestas = aux_arestas;
	if (aux_arestas != n_arestas) {
		system("cls");
		cout << "Ficheiro nao esta com o formato certo" << endl;
		exit(1);
	}

	/* TESTES */
	list<int> *lista_fronteiras_nos = NoMaisArcos();
	list<int> *lista_vertices_isolados = VerticesIsolados();
	list<int> *lista_vertices_tipo = DevolveVerticesTipo("1");

	//ShowGrafo
	mostrarGrafo();
	cout << "Vertices: " << ContarNos() << " Arestas: " << ContarArcos() << endl;
	cout << "vertices: " << lista_fronteiras.size() << " Arestas: " << aux_arestas << endl;
	cout << "Memoria ocupada (Bytes): " << Memoria() << endl;
	cout << "----------------------" << endl;
	cout << "Vertices com mais arcos" << endl;

	for (list<int>::iterator it = lista_fronteiras_nos->begin(); it != lista_fronteiras_nos->end(); it++) {
		cout << (*it) << endl;
	}

	if (Adjacencia(1,3) == true) {
		cout << "Sao adjacentes" << endl;
	}
	else {
		cout << "rekt" << endl;
	}

	if (Search(50) == true) {
		cout << "Existe" << endl;
	}
	else {
		cout << "Nao existe" << endl;
	}

	cout << "----------------------" << endl;
	for (list<int>::iterator it = lista_vertices_isolados->begin(); it != lista_vertices_isolados->end(); it++) {
		cout << (*it) << endl;
	}

	cout << "----------------------" << endl;
	for (list<int>::iterator it = lista_vertices_tipo->begin(); it != lista_vertices_tipo->end(); it++) {
		cout << (*it) << endl;
	}

	return NULL;
	delete(lista_fronteiras_nos);
	delete(lista_vertices_isolados);
	delete(lista_vertices_tipo);
}

//-------------------------------------------------------------------
//Método: ContarNos
//Parametros:
// Entrada:
//
// Retorno:
//    Numero de nos do grafo
//-------------------------------------------------------------------
int Grafo::ContarNos() {
	return n_vertices;
}

//-------------------------------------------------------------------
//Método: ContarArcos
//Parametros:
// Entrada:
//
// Retorno:
//    Numero de arcos/arestas do grafo
//-------------------------------------------------------------------
int Grafo::ContarArcos() {
	return n_arestas;
}

//-------------------------------------------------------------------
//Método: Memoria
//Parametros:
// Entrada:
//
// Retorno:
//    Quanta memoria está a ser ocupada pelo grafo
//-------------------------------------------------------------------
int Grafo::Memoria() {
	int memoria_ocupada = sizeof(Fronteira) * n_vertices + sizeof(Arestas) * n_arestas;
	return memoria_ocupada;
}

//-------------------------------------------------------------------
//Método: NoMaisArcos
//Parametros:
// Entrada:
//
// Retorno:
//    No/fronteira com mais arcos (se for mais que um da return numa lista)
//-------------------------------------------------------------------
list<int> *Grafo::NoMaisArcos() {
	list<int> *l_fronteiras = new list<int>;
	int vezes = 0, maior = 1;

	for (int i = 2; i < n_vertices; i++) {
		if (myGrafo[i].size() == myGrafo[maior].size()) {
			vezes++;
		}
		if (myGrafo[i].size() > myGrafo[maior].size()) {
			maior = i;
		}
	}

	if (!vezes) {
		l_fronteiras->push_back(maior);
		return l_fronteiras;
	}
	
	for (int i = 1; i < n_vertices; i++) {
		if (myGrafo[i].size() == myGrafo[maior].size()) {
			l_fronteiras->push_back(i);
		}
	}

	return l_fronteiras;
}

//-------------------------------------------------------------------
//Método: Adjancencia
//Parametros:
// Entrada:
//     v1: vertice 1
//     v2: vertice 2
// Retorno:
//    true/false, mediante serem adjacentes ou nao
//-------------------------------------------------------------------
bool Grafo::Adjacencia(int v1, int v2) {
	for (list<Arestas*>::iterator it = myGrafo[v1].begin(); it != myGrafo[v1].end(); it++) {
		if ((*it)->getVertice()->getVertice() == v2) {
			return true;
		}
	}
	return false;
}

//-------------------------------------------------------------------
//Método: Caminho
//Parametros:
// Entrada:
//     v1: vertice 1
//     v2: vertice 2
//	   custo_total: custo total entre o vertice 1 e o vertice 2
// Retorno:
//    caminho entre o vertice 1 e o vertice 2
//-------------------------------------------------------------------
list<int> *Grafo::Caminho(int v1, int v2, double &custo_total) {
	list<int> visitados;
	list<int> *caminho = new list<int>;
	int current = v1;
	// O inicio ja foi "visitado"
	visitados.push_back(v1);
	caminho->push_back(current);

	while (current != v2) {
		for (list<Arestas*>::iterator it = myGrafo[current].begin(); it != myGrafo[current].end(); it++) {
			if ((*it)->getVertice()->getVertice() == v2) {
				visitados.push_back(current);
				current = (*it)->getVertice()->getVertice();
				caminho->push_back(current);
			}
			else {

			}
		}
	}
	return caminho;
}

//-------------------------------------------------------------------
//Método: VerticesIsolados
//Parametros:
// Entrada:
//
// Retorno:
//    Lista de vertices isolados
//-------------------------------------------------------------------
list<int> *Grafo::VerticesIsolados() {
	list<int> *l_fronteiras = new list<int>;

	for (int i = 1; i <= n_vertices; i++) {
		if (!myGrafo[i].size()) {
			l_fronteiras->push_back(i);
		}
	}
	return l_fronteiras;
}

//-------------------------------------------------------------------
//Método: Search
//Parametros:
// Entrada:
//     v: vertice a procurar
// Retorno:
//    true/false, dependendo se encontra ou nao o vertice
//-------------------------------------------------------------------
bool Grafo::Search(int v) {
	for (list<Fronteira*>::iterator it = lista_fronteiras.begin(); it != lista_fronteiras.end(); it++) {
		if ((*it)->getVertice() == v) {
			return true;
		}
	}
	return false;
}

//-------------------------------------------------------------------
//Método: RemoverVertice
//Parametros:
// Entrada:
//	   v: vertice a procurar 
// Retorno:
//    true/false, dependendo se o vertice foi removido ou nao
//-------------------------------------------------------------------
bool Grafo::RemoverVertice(int v) {
	return false;
}

//-------------------------------------------------------------------
//Método: RemoverAresta
//Parametros:
// Entrada:
//	   v1: vertice 1
//	   v2: vertice 2
// Retorno:
//    true/false, dependendo se o aresta foi removida ou nao
//-------------------------------------------------------------------
bool Grafo::RemoverAresta(int v1, int v2) {
	return false;
}

//-------------------------------------------------------------------
//Método: EscreverXML
//Parametros:
// Entrada:
//	   s: Nome do ficheiro que se quer gravar as informacoes do grafo
// Retorno:
//
//-------------------------------------------------------------------
void Grafo::EscreverXML(const string &s) {

}

//-------------------------------------------------------------------
//Método: LerXML
//Parametros:
// Entrada:
//	   s: Nome do ficheiro que se quer ler as informacoes do grafo
// Retorno:
//    true/false, dependendo se o ficheiro foi lido ou nao
//-------------------------------------------------------------------
bool Grafo::LerXML(const string &s) {
	return false;
}

//-------------------------------------------------------------------
//Método: DevolveVerticesTipo
//Parametros:
// Entrada:
//	   tipo: tipo de vertice pretendido
// Retorno:
//    lista com os vertices do grafo do tipo pretendido
//-------------------------------------------------------------------
list<int> *Grafo::DevolveVerticesTipo(const string &tipo) {
	list<int> *lista_vertices_tipo = new list<int>;

	for (list<Fronteira*>::iterator it = lista_fronteiras.begin(); it != lista_fronteiras.end(); it++) {
		if ((*it)->getTipo() == atoi(tipo.c_str())) {
			lista_vertices_tipo->push_back((*it)->getVertice());
		}
	}
	return lista_vertices_tipo;
}

//-------------------------------------------------------------------
//Método: CaminhoMinimo
//Parametros:
// Entrada:
//	   v1: vertice 1
//	   v2: vertice 2
//	   custo_total: custo total entre os dois vertices
// Retorno:
//    lista dos vertices com o caminho mais curto entre v1 e v2
//-------------------------------------------------------------------
list<int> *Grafo::CaminhoMinimo(int v1, int v2, double &custo_total) {
	return NULL;
}

//-------------------------------------------------------------------
//Método: CaminhoMaximo
//Parametros:
// Entrada:
//	   v1: vertice 1
//	   v2: vertice 2
//	   custo_total: custo total entre os dois vertices
// Retorno:
//    lista dos vertices com o caminho maximo entre v1 e v2
//-------------------------------------------------------------------
list<int> *Grafo::CaminhoMaximo(int v1, int v2, double &custo_total) {
	return NULL;
}

//-------------------------------------------------------------------
//Método: PossivelCaminho
//Parametros:
// Entrada:
//	   v1: vertice 1
//	   v2: vertice 2
//	   TipoFronteira: tipo de uma fronteira
// Retorno:
//    true/falso, dependendo se existe caminho entre v1 e v2 por fronteiras do TipoFronteira
//-------------------------------------------------------------------
bool Grafo::PossivelCaminho(int v1, int v2, int TipoFronteira) {
	return false;
}

//-------------------------------------------------------------------
//Método: FronteirasMenosVisitadas
//Parametros:
// Entrada:
//	   Lv: Lista de viagens
// Retorno:
//
//-------------------------------------------------------------------
void Grafo::FronteirasMenosVisitadas(list<int> &Lv) {

}

//-------------------------------------------------------------------
//Método: SitiosInacessiveisAPartirDe
//Parametros:
// Entrada:
//	   v1: vertice 1
//	   Lv: Lista de viagens
// Retorno:
//
//-------------------------------------------------------------------
void Grafo::SitiosInacessiveisAPartirDe(int V1, list<int> &Lv) {

}

//-------------------------------------------------------------------
//Método: ~Grafo
//Parametros:
// Entrada:
//
// Retorno:
//
//-------------------------------------------------------------------
Grafo::~Grafo() {

}

/* ------------------------- Private Functions ------------------------- */
Arestas Grafo::fronteira_arestas(int vertice, int x_pos, int y_pos, int tipo, int _custo) {
	Arestas current;
	current.setCusto(_custo);

	// E uma fronteira do tipo Oficial
	if (tipo == 1) {
		FOficial aux(vertice, x_pos, y_pos);
		current.setVertice(&aux);
	}
	// E uma fronteira do tipo 1
	else if (tipo == 2) {
		FTipo1 aux(vertice, x_pos, y_pos);
		current.setVertice(&aux);
	}
	// E uma fronteira do tipo 2
	else if (tipo == 3) {
		FTipo2 aux(vertice, x_pos, y_pos);
		current.setVertice(&aux);
	}
	return current;
}
Fronteira* Grafo::encontrarFronteira(int vertice) {
	for (list<Fronteira*>::iterator it = lista_fronteiras.begin(); it != lista_fronteiras.end(); it++) {
		if ((*it)->getVertice() == vertice) {
			return *it;
		}
	}
	return NULL;
}

Fronteira* Grafo::fronteira_vertice_principal(int vertice, int x_pos, int y_pos, int tipo) {
	// E uma fronteira do tipo Oficial
	if (tipo == 1) {
		FOficial *aux = new FOficial(vertice, x_pos, y_pos);
		return (FOficial *)aux;
	}
	// E uma fronteira do tipo 1
	else if (tipo == 2) {
		FTipo1 *aux = new FTipo1(vertice, x_pos, y_pos);
		return (FTipo1 *)aux;
	}
	// E uma fronteira do tipo 2
	else if (tipo == 3) {
		FTipo2 *aux = new FTipo2(vertice, x_pos, y_pos);
		return (FTipo2 *)aux;
	}
	cout << "Ficheiro lido incorreto" << endl;
	exit(1);
}

void Grafo::mostrarFronteiras() {
	for (list<Fronteira*>::iterator it = lista_fronteiras.begin(); it != lista_fronteiras.end(); it++) {
		(*it)->Mostrar();
		cout << "//-----------------" << endl;
	}
}

void Grafo::mostrarGrafo() {
	for (int i = 1; i <= n_vertices; i++) {
		cout << "Caminhos para o vertice " << i << endl;
		for (list<Arestas*>::iterator it = myGrafo[i].begin(); it != myGrafo[i].end(); it++) {
			(*it)->Mostrar();
		}
		cout << "-----------------------------" << endl;
	}
}