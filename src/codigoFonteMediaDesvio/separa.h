#ifndef SEPARA_H
#define SEPARA_H

/////////////////biblioteca/////////////////

#include <cctype>
#include <fstream>
#include <vector>
#include <cmath>
#include <iostream>
#include <list>
#include <string>

using namespace std;

//////////////declaracao das funcoes/////////////

// funcao usada para separar as virgulas
list<string> separador(const string &texto, string sep);

// funcao usada para separar a primeira linha do arquivo
string separa(const string &texto, string sep);

#endif