#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <iterator>

using namespace std;

class fisica
{
private:
    int* quadro;
    int quadro_tamanho;
    void setQuadro(int*, int);
public:
    //All methods should modify the private atribute <quadro>
    //TRANSMISSÃO
    /**
     * @brief Chama métodos responsáveis pela codificação da mensagem
     * de acordo com o valor definido dentro do próprio método
     * 
     */
    void CamadaFisicaTransmissora();
    /**
     * @brief Simplesmente transmite o quadro que foi codificado
     * com codificação binária
     * 
     */
    void CamadaFisicaTransmissoraCodificacaoBinaria();
    /**
     * @brief Simplesmente pega o vetor de bits e repassa para próxima camada.  
     * Não há necessidade de se simular um clock.
     */
    void CamadaFisicaTransmissoraCodificacaoManchester();
    /**
     * @brief Realiza a codificação Manchester Diferencial para a
     * Realiza a codificação Manchester para a transmissão
     * Para simular o clock, a cada bit da mensagem foi feito uma
     * operação de XOR com o bit 0 e em seguida com o bit 1. O 
     * resultado dessas operações formam uma nova mensagem e então
     * à transmitem.
     * * 
     */
    void CamadaFisicaTransmissoraCodificacaoManchesterDiferencial();
    /**
     * @brief Chama métodos responsáveis pela decodificação da mensagem
     * de acordo com o valor definido dentro do próprio método
     * 
     */
    void CamadaFisicaReceptora();

    //RECEPÇÃO
    /**
     * @brief Realiza a decodificação binária verificando se 
     * algum bit é diferente de 0 ou 1 e, caso seja, devolve uma 
     * mensagem de erro e descarta a mensagem. Caso a mensagem 
     * esteja correta, salva o quadro
     * 
     */
    void CamadaFisicaReceptoraDecodificacaoBinaria();
    /**
     * @brief Realiza a decodificação binária simplesmente pegando
     * o vetor de bits anterior e transformando na mensagem enviada
     * pelo transmissor
     *
     */
    void CamadaFisicaReceptoraDecodificacaoManchester();
    /**
     * @brief Realiza a decodificação Manchester verificando se
     * alguma sequencia de bits tomados dois a dois é diferente
     * de '01' ou '10' e, caso seja, devolve uma mensagem de 
     * erro e descarta a mensagem. Caso a mensagem esteja correta,
     * salva o quadro
     * 
     */
    void CamadaFisicaReceptoraDecodificacaoManchesterDiferencial();

    //MEIO COMUNICAÇAO
    /**
     * @brief Simula a comunicação entre um ponto A e B. Por questão
     * de simplificação, a comunicação é realizada dentro da própria
     * classe instanciada, realizando chamadas de métodos
     * 
     */
    void MeioDeComunicacao();


    int* getQuadro();
    int getTamanho();

    fisica(int* quadro, int quadro_tamanho);
    ~fisica();
};

