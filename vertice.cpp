#include "vertice.h"

Vertice::Vertice(unsigned identificador, string nomeNo):id(identificador), nome(nomeNo), contAresta(0) {}

unsigned Vertice::getId(){ return id;}

string Vertice::getNome(){ return nome;}

unsigned Vertice::getArestas(){ return contAresta;}

void Vertice::incrementarAresta(){ contAresta++;}