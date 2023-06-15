#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <cmath>

double calcularDesvioPadrao(const std::vector<double>& numeros, const int media) {
    double somaQuadrados = 0.0;
    for (double numero : numeros) {
        double diferenca = numero - media;
        somaQuadrados += diferenca * diferenca;
    }
    double variancia = somaQuadrados / numeros.size();
    return std::sqrt(variancia);
}

int main(int argc, char* argv[]) {
    std::ifstream file(argv[2]);

    std::string separador = argv[3];
    char sep = separador.at(0);

    if (!file) {
        std::cerr << "Erro ao abrir o arquivo." << std::endl;
        return 1;
    }

    std::vector<double> coluna;
    std::vector<double> numeros;
    std::string linha, valor;
    std::string nomeColunaDesejada = argv[1];
    double count = 0;
    double soma = 0;
    double media = 0;

    // Ignorar a primeira linha (cabeçalhos das colunas)
    std::getline(file, linha);

    std::istringstream header(linha);
    int colunaDesejada = -1; // Inicializar com valor inválido

    // Encontrar o índice da coluna desejada pelo nome
    int indiceColuna = 0;
    while (std::getline(header, valor, sep)) {
        if (valor == nomeColunaDesejada) {
            colunaDesejada = indiceColuna;
            break;
        }
        indiceColuna++;
    }

    if (colunaDesejada == -1) {
        std::cerr << "Nome da coluna não encontrado." << std::endl;
        return 1;
    }

    while (std::getline(file, linha)) {
        std::stringstream ss(linha);

        for (int i = 0; i <= colunaDesejada; i++) {
            std::getline(ss, valor, sep);
        }
        count++;
        soma += std::stod(valor);
        coluna.push_back(std::stod(valor));
    }

    file.close();
    media = soma / count;

    double desvioPadrao = calcularDesvioPadrao(coluna, media);

    std::cout << "O desvio padrão é: " << desvioPadrao << std::endl;

    std::cout << "Media dos usuarios: " << media << std::endl;

    return 0;
}
