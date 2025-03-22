#include "GeradorDeAutomatos.hpp"

bool Automato::addEstado(std::vector<std::string> regexsPermanencia, TipoEstado tipo)
{
	try
	{
		std::string estadoName = getNextEstadoName();
		std::shared_ptr<Estado> estado = std::make_shared<Estado>(estadoName, regexsPermanencia, tipo);

		this->todosOsEstados.insert({ estadoName, estado });

		return true;
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	
}

std::shared_ptr<Estado> Automato::procurarNosEstados(std::string estadoName)
{
	return this->todosOsEstados.at(estadoName);
}

std::vector<std::shared_ptr<Estado>> Automato::obterEstadosQueTransitaoPara(std::string estadoName)
{
	try
	{
		std::shared_ptr <Estado> estadoAlvo = procurarNosEstados(estadoName);

		std::vector<std::shared_ptr<Estado>> estadosQueTransitamPara;

		for (std::unordered_map<std::string, std::shared_ptr<Estado>>::iterator element = this->todosOsEstados.begin(); element != this->todosOsEstados.end(); element++)
		{
			if (element->second->getEstadoAlcavel(estadoAlvo->getNomeEstado()) ) {
				estadosQueTransitamPara.push_back(element->second);
			}
		}

		return estadosQueTransitamPara;
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

}

bool Automato::addTransicaoEntreEstados(std::string estadoOrigem, std::string estadoDestino, std::vector<std::string> regexTransicao)
{
	try
	{
		std::shared_ptr<Estado> ptrEstadoOrigem = procurarNosEstados(estadoOrigem);
		std::shared_ptr<Estado> ptrEstadoDestino = procurarNosEstados(estadoDestino);

		if (ptrEstadoOrigem != nullptr && ptrEstadoDestino != nullptr)
		{
			ptrEstadoOrigem->addEstadoAlcancavel(ptrEstadoDestino, regexTransicao);
			return true;
		}
		else
		{
			return false;
		}
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
}

bool Automato::removeEstado(std::string estadoName)
{
	try
	{
		std::shared_ptr<Estado> estadoToRemove = procurarNosEstados(estadoName);
		if (estadoToRemove != nullptr)
		{
			std::vector<std::shared_ptr<Estado>> estadosQueTransitamPara = obterEstadosQueTransitaoPara(estadoName);
			for (std::vector<std::shared_ptr<Estado>>::iterator element = estadosQueTransitamPara.begin(); element != estadosQueTransitamPara.end(); element++)
			{
				element->get()->clearEstadoAlcavel(estadoName);
			}
			this->todosOsEstados.erase(estadoName);
			return true;
		}
		else
		{
			return false;
		}
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	
	
}

std::string Automato::transitarEntreEstados(std::string lexema)
{
	
	std::shared_ptr<Estado> estadoTansicionado = this->estadoAtual->regexVerificador(lexema);

	if (estadoTansicionado != nullptr) {
		this->estadoAtual = estadoTansicionado;
        std::string statusDoAutomato = "\nO lexema foi aceito!: \n" +
                                          std::string("Estado Atual: ") + estadoTansicionado->getNomeEstado() + "\n" +
                                          std::string("Tipo do estado: ") + Estado::enumToString(this->estadoAtual->getTipoEstado()) + "\n";
		/*if (estadoTansicionado->getTipoEstado() == TipoEstado::FINAL)
		{
			this->~Automato();
		}*/
		return statusDoAutomato;
	}
	else
	{
		std::string errorMensage = "\nERRO: O lexema não é aceito pelo estado atual e nem pelos estados de transição.\n";
								  +"Ultimo Estado alcançado : " + this->estadoAtual->getNomeEstado() + "\n";
								  +"Tipo do estado: " + Estado::enumToString(this->estadoAtual->getTipoEstado()) + "\n";
								  +"Lexema : " + lexema + "\n";
								  +"Estados Alcançáveis: " + this->estadoAtual->getAllEstadosAlncancaveis() + "\n";
		return errorMensage;
	}
	
}

std::string Automato::getNextEstadoName()
{
	std::string name("q" + std::to_string(this->contadorEstados));
	this->contadorEstados++;
	return name;
}

Automato::Automato(std::string automatoName, std::vector<std::string> regexsPermanencia)
{
	this->automatoName = automatoName;

	TipoEstado firstEstadoTipo = TipoEstado::INICIAL;

	std::string estadoName = getNextEstadoName();
	std::shared_ptr<Estado> estado = std::make_shared<Estado>(estadoName, regexsPermanencia, firstEstadoTipo);

	this->todosOsEstados.insert({ estadoName, estado });

	this->estadoInicial = estado;
	this->estadoAtual = estado;

}

Automato::~Automato()
{
	this->todosOsEstados.clear();
}
