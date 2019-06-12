#include "../include/fisica.hpp"

fisica::fisica(int *quadro_inicial)
{
    setQuadro(quadro_inicial);
}

fisica::~fisica()
{
    free(this->quadro);
    this->quadro = nullptr;
}

void fisica::setQuadro(int *quadro)
{
    this->quadro = quadro;
}

int *fisica::getQuadro()
{
    return this->quadro;
}

void fisica::CamadaFisicaTransmissora()
{
    int tipoDeCodificacao = 0; //alterar de acordo o teste
                               //ATENÇÃO: trabalhar com BITS!!!
    switch (tipoDeCodificacao)
    {
    case 0: //codificao binaria
        CamadaFisicaTransmissoraCodificacaoBinaria();
        break;
    case 1: //codificacao manchester
        CamadaFisicaTransmissoraCodificacaoManchester();
        break;
    case 2: //codificacao manchester diferencial
        CamadaFisicaTransmissoraCodificacaoManchesterDiferencial();
        break;
    } //fim do switch/case
    //int *fluxoBrutoDeBits = getQuadro();

    //ADICIONAR MEIO DE COMUNICAÇÃO
    //MeioDeComunicacao(fluxoBrutoDeBits);
}

void fisica::CamadaFisicaReceptora()
{
    int tipoDeDecodificacao = 0; //alterar de acordo o teste
                                 //ATENÇÃO: trabalhar com BITS!!!
    switch (tipoDeDecodificacao)
    {
    case 0: //codificao binaria
        CamadaFisicaReceptoraDecodificacaoBinaria();
        break;
    case 1: //codificacao manchester
        CamadaFisicaReceptoraDecodificacaoManchester();
        break;
    case 2: //codificacao manchester diferencial
        CamadaFisicaReceptoraDecodificacaoManchesterDiferencial();
        break;
    } //fim do switch/case
    //int *fluxoBrutoDeBits = getQuadro();
    //ADICIONAR MEIO DE COMUNICAÇÃO CHAMADA A PROXIMA CAMADA
    //CamadaDeAplicacaoReceptora(fluxoBrutoDeBits);
}

void fisica::CamadaFisicaTransmissoraCodificacaoBinaria()
{
}

void fisica::CamadaFisicaTransmissoraCodificacaoManchester()
{
}

void fisica::CamadaFisicaTransmissoraCodificacaoManchesterDiferencial()
{
}

void fisica::CamadaFisicaReceptoraDecodificacaoBinaria()
{
}

void fisica::CamadaFisicaReceptoraDecodificacaoManchester()
{
}

void fisica::CamadaFisicaReceptoraDecodificacaoManchesterDiferencial()
{
}