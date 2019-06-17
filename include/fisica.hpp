#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <iterator>

using namespace std;

class fisica
{
private:
    int* quadro;
    int quadro_tamanho;
    void setQuadro(int*, int);
public:
    //All methods should modify the private atribute <quadro>
    //TRANSMISSÃO
    void CamadaFisicaTransmissora();
    void CamadaFisicaTransmissoraCodificacaoBinaria();
    void CamadaFisicaTransmissoraCodificacaoManchester();
    void CamadaFisicaTransmissoraCodificacaoManchesterDiferencial();
    void CamadaFisicaReceptora();

    //RECEPÇÃO
    void CamadaFisicaReceptoraDecodificacaoBinaria();
    void CamadaFisicaReceptoraDecodificacaoManchester();
    void CamadaFisicaReceptoraDecodificacaoManchesterDiferencial();

    //MEIO COMUNICAÇAO
    void MeioDeComunicacao();

    int* getQuadro();
    int getTamanho();

    fisica(int* quadro, int quadro_tamanho);
    ~fisica();
};

