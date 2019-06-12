#include "../include/enlace.hpp"

enlace::enlace(int *quadro_inicial)
{
    setQuadro(quadro_inicial);
}

enlace::~enlace()
{
    free(this->quadro);
    this->quadro = nullptr;
}

void enlace::setQuadro(int *)
{
    this->quadro = quadro;
}

int *enlace::getQuadro()
{
    return this->quadro;
}

void enlace::CamadaEnlaceDadosTransmissora()
{
    CamadaEnlaceDadosTransmissoraEnquadramento();
    CamadaEnlaceDadosTransmissoraControleDeErro();
    CamadaEnlaceDadosTransmissoraControleDeFluxo();
}

void enlace::CamadaEnlaceDadosReceptora()
{
    CamadaEnlaceDadosReceptoraEnquadramento();
    CamadaEnlaceDadosReceptoraControleDeErro();
    CamadaEnlaceDadosReceptoraControleDeFluxo();
}

void enlace::CamadaEnlaceDadosTransmissoraEnquadramento()
{
}

void enlace::CamadaEnlaceDadosTransmissoraControleDeErro()
{
    int tipoDeControleDeErro = 0; //alterar de acordo com o teste
    switch (tipoDeControleDeErro)
    {
    case 0: //bit de paridade par
        //codigo
        break;
    case 1: //bit de paridade impar
        //codigo
        break;
    case 2: //CRC
    //codigo
    case 3: //codigo de Hamming
        //codigo
        break;
    } //fim do switch/case
}

void enlace::CamadaEnlaceDadosTransmissoraControleDeFluxo()
{
}

void enlace::CamadaEnlaceDadosTransmissoraControleDeErroBitParidadePar()
{
}

void enlace::CamadaEnlaceDadosTransmissoraControleDeErroBitParidadeImpar()
{
}

void enlace::CamadaEnlaceDadosTransmissoraControleDeErroCRC()
{
}

void enlace::CamadaEnlaceDadosTransmissoraControleDeErroCodigoDeHamming()
{
}

void enlace::CamadaEnlaceDadosReceptoraEnquadramento()
{
}

void enlace::CamadaEnlaceDadosReceptoraControleDeErro()
{
    int tipoDeControleDeErro = 0; //alterar de acordo com o teste
    switch (tipoDeControleDeErro)
    {
    case 0: //bit de paridade par
        //codigo
        break;
    case 1: //bit de paridade impar
        //codigo
        break;
    case 2: //CRC
    //codigo
    case 3: //codigo de hamming
        //codigo
        break;
    } //fim do switch/case
}

void enlace::CamadaEnlaceDadosReceptoraControleDeFluxo()
{
}

void enlace::CamadaEnlaceDadosReceptoraControleDeErroBitDeParidadePar()
{
}

void enlace::CamadaEnlaceDadosReceptoraControleDeErroBitDeParidadeImpar()
{
}

void enlace::CamadaEnlaceDadosReceptoraControleDeErroCRC()
{
}

void enlace::CamadaEnlaceDadosReceptoraControleDeErroCodigoDeHamming()
{
}
