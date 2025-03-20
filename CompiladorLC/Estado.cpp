#include "Estado.hpp"

std::shared_ptr<Estado> Estado::regexVerificador(std::string caracteres) {

	for (std::vector<std::string>::iterator indice = padroesRegexPermanencia.begin(); indice != padroesRegexPermanencia.end(); indice++) {
		std::regex padrao((*indice));
		if (std::regex_match(caracteres, padrao)) {
			return shared_from_this();
		}
	}

	for (std::vector<std::string>::iterator indice = padroesRegexTransicao.begin(); indice != padroesRegexTransicao.end(); indice++) {
		std::regex padrao((*indice));
		if (std::regex_match(caracteres, padrao)) {
			return this->estadoAlcavel;
		}
	}

	return nullptr;
}

std::shared_ptr<Estado> Estado::getEstadoAlcavel() {
	return this->estadoAlcavel;
}

TipoEstado Estado::getTipoEstado()
{
	return this->tipo;
}

bool Estado::addEstadoAlcancavel(std::shared_ptr<Estado> estado)
{
	if (estado != nullptr)
	{
		this->estadoAlcavel = estado;
		return true;
	}
	else {
		return false;
	}
}

std::string Estado::getNomeEstado() {
	return this->name;
}


Estado::Estado(std::string estadoName, std::vector<std::string> regexsPermanencia, std::vector<std::string> regexsTransicao, TipoEstado tipo)
{
	this->name = estadoName;
	this->padroesRegexPermanencia = regexsPermanencia;
	this->padroesRegexTransicao = regexsTransicao;
	this->tipo = tipo;
}
           