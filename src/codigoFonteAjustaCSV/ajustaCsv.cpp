#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>

using namespace std;

int main(int argc, char* argv[]) {
    std::ifstream inputFile(argv[1]);
    std::ofstream outputFile(argv[2]);

    if (!inputFile) {
        std::cerr << "Erro ao abrir o arquivo de entrada." << std::endl;
        return 1;
    }

    if (!outputFile) {
        std::cerr << "Erro ao abrir o arquivo de saída." << std::endl;
        return 1;
    }

    std::string line;
    while (std::getline(inputFile, line)) {
        // Remover a quebra de linha, se existir
        if (!line.empty() && line[line.length() - 1] == '\r') {
            line.erase(line.length() - 1);
        }
        // Adicionar ponto e vírgula no final de cada linha
        line += ";";
        // Substituir pontos e vírgulas por vírgulas
        std::replace(line.begin(), line.end(), ';', ',');

        // Substituir espaços em branco por underscores
        for (char& c : line) {
            if (c == ' ') {
                c = '_';
            }
        }

        // Escrever a linha modificada no arquivo de saída
        outputFile << line << std::endl;
    }

    inputFile.close();
    outputFile.close();

    std::cout << "Substituição concluída. O arquivo de saída foi gerado com sucesso." << std::endl;

    return 0;
}
