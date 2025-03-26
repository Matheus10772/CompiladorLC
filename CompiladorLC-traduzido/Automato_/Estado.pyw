import re
from typing import Dict, List, Optional, Tuple
from dataclasses import dataclass

@dataclass
class TipoEstado:
    INICIAL: str
    FINAL: str
    NORMAL: str

    INICIAL = "INICIAL"
    FINAL = "FINAL"
    NORMAL = "NORMAL"
    


class Estado:
    def __init__(self, estado_name: str, regexs_permanencia: List[str], tipo: TipoEstado):
        self.name = estado_name
        self.padroes_regex_permanencia = regexs_permanencia
        self.estados_alcancaveis: Dict[str, Tuple[List[str], "Estado"]] = {}
        self.tipo = tipo

    def regex_verificador(self, caracteres: str) -> Optional["Estado"]:
        """Verifica se os caracteres correspondem a algum padrão de permanência ou transição."""
        # Verificação nos padrões de permanência
        for padrao in self.padroes_regex_permanencia:
            if re.fullmatch(padrao, caracteres):
                return self  # Retorna o próprio estado

        # Verificação nos estados alcançáveis
        for estado_alcancavel in self.estados_alcancaveis.values():
            regex_transicoes, estado = estado_alcancavel
            for padrao in regex_transicoes:
                if re.fullmatch(padrao, caracteres):
                    return estado

        return None

    def get_estado_alcancavel(self, estado: str) -> Optional["Estado"]:
        """Retorna um estado alcançável pelo nome, se existir."""
        return self.estados_alcancaveis.get(estado, (None, None))[1] # Retorna o estado procurado ou nada, se não encontrar. [1] é para pegar o segundo elemento da tupla

    def clear_estado_alcancavel(self, estado: str) -> bool:
        """Remove um estado alcançável pelo nome."""
        return self.estados_alcancaveis.pop(estado, None) is not None

    def get_tipo_estado(self) -> TipoEstado:
        """Retorna o tipo do estado."""
        return self.tipo

    @staticmethod
    def enum_to_string(enum_tipo: TipoEstado) -> str:
        """Converte o tipo de estado em string."""
        return enum_tipo if enum_tipo in (TipoEstado.INICIAL, TipoEstado.NORMAL, TipoEstado.FINAL) else ""

    def get_all_estados_alcancaveis(self) -> str:
        """Retorna os nomes de todos os estados alcançáveis em uma única string, separados por nova linha."""
        return "\n".join(estado[1].get_nome_estado() for estado in self.estados_alcancaveis.values())

    def add_estado_alcancavel(self, estado: "Estado", regex_transicao: List[str]) -> bool:
        """Adiciona um estado alcançável com seus padrões de transição."""
        if estado:
            self.estados_alcancaveis[estado.get_nome_estado()] = (regex_transicao, estado)
            return True
        return False

    def get_nome_estado(self) -> str:
        """Retorna o nome do estado."""
        return self.name
