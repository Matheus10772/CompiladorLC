#ifndef GERADORAUTOMATO_HPP
#define GERADORAUTOMATO_HPP


#include "Estado.hpp"
#include <map>
#include <algorithm>


class Automato {


private:
    std::unordered_map<std::string, std::shared_ptr<Estado>> todosOsEstados;
	std::shared_ptr<Estado> estadoInicial; 
	std::shared_ptr<Estado> estadoAtual;
	std::string automatoName;
	int contadorEstados = 0;

	std::string getNextEstadoName();

public:
	Automato(std::string automatoName, std::vector<std::string> regexsPermanencia);
	~Automato(); // Destrutor da classe

	bool addEstado(std::vector<std::string> regexsPermanencia, TipoEstado tipo);

	bool addTransicaoEntreEstados(std::string estadoOrigem, std::string estadoDestino, std::vector<std::string> regexTransicao);
	
	std::shared_ptr<Estado> procurarNosEstados(std::string estadoName);

	std::vector <std::shared_ptr<Estado>> obterEstadosQueTransitaoPara(std::string estadoName);

	bool removeEstado(std::string estadoName);

	//Faça aqui um método que imprima e mostre o Automato (Utilizar interface gráfica ?)

	std::string transitarEntreEstados(std::string lexema);

	
    
};

#endif
