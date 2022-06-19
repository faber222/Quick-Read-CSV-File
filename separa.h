#ifndef SEPARA_H
#define SEPARA_H

/////////////////biblioteca/////////////////

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

#endif