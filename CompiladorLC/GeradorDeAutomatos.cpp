#include <vector>
#include <map>
#include <string>
#include <algorithm>
class Automato {
private:
    std::vector<std::string> estados;
    std::vector<char> alfabeto;
    std::map<std::pair<std::string, char>, std::string> transicoes;
    std::string estadoInicial;
    std::vector<std::string> estadosFinais;

public:
    Automato(const std::vector<std::string>& estados, const std::vector<char>& alfabeto,
             const std::map<std::pair<std::string, char>, std::string>& transicoes,
             const std::string& estadoInicial, const std::vector<std::string>& estadosFinais)
        : estados(estados), alfabeto(alfabeto), transicoes(transicoes),
          estadoInicial(estadoInicial), estadosFinais(estadosFinais) {}

    bool processarEntrada(const std::string& entrada) {
        std::string estadoAtual = estadoInicial;
        for (char simbolo : entrada) {
            auto it = transicoes.find({estadoAtual, simbolo});
            if (it == transicoes.end()) {
                return false;
            }
            estadoAtual = it->second;
        }
        return std::find(estadosFinais.begin(), estadosFinais.end(), estadoAtual) != estadosFinais.end();
    }
};
