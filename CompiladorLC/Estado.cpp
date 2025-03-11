#include "Estado.hpp"

bool Estado::regexVerificador(std::string caracteres) {

	for (std::vector<std::string>::iterator indice = padroesRegex.begin(); indice != padroesRegex.end(); indice++) {
		std::regex padrao((*indice));
		if (std::regex_match(caracteres, padrao)) {
			return true;
		}

	}

	return false;
}

Estado* Estado::getNextEstado() {
	if (currentEstadoIndice != estadosAlcancaveis.end()) {
		return *currentEstadoIndice++;
	}
	else {
		currentEstadoIndice = estadosAlcancaveis.begin();
		return nullptr;
	}

}

std::string Estado::getNomeEstado() {
	return this->name;
}


Estado::Estado(std::vector<std::string> regexs, std::vector<Estado*> estadosAlcancaveis)
{
	this->padroesRegex = regexs;
	this->estadosAlcancaveis = estadosAlcancaveis; // Corrigido de 'estadosAlcancavies' para 'estadosAlcancaveis'
	this->currentEstadoIndice = this->estadosAlcancaveis.begin();
}
