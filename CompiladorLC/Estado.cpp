#include "Estado.hpp"

class Estado  
{  
public:  

    Estado(std::vector<std::string> regexs, std::vector<Estado*> estadosAlcancavies);
   

   bool regexVerificador(std::string caracteres) {
    
    for (std::vector<std::string>::iterator indice = padroesRegex.begin(); indice != padroesRegex.end(); indice++) {
     std::regex padrao((*indice));
     if (std::regex_match(caracteres, padrao)) {
      return true;
     }

    }

    return false;
   }

   Estado* getNextEstado() {
    if (currentEstadoIndice != estadosAlcancaveis.end()) {
     return *currentEstadoIndice++;
    }
    else {
     currentEstadoIndice = estadosAlcancaveis.begin();
     return nullptr;
    }
    
   }

   std::string getNomeEstado() {
       return this->name;
   }



private:
    std::string name;
	std::vector<std::string> padroesRegex;
	std::vector<Estado*>::iterator currentEstadoIndice;
	std::vector<Estado*> estadosAlcancaveis;

	

};

Estado::Estado(std::vector<std::string> regexs, std::vector<Estado*> estadosAlcancavies)  
{  
	this->padroesRegex = regexs;
	this->estadosAlcancaveis = estadosAlcancavies;
	this->currentEstadoIndice = this->estadosAlcancaveis.begin();
}
