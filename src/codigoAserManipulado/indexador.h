#ifndef INDEXADOR_H
#define INDEXADOR_H

////////////////referencia////////////////////

#include "separa.h"
#include "manipulacao_de_dados.h"
#include <structs.h>

///////////////bibliotecas////////////////////

#include <cctype>
#include <fstream>
#include <iostream>
#include <list>
#include <string>
#include <vector>
#include <cmath>

#include "prglib.h"

using namespace std;
using prglib::arvore;

// funcao utilizada para fazer a indexacao dos dados, recebendo o nome do
// arquivo de argv[1] e o nome da coluna de argv[2]
void indexar_dados(ifstream &arquivo, const string sep,
                   arvore<index> &indexaca, string nomeArq);

#endif