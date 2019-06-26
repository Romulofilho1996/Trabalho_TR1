#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <iterator>
#include <algorithm>

using namespace std;

class enlace
{
private:
    
    void setQuadro(int*);

public:
    int* quadro;
    int quadro_tamanho;
    //TRANSMISSÃO
    void CamadaEnlaceDadosTransmissora();
    void CamadaEnlaceDadosTransmissoraEnquadramento();
    void CamadaEnlaceDadosTransmissoraControleDeErro();
    void CamadaEnlaceDadosTransmissoraControleDeFluxo();
    void CamadaEnlaceDadosTransmissoraControleDeErroBitParidadePar();
    void CamadaEnlaceDadosTransmissoraControleDeErroBitParidadeImpar();
    void CamadaEnlaceDadosTransmissoraControleDeErroCRC();
    void CamadaEnlaceDadosTransmissoraControleDeErroCodigoDeHamming();

    //RECEPÇÃO
    void CamadaEnlaceDadosReceptora();
    void CamadaEnlaceDadosReceptoraEnquadramento();
    void CamadaEnlaceDadosReceptoraControleDeErro();
    void CamadaEnlaceDadosReceptoraControleDeFluxo();
    void CamadaEnlaceDadosReceptoraControleDeErroBitDeParidadePar();
    void CamadaEnlaceDadosReceptoraControleDeErroBitDeParidadeImpar();
    void CamadaEnlaceDadosReceptoraControleDeErroCRC();
    void CamadaEnlaceDadosReceptoraControleDeErroCodigoDeHamming();

    int* getQuadro();

    enlace(int* quadro, int quadro_tamanho);
    ~enlace();
};