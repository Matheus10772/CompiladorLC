#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <iterator>

void imprimirVectorDeStrings(std::vector<std::string> vetor) {
    for (std::string linha : vetor) {
        std::cout << linha << std::endl;
    }
}

std::vector<std::string> lerArquivo(std::string nomeArquivo) {
    std::ifstream arquivo(nomeArquivo);
    std::vector<std::string> linhas;
    std::string linha;
    while (std::getline(arquivo, linha)) {
        linhas.push_back(linha);
    }
    return linhas;
}

void escreveArquivo(std::string nomeArquivo, std::vector<std::string> linhas) {
    std::ofstream arquivo(nomeArquivo);
    for (std::string linha : linhas) {
        arquivo << linha << std::endl;
    }
}

std::vector<std::string> preProcessamento(std::vector<std::string> linhas) {
    std::vector<std::string> linhasPreProcessadas;
    for (std::string linha : linhas) {
        std::string linhaPreProcessada;
        for (char c : linha) {
            if (c == ' ') {
                continue;
            }
            linhaPreProcessada += c;
        }
        linhasPreProcessadas.push_back(linhaPreProcessada);
    }
    return linhasPreProcessadas;
}

bool verificarVersaodoSO() {
    #ifdef _WIN32
	    return true;
    #else
	    return false;
    #endif
}

void corrigirCodificacaoDoTerminal(bool versaoWindows) {
	if (versaoWindows) {
		system("chcp 65001");
	}
}

void ajustesIniciais() {
	corrigirCodificacaoDoTerminal(verificarVersaodoSO());
}

int main()
{
	ajustesIniciais();

    std::cout << "Hello World!\n";
    std::vector<std::string> linhas = lerArquivo("C:\\Users\\mathe\\Downloads\\Novo(a) Documento de Texto.txt");
    std::cout << "Conteúdo do arquivo lido: ";
	imprimirVectorDeStrings(linhas);
    
    return 0;
}



// Dicas para Começar: 
//   1. Use a janela do Gerenciador de Soluções para adicionar/gerenciar arquivos
//   2. Use a janela do Team Explorer para conectar-se ao controle do código-fonte
//   3. Use a janela de Saída para ver mensagens de saída do build e outras mensagens
//   4. Use a janela Lista de Erros para exibir erros
//   5. Ir Para o Projeto > Adicionar Novo Item para criar novos arquivos de código, ou Projeto > Adicionar Item Existente para adicionar arquivos de código existentes ao projeto
//   6. No futuro, para abrir este projeto novamente, vá para Arquivo > Abrir > Projeto e selecione o arquivo. sln
