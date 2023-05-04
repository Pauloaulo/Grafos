#include <iostream>
#include <vector>
#include <cstring>
#include <queue>
#include <stack>
using namespace std;

#define BRANCO 0
#define CINZA 1
#define PRETO 2

class Grafo {
    int num_vert;
    vector<vector<int>> matriz_adj;
    vector<vector<int>> lista_adj;

    vector<int> pai;
    vector<int> dist;
    vector<int> cor;
public:
    Grafo(int n);
    int num_comp_desconexas();
    void bfs(int n);
    void dfs(int fonte);
};
