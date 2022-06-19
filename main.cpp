////////////////referencias//////////////////////

#include <obter_linhas.h>
#include <separa.h>
#include <structs.h>

////////////////bibliotecas//////////////////////

#include <fstream>
#include <iostream>
#include <list>
#include <string>

#include "prglib.h"

using namespace std;
using prglib::arvore;

// operadores usados para balancear a arvore
// baseado nos dados da coluna e não das linhas
bool operator==(const index &d1, const index &d2) {
  return d1.coluna == d2.coluna;
}
bool operator<(const index &d1, const index &d2) {
  return d1.coluna < d2.coluna;
}

arvore<index> indexacao;  // declaracao de uma arvore de struct global

// funcao utilizada para fazer a indexacao dos dados, recebendo o nome do
// arquivo de argv[1] e o nome da coluna de argv[2]
void indexar_dados(string nome_arq, string coluna_escolhida,
                   index &ultimo_item) {
  string leitura;
  string coluna;
  string dado_coluna;
  string sep = ",";     // caracter separador usado nas
                        // funcoes separa e separa_coluna
  int ver_posicao = 0;  // usado para saber em qual posicao trabalhar e capturar
                        // do arquivo csv
  index referencia;     // nomeacao da struct index

  ifstream arquivo(nome_arq);  // abre o arquivo em modo leitura de argv[1]

  if (!arquivo.is_open()) {  // testa se o arquivo nao for aberto e dispara
                             // evento encerrando o codigo, com exit(true)
    cout << "ARQUIVO INVALIDO OU INEXISTENTE" << endl;
    exit(true);
  }
  getline(arquivo, leitura);  // obtem apenas a primeira linha do arquivo csv e
                              // armazena na string leitura
  coluna = separa(leitura, sep, coluna_escolhida,
                  ver_posicao);  // chama a funcao separa, que retorna o nome da
                                 // coluna escolhida
  if (coluna != coluna_escolhida) {  // se o valor de coluna nao for == argv[2]
                                     // dispara evento e encerra com exit(true)
    cout << "A COLUNA NAO EXISTE" << endl;
    exit(true);
  }
  leitura.clear();  // limpa a string leitura para ser usada no proximo loop
  ultimo_item.coluna.clear();  // limpa a memoria para evitar lixo

  while (true) {
    int pos = arquivo.tellg();  // captura a posicao da linha que esta sendo
                                // lida nesse momento

    if (getline(arquivo, leitura)) {  // captura os dados da linha e
                                      // armazena em leitura
      // separa_coluna vai retornar o valor da coluna definida em ver_posicao
      dado_coluna = separa_coluna(leitura, sep, ver_posicao);
      referencia.coluna = dado_coluna;  // armazena o valor dentro da struct
      referencia.pos_linha = pos;      // armazena a linha desse valor na struct
      indexacao.adiciona(referencia);  // adiciona referencia na arvore
      // se referencia for maior que ultimo_item, iguala para ter sempre a
      // ultima maior informacao da indexacao
      if (referencia.coluna > ultimo_item.coluna) {
        ultimo_item = referencia;
      }
    } else {  // caso não de certo, limpa arquivo
      arquivo.clear();
      break;
    }
  }
  arquivo.close();  // fecha o arquivo para liberar memoria
}

int main(int argc, char *argv[]) {
  index ultimo_valor;
  indexar_dados(argv[1], argv[2],
                ultimo_valor);  // chama funcao que armazena os dados
                                // indexados na arvore indexacao
  indexacao.balanceia(true);    // balanceia(true), vai balancear o maximo
                                // possivel a arvore

  index valor_inicial;   // definicao de struct para valor1
  index valor_final;     // definicao de struct para valor2
  list<index> linhas;    // lista de struct usada em obter_linhas
  list<string> printar;  // lista de string usada para armazenar o retorno de
                         // obter_linhas

  while (true) {                            // loop infinito
    while (valor_inicial.coluna.empty()) {  // loop enquanto nada for difigitado
      cout << "valor1> ";
      getline(cin, valor_inicial.coluna);  // captura a linha do terminal
    }
    cout << "valor2> ";
    getline(cin, valor_final.coluna);  // captura a linha do terminal
    if (valor_final.coluna.empty()) {  // se for vazio, declara
                                       // valor_final = ultimo_valor
      valor_final.coluna = ultimo_valor.coluna;
    }
    indexacao.obtemIntervalo(linhas, valor_inicial,
                             valor_final);  // obtem um intervalo de dados da
                                            // arvore e armazena em linhas
    printar =
        obter_linhas(linhas, argv[1]);  // obter_linhas retorna os dados da
                                        // pesquisa de linhas em argv[1]
    if (printar.empty()) {  // se a lista for fazia, dispara mensagem de evento
      cout << "Nenhum resultado foi encontrado" << endl;
    }
    for (auto &x : printar) {  // loop para printar os dados na tela
      cout << x << endl;
    }
    valor_final.coluna.clear();    // limpa as variaveis para o loop seguinte
    valor_inicial.coluna.clear();  // limpa as variaveis para o loop seguinte
    linhas.clear();                // limpa as variaveis para o loop seguinte
  }
}