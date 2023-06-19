#ifndef MANIPULACAO_DE_DADOS_H
#define MANIPULACAO_DE_DADOS_H

////////////////referencia////////////////////

#include <structs.h>

///////////////bibliotecas////////////////////

#include <cctype>
#include <fstream>
#include <iostream>
#include <list>
#include <vector>
#include <cmath>
#include <string>

#include "prglib.h"

using namespace std;
using prglib::arvore;

////////////declaracao da funcao//////////////

double calcularDesvioPadrao(const vector<double>& numeros, const double media);

// funcao para mostrar os resultados de obter linhas
void mostrar_resultado(vector<double> desvio, double media, string nomeArq);

#endif