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
        Aresta& getAresta(unsigned, unsigned);
        Vertice& getVertice(unsigned);
        unsigned getQuantidadeVertice();
        unsigned getQuantidadeAresta();

        void mostrarVerticeAresta();
        void mostrarMatrizAdjacencia();
        void mostrarMenorCaminho(unsigned, unsigned);
        void mostrarTotalmenteConectado();
        void mostrarMaiorGrau();
        
    private:
        vector <vector <float>> matrizAdjacencia();
        vector < vector <Aresta>>  menoresCaminhos( unsigned);

        vector <Aresta> arestas;
        vector <Vertice> vertices;
        string nome;
};