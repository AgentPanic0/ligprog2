#include <string>

using namespace std;

class Vertice
{
    public:
        Vertice (unsigned, string);

        unsigned getId();
        string getNome();
        unsigned getArestas();

        void incrementarAresta();

    private:
        unsigned id;
        string nome;
        unsigned contAresta;
};