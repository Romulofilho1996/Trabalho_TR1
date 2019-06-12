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
    void setQuadro(int*);

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
    int* getQuadro();

    fisica(int* quadro);
    ~fisica();
};

