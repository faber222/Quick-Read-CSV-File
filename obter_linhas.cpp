#include <obter_linhas.h>

list<string> obter_linhas(const list<index> dados_solicitados,
                          string nome_arquivo) {
  index informacoes;
  list<string> saida;
  list<int> para_ler;
  string linha_lida;
  
  for (auto &iterador : dados_solicitados) {
    para_ler.push_back(iterador.pos_linha);
  }
  ifstream segunda_leitura(nome_arquivo);
  while (!para_ler.empty()) {
    segunda_leitura.seekg(para_ler.front());
    getline(segunda_leitura, linha_lida);
    saida.push_back(linha_lida);
    para_ler.pop_front();
  }

  return saida;
}