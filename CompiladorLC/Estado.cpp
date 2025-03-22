#include "Estado.hpp"

std::shared_ptr<Estado> Estado::regexVerificador(std::string caracteres) {

	for (std::vector<std::string>::iterator indice = padroesRegexPermanencia.begin(); indice != padroesRegexPermanencia.end(); indice++) {
		std::regex padrao((*indice));
		if (std::regex_match(caracteres, padrao)) {
			return shared_from_this();
		}
	}

	for (std::unordered_map<std::string, EstadoAlcancavel>::iterator indice = estadosAlcancaveis.begin(); indice != estadosAlcancaveis.end(); indice++) {
		
		for (std::vector<std::string>::iterator indiceRegex = indice->second.first.begin(); indiceRegex != indice->second.first.end(); indiceRegex++) {
			std::regex padrao((*indiceRegex));
			if (std::regex_match(caracteres, padrao)) {
				return indice->second.second;
			}
		}
	}

	return nullptr;
}

std::shared_ptr<Estado> Estado::getEstadoAlcavel(std::string estado) {
	try
	{

		return this->estadosAlcancaveis.at(estado).second;
	}
	catch (const std::exception& e)
	{
		return nullptr;
	}
	
}

bool Estado::clearEstadoAlcavel(std::string estado)
{
	try
	{
		this->estadosAlcancaveis.erase(estado);
		return true;
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
}

TipoEstado Estado::getTipoEstado()
{
	return this->tipo;
}

std::string Estado::enumToString(TipoEstado enumTipo)
{
	switch (enumTipo)
	{
	case TipoEstado::INICIAL:
		return "INICIAL";
		break;
	case TipoEstado::NORMAL:
		return "NORMAL";
		break;
	case TipoEstado::FINAL:
		return "FINAL";
		break;
	default:
		return "\0";
		break;
	}
}

std::string Estado::getAllEstadosAlncancaveis()
{
	std::string estadosAlcancaveis;
	for (std::unordered_map<std::string, EstadoAlcancavel>::iterator indice = this->estadosAlcancaveis.begin(); indice != this->estadosAlcancaveis.end(); indice++)
	{
		estadosAlcancaveis.append(indice->second.second->getNomeEstado() + "\n");
	}

	return estadosAlcancaveis;
}



bool Estado::addEstadoAlcancavel(std::shared_ptr<Estado> estado, std::vector<std::string> regexTransicao)
{
	try
	{
		if (estado != nullptr)
		{
			EstadoAlcancavel novoEstadoAlcancavel(regexTransicao, estado);
			this->estadosAlcancaveis.insert({ estado->getNomeEstado(), novoEstadoAlcancavel });
			return true;
		}
		else {
			return false;
		}
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	
}

std::string Estado::getNomeEstado() {
	return this->name;
}


Estado::Estado(std::string estadoName, std::vector<std::string> regexsPermanencia, TipoEstado tipo)
{
	this->name = estadoName;
	this->padroesRegexPermanencia = regexsPermanencia;
	this->tipo = tipo;
}
           