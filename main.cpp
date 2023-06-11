#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <vector>
//#include "vertice.h"
#include "grafo.h"

using namespace std;

int main (int argc, char *argv[]) 
{
    fstream file;
    string noInicial, noFinal, peso;
    vector <Vertice> nosExistes;
    Grafo grafo("Proximidade dos alunos");
    unsigned idI, idF;

    int opcao = 0;

    if (argc != 2)
    {
        cout << "\nQuantidade de argumentos invalido!!\n>>E preciso que insira somente o nome do arquivo.\n" <<endl;
        return 0;
    }

    file.open(argv[1], fstream::in);

    if (!file.is_open())
    {
        cout << "\nArquivo nao existe.\n" << endl;
        return 0;
    }

    while (file.good()) 
    {
        getline(file, noInicial,',');
        getline(file, noFinal,',');
        getline(file, peso,'\n');

        //verificando se o noInicial ja existe
        unsigned i = 0;
        unsigned idI = 0;
        for (i = 0; i < grafo.getQuantidadeVertice(); i++)
        {
            if (grafo.getVertice(i).getNome() == noInicial)
            {
                idI = i;
                i = grafo.getQuantidadeVertice()+1; //break
            }
            
        }
        if (i == grafo.getQuantidadeVertice())
        {
            idI = i;
            grafo.inserirVertice(noInicial);
        }
        
        //verificando se o noFinal ja existe
        unsigned idF = 0;
        for (i = 0; i < grafo.getQuantidadeVertice(); i++)
        {
            if (grafo.getVertice(i).getNome() == noFinal)
            {
                idF = i;
                i = grafo.getQuantidadeVertice()+1; //break
            }
            
        }
        if (i == grafo.getQuantidadeVertice())
        {
            idF = i;
            grafo.inserirVertice(noFinal);
        }
        
        grafo.inserirAresta(grafo.getVertice(idI), grafo.getVertice(idF), stof(peso));
    }

    file.close();
    
    cout << endl;
    cout <<  setw(25) <<"Bem vindo! :)" << endl;

    while(opcao != 6)
    {
        opcao = 0;

        cout << endl;

        //Menu Principal
        cout << setw(18) << "MENU" << endl;
        cout << "Digite o numero da opcao de deseja:" << endl;
        cout << left << setw(25) << "1.Enlaces por No" << left << setw(25) << "2.Matriz de adjacencia" << endl;
        cout << left << setw(25) << "3.Menor caminho" << left << setw(25) << "4.Totalmente conectado" << endl;
        cout << left << setw(25) << "5.Maior grau" << left << setw(25) << "6.Sair" << endl;
        cout << endl;

        cout << "Digite aqui:";
        cin >> opcao;
        cout << endl;

        switch(opcao)
        {
            case 1:

                grafo.mostrarVerticeAresta();

                break;

            case 2:

                grafo.mostrarMatrizAdjacencia();

                break;

            case 3:
                idI = grafo.getQuantidadeVertice();
                cout << "Digite o numero referente a opcao do vertice inicial:" << endl;
                for (unsigned i = 0; i < grafo.getQuantidadeVertice(); i++)
                {
                    cout << i << ". " << grafo.getVertice(i).getNome() << endl;
                }
                cout << endl;
                cout << "Digite aqui:";
                cin >> idI;
                cout << endl;

                //validacao
                if(idI>grafo.getQuantidadeVertice()-1 )
                {
                    cout << "\nOpcao invalida!!\n" << endl;
                    break;
                }
                

                idF = grafo.getQuantidadeVertice();
                cout << "Digite o numero referente a opcao do vertice final:" << endl;
                for (unsigned i = 0; i < grafo.getQuantidadeVertice(); i++)
                {
                    cout << i << ". " << grafo.getVertice(i).getNome() << endl;
                }
                cout << endl;
                cout << "Digite aqui:";
                cin >> idF;
                cout << endl;

                //validacao
                if(idI>grafo.getQuantidadeVertice()-1 )
                {
                    cout << "\nOpcao invalida!!\n" << endl;
                    break;
                }

                grafo.mostrarMenorCaminho(idI, idF);

                break;

             case 4:

                grafo.mostrarTotalmenteConectado();

                break;

             case 5:
                grafo.mostrarMaiorGrau();
                break;

            case 6:
                cout << "Volte sempre! :)" << endl;
                cout << endl;
                break;

            default:
                cout << "Opcao invalida!!!" << endl;
        }
    }

    return 0;
}