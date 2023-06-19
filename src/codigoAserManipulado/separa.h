#ifndef SEPARA_H
#define SEPARA_H

////////////////referencia////////////////////

#include <structs.h>

/////////////////biblioteca/////////////////

#include <cctype>
#include <fstream>
#include <vector>
#include <cmath>
#include <iostream>
#include <list>
#include <string>

#include "prglib.h"

using namespace std;
using prglib::arvore;

//////////////declaracao das funcoes/////////////

// funcao usada para separar as virgulas
list<string> separador(const string &texto, string sep);

// funcao usada para separar a primeira linha do arquivo
string separa(const string &texto, string sep, int coluna, int posicao);

#endif