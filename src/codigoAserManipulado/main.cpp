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

int main(int argc, char* argv[]) {
  arvore<index> indexacao;  // declaracao de uma arvore de struct global
  ifstream arq2(argv[1]);   // abre o arquivo em modo leitura
  string sep = ",";         // caracter separador usado na funcao sep_arquivo
  string nomeArq = argv[2]; // nome do arquivo de saida

  indexar_dados(arq2, sep, indexacao, nomeArq);  // chama funcao que armazena os dados
}