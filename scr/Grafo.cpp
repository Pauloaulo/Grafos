#include "Grafo.h"

Grafo::Grafo(int n) {
    num_vert = n;
    matriz_adj.resize(n, vector<int>(n, 0));
    lista_adj.resize(n);

    pai.resize(n, NULL);
    dist.resize(n, -1);
    cor.resize(n, BRANCO);
}

int Grafo::num_comp_desconexas() {
    bfs(0);
    int n_comp = 0;
    for (int* p : pai) {
        if (p == NULL) n_comp += 1;
    }
    return n_comp - 1;
}

void Grafo::bfs(int fonte) {
    cor[fonte] = CINZA;
    dist[fonte] = 0;
    queue<int> lista;
    lista.push(fonte);

    while (lista.empty() == false) {
        int u = lista.front();
        int* novo_pai = new int(u);
        lista.pop();
        for (int v : lista_adj[u]) {
            if (cor[v] == BRANCO) {
                cor[v] = CINZA;
                dist[v] = dist[u] + 1;
                pai[v] = novo_pai;
                lista.push(v);
            }
        } 
        cor[u] = PRETO;
    } 
       
    //for (int d : dist) cout << d << ", ";
    //cout << endl;
    /*
    for (int* p : pai) {
        if (p != NULL) {
            cout << *p << ", ";
        } else cout << "NULL" << ", ";
    }
    cout << endl;
    */
}

void Grafo::dfs() {
    stack<int> pilha;
    cor[0] = CINZA;
    pilha.push(0);
    while(pilha.empty() == false) {
        int u = pilha.top();
        int* novo_pai = new int(u);
        pilha.pop();
        for(auto v = lista_adj[u].rbegin(); v != lista_adj[u].rend(); v++) {
            int vi = *v;
            if(cor[vi] == BRANCO) {
                pai[vi] = novo_pai;
                cor[vi] = CINZA;
                pilha.push(vi);
            } 
        }
        cor[u] = PRETO;
    }

    cout << endl;
    for (int* p : pai) {
        if (p != NULL) {
            cout << *p << ", ";
        } else cout << "NULL" << ", ";
    }
    cout << endl;
}

void Grafo::menor_caminho(int fonte, int destino) {
    if (fonte == destino) return; // ponto de partida e saída são iguais 
    queue<int> caminho;

    bfs(destino);

    if (pai[fonte] == NULL) { // vertices desconexos 
        cout << "Os vértices são desconexos." << endl;
        return;
    } 

    const int* ponteiro = pai[fonte];
    caminho.push(*ponteiro);
    int u = caminho.front();
    while (u != destino) {

        const int* aux = pai[u];
        caminho.push(*aux);
        u = *aux;
    }

    cout << "{";
    while (!caminho.empty()) {
        int elemento = caminho.front();
        caminho.pop();
        if (caminho.size() != 0) {
            cout << elemento << ", ";
        } else cout << elemento;
    }
    cout << "}" << endl;
}

void Grafo::setMatriz_adj(int i, int j, int num) {
    matriz_adj[i][j] = num;
}

int Grafo::getMatriz_adj(int i, int j) {
    return matriz_adj[i][j];
}

void Grafo::setLista_adj(int i, int num) {
    lista_adj[i].push_back(num);
}

int Grafo::getLista_adj(int i, int j) {
    return lista_adj[i][j];
}
