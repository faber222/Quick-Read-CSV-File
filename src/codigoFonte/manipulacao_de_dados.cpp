////////////////referencia////////////////

#include "manipulacao_de_dados.h"

// funcao usada para capturar os dados de valor 1 e valor 2
void entrada_valores(string& valor1, string& valor2) {
  while (valor1.empty()) {  // loop enquanto nada for difigitado
    cout << "valor1> ";
    getline(cin, valor1);  // captura a linha do terminal
  }
  cout << "valor2> ";
  getline(cin, valor2);  // captura a linha do terminal
}

// funcao usada para obter as linhas do range de valor 1 e valor 2
list<string> obter_linhas(const list<index> dados_solicitados, ifstream& arq) {
  list<string> saida;  // lista de strings a ser retornada da funcao
  string linha_lida;   // string usada para armazenar dados obtidos apos
  // indexacao dentro de argv[1]
  for (auto& iterador : dados_solicitados) {          // iterador da lista
    for (auto& iterardor_pos : iterador.pos_linha) {  // iterador da posicao
      arq.seekg(iterardor_pos);     // posiciona na linha desejada
      getline(arq, linha_lida);     // armazena em linha_lida
      saida.push_back(linha_lida);  // adiciona na fila saida
    }
  }
  return saida;  // retorna a fila saida
}

// funcao para mostrar os resultados de obter linhas
void mostrar_resultado(list<string> printar, string nomeArq, string nomeFiltro) {
  if (printar.empty()) {  // se a lista for fazia, dispara mensagem de evento
    cout << "Nenhum resultado foi encontrado" << endl;
    exit(true);
  }
  ofstream arq2("" + nomeArq + "-" + nomeFiltro + ".csv");     // abre um arquivo em modo de escrita

  for (auto& x : printar) {  // loop para printar os dados na tela
    arq2 << x << endl;
    // cout << x << endl;
  }
  cout << "finalizado" << endl;
}
