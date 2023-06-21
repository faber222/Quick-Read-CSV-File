///////////////////referencia//////////////////////

#include "separa.h"

// funcao usada para separar as virgulas
list<string> separador(const string& texto, string sep) {
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
  dados.pop_back(); // removo o ultimo dado por ser vazio

  return dados;  // retorna os dados da lista
}

// funcao usada para separar a primeira linha do arquivo
string separa(const string& texto, string sep) {
  list<string> dados = separador(texto, sep);  // cria uma lista que recebe como dados o retorno da funcao separador
  return dados.back();            // retorna a coluna desejada
}
