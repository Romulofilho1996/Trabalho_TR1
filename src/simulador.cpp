#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <iterator>
#include "../include/enlace.hpp"
#include "../include/fisica.hpp"
#include "../include/wraper.hpp"

#define TAM_QUADRO 8

using namespace std;
long int size = 0;
int posicaoTotal = 0;
char mem[1000];
char quadro[8];
char hamming[12];

void pegarDadosEnvio()
{
	FILE *file;
	file = fopen("../assets/text.bin", "rb");
	fread(mem, sizeof(mem), 1, file);
	fseek(file, 0L, SEEK_END);
	size = ftell(file);
}

void montarQuadro()
{
	int j = 0;
	for (int i = posicaoTotal; i < (posicaoTotal + 8); i++)
	{
		quadro[j] = mem[i];
		j++;
	}
	j = 0;
	posicaoTotal += 9;
	printf("Quadro: %s\n", quadro);
}

void bitParidade()
{
	bool paridadeBool = false;
	for (int i = 0; i < TAM_QUADRO; i++)
	{
		if (quadro[i] == '1')
		{
			paridadeBool = !paridadeBool;
		}
	}
	printf("Bit paridade par: %d\n", paridadeBool);
	printf("Bit paridade impar: %d\n", !paridadeBool);
}



void codigoDeHamming(){
	int data[12];
	int datareceived[12],c1,c2,c4,c8,c,i=1,n=0;
	//cout << "lendo quadro\n";
	cout << "Hamming (12,8): ";
	data[2] = quadro[0];
	data[4] = quadro[1];
	data[5] = quadro[2];
	data[6] = quadro[3];
	data[8] = quadro[4];
	data[9] = quadro[5];
	data[10] = quadro[6];
	data[11] = quadro[7];
	//cout << "calculando bits especiais \n";
	data[0] = data[2] ^ data[4] ^ data[6] ^ data[8] ^ data[10];
	data[1] = data[2] ^ data[5] ^ data[6] ^ data[9] ^ data[10];
	data[3] = data[4] ^ data[5] ^ data[6] ^ data[11];
	data[7] = data[8] ^ data[9] ^ data[10] ^ data[11];
	//cout << "parte do receiver \n";
	for (int i = 0; i < 12; ++i)
	{
		datareceived[i] = data[i];
	}
	//e se receiver receber bit flipado?
	//datareceived[5] = 0;
	
	c1 = datareceived[0] ^ datareceived[2] ^ datareceived[4] ^ datareceived[6] ^ datareceived[8] ^ datareceived[10];
	c2 = datareceived[1] ^ datareceived[2] ^ datareceived[5] ^ datareceived[6] ^ datareceived[9] ^ datareceived[10];
    c4 = datareceived[3] ^ datareceived[4] ^ datareceived[5] ^ datareceived[6] ^ datareceived[11];
    c8 = datareceived[7] ^ datareceived[8] ^ datareceived[9] ^ datareceived[10] ^ datareceived[11];
    c = ((c8*8) + (c4*4) + (c2*2) + c1); 

    if (c == 0)
    {
    	cout<<"\nSem erro durante a transimissao\n";
    }
    else {
    cout<<"\nError na posicao "<<c;
    cout<<"\nDado enviado: ";
    for(i=0;i<12;i++)
          cout<<data[i];
        
    cout<<"\nDado recebido: ";
        for(i=0;i<12;i++)
          cout<<datareceived[i];
        
    cout<<"\nDado correto é: \n";
        
    if(datareceived[12-c]==0)
      datareceived[12-c]=1;
        else
      datareceived[12-c]=0;
    for (i=0;i<12;i++) {
      cout<<datareceived[i];
    }
  }
		
}



int main(int argc, char const *argv[])
{
	// pegarDadosEnvio();
	// while (size != 0)
	// {
	// 	montarQuadro();
	// 	bitParidade();
	// 	//codigoDeHamming();
	// 	size -= 9;
	// }

	wraper* w = new wraper();
	w->AplicacaoTransmissora();

	fisica *camada_fisica = new fisica(w->quadro, w->quadro_tamanho);
	camada_fisica->CamadaFisicaTransmissoraCodificacaoManchester();

	return 0;
}
