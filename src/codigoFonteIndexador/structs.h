#ifndef STRUCT_H
#define STRUCT_H

////////////////bibliotecas///////////////

#include <cctype>
#include <fstream>
#include <iostream>
#include <list>
#include <string>

#include "prglib.h"

///////////////struct index///////////////

struct index {
  string coluna;        // armazena os dados da coluna
  list<int> pos_linha;  // armazena as posicoes da coluna

  // operadores usados para balancear a arvore
  // baseado nos dados da coluna e não das linhas
  bool operator==(const index &d1) { return (coluna == d1.coluna); }
  bool operator<(const index &d1) { return (coluna < d1.coluna); }
};

#endif