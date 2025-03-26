from typing import Dict, List, Optional

from Automato_.Estado import Estado, TipoEstado

class Automato:
    def __init__(self, automato_name: str, regexs_permanencia: List[str]):
        self.automato_name = automato_name
        self.todos_os_estados: Dict[str, Estado] = {}
        self.contador_estados = 0

        # Criando o primeiro estado
        estado_name = self.get_next_estado_name()
        estado = Estado(estado_name, regexs_permanencia, TipoEstado.INICIAL)
        self.todos_os_estados[estado_name] = estado
        
        self.estado_inicial = estado
        self.estado_atual = estado

    def get_next_estado_name(self) -> str:
        name = f"q{self.contador_estados}"
        self.contador_estados += 1
        return name

    def add_estado(self, regexs_permanencia: List[str], tipo: TipoEstado) -> bool:
        try:
            estado_name = self.get_next_estado_name()
            estado = Estado(estado_name, regexs_permanencia, tipo)
            self.todos_os_estados[estado_name] = estado
            return True
        except Exception as e:
            print(e)
            return False

    def procurar_nos_estados(self, estado_name: str) -> Optional[Estado]:
        return self.todos_os_estados.get(estado_name)

    def obter_estados_que_transitam_para(self, estado_name: str) -> List[Estado]:
        try:
            estado_alvo = self.procurar_nos_estados(estado_name)
            if not estado_alvo:
                return []
            
            return [estado for estado in self.todos_os_estados.values() if estado.get_estado_alcancavel(estado_alvo.get_nome_estado())]
        except Exception as e:
            print(e)
            return []

    def add_transicao_entre_estados(self, estado_origem: str, estado_destino: str, regex_transicao: List[str]) -> bool:
        try:
            estado_origem_obj = self.procurar_nos_estados(estado_origem)
            estado_destino_obj = self.procurar_nos_estados(estado_destino)

            if estado_origem_obj and estado_destino_obj:
                estado_origem_obj.add_estado_alcancavel(estado_destino_obj, regex_transicao)
                return True
            return False
        except Exception as e:
            print(e)
            return False

    def remove_estado(self, estado_name: str) -> bool:
        try:
            estado_to_remove = self.procurar_nos_estados(estado_name)
            if not estado_to_remove:
                return False
            
            estados_que_transitam_para = self.obter_estados_que_transitam_para(estado_name)
            for estado in estados_que_transitam_para:
                estado.clear_estado_alcancavel(estado_name)
            
            del self.todos_os_estados[estado_name]
            return True
        except Exception as e:
            print(e)
            return False

    def transitar_entre_estados(self, lexema: str) -> str:
        estado_transicionado = self.estado_atual.regex_verificador(lexema)
        if estado_transicionado:
            self.estado_atual = estado_transicionado
            return f"\nO lexema foi aceito!:\nEstado Atual: {estado_transicionado.get_nome_estado()}\nTipo do estado: {Estado.enum_to_string(self.estado_atual.get_tipo_estado())}\n"
        else:
            return (f"\nERRO: O lexema não é aceito pelo estado atual e nem pelos estados de transição.\n"
                    f"Último Estado alcançado: {self.estado_atual.get_nome_estado()}\n"
                    f"Tipo do estado: {Estado.enum_to_string(self.estado_atual.get_tipo_estado())}\n"
                    f"Lexema: {lexema}\n"
                    f"Estados Alcançáveis: {self.estado_atual.get_all_estados_alcancaveis()}\n")

    def __del__(self):
        self.todos_os_estados.clear()
