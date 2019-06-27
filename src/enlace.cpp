#include "../include/enlace.hpp"

enlace::enlace(int *quadro_inicial, int quadro_tamanho)
{
    this->quadro = quadro_inicial;
    this->quadro_tamanho = quadro_tamanho;
}

enlace::~enlace()
{
    free(this->quadro);
    this->quadro = nullptr;
}

void enlace::CamadaEnlaceDadosTransmissora()
{
    cout << endl
    << "==================CAMADA ENLACE TRANSMISSORA================" << endl;
    CamadaEnlaceDadosTransmissoraEnquadramento();
    CamadaEnlaceDadosTransmissoraControleDeErro();
}

void enlace::CamadaEnlaceDadosReceptora()
{
    cout << endl
    << "====================CAMADA ENLACE RECEPTORA=================" << endl;
    CamadaEnlaceDadosReceptoraEnquadramento();
    CamadaEnlaceDadosReceptoraControleDeErro();
}

void enlace::CamadaEnlaceDadosTransmissoraEnquadramento()
{
}

void enlace::CamadaEnlaceDadosTransmissoraControleDeErro()
{
    int tipoDeControleDeErro = 3; // Alterar de acordo com o teste
    switch (tipoDeControleDeErro)
    {
        case 0:
        CamadaEnlaceDadosTransmissoraControleDeErroBitParidadePar();
        break;
        case 1:
        CamadaEnlaceDadosTransmissoraControleDeErroBitParidadeImpar();
        break;
        case 2:
        CamadaEnlaceDadosTransmissoraControleDeErroCRC();
        break;
        case 3:
        CamadaEnlaceDadosTransmissoraControleDeErroCodigoDeHamming();
        break;
    }
}

void enlace::CamadaEnlaceDadosTransmissoraControleDeErroBitParidadePar()
{
    cout << endl
    << "=====================CONTROLE PARIDADE PAR==================" << endl;

    int *quadro_codificado;
    int novo_tamanho = this->quadro_tamanho + 1;
    bool paridade = false;
    quadro_codificado = (int *)malloc(sizeof(int) * novo_tamanho);

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
    cout << endl
    << "=====================CONTROLE PARIDADE IMPAR================" << endl;

    int *quadro_codificado;
    int novo_tamanho = this->quadro_tamanho + 1;
    bool paridade = true;
    quadro_codificado = (int *)malloc(sizeof(int) * novo_tamanho);

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
    cout << endl
    << "========================CONTROLE CRC 32=====================" << endl;
    // 0x04C11DB7
    // x26 + x23 + x22 + x16 + x12 + x11 + x10 + x8 + x7 + x5 + x4 + x2 + x + 1
    // 0000 0100 1100 0001 0001 1101 1011 0111
    cout << endl
    << "QUADRO: ";
    for (int i = 0; i < this->quadro_tamanho; i++)
    {
        cout << this->quadro[i];
    }
    // Removi os 0's da frente pra facilitar na divisao
    int polinomio[27] = {1, 0, 0, 1, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 1};
    cout << endl
    << "POLINOMIO: ";
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
    cout << "CRC-32: ";
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
    cout << endl
    << "========================CONTROLE HAMMING====================" << endl;

    int potencias[4] = {0, 1, 3, 7};
    int j = 0;
    int *quadro_codificado;
    int novo_tamanho = this->quadro_tamanho + (4 * this->quadro_tamanho / 8);
    quadro_codificado = (int *)malloc(sizeof(int) * novo_tamanho);
    for (int k = 0; k < this->quadro_tamanho / 8; k++)
    {
        for (int i = k * 12; i < (k * 12) + 12; i++)
        {
            if (find(begin(potencias), end(potencias), i % 12) == end(potencias))
            {
                quadro_codificado[i] = this->quadro[j];
                j++;
            }
            else
            {
                quadro_codificado[i] = 0;
            }
        }
    }
    for (int k = 0; k < novo_tamanho / 12; k++)
    {
        for (int i = k * 12; i < (k * 12) + 12; i++)
        {
            switch (i % 12)
            {
                case 0:
                quadro_codificado[i] = quadro_codificado[i + 2] ^ quadro_codificado[i + 4] ^ quadro_codificado[i + 6] ^ quadro_codificado[i + 8] ^ quadro_codificado[i + 10];
                break;
                case 1:
                quadro_codificado[i] = quadro_codificado[i + 1] ^ quadro_codificado[i + 4] ^ quadro_codificado[i + 5] ^ quadro_codificado[i + 8] ^ quadro_codificado[i + 9];
                break;
                case 3:
                quadro_codificado[i] = quadro_codificado[i + 1] ^ quadro_codificado[i + 2] ^ quadro_codificado[i + 3] ^ quadro_codificado[i + 8];
                break;
                case 7:
                quadro_codificado[i] = quadro_codificado[i + 1] ^ quadro_codificado[i + 2] ^ quadro_codificado[i + 3] ^ quadro_codificado[i + 4];
                break;
            }
        }
    }
    for (int i = 0; i < novo_tamanho; i++)
    {
        cout << quadro_codificado[i];
    }
    cout << endl;
    this->quadro = quadro_codificado;
    this->quadro_tamanho = novo_tamanho;
}

