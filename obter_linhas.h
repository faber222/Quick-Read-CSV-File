#ifndef OBTER_LINHAS_H
#define OBTER_LINHAS_H

#include <structs.h>

#include <fstream>
#include <iostream>
#include <list>
#include <string>

#include "prglib.h"

using namespace std;
using prglib::arvore;

list<string> obter_linhas(const list<index> dados_solicitados,
                          string nome_arquivo);

#endif