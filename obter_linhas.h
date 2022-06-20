#ifndef OBTER_LINHAS_H
#define OBTER_LINHAS_H

////////////////referencia////////////////////

#include <structs.h>

///////////////bibliotecas////////////////////

#include <cctype>
#include <fstream>
#include <iostream>
#include <list>
#include <string>

#include "prglib.h"

using namespace std;
using prglib::arvore;

////////////declaracao da funcao//////////////

list<string> obter_linhas(const list<index> dados_solicitados,
                          string nome_arquivo);

#endif