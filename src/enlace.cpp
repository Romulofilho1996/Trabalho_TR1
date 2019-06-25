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
    int tipoDeControleDeErro = 3; //alterar de acordo com o teste
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
        CamadaEnlaceDadosTransmissoraControleDeErroCodigoDeHamming();
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
        if(this->quadro[i] == 1) {
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
        if(this->quadro[i] == 1) {
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
}

void enlace::CamadaEnlaceDadosTransmissoraControleDeErroCodigoDeHamming()
{
    int potencias[4] = {0,1,3,7};
    int j = 0;
    int *quadro_codificado;
    int novo_tamanho = this->quadro_tamanho + 4;
    quadro_codificado = (int *)malloc(sizeof(int) * novo_tamanho);
    cout << "\n=========Transmissão Codificada Hamming=========" << endl;
    for(int i = 0; i < novo_tamanho; i++){
        if(find(begin(potencias), end(potencias), i) == end(potencias)){
            quadro_codificado[i] = this->quadro[j];
            j++;
        }else{
            quadro_codificado[i] = 0;
        }
    }
    for(int i = 0; i < novo_tamanho; i++){
        switch(i){
            case 0: quadro_codificado[i] = quadro_codificado[2] ^ quadro_codificado[4] ^ quadro_codificado[6] ^ quadro_codificado[8] ^ quadro_codificado[10]; break;
            case 1: quadro_codificado[i] = quadro_codificado[2] ^ quadro_codificado[5] ^ quadro_codificado[6] ^ quadro_codificado[9] ^ quadro_codificado[10]; break;
            case 3: quadro_codificado[i] = quadro_codificado[4] ^ quadro_codificado[5] ^ quadro_codificado[6]; break;
            case 7: quadro_codificado[i] = quadro_codificado[8] ^ quadro_codificado[9] ^ quadro_codificado[10]; break;
        }
    }
    for(int i = 0; i < novo_tamanho; i++){
        printf("%d", quadro_codificado[i]);
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
    int tipoDeControleDeErro = 3; //alterar de acordo com o teste
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
        if(this->quadro[i] == 1) {
            paridade = !paridade;
        }
        quadro_codificado[i] = this->quadro[i];
        cout << quadro_codificado[i];
    }
    cout << this->quadro[novo_tamanho];
    if(this->quadro[novo_tamanho] != int(paridade)) {
        cout << endl << "Erro na mensagem" << endl;
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
        if(this->quadro[i] == 1) {
            paridade = !paridade;
        }
        quadro_codificado[i] = this->quadro[i];
        cout << quadro_codificado[i];
    }
    cout << this->quadro[novo_tamanho];
    if(this->quadro[novo_tamanho] != int(paridade)) {
        cout << endl << "Erro na mensagem" << endl;
    }
    cout << endl;
    free(this->quadro);
    this->quadro = quadro_codificado;
    this->quadro_tamanho = novo_tamanho;
}

void enlace::CamadaEnlaceDadosReceptoraControleDeErroCRC()
{
}

void enlace::CamadaEnlaceDadosReceptoraControleDeErroCodigoDeHamming()
{
}
