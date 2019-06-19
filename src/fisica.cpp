#include "../include/fisica.hpp"

fisica::fisica(int *quadro_inicial, int quadro_tamanho)
{
    this->quadro = quadro;
    this->quadro_tamanho = quadro_tamanho;
}

fisica::~fisica()
{
    free(this->quadro);
    this->quadro = nullptr;
}

void fisica::MeioDeComunicacao()
{
    cout << "\n=========REALIZANDO TRANSMISSAO PONTO A PARA PONTO B=========" << endl;
    int *fluxoBrutoDeBitsPontoA;
    int *fluxoBrutoDeBitsPontoB;
    fluxoBrutoDeBitsPontoA = this->quadro;
    fluxoBrutoDeBitsPontoB = (int *)malloc(sizeof(int) * this->quadro_tamanho);
    for (int i = 0; i < this->quadro_tamanho; i++)
    {
        fluxoBrutoDeBitsPontoB[i] = fluxoBrutoDeBitsPontoA[i];
    }
    free(fluxoBrutoDeBitsPontoA);
    fluxoBrutoDeBitsPontoA = nullptr;
    this->quadro = fluxoBrutoDeBitsPontoB;
    CamadaFisicaReceptora();
}

void fisica::CamadaFisicaTransmissora()
{
    cout << "\n=========ENTRANDO CAMADA FISICA TRANSMISSORA=========" << endl;
    int tipoDeCodificacao = 0; //alterar de acordo o teste
    switch (tipoDeCodificacao)
    {
    case 0:
        CamadaFisicaTransmissoraCodificacaoBinaria();
        break;
    case 1:
        CamadaFisicaTransmissoraCodificacaoManchester();
        break;
    case 2:
        CamadaFisicaTransmissoraCodificacaoManchesterDiferencial();
        break;
    }
    MeioDeComunicacao();
}

void fisica::CamadaFisicaReceptora()
{
    cout << "\n=========ENTRANDO CAMADA FISICA RECEPTORA=========" << endl;
    int tipoDeDecodificacao = 0; //alterar de acordo o teste
    switch (tipoDeDecodificacao)
    {
    case 0:
        CamadaFisicaReceptoraDecodificacaoBinaria();
        break;
    case 1:
        CamadaFisicaReceptoraDecodificacaoManchester();
        break;
    case 2:
        CamadaFisicaReceptoraDecodificacaoManchesterDiferencial();
        break;
    }
}

void fisica::CamadaFisicaTransmissoraCodificacaoBinaria()
{
    int *quadro_codificado;

    quadro_codificado = (int *)malloc(sizeof(int) * this->quadro_tamanho);
    cout << "\n=========Transmissão Codificada Binaria=========" << endl;
    for (int i = 0; i < this->quadro_tamanho; i++)
    {
        quadro_codificado[i] = this->quadro[i];
        cout << quadro_codificado[i];
    }
    cout << endl;

    free(this->quadro);
    this->quadro = quadro_codificado;
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
    int *quadro_codificado;
    int novo_tamanho = this->quadro_tamanho * 2;
    int bitreferencia = 0;

    quadro_codificado = (int *)malloc(sizeof(int) * novo_tamanho);
    cout << "\n======Transmissão Codificada Manchester Diferencial======" << endl;
    for (int i = 0, j = 0; i < this->quadro_tamanho; i++, j += 2)
    {
        if (this->quadro[i] == 1)
        {
            bitreferencia = bitreferencia ^ 1;
        }

        quadro_codificado[j] = bitreferencia;
        quadro_codificado[j + 1] = bitreferencia ^ 1;

        cout << quadro_codificado[j];
        cout << quadro_codificado[j + 1];
    }
    cout << endl;
    free(this->quadro);
    this->quadro = quadro_codificado;
    this->quadro_tamanho = novo_tamanho;
}

void fisica::CamadaFisicaReceptoraDecodificacaoBinaria()
{
    int *quadro_decodificado = (int *)malloc(sizeof(int) * this->quadro_tamanho);
    cout << "\n=========Recepção de Binaria=========" << endl;
    for (int i = 0; i < this->quadro_tamanho; i++)
    {
        if (this->quadro[i] != 0 && this->quadro[i] != 1)
        {
            cout << "Erro na mensagem: " << i << endl;
            break;
        }
        quadro_decodificado[i] = this->quadro[i];

        cout << quadro_decodificado[i];
    }
    cout << endl;
    free(this->quadro);
    this->quadro = quadro_decodificado;
}

void fisica::CamadaFisicaReceptoraDecodificacaoManchester()
{
    int novo_tamanho = this->quadro_tamanho / 2;
    int *quadro_decodificado = (int *)malloc(sizeof(int) * novo_tamanho);

    cout << "\n=========Recepção de Manchester=========" << endl;
    for (int i = 0, j = 0; i < this->quadro_tamanho; i += 2, j++)
    {
        if ((this->quadro[i] == 0) && (this->quadro[i + 1] == 1))
        {
            quadro_decodificado[j] = 0;
        }
        else if ((this->quadro[i] == 1) && (this->quadro[i + 1] == 0))
        {
            quadro_decodificado[j] = 1;
        }
        else
        {
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
    int novo_tamanho = this->quadro_tamanho / 2;
    int *quadro_decodificado = (int *)malloc(sizeof(int) * novo_tamanho);
    int bitreferencia = 0;

    cout << "\n======Recepção de Manchester Diferencial======" << endl;

    for (int i = 0, j = 0; i < this->quadro_tamanho; i += 2, j++)
    {

        if ((this->quadro[i] == (0 ^ bitreferencia)) && (this->quadro[i + 1] == (1 ^ bitreferencia)))
        {
            quadro_decodificado[j] = 0;
        }
        else if ((this->quadro[i] == (1 ^ bitreferencia)) && (this->quadro[i + 1] == (0 ^ bitreferencia)))
        {
            quadro_decodificado[j] = 1;
            bitreferencia = bitreferencia ^ 1;
        }
        else
        {
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
