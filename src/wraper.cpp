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
    }
    this->quadro = binario_array;
    this->quadro_tamanho = binario.size();
    binario_array = nullptr;
    MeioDeComunicacao();
}

void wraper::MeioDeComunicacao()
{
    cout << "Binario: ";
    for (int i = 0; i < this->quadro_tamanho; i++)
    {
        cout << this->quadro[i];
    }
    cout << endl;
}

void wraper::AplicacaoReceptora()
{
}

void wraper::CamadaDeAplicacaoReceptora()
{
}

wraper::wraper()
{
}

wraper::~wraper()
{
}