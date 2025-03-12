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
	int contadorEstados;

	std::string getNextEstadoName();

public:
	Automato(std::string automatoName, std::vector<std::string> regexs);

	bool addEstado(std::vector<std::string> regexs, std::vector<std::string> estadosAlcancaveis, TipoEstado tipo);

	std::shared_ptr<Estado> procurarNosEstados(std::string estadoName);
	

    
};
