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

void Grafo::dfs(int fonte) {
    std::stack<int> pilha;
    cor[fonte] = CINZA;
    pilha.push(fonte);
    while(pilha.empty() == false) {
        int u = pilha.top();
        for(int v : lista_adj[u]) {
            if(cor[v] == BRANCO) {
                pai[v] = u;
                cor[v] == CINZA;
                pilha.push(v);
            } 
        }
        cor[u] == PRETO;
    }
}