void enlace::CamadaEnlaceDadosReceptoraEnquadramento()
{
}

void enlace::CamadaEnlaceDadosReceptoraControleDeErro()
{
    int tipoDeControleDeErro = 3; // Alterar de acordo com o teste
    switch (tipoDeControleDeErro)
    {
        case 0:
        CamadaEnlaceDadosReceptoraControleDeErroBitDeParidadePar();
        break;
        case 1:
        CamadaEnlaceDadosReceptoraControleDeErroBitDeParidadeImpar();
        break;
        case 2:
        CamadaEnlaceDadosReceptoraControleDeErroCRC();
        break;
        case 3:
        CamadaEnlaceDadosReceptoraControleDeErroCodigoDeHamming();
        break;
    }
}

void enlace::CamadaEnlaceDadosReceptoraControleDeErroBitDeParidadePar()
{
    cout << endl
    << "=====================RECEPCAO PARIDADE PAR==================" << endl;

    int *quadro_codificado = (int *)malloc(sizeof(int) * this->quadro_tamanho);
    int novo_tamanho = this->quadro_tamanho - 1;
    bool paridade = false;
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
        cout << endl << "ERRO NA MENSAGEM" << endl;
        exit(EXIT_FAILURE);
    }
    cout << endl;
    free(this->quadro);
    this->quadro = quadro_codificado;
    this->quadro_tamanho = novo_tamanho;
}

void enlace::CamadaEnlaceDadosReceptoraControleDeErroBitDeParidadeImpar()
{
    cout << endl
    << "=====================RECEPCAO PARIDADE IMPAR================" << endl;

    int *quadro_codificado = (int *)malloc(sizeof(int) * this->quadro_tamanho);
    int novo_tamanho = this->quadro_tamanho - 1;
    bool paridade = true;
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
        cout << endl << "ERRO NA MENSAGEM" << endl;
        exit(EXIT_FAILURE);
    }
    cout << endl;
    free(this->quadro);
    this->quadro = quadro_codificado;
    this->quadro_tamanho = novo_tamanho;
}

void enlace::CamadaEnlaceDadosReceptoraControleDeErroCRC()
{
    cout << endl
    << "========================RECEPCAO CRC 32=====================" << endl;
    cout << endl
    << "QUADRO: ";
    bool quadro_valido = true;

    int tamanho_decodificado = this->quadro_tamanho - 31;
    int *quadro_decodificado = (int *)malloc(sizeof(int) * tamanho_decodificado);
    for (int i = 0; i < tamanho_decodificado; i++)
    {
        quadro_decodificado[i] = this->quadro[i];
    }

    for (int i = 0; i < this->quadro_tamanho; i++)
    {
        cout << this->quadro[i];
    }
    int polinomio[27] = {1, 0, 0, 1, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 1};

    cout << endl
    << "POLINOMIO: ";
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

    cout << "RESTO: ";
    for (int i = 0; i < this->quadro_tamanho; i++)
    {
        if (quadro_crc[i] != 0)
        {
            quadro_valido = false;
        }
        cout << quadro_crc[i];
    }
    cout << endl;

    if (quadro_valido)
    {
        this->quadro = quadro_decodificado;
        this->quadro_tamanho = tamanho_decodificado;
    }
    else
    {
        cout << endl << "ERRO NA MENSAGEM" << endl;
        exit(EXIT_FAILURE);
    }
}

