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

using namespace std;

int main(int argc, char* argv[]) {
  ifstream arquivoCsv(argv[1]);   // abre o arquivo em modo leitura
  string sep = argv[3];         // caracter separador usado na funcao sep_arquivo
  string nomeArq = argv[2]; // nome do arquivo de saida

  indexar_dados(arquivoCsv, sep, nomeArq);  // chama funcao que armazena os dados
}