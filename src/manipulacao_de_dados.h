#ifndef MANIPULACAO_DE_DADOS_H
#define MANIPULACAO_DE_DADOS_H

////////////////referencia////////////////////

#include <structs.h>

///////////////bibliotecas////////////////////

#include <fstream>
#include <iostream>
#include <list>
#include <string>

#include "prglib.h"

using namespace std;
using prglib::arvore;

////////////declaracao da funcao//////////////

// funcao usada para capturar os dados de valor 1 e valor 2
void entrada_valores(string &valor1, string &valor2);

// funcao usada para obter as linhas do range de valor 1 e valor 2
list<string> obter_linhas(const list<index> dados_solicitados, ifstream &arq);

// funcao para mostrar os resultados de obter linhas
void mostrar_resultado(list<string> printar);

#endif