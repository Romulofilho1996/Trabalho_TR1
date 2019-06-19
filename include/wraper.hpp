#include <iostream>
#include <bitset>
#include <string>
#include <sstream>
#include "./enlace.hpp"
#include "./fisica.hpp"

using namespace std;

class wraper
{
private:
    //Atributo que guarda mensagem inicial ou final da simulação
    string mensagem;
    //Atributo que guarda referencia da camada fisica
    fisica *camada_fisica;
    //Atributo que guarda referencia da camada de enlace
    enlace *camada_enlace;

public:
    //Guarda quadro inicial antes dos processos de codificação
    int *quadro;
    //Guarda tamanho do quadro inicial antes dos processos de codificação
    int quadro_tamanho;

    /**
     *  @brief Simula recebimento de mensagem pela camada de aplicação
     */
    void AplicacaoTransmissora();

    /**
     *  @brief Transforma mensagem de ASCII chars para binário
     */
    void CamadaDeAplicacaoTransmissora();

    /**
     *  @brief Recebe mensagem ao final de todo processo de transmissão,
     *  simulando aplicação receptora
     */
    void AplicacaoReceptora();

    /**
     *  @brief Transforma o fluxo de binário ao final da transmissão,
     *  para string novamente.
     */
    void CamadaDeAplicacaoReceptora();

    /**
     *  @brief Construtora da classe wraper.
     */
    wraper();


    /**
     *  @brief Destrutor da classe wraper, desreferencia e desaloca as memorias
     *  utilizadas.
     */
    ~wraper();
};