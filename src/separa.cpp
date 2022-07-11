///////////////////referencia//////////////////////

#include "separa.h"

// funcao usada para separar as virgulas
list<string> separador(const string &texto, string sep) {
  int x = 0;
  string memoria;      // string que armazena o valor da separacao
  list<string> dados;  // lista usada para armazenar os dados da separacao

  while (x != string::npos) {                 // loop se encerra quando x for
                                              // igual ao final da linha
    int z = texto.find_first_not_of(sep, x);  // encontra o primeiro caracter
                                              // que nao for o separador
    if (z == string::npos) break;             // se a busca for o fim, para loop
    x = texto.find(sep, z);                   // encontra o primerio separador
    memoria = texto.substr(z, x - z);         // captura os dados do z até x-z
    dados.push_back(memoria);                 // armazena na lista
  }
  return dados;  // retorna os dados da lista
}

// funcao usada para separar a primeira linha do arquivo
string separa(const string &texto, string sep, string coluna, int &posicao) {
  list<string> dados =
      separador(texto, sep);  // cria uma lista que recebe como dados o retorno
                              // da funcao separador
  for (auto &memoria : dados) {  // itera a lista
    posicao++;                   // incremente a posicao para saber a coluna
    if (coluna == memoria) {     // se for igual a argv[2]
      return memoria;            // retorna a coluna desejada
    }
  }
  return "falso";  // retorna um valor com nome falso
}

// funcao usada para separar os dados da coluna
string separa_coluna(const string &texto, string sep, int &posicao) {
  int posicao_comparada = 0;  // variavel a ser comparada com posicao
  list<string> dados =
      separador(texto, sep);  // cria uma lista que recebe como dados o retorno
                              // da funcao separador
  for (auto &memoria : dados) {          // itera a lista
    posicao_comparada++;                 // encrementa posicao_compara
    if (posicao == posicao_comparada) {  // se for igual a posicao
      return memoria;                    // retorna a coluna desejada
    }
  }
  return 0;  // retorna valor 0
}