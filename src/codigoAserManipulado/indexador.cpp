#include "indexador.h"

// funcao utilizada para fazer a indexacao dos dados, recebendo o nome do
// arquivo de argv[1] e o nome da coluna de argv[2]
void indexar_dados(ifstream& arquivo, const string sep,
                   arvore<index>& indexacao, string nomeArq) {
  string leitura;            // armazena as linhas do arquivo
  string coluna;             // armazena o nome da coluna desejada
  int valor = 0;
  int count = 0;
  double media = 0;
  double desvioPadrao = 0;
  int colunaAtual = 26;
  vector<double> vetorDesvioPadrao;

  while (getline(arquivo, leitura)) {
    int pos_coluna = 0;
    coluna = separa(leitura, sep, colunaAtual,
                    pos_coluna);  // chama a funcao separa, que retorna o nome da
    
    valor += stoi(coluna);
    count++;
    vetorDesvioPadrao.push_back(stod(coluna));
    leitura.clear();  // limpa a string leitura para ser usada no proximo loop
  };  // obtem apenas a primeira linha do arquivo csv e
  media = valor / count;
  mostrar_resultado(vetorDesvioPadrao, media, nomeArq);
}
