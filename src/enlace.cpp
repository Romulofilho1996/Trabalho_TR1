#include "../include/enlace.hpp"

enlace::enlace(int *quadro_inicial, int quadro_tamanho)
{
    // setQuadro(quadro_inicial);
    this->quadro = quadro_inicial;
    this->quadro_tamanho = quadro_tamanho;
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
        CamadaEnlaceDadosTransmissoraControleDeErroBitParidadePar();
        break;
    case 1: //bit de paridade impar
        CamadaEnlaceDadosTransmissoraControleDeErroBitParidadeImpar();
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
    int *quadro_codificado;
    int novo_tamanho = this->quadro_tamanho + 1;
    bool paridade = false;
    quadro_codificado = (int *)malloc(sizeof(int) * novo_tamanho);
    cout << "\n=========Transmissão Codificada Paridade Par=========" << endl;
    for (int i = 0; i < this->quadro_tamanho; i++)
    {
        if (this->quadro[i] == 1)
        {
            paridade = !paridade;
        }
        quadro_codificado[i] = this->quadro[i];
    }
    quadro_codificado[this->quadro_tamanho] = int(paridade);
    for (int i = 0; i < novo_tamanho; i++)
    {
        cout << quadro_codificado[i];
    }
    cout << endl;
    // free(this->quadro);
    this->quadro = quadro_codificado;
    this->quadro_tamanho = novo_tamanho;
}

void enlace::CamadaEnlaceDadosTransmissoraControleDeErroBitParidadeImpar()
{
    int *quadro_codificado;
    int novo_tamanho = this->quadro_tamanho + 1;
    bool paridade = true;
    quadro_codificado = (int *)malloc(sizeof(int) * novo_tamanho);
    cout << "\n=========Transmissão Codificada Paridade Par=========" << endl;
    for (int i = 0; i < this->quadro_tamanho; i++)
    {
        if (this->quadro[i] == 1)
        {
            paridade = !paridade;
        }
        quadro_codificado[i] = this->quadro[i];
    }
    quadro_codificado[this->quadro_tamanho] = int(paridade);
    for (int i = 0; i < novo_tamanho; i++)
    {
        cout << quadro_codificado[i];
    }
    cout << endl;
    // free(this->quadro);
    this->quadro = quadro_codificado;
    this->quadro_tamanho = novo_tamanho;
}

void enlace::CamadaEnlaceDadosTransmissoraControleDeErroCRC()
{
    // 0x04C11DB7
    // x26 + x23 + x22 + x16 + x12 + x11 + x10 + x8 + x7 + x5 + x4 + x2 + x + 1
    // 0000 0100 1100 0001 0001 1101 1011 0111
    cout << "\n=========Transmissão Codificada CRC-32=========" << endl;
    cout << "Quadro a ser transmitido: ";
    for (int i = 0; i < this->quadro_tamanho; i++)
    {
        cout << this->quadro[i];
    }
    // Removi os 0's da frente pra facilitar na divisao
    int polinomio[] = {1, 0, 0, 1, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 1};
    cout << endl
         << "Polinomio: ";
    for (int i = 0; i < 27; i++)
    {
        cout << polinomio[i];
    }

    // Padding de tamanho (grau do polinomio-1)
    int novo_tamanho = this->quadro_tamanho + 31;
    int *quadro_crc = (int *)malloc(sizeof(int) * novo_tamanho);
    for (int i = 0; i < novo_tamanho; i++)
    {
        if (i < this->quadro_tamanho)
            quadro_crc[i] = this->quadro[i];
        else
            quadro_crc[i] = 0;

    }
    cout << endl;

    for (int i = 0; i < this->quadro_tamanho; i++)
    {
        if (quadro_crc[i] == 1)
        {
            //Faz o XOR com todos os elementos do polinomio
            for (int j = 0; j < 27; j++)
            {
                quadro_crc[j + i] ^= polinomio[j];
            }
        }
    }

    for (int i = 0; i < this->quadro_tamanho; i++)
    {
        quadro_crc[i] = this->quadro[i];
    }
    cout << "Quadro CRC-32: ";
    for (int i = 0; i < novo_tamanho; i++)
    {
        cout << quadro_crc[i];
    }
    cout << endl;

    this->quadro_tamanho = novo_tamanho;
    this->quadro = quadro_crc;
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
        CamadaEnlaceDadosReceptoraControleDeErroBitDeParidadePar();
        break;
    case 1: //bit de paridade impar
        CamadaEnlaceDadosReceptoraControleDeErroBitDeParidadeImpar();
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
    int *quadro_codificado = (int *)malloc(sizeof(int) * this->quadro_tamanho);
    int novo_tamanho = this->quadro_tamanho - 1;
    bool paridade = false;
    cout << "\n=========Recepção Codificada Paridade Par=========" << endl;
    for (int i = 0; i < novo_tamanho; i++)
    {
        if (this->quadro[i] == 1)
        {
            paridade = !paridade;
        }
        quadro_codificado[i] = this->quadro[i];
        cout << quadro_codificado[i];
    }
    cout << this->quadro[novo_tamanho];
    if (this->quadro[novo_tamanho] != int(paridade))
    {
        cout << endl
             << "Erro na mensagem" << endl;
    }
    cout << endl;
    free(this->quadro);
    this->quadro = quadro_codificado;
    this->quadro_tamanho = novo_tamanho;
}

