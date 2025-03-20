#include <vector>
#include <map>
#include <string>
#include <algorithm>
#include "Estado.hpp"

class Automato {


private:
    std::unordered_map<std::string, std::shared_ptr<Estado>> todosOsEstados;
	std::shared_ptr<Estado> estadoInicial; 
	std::shared_ptr<Estado> estadoAtual;
	std::string automatoName;
	int contadorEstados = 0;

	std::string getNextEstadoName();

public:
	Automato(std::string automatoName, std::vector<std::string> regexsPermanencia, std::vector<std::string> regexsTransicao);

	bool addEstado(std::vector<std::string> regexsPermanencia, std::vector<std::string> regexsTransicao,std::string estadoAlcancavel, TipoEstado tipo);

	std::shared_ptr<Estado> procurarNosEstados(std::string estadoName);

	bool addTransicaoEntreEstados(std::string estadoOrigem, std::string estadoDestino);
	
	bool removeEstado(std::string estadoName);

	//Faça aqui um método que imprima e mostre o Automato (Utilizar interface gráfica ?)

    
};
