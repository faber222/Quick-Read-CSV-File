////////////////referencia////////////////

#include "manipulacao_de_dados.h"

double calcularDesvioPadrao(const vector<double>& numeros, const double media) {
  double somaQuadrados = 0.0;
  for (double numero : numeros) {
    double diferenca = numero - media;
    somaQuadrados += diferenca * diferenca;
  }
  double variancia = somaQuadrados / numeros.size();
  return sqrt(variancia);
}

// funcao para mostrar os resultados de obter linhas
void mostrar_resultado(vector<double> desvio, double media, string nomeArq) {

  ofstream arq2("" + nomeArq + ".txt");     // abre um arquivo em modo de escrita

  arq2 << "Media:> " + to_string(media) << endl;
  arq2 << "Desvio Padrao:> " + to_string(calcularDesvioPadrao(desvio, media)) << endl;

  cout << "finalizado" << endl;
}
