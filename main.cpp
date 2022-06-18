#include <obter_linhas.h>
#include <separa.h>
#include <structs.h>

#include <fstream>
#include <iostream>
#include <list>
#include <string>

#include "prglib.h"

using namespace std;
using prglib::arvore;

bool operator==(const index &d1, const index &d2) {
  return d1.coluna == d2.coluna;
}
bool operator<(const index &d1, const index &d2) {
  return d1.coluna < d2.coluna;
}

arvore<index> indexacao;

void indexar_dados(string nome_arq, string coluna_escolhida) {
  string leitura;
  string coluna;
  string dado_coluna;
  string sep = ",";
  index referencia;
  int ver_posicao = 0;

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
  arquivo.close();
}

int main(int argc, char *argv[]) {
  indexar_dados(argv[1], argv[2]);
  indexacao.balanceia(true);

  index valor_inicial;
  index valor_final;
  list<index> linhas;
  list<string> printar;

  while (true) {
    while (valor_inicial.coluna.empty()) {
      cout << "valor1> ";
      getline(cin, valor_inicial.coluna);
    }
    cout << "valor2> ";
    getline(cin, valor_final.coluna);
    indexacao.obtemIntervalo(linhas, valor_inicial, valor_final);
    printar = obter_linhas(linhas, argv[1]);
    while (!printar.empty()) {
      cout << printar.front() << endl;
      printar.pop_front();
    }
    valor_final.coluna.clear();
    valor_inicial.coluna.clear();
    linhas.clear();
  }
}