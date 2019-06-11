#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <fstream>

#define TAM_QUADRO 8

/**
 * Integrantes:
 * 
 * Christian Luis - 15/0153538
 * Thiago Araújo da Silva - 15/0149832
 * Rômulo de Vasconcelos Feijão Filho - 14/00312602
 * Matheus Feitosa de Castro - 15/01412974
 * Guilherme Andreúce- 14/01419615
 * Gabriel Guerra - 15/0126247
 * 
**/
using namespace std;
long int size = 0;
int posicaoTotal = 0;
char mem[1000];
char quadro[8];
char quadroParidadePar[9];

void pegarDadosEnvio(){
	int buffer;
	FILE *file;
	file = fopen("text.bin", "rb");
	fread(mem, sizeof(mem), 1, file);
	fseek(file, 0L, SEEK_END);
	size = ftell(file);
}

void montarQuadro(){
	int j = 0;
	for(int i = posicaoTotal; i < (posicaoTotal+8); i++){
		quadro[j] = mem[i];
		j++;
	}
	j = 0; posicaoTotal += 9;
	printf("%s\n", quadro);
}

void bitParidade(){
	int paridade = 0;
	int bitParidadePar = 0;
	int bitParidadeImpar = 0;
	for(int i = 0; i < TAM_QUADRO; i++){
		if(quadro[i] == '1'){
			paridade += 1;
		}
	}
	bitParidadePar = paridade % 2;
	bitParidadeImpar = (bitParidadePar + 1) % 2;
	printf("Bit paridade par: ");
	printf("%d\n", bitParidadePar);
	printf("Bit paridade impar: ");
	printf("%d\n", bitParidadeImpar);
}

int main(int argc, char const *argv[]) {
	pegarDadosEnvio();
	while(size != 0){
		montarQuadro();
		bitParidade();
		size -= 9;
	}
    return 0;
}
