#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <iterator>
#include "../include/wraper.hpp"

/**
 * Integrantes:
 * 
 * Christian Luis - 15/0153538
 * Thiago Araújo da Silva - 15/0149832
 * Rômulo de Vasconcelos Feijão Filho - 14/0031260
 * Matheus Feitosa de Castro - 15/01412974
 * Guilherme Andreúce- 14/01419615
 * Gabriel Guerra - 15/0126247
 * 
**/
using namespace std;

int main(int argc, char const *argv[])
{
	wraper* w = new wraper();
	w->AplicacaoTransmissora();
	 
	delete w;
	return 0;
}
