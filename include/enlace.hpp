#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <iterator>

using namespace std;

class enlace
{
private:
    int* quadro;
    void setQuadro(int*);

public:
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

    enlace(int* quadro);
    ~enlace();
};