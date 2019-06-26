#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <iterator>
#include <algorithm>

using namespace std;

class enlace
{
private:
    
public:
    int* quadro;
    int quadro_tamanho;
    //TRANSMISSÃO
    void CamadaEnlaceDadosTransmissora();
    void CamadaEnlaceDadosTransmissoraEnquadramento();
    void CamadaEnlaceDadosTransmissoraControleDeErro();

    /**
     * @brief Realiza o controle de erro de paridade par.
     * Encontra a paridade realizando operações NOT numa variável booleana
     * a cada '1' encontrado, para então adicionar a variável ao quadro.
     */
    void CamadaEnlaceDadosTransmissoraControleDeErroBitParidadePar();

    /**
     * @brief Realiza o controle de erro de paridade par.
     * Encontra a paridade realizando operações NOT numa variável booleana
     * a cada '1' encontrado, para então adicionar a variável ao quadro.
     */
    void CamadaEnlaceDadosTransmissoraControleDeErroBitParidadeImpar();
    void CamadaEnlaceDadosTransmissoraControleDeErroCRC();
    void CamadaEnlaceDadosTransmissoraControleDeErroCodigoDeHamming();

    //RECEPÇÃO
    void CamadaEnlaceDadosReceptora();
    void CamadaEnlaceDadosReceptoraEnquadramento();
    void CamadaEnlaceDadosReceptoraControleDeErro();

    /**
     * @brief Realiza o controle de erro de paridade par.
     * Encontra a paridade realizando operações NOT numa variável booleana
     * a cada '1' encontrado no quadro recebido, então compara
     * a variável encontrada com o último elemento do quadro recebido.
     * Caso sejam diferentes, houve erro na transmissão.
     */
    void CamadaEnlaceDadosReceptoraControleDeErroBitDeParidadePar();

    /**
     * @brief Realiza o controle de erro de paridade par.
     * Encontra a paridade realizando operações NOT numa variável booleana
     * a cada '1' encontrado no quadro recebido, então compara
     * a variável encontrada com o último elemento do quadro recebido.
     * Caso sejam diferentes, houve erro na transmissão.
     */
    void CamadaEnlaceDadosReceptoraControleDeErroBitDeParidadeImpar();
    void CamadaEnlaceDadosReceptoraControleDeErroCRC();
    void CamadaEnlaceDadosReceptoraControleDeErroCodigoDeHamming();

    enlace(int* quadro, int quadro_tamanho);
    ~enlace();
};