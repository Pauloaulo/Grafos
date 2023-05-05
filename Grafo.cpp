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
    int n_comp = 0;
    for (int p : pai) {
        if (p == NULL) n_comp += 1;
    }
    return n_comp;
}

void Grafo::bfs(int fonte) {
    cor[fonte] = CINZA;
    dist[fonte] = 0;
    std::queue<int> lista;
    lista.push(fonte);

    while (lista.empty() == false) {
        int u = lista.front();
        lista.pop();
        for (int v : lista_adj[u]) {
            if (cor[v] == BRANCO) {
                cor[v] = CINZA;
                dist[v] = dist[u] + 1;
                pai[v]  = u;
                lista.push(v);
            }
        } 
        cor[u] = PRETO;
    } 
       
        for (int d : dist) cout << dist[d] << ", ";
        cout << endl;
        for (int p : pai) cout << pai[p] << ", ";
        cout << endl;
}

void Grafo::dfs() {
    std::stack<int> pilha;
    cor[0] = CINZA;
    pilha.push(0);
    while(pilha.empty() == false) {
        int u = pilha.top();
        pilha.pop();
        for(int v = lista_adj[u].size() - 1; v >= 0; v--) {
            if(cor[v] == BRANCO) {
                pai[v] = u;
                cor[v] == CINZA;
                pilha.push(v);
            } 
        }
        cor[u] == PRETO;
    }

    for  (int p : pai) cout << pai[p] << ", ";
    cout << endl;
}

void Grafo::setMatriz_adj(int i, int j, int num) {
    matriz_adj[i][j] = num;
}

int Grafo::getMatriz_adj(int i, int j) {
    return matriz_adj[i][j];
}

void Grafo::setLIsta_adj(int i, int j, int num) {
    lista_adj[i][j] = num;
}

int Grafo::getLista_adj(int i, int j) {
    return lista_adj[i][j];
}