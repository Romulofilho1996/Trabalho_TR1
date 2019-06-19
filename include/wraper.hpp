#include <iostream>
#include <bitset>
#include <string>
#include <sstream>
#include "./enlace.hpp"
#include "./fisica.hpp"

using namespace std;

class wraper
{
private:
    string mensagem;
    fisica *camada_fisica;
    enlace *camada_enlace;

public:
    int *quadro;
    int quadro_tamanho;
    void AplicacaoTransmissora();
    void CamadaDeAplicacaoTransmissora();
    void AplicacaoReceptora();
    void CamadaDeAplicacaoReceptora();

    wraper();
    ~wraper();
};