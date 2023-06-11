#include "aresta.h"

Aresta::Aresta(Vertice noI, Vertice noF, float p):noInicial(noI), noFinal(noF), peso(p) {}

Vertice Aresta::getNoInicial(){ return noInicial;}

Vertice Aresta::getNoFinal(){ return noFinal;}

Vertice Aresta::getNoComplementar(unsigned id)
{
    if (id == noInicial.getId())
    {
        return noFinal;
    }
    else 
    {
        if (id == noFinal.getId())
        {
            return noInicial;
        }
    }
    return noInicial;  //error
}

float Aresta::getPeso(){ return peso;}