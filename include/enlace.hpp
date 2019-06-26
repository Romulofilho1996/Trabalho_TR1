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
    
    void setQuadro(int*);

public:
    int* quadro;
    int quadro_tamanho;
    //TRANSMISSÃO
    void CamadaEnlaceDadosTransmissora();
    void CamadaEnlaceDadosTransmissoraEnquadramento();
    void CamadaEnlaceDadosTransmissoraControleDeErro();
    void CamadaEnlaceDadosTransmissoraControleDeFluxo();

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

    /**
     * @brief Realiza o codificação CRC-32 para controle de erro.
     * Primeiramente, é gerado um polinômio de grau 32. Em 
     * seguida, a partir do quadro original, geramos um novo
     * quadro com (32-1) bits acrescentados ao final do quadro
     * original preenchidos com 0. Neste novo quadro, fazemos
     * a operação de XOR com o polinomio gerado (CRC) sempre que
     * for encontrado o bit 1. A operação de XOR é realizada até
     * que se chegue a posição do ultimo bit do quadro original.
     * Em seguida, é feita a soma bit a bit do quadro novo com
     * o quadro CRC, e este novo quadro é então enviado
     * 
     */
    void CamadaEnlaceDadosTransmissoraControleDeErroCRC();
    void CamadaEnlaceDadosTransmissoraControleDeErroCodigoDeHamming();

    //RECEPÇÃO
    void CamadaEnlaceDadosReceptora();
    void CamadaEnlaceDadosReceptoraEnquadramento();
    void CamadaEnlaceDadosReceptoraControleDeErro();
    void CamadaEnlaceDadosReceptoraControleDeFluxo();

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
    /**
     * @brief Realiza o codificação CRC-32 para controle de erro.
     * Com o mesmo polinomio gerado na transmissão, é feito a 
     * operação de XOR com o quadro recebido até a posição do
     * (tamanho do quadro-(32-1)), se o resultado obtido dessas
     * operações for 0, então o quadro foi recebido corretamente.
     * Caso sejam diferentes, houve erro na transmissão.
     * 
     */
    void CamadaEnlaceDadosReceptoraControleDeErroCRC();
    void CamadaEnlaceDadosReceptoraControleDeErroCodigoDeHamming();

    int* getQuadro();

    enlace(int* quadro, int quadro_tamanho);
    ~enlace();
};