void enlace::CamadaEnlaceDadosReceptoraControleDeErroCodigoDeHamming()
{
    int c0=0,c1=0,c3=0,c7=0,c=0,k=0,j=0;
    int *quadro_decodificado;
    int novo_tamanho = this->quadro_tamanho - (4 * (this->quadro_tamanho) / 12); //tamanho 8
    cout <<"teste " << novo_tamanho << endl;
    quadro_decodificado = (int *)malloc(sizeof(int) * novo_tamanho);  //quadro pra voltar pro tamanho original
    cout << "\n=========Recepção Codificada Hamming=========" << endl;
    for(int k = 0; k < this->quadro_tamanho / 12; k++){  //pega a quantidade de quadros possiveis com tamanho 12
        for(int i = k * 12; i < (k * 12) + 12; i++){     //verifica se o quadro veio com erro pegando os bits de controle do hamming
            if(i % 12 == 0){
              c0 = this->quadro[i+0] ^ this->quadro[i+2] ^ this->quadro[i+4] ^ this->quadro[i+6] ^ this->quadro[i+8] ^ this->quadro[i+10];
          }
          if(i % 12 == 1){  
              c1 = this->quadro[i+0] ^ this->quadro[i+1] ^ this->quadro[i+4] ^ this->quadro[i+5] ^ this->quadro[i+8] ^ this->quadro[i+9]; 
          }
          if(i % 12 == 3){  
              c3 = this->quadro[i+0] ^ this->quadro[i+1] ^ this->quadro[i+2] ^ this->quadro[i+3] ^ this->quadro[i+8];
          }       
          if(i % 12 == 7){  
              c7 = this->quadro[i+0] ^ this->quadro[i+1] ^ this->quadro[i+2] ^ this->quadro[i+3] ^ this->quadro[i+4];   
          }
          if(i % 12 == 11){
                    c = ((c7*8) + (c3*4) + (c1*2) + c0);             //calculo pra ver qual bit veio com defeito se tiver defeito
                    if (c == 0)
                    {
                      cout<<"\nDado recebido: ";
                      for(int i = k * 12; i < (k * 12) + 12; i++)
                          cout<<this->quadro[i];
                      cout<<"\nSem erro durante a transimissao\n";
                  }   
                  else {
                    cout<<"\nError na posicao "<< c;
                    cout<<"\nDado recebido: ";
                    for(int i = k * 12; i < (k * 12) + 12; i++)
                      cout<<this->quadro[i];

                  cout<<"\nDado correto é: \n";

                  if(quadro[12-c]==0)
                      quadro[12-c]=1;
                  else
                      quadro[12-c]=0;
                  for(int i = k * 12; i < (k * 12) + 12; i++) {
                      cout<<this->quadro[i];
                  } 
              }

          }
      }




  }
    while(k <= (this->quadro_tamanho / 12) * 8)  //quantos quadros eu tenho. aqui coloca os bits nas posicoes certas
    {       
        quadro_decodificado[k] = this->quadro[j+2];
        quadro_decodificado[k+1] = this->quadro[j+4];
        quadro_decodificado[k+2] = this->quadro[j+5];
        quadro_decodificado[k+3] = this->quadro[j+6];
        quadro_decodificado[k+4] = this->quadro[j+8];
        quadro_decodificado[k+5] = this->quadro[j+9];
        quadro_decodificado[k+6] = this->quadro[j+10];
        quadro_decodificado[k+7] = this->quadro[j+11];
        k+=8;
        j+=12;
    }   
    this->quadro = quadro_decodificado;
    this->quadro_tamanho = novo_tamanho;
}
