#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <fstream>
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

int main(int argc, char const *argv[]) {
	pegarDadosEnvio();
	while(size != 0){
		montarQuadro();
		size -= 9;
	}
    return 0;
}
