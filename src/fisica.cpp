#include "../include/fisica.hpp"

fisica::fisica(int *quadro_inicial, int quadro_tamanho)
{
    setQuadro(quadro_inicial, quadro_tamanho);
}

fisica::~fisica()
{
    free(this->quadro);
    this->quadro = nullptr;
}

void fisica::setQuadro(int *quadro, int quadro_tamanho)
{
    this->quadro = quadro;
    this->quadro_tamanho = quadro_tamanho;
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
    int *quadro_codificado;
    int novo_tamanho = this->quadro_tamanho * 2;

    quadro_codificado = (int *)malloc(sizeof(int) * novo_tamanho);
    cout << "\n=========Transmissão Codificada Manchester=========" << endl;
    for (int i = 0, j = 0; i < this->quadro_tamanho; i++, j += 2)
    {
        quadro_codificado[j] = this->quadro[i] ^ 0;
        quadro_codificado[j + 1] = this->quadro[i] ^ 1;
        cout << quadro_codificado[j];
        cout << quadro_codificado[j + 1];
    }
    cout << endl;
    free(this->quadro);
    this->quadro = quadro_codificado;
    this->quadro_tamanho = novo_tamanho;
}

void fisica::CamadaFisicaTransmissoraCodificacaoManchesterDiferencial()
{
}

void fisica::CamadaFisicaReceptoraDecodificacaoBinaria()
{
}

void fisica::CamadaFisicaReceptoraDecodificacaoManchester()
{
    int novo_tamanho = this->quadro_tamanho / 2;
    int *quadro_decodificado = (int *)malloc(sizeof(int) * novo_tamanho);

    cout << "\n=========Recepção de Manchester=========" << endl;
    for (int i = 0, j = 0; i < this->quadro_tamanho; i += 2, j++)
    {
        if((this->quadro[i] == 0) && (this->quadro[i + 1] == 1)) {
            quadro_decodificado[j] = 0;
        }
        else if((this->quadro[i] == 1) && (this->quadro[i + 1] == 0)) {
            quadro_decodificado[j] = 1;
        }
        else {
            cout << "Erro na mensagem: " << i << " " << i + 1 << endl;
            break;
        }
        cout << quadro_decodificado[j];
    }

    cout << endl;
    free(this->quadro);
    this->quadro = quadro_decodificado;
    this->quadro_tamanho = novo_tamanho;
}

void fisica::CamadaFisicaReceptoraDecodificacaoManchesterDiferencial()
{
}