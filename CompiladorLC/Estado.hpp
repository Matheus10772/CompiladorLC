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
    Estado* getNextEstado();

    Estado(std::vector<std::string> regexs, std::vector<Estado*> estadosAlcancaveis);

private:
    std::string nome;
    std::vector<std::string> padroesRegex;
    std::vector<Estado*>::iterator currentEstadoIndice;
    std::vector<Estado*> estadosAlcancaveis;

    
};


#endif