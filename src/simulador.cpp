#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <iterator>
#include "../include/wraper.hpp"

using namespace std;

int main(int argc, char const *argv[])
{
	wraper* w = new wraper();
	w->AplicacaoTransmissora();
	delete w;

	return 0;
}
