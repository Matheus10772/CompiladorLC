#ifndef ESTADO_HPP
#define ESTADO_HPP


#include <string>  
#include <iostream> 
#include <vector>
#include <regex>

class Estado {
public:
    std::string name;

    bool regexVerificador(const std::string caracteres);
    std::string getNomeEstado();
    std::shared_ptr<Estado> getNextEstado();

    Estado(std::vector<std::string> regexs, std::vector<std::shared_ptr<Estado>> estadosAlcancaveis);

private:
    std::string nome;
    std::vector<std::string> padroesRegex;
    std::vector<std::shared_ptr<Estado>> estadosAlcancaveis;
    std::vector<std::shared_ptr<Estado>>::iterator currentEstadoIndice;

    
};


#endif