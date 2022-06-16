#include <iostream>
#include "prglib.h"
#include <string>
#include <fstream>

using namespace std;
using prglib::arvore;

typedef struct{
  int pos_linha;
  string coluna;
} index;

bool operator == (const index & d1, const index & d2){
  return d1.pos_linha == d2.pos_linha;
}
bool operator < (const index & d1, const index & d2){
  return d1.pos_linha < d2.pos_linha;
}

arvore<index> indexacao;

int main(int argc, char *argv[]){
  string leitura;
  string coluna;
  string dado_index;
  string dado_coluna;
  int pos1=0, pos2=0;
  int ver_posicao=1;
  int posicao=1;
  index referencia;
  
  ifstream arquivo(argv[1]);
  if (! arquivo.is_open()){
    cout << "ARQUIVO INVALIDO OU INEXISTENTE" << endl;
    return 0;
  }
  
  getline(arquivo, leitura);
  while(true){
    pos1 = leitura.find_first_of(",", pos2);
    pos2 = leitura.find_first_of(",", pos1+1);
    if (pos1 == string::npos){
      break;
    }
    if (pos2 == string::npos){
      coluna = leitura.substr(pos1);
      ver_posicao++;
      break;
    }
    coluna = leitura.substr(pos2-pos1);
    ver_posicao++;
    if (coluna == argv[2]){
      break;
    }
  }
  if (coluna != argv[2]){
    cout << "A COLUNA NAO EXISTE" << endl;
    return 0;
  }
  
  while(getline(arquivo, leitura)){
    pos1 = 0;
    pos2 = 0;
    posicao = 1;
    while(true){
      pos1 = leitura.find_first_of(",", pos2);
      pos2 = leitura.find_first_of(",", pos1+1);
      if (pos1 == string::npos){
        break;
      }
      if (pos2 == string::npos){
        dado_coluna = leitura.substr(pos1);
        referencia.coluna = dado_coluna;
        referencia.pos_linha = arquivo.tellg();
        indexacao.adiciona(referencia);
        break;
      }
      dado_coluna = leitura.substr(pos2-pos1);
      if (posicao == ver_posicao){
        referencia.coluna = dado_coluna;
        referencia.pos_linha = arquivo.tellg();
        indexacao.adiciona(referencia);
        break;
      }
      posicao++;
    }
  }
}
