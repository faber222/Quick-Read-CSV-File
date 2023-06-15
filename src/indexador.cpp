#include "indexador.h"

// funcao utilizada para fazer a indexacao dos dados, recebendo o nome do
// arquivo de argv[1] e o nome da coluna de argv[2]
void indexar_dados(ifstream& arquivo, string coluna_escolhida, const string sep,
                   arvore<index>& indexacao) {
  string leitura;            // armazena as linhas do arquivo
  string coluna;             // armazena o nome da coluna desejada
  string dado_coluna;        // armazena os dados da coluna
  int pos_coluna = 0;        // posicao de cada coluna
  if (!arquivo.is_open()) {  // testa se o arquivo nao for aberto e dispara
    // evento encerrando o codigo, com exit(true)
    cout << "ARQUIVO INVALIDO OU INEXISTENTE" << endl;
    exit(true);
  }
  getline(arquivo, leitura);  // obtem apenas a primeira linha do arquivo csv e
  // armazena na string leitura
  coluna = separa(leitura, sep, coluna_escolhida,
                  pos_coluna);  // chama a funcao separa, que retorna o nome da
  // coluna escolhida
  if (coluna != coluna_escolhida) {  // se o valor de coluna nao for == argv[2]
    // dispara evento e encerra com exit(true)
    cout << "A COLUNA NAO EXISTE" << endl;
    exit(true);
  }
  leitura.clear();  // limpa a string leitura para ser usada no proximo loop

  while (true) {
    index referencia;                 // nomeacao da struct index
    int pos = arquivo.tellg();        // captura a posicao da linha do codigo
    if (getline(arquivo, leitura)) {  // captura cada linha do codigo
      // separa_coluna vai retornar o valor da
      // coluna definida em pos_coluna
      dado_coluna = separa_coluna(leitura, sep, pos_coluna);
      referencia.coluna = dado_coluna;  // armazena o valor dentro da struct
      try {
        // se o valor ja existe na arvore
        // adiciona a posicao dele na nova estrutura
        index& estrutura = ( index& ) indexacao.obtem(referencia);
        estrutura.pos_linha.push_back(pos);
      }
      catch (...) {
        // armazena a nova posicao e adiciona na arvore, criando um novo nodo
        referencia.pos_linha.push_back(pos);
        indexacao.adiciona(referencia);
      }
      indexacao.balanceia(true);  // balanceia o maximo a arvore
    } else {
      arquivo.clear();  // caso não de certo, limpa arquivo
      break;
    }
  }
  list<index> preordernado;  // cria lista para armzenar dados da arvore
  indexacao.listePreOrder(
      preordernado);                   // armazena os dados da arvore na lista
  ofstream arq2(coluna_escolhida);     // abre um arquivo em modo de escrita
  int t = 0;
  for (auto& x : preordernado) {       // itera a lista
    for (auto& linha : x.pos_linha) {  // itera a posicao de cada struct
      if (t == 0) {
        arq2 << coluna_escolhida << sep << endl;  // escreve no arquivo
      }
      t++;
      arq2 << x.coluna << sep << linha << endl;  // escreve no arquivo
    }
  }
}

// funcao utilizada para refazer a arvore ja indexada
void reutilizar_dados(ifstream& arq, arvore<index>& indexacao_reciclada,
                      const string sep) {
  string str_memoria;  // string que armazena os dados do arq
  index ler_arq;       // struct para armazenar os dados de sep_arq
  while (getline(arq, str_memoria)) {  // captura a primeira linha do arquivo
    // separa a linha usando o sep e armazena em ler_arq
    sep_arq(str_memoria, sep, ler_arq);
    try {
      // se o valor ja existe na arvore
      // adiciona a posicao dele na nova estrutura
      index& estrutura = ( index& ) indexacao_reciclada.obtem(ler_arq);
      estrutura.pos_linha.push_back(ler_arq.pos_linha.front());
    }
    catch (...) {
      // armazena a nova posicao e adiciona na arvore, criando um novo nodo
      indexacao_reciclada.adiciona(ler_arq);  // adiciona na arvore reciclada
    }
  }
};