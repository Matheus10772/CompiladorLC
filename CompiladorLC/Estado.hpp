#ifndef ESTADO_HPP
#define ESTADO_HPP


#include <string>  
#include <iostream> 
#include <vector>
#include <regex>
#include <unordered_map>

enum TipoEstado {
	INICIAL,
	FINAL,
	NORMAL
};

class Estado {
public:

    Estado(std::string estadoName, std::vector<std::string> regexs, std::unordered_map<std::string ,std::shared_ptr<Estado>> estadosAlcancaveis, TipoEstado tipo);
    bool addEstadoAlcancavel(std::shared_ptr<Estado> estado);

private:
    //Variáveis
    std::string name;
    std::vector<std::string> padroesRegex;
    std::unordered_map<std::string, std::shared_ptr<Estado>> estadosAlcancaveis;
	TipoEstado tipo;

    //Métodos
    bool regexVerificador(const std::string caracteres);
    std::string getNomeEstado();
    std::shared_ptr<Estado> procurarEstadoAlncancaveis(std::string estadoName);
    TipoEstado getTipoEstado();
    


    //Classe responsável pelo controle
	friend class GeradorDeAutomatos;
};


#endif