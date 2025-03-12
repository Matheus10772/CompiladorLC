#include "GeradorDeAutomatos.hpp"

bool Automato::addEstado(std::vector<std::string> regexs, std::vector<std::string> estadosAlcancaveis, TipoEstado tipo)
{
	try
	{
		std::vector<std::shared_ptr<Estado>> estadosAlcancaveisPtr;

		for (std::vector<std::string>::iterator indice = estadosAlcancaveis.begin(); indice != estadosAlcancaveis.end(); indice++)
		{
			std::shared_ptr<Estado> estado = procurarNosEstados(*indice);
			if (estado != nullptr)
			{
				estadosAlcancaveisPtr.push_back(estado);
			}

		}

		std::string estadoName = getNextEstadoName();
		std::shared_ptr<Estado> estado = std::make_shared<Estado>(estadoName, regexs, estadosAlcancaveisPtr, tipo);

		if (estadosAlcancaveis.begin()->compare("self"))
		{
			estado->addEstadoAlcancavel(estado);
		}

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

std::string Automato::getNextEstadoName()
{
	std::string name("q" + this->contadorEstados);
	this->contadorEstados++;
	return name;
}

Automato::Automato(std::string automatoName, std::vector<std::string> regexs)
{
	this->automatoName = automatoName;

	std::vector<std::string> estadosAlcancaveis;
	estadosAlcancaveis.push_back("self");

	TipoEstado firstEstadoTipo = TipoEstado::INICIAL;

	addEstado(regexs, estadosAlcancaveis, firstEstadoTipo);
}
