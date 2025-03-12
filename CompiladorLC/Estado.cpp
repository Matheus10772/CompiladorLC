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

std::shared_ptr<Estado> Estado::procurarEstadoAlncancaveis(std::string estadoName) {
	return this->estadosAlcancaveis[estadoName];
}

TipoEstado Estado::getTipoEstado()
{
	return this->tipo;
}

bool Estado::addEstadoAlcancavel(std::shared_ptr<Estado> estado)
{
	if (estado != nullptr)
	{
		this->estadosAlcancaveis[estado->getNomeEstado()] = estado;
		return true;
	}
	else {
		return false;
	}
}

std::string Estado::getNomeEstado() {
	return this->name;
}


Estado::Estado(std::string estadoName, std::vector<std::string> regexs, std::unordered_map<std::string, std::shared_ptr<Estado>> estadosAlcancaveis, TipoEstado tipo)
{
	this->padroesRegex = regexs;
	this->estadosAlcancaveis = estadosAlcancaveis; // Corrigido de 'estadosAlcancavies' para 'estadosAlcancaveis'
	this->tipo = tipo;
}
