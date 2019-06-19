#include "../include/wraper.hpp"

void wraper::AplicacaoTransmissora()
{
    string entrada_usuario;
    cout << "Digite uma mensagem:" << endl;
    getline(cin, entrada_usuario);
    this->mensagem = entrada_usuario;
    CamadaDeAplicacaoTransmissora();
}

void wraper::CamadaDeAplicacaoTransmissora()
{
    cout << "\n=========ENTRANDO CAMADA APLICACAO TRANSMISSORA=========" << endl;
    cout << "\n=========REALIZANDO CONVERSAO PARA BINARIO=========" << endl;
    string binario;
    for (size_t i = 0; i < this->mensagem.size(); i++)
    {
        bitset<8> bits(this->mensagem.c_str()[i]);
        binario += bits.to_string();
    }
    int *binario_array = (int *)malloc(binario.size() * sizeof(int));
    for (size_t i = 0; i < binario.size(); i++)
    {
        binario_array[i] = (int)binario.at(i) - 48;
        cout << binario_array[i];
    }
    cout << endl;
    this->quadro = binario_array;
    this->quadro_tamanho = binario.size();
    binario_array = nullptr;
    this->camada_fisica = new fisica(this->quadro, this->quadro_tamanho);
    this->camada_fisica->CamadaFisicaTransmissora();


    //Recuperar quadro da camada fisica
    this->quadro = this->camada_fisica->quadro;
    CamadaDeAplicacaoReceptora();
}

void wraper::AplicacaoReceptora()
{
    cout << "A mensagem recebida foi: " << this->mensagem << endl;
}

void wraper::CamadaDeAplicacaoReceptora()
{
    cout << "\n=========ENTRANDO CAMADA APLICACAO RECEPTORA=========" << endl;
    string bit_string = "";
    string mensagem_final = "";
    for (int i = 0; i < this->quadro_tamanho; i++)
    {
        bit_string += (char)(this->quadro[i] + 48);
    }
    stringstream sstream(bit_string);
    while(sstream.good()) {
        bitset<8> bits;
        sstream >> bits;
        char caractere = char(bits.to_ulong());
        mensagem_final += caractere;
    }
    this->mensagem = mensagem_final;
    AplicacaoReceptora();
}

wraper::wraper()
{
}

wraper::~wraper()
{
    delete this->camada_fisica;
}