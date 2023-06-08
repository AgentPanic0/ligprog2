#include "aresta.h"

Aresta::Aresta(Vertice noI, Vertice noF, float p):noInicial(noI), noFinal(noF), peso(p) {}

Vertice Aresta::getNoInicial(){ return noInicial;}

Vertice Aresta::getNoFinal(){ return noFinal;}

float Aresta::getPeso(){ return peso;}