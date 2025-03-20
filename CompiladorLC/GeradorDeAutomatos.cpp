#include "GeradorDeAutomatos.hpp"

bool Automato::addEstado(std::vector<std::string> regexsPermanencia, std::vector<std::string> regexsTransicao, std::string estadoAlcancavel, TipoEstado tipo)
{
	try
	{
		std::shared_ptr<Estado> estadoAlcancavelPtr = nullptr;



		std::shared_ptr<Estado> estado = procurarNosEstados(estadoAlcancavel);
		if (estado != nullptr)
		{
			estadoAlcancavelPtr = estado;
		}

		std::string estadoName = getNextEstadoName();
		std::shared_ptr<Estado> estado = std::make_shared<Estado>(estadoName, regexsPermanencia, regexsTransicao, estadoAlcancavelPtr, tipo);

		this->todosOsEstados[estadoName] = estado;

		return true;
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	
}

std::shared_ptr<Estado> Automato::procurarNosEstados(std::string estadoName)
{
	return this->todosOsEstados[estadoName];
}

bool Automato::addTransicaoEntreEstados(std::string estadoOrigem, std::string estadoDestino)
{
	std::shared_ptr<Estado> ptrEstadoOrigem= procurarNosEstados(estadoOrigem);
	std::shared_ptr<Estado> ptrEstadoDestino = procurarNosEstados(estadoDestino);

	if (ptrEstadoOrigem != nullptr && ptrEstadoDestino != nullptr)
	{
		ptrEstadoOrigem->addEstadoAlcancavel(ptrEstadoDestino);
		return true;
	}
	else
	{
		return false;
	}
}

std::string Automato::getNextEstadoName()
{
	std::string name("q" + this->contadorEstados);
	this->contadorEstados++;
	return name;
}

Automato::Automato(std::string automatoName, std::vector<std::string> regexsPermanencia, std::vector<std::string> regexsTransicao)
{
	this->automatoName = automatoName;

	TipoEstado firstEstadoTipo = TipoEstado::INICIAL;

	std::string estadoName = getNextEstadoName();
	std::shared_ptr<Estado> estado = std::make_shared<Estado>(estadoName, regexsPermanencia, regexsTransicao, firstEstadoTipo);

	this->todosOsEstados[estadoName] = estado;

}
