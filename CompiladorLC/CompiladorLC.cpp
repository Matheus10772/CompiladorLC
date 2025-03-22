#include "Estado.hpp"
#include "GeradorDeAutomatos.hpp"
#include <fstream>

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

	std::vector<std::string> regexs = { "a", "b", "c" };
    Automato LCAutomato("My Automato", regexs); //q0

    std::vector<std::string> regexs2 = { "d", "e", "f" }; //q1
    std::vector<std::string> regexs3 = { "g", "h", "i" }; //q2

    LCAutomato.addEstado(regexs2, TipoEstado::NORMAL);
    LCAutomato.addEstado(regexs3, TipoEstado::FINAL);

    LCAutomato.addTransicaoEntreEstados("q0", "q1", std::vector<std::string>{"z"});
    LCAutomato.addTransicaoEntreEstados("q1", "q2", std::vector<std::string>{"z"});

    std::cout << LCAutomato.transitarEntreEstados("z") << std::endl;
    std::cout << LCAutomato.transitarEntreEstados("z") << std::endl;

    //LCAutomato.~Automato();
    
    return 0;
}
