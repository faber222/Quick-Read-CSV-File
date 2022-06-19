////////////////referencia////////////////

#include <obter_linhas.h>

list<string> obter_linhas(const list<index> dados_solicitados,
                          string nome_arquivo) {
  list<string> saida;  // lista de strings a ser retornada da funcao
  list<int> para_ler;  // lista de inteiros para armazenas as posicoes das
                       // linhas da lista indexada
  string linha_lida;   // string usada para armazenar dados obtidos apos
                       // indexacao dentro de argv[1]

  for (auto &iterador : dados_solicitados) {  // iterador da lista
    para_ler.push_back(iterador.pos_linha);   // armazena os dados de linhas
                                              // em para_ler
  }
  ifstream segunda_leitura(nome_arquivo);  // abre em modo leitura argv[1]
  for (auto &pos : para_ler) {             // iterador da lista
    segunda_leitura.seekg(pos);            // busca os dados da linha
                                           // pos no arquivo
    getline(segunda_leitura, linha_lida);  // armazena em linha_lida
    saida.push_back(linha_lida);           // adiciona na fila saida
  }

  return saida;  // retorna a fila saida
}