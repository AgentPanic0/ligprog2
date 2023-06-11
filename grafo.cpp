#include <iostream>
#include <iomanip>
#include "grafo.h"
#define INFINITO 999

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

Aresta& Grafo::getAresta(unsigned id1, unsigned id2)
{ 
    unsigned i = 0;
    for (i = 0; i < getQuantidadeAresta(); i++)
    {
        if (arestas[i].getNoInicial().getId() == id1 && arestas[i].getNoFinal().getId() == id2)
        {
            return arestas[i];
        }
        else if (arestas[i].getNoInicial().getId() == id2 && arestas[i].getNoFinal().getId() == id1)
        {
            return arestas[i];
        }        
    }
    
    cout << "erro aresta nao encontrada" << endl;
    return arestas[i];//nao sei o q retornar como erro
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

void Grafo::mostrarMenorCaminho(unsigned idI, unsigned idF)
{
    vector < vector <Aresta>> todosMenoresCaminhos = menoresCaminhos(idI);
    vector <Aresta> caminho = todosMenoresCaminhos[idF];

    unsigned idAtual = idI;

    if (caminho.size() == 0)
    {
        cout << "O seu ponto de partida e o mesmo da chegada" <<endl;
    }
    else if (caminho[0].getPeso() == INFINITO)
    {
        cout << "Nao existe caminho entre o vertice de partida e o de chegada" <<endl;
    }
    else
    {
        cout << "O Melhor caminho sera:" <<endl;
        cout <<getVertice(idI).getNome();
        for (unsigned i = 0; i < caminho.size(); i++)
        {
            cout <<"->"<<caminho[i].getNoComplementar(idAtual).getNome();
            idAtual = caminho[i].getNoComplementar(idAtual).getId();
        }
        cout <<endl;
    }
}

void Grafo::mostrarTotalmenteConectado()
{
    vector < vector <Aresta>> todosMenoresCaminhos;
    bool totalmenteConectado = true;

    if (vertices.size() == 0)
    {
        cout << "O grafo nao possui vertices" <<endl;
    }
    else if (vertices.size() == 1)
    {
        cout << "O grafo so possui um vertice" <<endl;
    }
    else if (vertices.size() > 1)
    {
        todosMenoresCaminhos = menoresCaminhos(0);

        totalmenteConectado = true;
        for (unsigned i = 1; i < todosMenoresCaminhos.size(); i++)
        {
            if (todosMenoresCaminhos[i][0].getPeso() == INFINITO)
            {
                totalmenteConectado = false;
            }
            
        }

        if (totalmenteConectado)
        {
           cout << "O grafo e SIM totalmente conectado" <<endl;
        }
        else
        {
            cout << "O grafo NAO e totalmente conectado" <<endl;
        }
    }
}

void Grafo::mostrarMaiorGrau()
{
    vector <vector <float>> adjacencia = matrizAdjacencia();
    vector<unsigned> idsMaiorGrau;
    float maiorSoma = 0;
    float somaAtual = 0;

    for (unsigned i = 0; i < adjacencia.size(); i++) //captura o maior valor de grau
    {
        somaAtual = 0;
        for (unsigned c = 0; c < adjacencia[i].size(); c++)
        {
            if (adjacencia[i][c] != INFINITO)
            {
                somaAtual = somaAtual + adjacencia[i][c];
            } 
        }

        if (somaAtual > maiorSoma)
        {
            maiorSoma = somaAtual;
        }  
    }

    for (unsigned i = 0; i < adjacencia.size(); i++) // captura os ids que possuem o maior valor obtido anteriormente
    {
        somaAtual = 0;
        for (unsigned c = 0; c < adjacencia[i].size(); c++)
        {
            if (adjacencia[i][c] != INFINITO)
            {
                somaAtual = somaAtual + adjacencia[i][c];
            } 
        }

        if (somaAtual == maiorSoma)
        {
            idsMaiorGrau.push_back(i);
        } 
    }

    if (idsMaiorGrau.size() == 1)
    {
        cout << "O vertice "<< getVertice(idsMaiorGrau[0]).getNome() << " possui o maior grau." <<endl;
    }
    else if (idsMaiorGrau.size() > 1)
    {
        cout << "Os vertices que possuem o maior grau sao:" <<endl;
         for (unsigned i = 0; i < idsMaiorGrau.size(); i++)
        {
            cout << getVertice(idsMaiorGrau[i]).getNome() <<endl;
        }
    }    
}

vector <vector <float>> Grafo::matrizAdjacencia()
{
    vector <float> linha;
    vector <vector <float>> matriz;

    for (unsigned i = 0; i < getQuantidadeVertice(); i++)
    {
        linha.push_back(INFINITO);
    }

    for (unsigned i = 0; i < getQuantidadeVertice(); i++)
    {
        matriz.push_back(linha);
    }

    for (size_t i = 0; i < getQuantidadeAresta(); i++)
    {
        matriz[arestas[i].getNoInicial().getId()][arestas[i].getNoFinal().getId()] = arestas[i].getPeso();
        matriz[arestas[i].getNoFinal().getId()][arestas[i].getNoInicial().getId()] = arestas[i].getPeso();
    }
    
    return matriz;
}

vector < vector <Aresta>> Grafo::menoresCaminhos( unsigned idI)
{
    vector < vector <Aresta>> caminhosOtimos;
    vector <Aresta> inicioCaminho;
    vector <Aresta> semCaminho;
    Vertice verticeNull(INFINITO, "Null");
    Aresta arestainf(verticeNull, verticeNull, INFINITO);
    Aresta arestainicial(verticeNull, verticeNull, 0);

    vector < unsigned > idsVisitados;
    vector < unsigned > idsAbertos;
    vector <vector <float>> adjacencia = matrizAdjacencia();
    unsigned idAtual = idI;
    float somaNoAtual = 0;
    float somaNoDestino = 0;
    bool noValido = true;
    float menorSoma;

    semCaminho.push_back(arestainf);

    for (unsigned i = 0; i < vertices.size(); i++) //inicializando todos os nos como sem caminho = inf
    {
        caminhosOtimos.push_back(semCaminho);
    }

    idsAbertos.push_back(idI); //inicializando os nos em aberto

    caminhosOtimos[idI] = inicioCaminho; //inicializando o no inicial como inicio do caminho = 0

    while (idsAbertos.size() != 0) //condiçao de parada da analise
    {
        idsVisitados.push_back(idAtual); //inclui o no nos visitados e tira ele dos abertos
        noValido = false;
        for (unsigned i = 0; i < idsAbertos.size(); i++)
        {
            if (idsAbertos[i] == idAtual)
            {
                noValido = true;
            }
            else
            {
                if (noValido)
                {
                    idsAbertos[i-1] = idsAbertos[i];
                }
            } 
        }
        idsAbertos.pop_back();
        
        for (unsigned i = 0; i < adjacencia[idAtual].size(); i++)
        {
            noValido = true;
            if (adjacencia[idAtual][i] != INFINITO) //verifica se tem ligação com outro no
            {
                for (unsigned c = 0; c < idsVisitados.size(); c++) //verifica se o no adjacente ja foi visitado
                {
                    if (i == idsVisitados[c])
                    {
                        noValido = false;
                    }
                }

                if (noValido)
                {
                    somaNoAtual = 0;
                    for (unsigned cont = 0; cont < caminhosOtimos[idAtual].size(); cont++)
                    {
                        somaNoAtual = somaNoAtual + caminhosOtimos[idAtual][cont].getPeso();
                    }
                    somaNoDestino = 0;
                    for (unsigned cont = 0; cont < caminhosOtimos[i].size(); cont++)
                    {
                        somaNoDestino = somaNoDestino + caminhosOtimos[i][cont].getPeso();
                    }
                    if (adjacencia[idAtual][i] + somaNoAtual < somaNoDestino)//se o peso da aresta + o caminho otimo da analise for menr que o caminho otimo do no de destino ele vai virar o otimo do destinho(caminho otimo atual + aresta)
                    {
                        caminhosOtimos[i] = caminhosOtimos[idAtual];
                        caminhosOtimos[i].push_back(getAresta(idAtual, i));

                        idsAbertos.push_back(i);
                    }  
                }  
            }   
        }

        menorSoma = INFINITO;
        for (unsigned i = 0; i < idsAbertos.size(); i++) //atualizando idAtual com o menor valor de caminho de um no nao visitado
        {
            somaNoAtual = 0;
            for (unsigned cont = 0; cont < caminhosOtimos[idsAbertos[i]].size(); cont++)
            {
                somaNoAtual = somaNoAtual + caminhosOtimos[idsAbertos[i]][cont].getPeso();
            }
            if (somaNoAtual < menorSoma)
            {
                idAtual = idsAbertos[i];
                menorSoma = somaNoAtual;
            }           
        }
    }
    return caminhosOtimos;
}