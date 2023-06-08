#include <iostream>
#include <iomanip>
#include "grafo.h"

Grafo::Grafo(string nomeGrafo):nome(nomeGrafo){}

void Grafo::inserirAresta(Vertice& noI, Vertice& noF, float peso)
{
    Aresta arestaNova(noI, noF, peso);
    arestas.push_back(arestaNova);

    noI.incrementarAresta();
    noF.incrementarAresta();
}

void Grafo::inserirVertice(string nome)
{
    static unsigned id = 0;

    Vertice verticeNovo(id, nome);
    vertices.push_back(verticeNovo);

    id++;
}

string Grafo::getNome(){ return nome;}

Aresta& Grafo::getAresta(unsigned id)
{ 
    if (id < arestas.size())
    {
        return arestas[id];
    }

    return arestas[id];//nao sei o q retornar como erro
}

Vertice& Grafo::getVertice(unsigned id)
{ 
    if (id < vertices.size())
    {
        return vertices[id];
    }

    return vertices[id];//nao sei o q retornar como erro
}

unsigned Grafo::getQuantidadeVertice(){ return vertices.size();}
unsigned Grafo::getQuantidadeAresta(){ return arestas.size();}

void Grafo::mostrarVerticeAresta()
{
    cout << "Nome do No : Quantidade de enlaces" << endl;
    for (unsigned i = 0; i < getQuantidadeVertice(); i++)
    {
        cout << getVertice(i).getNome() << " : " << getVertice(i).getArestas() << endl;
    }
    cout << endl;
}

void Grafo::mostrarMatrizAdjacencia()
{
    vector <vector <float>> matriz = matrizAdjacencia();

    cout << "Matriz de adjacencia do grafo:"<< endl;

    cout << left << setw(10) << "";
    for (unsigned i = 0; i < getQuantidadeVertice(); i++)
    {
        cout << left << setw(10) << vertices[i].getNome();
    }
    cout << endl;

    for (unsigned i = 0; i < matriz[0].size(); i++)
    {
        cout << left << setw(10) << vertices[i].getNome();
        for (unsigned j = 0; j < matriz[0].size(); j++)
        {
            cout << left << setw(10) << matriz[i][j];
        }
        cout << endl;
    }
    
}

vector <vector <float>> Grafo::matrizAdjacencia()
{
    vector <float> linha;
    vector <vector <float>> matriz;

    for (unsigned i = 0; i < getQuantidadeVertice(); i++)
    {
        linha.push_back(0.0);
    }

    for (unsigned i = 0; i < getQuantidadeVertice(); i++)
    {
        matriz.push_back(linha);
    }

    for (size_t i = 0; i < getQuantidadeAresta(); i++)
    {
        matriz[arestas[i].getNoInicial().getId()][arestas[i].getNoFinal().getId()] = arestas[i].getPeso();
    }
    
    return matriz;
}