#include "Grafo.h"
#include <fstream>
#include <string>
#include <sstream>

Grafo load_from(const std::string& nome_arquivo);

int main() {

    return 0;
}

Grafo load_from(const std::string& nome_arquivo) {
    std::ifstream arquivo(nome_arquivo);
    std::string linha;
    int n;
    while(std::getline(arquivo, linha)) {
        n++;
    }

    Grafo* g = new Grafo(n);

    int l = 0;
    while(std::getline(arquivo, linha)) {
        vector<int> numeros;
        linha.erase(0, linha.find_first_not_of(" \t\r\n"));
        linha.erase(linha.find_last_not_of(" \t\r\n") + 1);
        std::stringstream ss(linha);
        std::string substring;
        while (std::getline(ss, substring, '\t')) {
            numeros.push_back(std::stoi(substring));
    }
        int c = 0;
        for (int _id = 0; _id < n; _id++) {
            int i = numeros[_id];
            g->setMatriz_adj(l, c, (int)i);
            if (g->getMatriz_adj(l, c) > 0) {
                g->
            }
        }
}