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
    //Vari�veis
    std::string name;
    std::vector<std::string> padroesRegex;
    std::unordered_map<std::string, std::shared_ptr<Estado>> estadosAlcancaveis;
	TipoEstado tipo;

    //M�todos
    bool regexVerificador(const std::string caracteres);
    std::string getNomeEstado();
    std::shared_ptr<Estado> procurarEstadoAlncancaveis(std::string estadoName);
    TipoEstado getTipoEstado();
    


    //Classe respons�vel pelo controle
	friend class GeradorDeAutomatos;
};


#endif