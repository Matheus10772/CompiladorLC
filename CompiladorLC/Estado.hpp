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



class Estado : std::enable_shared_from_this<Estado> {
public:

    Estado(std::string estadoName, std::vector<std::string> regexsPermanencia, TipoEstado tipo);
    bool addEstadoAlcancavel(std::shared_ptr<Estado> estado, std::vector<std::string> regexTransicao);
    std::shared_ptr<Estado> getEstadoAlcavel(std::string estado);
	bool clearEstadoAlcavel(std::string estado);
    std::string getNomeEstado();
    std::shared_ptr<Estado> regexVerificador(std::string caracteres);
    TipoEstado getTipoEstado();
    static std::string enumToString(TipoEstado enumTipo);
	std::string getAllEstadosAlncancaveis();

private:

    typedef std::pair<std::vector<std::string>, std::shared_ptr<Estado>> EstadoAlcancavel;

    //Variáveis
    std::string name;
    std::vector<std::string> padroesRegexPermanencia;
    std::unordered_map<std::string, EstadoAlcancavel> estadosAlcancaveis;
	TipoEstado tipo;

    //Métodos
    
    
    
    
    


    //Classe responsável pelo controle
	friend class GeradorDeAutomatos;
};


#endif