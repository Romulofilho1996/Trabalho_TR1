#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <iterator>
#include <bitset>

using namespace std;

class wraper
{
private:
    string mensagem;
public:
    int* quadro;
    int quadro_tamanho;
    void AplicacaoTransmissora();
    void CamadaDeAplicacaoTransmissora();
    void MeioDeComunicacao();
    void AplicacaoReceptora();
    void CamadaDeAplicacaoReceptora();

    wraper();
    ~wraper();
};