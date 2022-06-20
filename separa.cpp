///////////////////referencia//////////////////////

#include <separa.h>

string separa(const string &texto, string sep, string coluna, int &posicao) {
  int x = 0;
  string memoria;  // string que armazena o valor da separacao

  while (x != string::npos) {                 // loop se encerra quando x for
                                              // igual ao final da linha
    int z = texto.find_first_not_of(sep, x);  // encontra o primeiro caracter
                                              // que nao for o separador
    if (z == string::npos) break;             // se a busca for o fim, para loop
    x = texto.find(sep, z);                   // encontra o primerio separador
    memoria = texto.substr(z, x - z);         // captura os dados do z até x-z
    posicao++;                                // encrementa posicao
    if (coluna == memoria) {                  // se for igual a argv[2]
      return memoria;                         // retorna a coluna desejada
      break;
    }
  }
  return memoria = "falso";  // retorna um valor com nome falso
}

string separa_coluna(const string &texto, string sep, int &posicao) {
  int x = 0;
  string memoria;             // string que armazena o valor da separacao
  int posicao_comparada = 0;  // variavel a ser comparada com posicao

  while (x != string::npos) {                 // loop se encerra quando x for
                                              // igual ao final da linha
    int z = texto.find_first_not_of(sep, x);  // encontra o primeiro caracter
                                              // que nao for o separador
    if (z == string::npos) break;             // se a busca for o fim, para loop
    x = texto.find(sep, z);                   // encontra o primerio separador
    memoria = texto.substr(z, x - z);         // captura os dados do z até x-z
    posicao_comparada++;                      // encrementa posicao_compara
    if (posicao == posicao_comparada) {       // se for igual a posicao
      return memoria;                         // retorna a coluna desejada
      break;
    }
  }
  return 0;  // retorna valor 0
}

void sep_arq(const string &texto, string sep, index &ler_arq) {
  int x = 0;
  int count = 0;      // contador para captura de dados
  string memoria;     // string que armazena o valor da separacao
  list<string> list;  // lista temporaria para guardar dados em memoria

  while (x != string::npos) {                 // loop se encerra quando x for
                                              // igual ao final da linha
    int z = texto.find_first_not_of(sep, x);  // encontra o primeiro caracter
                                              // que nao for o separador
    if (z == string::npos) break;             // se a busca for o fim, para loop
    x = texto.find(sep, z);                   // encontra o primerio separador
    memoria = texto.substr(z, x - z);         // captura os dados do z até x-z
    list.push_back(memoria);                  // joga para dentro da lista
  }
  for (auto &conteudo : list) {  // itera a lista
    if (count == 0) {            // se for == 0, joga conteudo em coluna
      ler_arq.coluna = conteudo;
    }
    if (count == 1) {  // se for == 1, joga conteudo em pos_linha
      ler_arq.pos_linha = stoi(conteudo);  // converte para inteiro
    }
    count++;  // incrementa contador
  }
}