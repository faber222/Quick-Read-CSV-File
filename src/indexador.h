#ifndef INDEXADOR_H
#define INDEXADOR_H

////////////////referencia////////////////////

#include "separa.h"
#include <structs.h>

///////////////bibliotecas////////////////////

#include <fstream>
#include <iostream>
#include <list>
#include <string>

#include "prglib.h"

using namespace std;
using prglib::arvore;

// funcao utilizada para fazer a indexacao dos dados, recebendo o nome do
// arquivo de argv[1] e o nome da coluna de argv[2]
void indexar_dados(ifstream &arquivo, string coluna_escolhida, const string sep,
                   arvore<index> &indexacao);

#endif