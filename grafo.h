#include <vector>
#include <string>
#include "aresta.h"

using namespace std;

class Grafo
{
    public:
        Grafo (string);

        void inserirAresta(Vertice&, Vertice&, float);
        void inserirVertice(string);

        string getNome();
        Aresta& getAresta(unsigned);
        Vertice& getVertice(unsigned);
        unsigned getQuantidadeVertice();
         unsigned getQuantidadeAresta();

        void mostrarVerticeAresta();
        void mostrarMatrizAdjacencia();

    private:
        vector <vector <float>> matrizAdjacencia();

        vector <Aresta> arestas;
        vector <Vertice> vertices;
        string nome;
};