void enlace::CamadaEnlaceDadosReceptoraControleDeErroBitDeParidadeImpar()
{
    int *quadro_codificado = (int *)malloc(sizeof(int) * this->quadro_tamanho);
    int novo_tamanho = this->quadro_tamanho - 1;
    bool paridade = true;
    cout << "\n=========Recepção Codificada Paridade Par=========" << endl;
    for (int i = 0; i < novo_tamanho; i++)
    {
        if (this->quadro[i] == 1)
        {
            paridade = !paridade;
        }
        quadro_codificado[i] = this->quadro[i];
        cout << quadro_codificado[i];
    }
    cout << this->quadro[novo_tamanho];
    if (this->quadro[novo_tamanho] != int(paridade))
    {
        cout << endl
             << "Erro na mensagem" << endl;
    }
    cout << endl;
    free(this->quadro);
    this->quadro = quadro_codificado;
    this->quadro_tamanho = novo_tamanho;
}

void enlace::CamadaEnlaceDadosReceptoraControleDeErroCRC()
{
    // 0x04C11DB7
    // x26 + x23 + x22 + x16 + x12 + x11 + x10 + x8 + x7 + x5 + x4 + x2 + x + 1
    // 0000 0100 1100 0001 0001 1101 1011 0111
    cout << "\n=========Recepção Codificada CRC-32=========" << endl;
    cout << "Quadro Recebido: ";
    for (int i = 0; i < this->quadro_tamanho; i++)
    {
        cout << this->quadro[i];
    }
    int polinomio[] = {1, 0, 0, 1, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 1};

    cout << endl
         << "Polinomio: ";
    for (int i = 0; i < 27; i++)
    {
        cout << polinomio[i];
    }

    int *quadro_crc = this->quadro;
    int tamanho_mensagem = this->quadro_tamanho - 31;
    cout << endl;
    for (int i = 0; i < tamanho_mensagem; i++)
    {
        if (quadro_crc[i] == 1)
        {
            for (int j = 0; j < 27; j++)
            {
                quadro_crc[j + i] = quadro_crc[j + i] == polinomio[j] ? 0 : 1;
            }
        }
    }

    cout << "\nResto: ";
    for (int i = 0; i < this->quadro_tamanho; i++)
    {
        cout << quadro_crc[i];
    }
    cout << endl;

}

void enlace::CamadaEnlaceDadosReceptoraControleDeErroCodigoDeHamming()
{
}
