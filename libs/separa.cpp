///////////////////referencia//////////////////////

#include <separa.h>

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

// funcao usada para ler o arquivo da indexacao na segunda chamada
void sep_arq(const string &texto, string sep, index &ler_arq) {
  int count = 0;  // contador para captura de dados
  list<string> list =
      separador(texto, sep);  // cria uma lista que recebe como dados o retorno
                              // da funcao separador
  index captura;              // armazena a struct local
  for (auto &conteudo : list) {  // itera a lista
    if (count == 0) {            // se for == 0, joga conteudo em coluna
      captura.coluna = conteudo;
    }
    if (count == 1) {  // se for == 1, joga conteudo em pos_linha
      captura.pos_linha.push_back(stoi(conteudo));  // converte para inteiro
    }
    count++;  // incrementa contador
  }
  ler_arq = captura;  // iguala a struct local na struct global
}