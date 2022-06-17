#include <separa.h>

string separa(const string &texto, string sep, string coluna, int &posicao) {
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
  return memoria = "falso";
}

string separa_coluna(const string &texto, string sep, int &posicao) {
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
  return 0;
}