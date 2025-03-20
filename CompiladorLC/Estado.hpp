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

    Estado(std::string estadoName, std::vector<std::string> regexsPermanencia, std::vector<std::string> regexsTransicao, TipoEstado tipo);
    bool addEstadoAlcancavel(std::shared_ptr<Estado> estado);

private:
    //Variáveis
    std::string name;
    std::vector<std::string> padroesRegexPermanencia;
    std::vector<std::string> padroesRegexTransicao;
    std::shared_ptr<Estado> estadoAlcavel = nullptr;
	TipoEstado tipo;

    //Métodos
    std::shared_ptr<Estado> regexVerificador(const std::string caracteres);
    std::string getNomeEstado();
    std::shared_ptr<Estado> getEstadoAlcavel();
    TipoEstado getTipoEstado();
    


    //Classe responsável pelo controle
	friend class GeradorDeAutomatos;
};


#endif