#include "pch.h"
#include "Grafo.h"
#include "Uteis.h"
#include "Arestas.h"
#include "FOficial.h"
#include "FTipo1.h"
#include "FTipo2.h"
#include "XMLWriter.h"

#include <vector>
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
	for (int i = 1; i <= n_vertices; ++i) {
		myGrafo[i].push_back(NULL);
		myGrafo[i].remove(NULL);
	}

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
		if (aux->getVertice()->getVertice() == NULL) {
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
	/*
	if (RemoverVertice(1)) {
		cout << "Foi removida a aresta 1 - 2" << endl;
	}
	else {
		cout << "NAO FOI REMOVIDA" << endl;
	}*/

	EscreverXML("grafo.xml");
	/* TESTES */
	list<int> *lista_fronteiras_nos = NoMaisArcos();
	list<int> *lista_vertices_isolados = VerticesIsolados();
	list<int> *lista_vertices_tipo = DevolveVerticesTipo("1");
	double custo = 0, custo_minimo = 0, custo_maximo = 0;
	list<int> *lista_caminho = Caminho(4, 13, custo);
	list<int> *caminho_curto = CaminhoMinimo(5, 15, custo_minimo);
	list<int> *caminho_maximo = CaminhoMaximo(4, 13, custo_maximo);
	
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

	if (Adjacencia(1, 3) == true) {
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

	cout << "--------- Vertices Isolados --------- " << endl;
	for (list<int>::iterator it = lista_vertices_isolados->begin(); it != lista_vertices_isolados->end(); it++) {
		cout << (*it) << endl;
	}

	cout << "--------- Vertices Tipo --------- " << endl;
	for (list<int>::iterator it = lista_vertices_tipo->begin(); it != lista_vertices_tipo->end(); it++) {
		cout << (*it) << endl;
	}

	cout << "--------- Caminho --------- " << endl;
	if (lista_caminho == NULL) {
		cout << "Nao existe caminho" << endl;
	}
	else {
		for (list<int>::iterator it = lista_caminho->begin(); it != lista_caminho->end(); it++) {
			cout << (*it) << endl;
		}
		cout << "Custo: " << custo << endl;
	}
	cout << "----------------------" << endl;
	if (caminho_curto->size() == 1) {
		cout << "Nao existe caminho" << endl;
	}
	else {
		for (list<int>::iterator it = caminho_curto->begin(); it != caminho_curto->end(); it++) {
			cout << (*it) << endl;
		}
		cout << "Custo: " << custo_minimo << endl;
	}
	/*cout << "--------- CAMINHO MAXIMO -------------" << endl;

	for (list<int>::iterator it = caminho_maximo->begin(); it != caminho_maximo->end(); it++) {
		cout << (*it) << endl;
	}
	cout << "Custo: " << custo_maximo << endl;
*/
	delete(lista_fronteiras_nos);
	delete(lista_vertices_isolados);
	delete(lista_vertices_tipo);
	delete(lista_caminho);
	delete(caminho_curto);
	delete(caminho_maximo);
	return NULL;
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
	int vezes = 0, maior;

	for (auto it = myGrafo.begin(); it != myGrafo.end(); it++) {
		if (it == myGrafo.begin()) {
			maior = (*it).first;
		}
		if (myGrafo[(*it).first].size() == myGrafo[maior].size()) {
			vezes++;
		}
		if (myGrafo[(*it).first].size() > myGrafo[maior].size()) {
			maior = (*it).first;
		}
	}

	if (!vezes) {
		l_fronteiras->push_back(maior);
		return l_fronteiras;
	}

	for (auto it = myGrafo.begin(); it != myGrafo.end(); it++) {
		if (myGrafo[(*it).first].size() == myGrafo[maior].size()) {
			l_fronteiras->push_back((*it).first);
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
	if (!fronteiraExiste(v1) && !fronteiraExiste(v2)) {
		return false;
	}
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
	list<int> visited;
	list<int> *caminho = new list<int>;
	return Caminho(v1, v2, visited, caminho, custo_total);
}

//-------------------------------------------------------------------
//Método: VerticesIsolados
//Parametros:
// Entrada:
//
// Retorno:
//    Lista de vertices isolados
//-------------------------------------------------------------------
// TODO: CORRIGIR, isto esta dar mal porque com o auto ele nao conta os vertices que nao tem arestas
list<int> *Grafo::VerticesIsolados() {
	list<int> *l_fronteiras = new list<int>;

	for (auto it = myGrafo.begin(); it != myGrafo.end(); ++it) {
		if (!myGrafo[(*it).first].size()) {
			l_fronteiras->push_back((*it).first);
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
	// Percorrer todas os vertices a qual ele está diretamente ligado
	for (auto it = myGrafo[v].begin(); it != myGrafo[v].end(); ++it) {
		RemoverAresta(v, (*it)->getVertice()->getVertice());
		it = myGrafo[v].begin();
		if (it == myGrafo[v].end()) {
			break;
		}
	}

	// Remover da lista de fronteiras e deletar de memoria
	myGrafo.erase(v);
	Fronteira* aux = encontrarFronteira(v);
	lista_fronteiras.remove(aux);
	delete(aux);
	return true;
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
	// Remover a aresta do vertice v1
	for (auto it = myGrafo[v1].begin(); it != myGrafo[v1].end(); ++it) {
		if ((*it)->getVertice()->getVertice() == v2) {
			myGrafo[v1].remove(*it);

			// Remover a aresta do vertice v2
			for (auto it = myGrafo[v2].begin(); it != myGrafo[v2].end(); ++it) {
				if ((*it)->getVertice()->getVertice() == v1) {
					myGrafo[v2].remove(*it);
					return true;
				}
			}
		}
	}
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
	XMLWriter xml;
	
	// Escrever o principio do xml
	xml.escreverPrincipioPrograma(s);

	// Escrever a info de todos os vertices
	xml.escreverPrincipioTag("Vertices");
	for (auto it = lista_fronteiras.begin(); it != lista_fronteiras.end(); ++it) {
		string vertice = to_string((*it)->getVertice());
		string x = to_string((*it)->getX_pos());
		string y = to_string((*it)->getY_pos());
		string tipo = to_string((*it)->getTipo());
		xml.escreverPrincipioElemento("vertice");
		xml.escreverElementoString(vertice, "Vertice");
		xml.escreverElementoString(x, "X-pos");
		xml.escreverElementoString(y, "Y-pos");
		xml.escreverElementoString(tipo, "Tipo");
		xml.escreverFimElemento();
	}
	xml.escreverFimTag();
	// Escrever a info das arestas
	xml.escreverPrincipioTag("Arestas");
	for (auto it = myGrafo.begin(); it != myGrafo.end(); ++it) {
		for (auto it1 = myGrafo[(*it).first].begin(); it1 != myGrafo[(*it).first].end(); ++it1) {
			string source = to_string((*it).first);
			string destination = to_string((*it1)->getVertice()->getVertice());
			string custo = to_string((*it1)->getCusto());
			xml.escreverPrincipioElemento("aresta");
			xml.escreverElementoString(source, "Fonte");
			xml.escreverElementoString(destination, "Destino");
			xml.escreverElementoString(custo, "Custo");
			xml.escreverFimElemento();
		}
	}
	xml.escreverFimTag();
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
	vector<int> distance(n_vertices + 1);     // The output array.  distance[i] will hold the shortest 
					 // distance from src to i 
	vector<int> parent(n_vertices + 1);
	vector<bool> visited(n_vertices + 1); // visited[i] will true if vertex i is included in shortest 
					// shortest distance from source to i is finalized (aka already visited) 

	// Initialize all distances as INT_MAX and visited[] as false 
	for (int i = 1; i <= n_vertices; i++) {
		distance[i] = INT_MAX;
		visited[i] = false;
		parent[0] = -1;
	}

	// Distance of source vertex from itself is always 0 
	distance[v1] = 0;

	// Find shortest path for all vertices 
	for (auto it1 = myGrafo.begin(); it1 != myGrafo.end(); it1++) {
		// Pick the minimum distance vertex from the set of vertices not 
		// yet processed. u is always equal to src in the first iteration. 
		int u = minDistance(distance, visited);

		// Mark the picked vertex as processed 
		visited[u] = true;

		// Update distance value of the adjacent vertices of the picked vertex. 
		for (auto it = myGrafo[u].begin(); it != myGrafo[u].end(); ++it) {
			// Update distance[v] only if is not in visited, there is an edge from  
			// u to v, and total weight of path from src to  v through u is  
			// smaller than current value of distance[v] 
			if (!visited[(*it)->getVertice()->getVertice()] && (*it)->getCusto() && distance[u] != INT_MAX
				&& distance[u] + (*it)->getCusto() < distance[(*it)->getVertice()->getVertice()]) {
				// Change the current destination of vertice
				parent[(*it)->getVertice()->getVertice()] = u;
				distance[(*it)->getVertice()->getVertice()] = distance[u] + (*it)->getCusto();
			}
		}
	}
	// Allocate list of shortest path
	list<int> *caminho = new list<int>;
	CopiarCaminhoParent(parent, v2, caminho);
	custo_total = distance[v2];
	list<int>::iterator it = --caminho->end();

	if ((*it) != v2) {
		for (int i = 0; i < caminho->size(); i++)
			caminho->pop_back();
	}
	return caminho;
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
//list<int> *Grafo::CaminhoMaximo(int v1, int v2, double &custo_total) {
/*void Grafo::CaminhoMaximo(int v1, int v2, double &custo_total) {
	vector<int> visited(n_vertices + 1, 0);
	list<int> *caminho = new list<int>;
	int x = CaminhoMaximo(v1, v2, visited, caminho, custo_total);

	for (auto it = caminho->begin(); it != caminho->end(); it++) {
		cout << *it << endl;
	}
	system("pause");
	//return CaminhoMaximo(v1, v2, visited, custo_total);
}*/
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
	for (auto it1 = myGrafo.begin(); it1 != myGrafo.end(); ++it1) {
		cout << "Caminhos para o vertice " << (*it1).first << endl;
		for (list<Arestas*>::iterator it = myGrafo[(*it1).first].begin(); it != myGrafo[(*it1).first].end(); it++) {
			(*it)->Mostrar();
		}
		cout << "-----------------------------" << endl;
	}
}

list<int> *Grafo::Caminho(int source, int destination, list<int> visited, list<int> *caminho, double &custo_total) {
	if (find(visited.begin(), visited.end(), source) != visited.end()) {
		return false;
	}
	visited.push_back(source);
	caminho->push_back(source);

	if (source == destination) {
		for (auto it1 = caminho->begin(); it1 != caminho->end(); ++it1) {
			// Verificar se o proximo elemento do iterator e = a NULL
			if (++it1 == caminho->end()) {
				break; // Se for da break
			}
			--it1; // Senao volta ao iterator onde estava

			for (auto it2 = myGrafo[*it1].begin(); it2 != myGrafo[*it1].end(); ++it2) {
				// Verifica se o vertice de it2 e igual ao proximo vertice do caminho
				if ((*it2)->getVertice()->getVertice() == *(++it1)) {
					custo_total += (*it2)->getCusto();
				}
				// retomar o endereco de it1
				--it1;
			}
		}
		return caminho;
	}

	for (auto it = myGrafo[source].begin(); it != myGrafo[source].end(); it++) {
		if (Caminho((*it)->getVertice()->getVertice(), destination, visited, caminho, custo_total)) {
			return caminho;
		}
	}
	caminho->pop_back();
	return false;
}

int Grafo::CaminhoMaximo(int v1, int v2, vector<int> visited, list<int> *caminho, double &custo_total) {
	int maxv = -1;
	int erro = 0;
	caminho->push_back(v1);
	if (v1 == v2) {
		caminho->pop_back();
		return 0;
	}

	visited[v1] = 1;
	for (auto it = myGrafo[v1].begin(); it != myGrafo[v1].end(); it++) {
		erro = 1;
		if (visited[(*it)->getVertice()->getVertice()] == 0) {
			int maxw = CaminhoMaximo((*it)->getVertice()->getVertice(), v2, visited, caminho, custo_total);
			if (maxw != -1 && maxv < (*it)->getCusto() + maxw)
				maxv = (*it)->getCusto() + maxw;
		}
	}

	if (erro == 1) {
		caminho->pop_back();
	}
	visited[v1] = 0; // atenção!
	return maxv;
}

int Grafo::minDistance(vector<int> dist, vector<bool> sptSet) {
	// Initialize min value 
	int min = INT_MAX, min_index;

	for (int v = 1; v <= n_vertices; v++)
		if (sptSet[v] == false && dist[v] <= min)
			min = dist[v], min_index = v;

	return min_index;
}

void Grafo::CopiarCaminhoParent(vector<int> parent, int j, list<int> *caminho) {
	// Base Case : If j is source 
	if (parent[j] == -1)
		return;
	CopiarCaminhoParent(parent, parent[j], caminho);
	caminho->push_back(j);
}