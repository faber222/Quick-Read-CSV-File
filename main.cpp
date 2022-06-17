#include <fstream>
#include <iostream>
#include <string>

#include "prglib.h"

using namespace std;
using prglib::arvore;

typedef struct {
  int pos_linha;
  string coluna;
} index;

bool operator==(const index &d1, const index &d2) {
  return d1.pos_linha == d2.pos_linha;
}
bool operator<(const index &d1, const index &d2) {
  return d1.pos_linha < d2.pos_linha;
}

arvore<index> indexacao;

string separa(const string &texto, auto sep, string coluna, int &posicao) {
  int x = 0;
  string memoria;
  while (x != string::npos) {
    int z = texto.find_first_not_of(sep, x);
    if (z == string::npos) break;
    x = texto.find(sep, z);
    memoria = texto.substr(z, x - z);
    posicao++;
    if (coluna == memoria) {
      return memoria;
      break;
    }
  }
}

string separa_coluna(const string &texto, auto sep, int &posicao) {
  int x = 0;
  string memoria;
  int posicao_comparada = 0;
  while (x != string::npos) {
    int z = texto.find_first_not_of(sep, x);
    if (z == string::npos) break;
    x = texto.find(sep, z);
    memoria = texto.substr(z, x - z);
    posicao_comparada++;
    if (posicao == posicao_comparada) {
      return memoria;
      break;
    }
  }
}

void indexar_dados(string nome_arq, string coluna_escolhida) {
  string leitura;
  string coluna;
  string dado_coluna;
  string sep = ",";

  int ver_posicao = 0;
  index referencia;

  ifstream arquivo(nome_arq);

  if (!arquivo.is_open()) {
    cout << "ARQUIVO INVALIDO OU INEXISTENTE" << endl;
    exit(true);
  }

  getline(arquivo, leitura);

  coluna = separa(leitura, sep, coluna_escolhida, ver_posicao);

  if (coluna != coluna_escolhida) {
    cout << "A COLUNA NAO EXISTE" << endl;
    exit(true);
  }
  while (true) {
    int pos = arquivo.tellg();
    if (getline(arquivo, leitura)) {
      int posicao = 1;
      dado_coluna = separa_coluna(leitura, sep, ver_posicao);
      referencia.coluna = dado_coluna;
      referencia.pos_linha = pos;
      indexacao.adiciona(referencia);
    } else {
      arquivo.clear();
      break;
    }
  }

  for (auto &x : indexacao) {
    cout << x.coluna << " " << x.pos_linha << endl;
  }
}

int main(int argc, char *argv[]) { indexar_dados(argv[1], argv[2]); }