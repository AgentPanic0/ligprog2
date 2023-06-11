#include "vertice.h"

using namespace std;

class Aresta
{
    public:
        Aresta (Vertice, Vertice, float);

        Vertice getNoInicial();
        Vertice getNoFinal();
        Vertice getNoComplementar(unsigned);
        float getPeso();

    private:
        Vertice noInicial;
        Vertice noFinal;
        float peso;
};