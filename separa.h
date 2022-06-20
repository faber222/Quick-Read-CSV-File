#ifndef SEPARA_H
#define SEPARA_H

////////////////referencia////////////////////

#include <structs.h>

/////////////////biblioteca/////////////////

#include <cctype>
#include <fstream>
#include <iostream>
#include <list>
#include <string>

#include "prglib.h"

using namespace std;
using prglib::arvore;

//////////////declaracao das funcoes/////////////

string separa(const string &texto, string sep, string coluna, int &posicao);

string separa_coluna(const string &texto, string sep, int &posicao);

void sep_arq(const string &texto, string sep, index &ler_arq);

#endif