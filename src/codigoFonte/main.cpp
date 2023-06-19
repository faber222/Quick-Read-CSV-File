////////////////referencias//////////////////////

#include "indexador.h"
#include "manipulacao_de_dados.h"
#include "separa.h"

////////////////bibliotecas//////////////////////

#include <cctype>
#include <fstream>
#include <iostream>
#include <list>
#include <string>

#include "prglib.h"

using namespace std;
using prglib::arvore;

int main(int argc, char *argv[]) {
  arvore<index> indexacao;  // declaracao de uma arvore de struct global
  ifstream arq(argv[2]);    // abre o arquivo em modo leitura
  ifstream arq2(argv[1]);   // abre o arquivo em modo leitura
  string sep = argv[4];     // caracter separador usado na funcao sep_arquivo
  string nomeArq = argv[3];

  if (arq.is_open()) {  // se existir o arquivo, executa a leitura dele
    reutilizar_dados(arq, indexacao,
                     sep);  // funcao utilizada para
                            // refazer a arvore ja indexada
  } else {
    indexar_dados(arq2, argv[2], sep,
                  indexacao);  // chama funcao que armazena os dados
                               //  indexados na arvore indexacao
  }
  while (true) {           // loop infinito
    list<string> printar;  // lista de string usada para armazenar o retorno de
                           // obter_linhas
    index valor1;          // definicao de struct para valor1
    index valor2;          // definicao de struct para valor2
    list<index> linhas;    // lista de struct usada em obter_linhas
    string valor1_digitado, valor2_digitado;

    entrada_valores(valor1_digitado, valor2_digitado);

    valor1.coluna = valor1_digitado;
    valor2.coluna = valor2_digitado;
    if (valor2.coluna.empty()) {  // se for vazio, obterm intervalo apenas
                                  // de valor1
      indexacao.obtemIntervalo(linhas, valor1, valor1);
    } else {
      indexacao.obtemIntervalo(linhas, valor1,
                               valor2);  // obtem um intervalo de dados da
                                         // arvore e armazena em linhas
    }
    // usado para reutilizar o arquivo
    arq2.clear();
    arq2.seekg(0);
    printar = obter_linhas(linhas, arq2);  // obter_linhas retorna os dados da
                                           // pesquisa de linhas em argv[1]
    mostrar_resultado(printar, nomeArq, valor1.coluna);
  }
}