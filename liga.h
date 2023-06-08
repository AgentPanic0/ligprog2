#include <string>
#include <vector>
#include "time.h"

class Liga
{
    public:
        Liga (string,  vector <Time>, vector <string>, vector <string>);

        void getMediaMovel(unsigned, unsigned, vector <unsigned>);
        void getParticipantes();
        unsigned getQuantidadeParticipantes();
        void getAnos();
        unsigned getQuantidadeAnos();
        void getCampeonatos();
        unsigned getQuantidadeCampeonatos();
        void getDesempenhoCamp(unsigned, unsigned);
        void getDesempenhoTotal(unsigned);
        void getMaxSaldoCamp(unsigned);
        void getMaiorEvolucao(unsigned);

        

        string getNome();

    private:
        string nome;
        vector <Time> listaTimes;
        vector <string> listaNomeAno;
        vector <string> listaNomeCamp;
        double criterioDesempenho = 0.05;
};