import os
from Automato_.GeradorDeAutomatos import Automato
from Automato_.Estado import TipoEstado


def imprimir_lista_de_strings(lista):
    """Imprime uma lista de strings."""
    for linha in lista:
        print(linha)


def ler_arquivo(nome_arquivo):
    """Lê um arquivo e retorna uma lista de linhas."""
    try:
        with open(nome_arquivo, "r", encoding="utf-8") as arquivo:
            return arquivo.readlines()
    except FileNotFoundError:
        print(f"Erro: Arquivo '{nome_arquivo}' não encontrado.")
        return []


def escreve_arquivo(nome_arquivo, linhas):
    """Escreve uma lista de strings em um arquivo."""
    with open(nome_arquivo, "w", encoding="utf-8") as arquivo:
        for linha in linhas:
            arquivo.write(linha + "\n")


def pre_processamento(linhas):
    """Remove espaços em branco de cada linha."""
    return ["".join(linha.split()) for linha in linhas]


def verificar_versao_do_so():
    """Verifica se o sistema operacional é Windows."""
    return os.name == "nt"


def corrigir_codificacao_do_terminal(versao_windows):
    """Ajusta a codificação do terminal no Windows."""
    if versao_windows:
        os.system("chcp 65001")


def ajustes_iniciais():
    """Executa ajustes iniciais no terminal."""
    corrigir_codificacao_do_terminal(verificar_versao_do_so())


def main():
    """Função principal."""
    ajustes_iniciais()

    print("Hello World!")
    
    # Ler um arquivo (altere o caminho para um válido no seu sistema)
    caminho_arquivo = "C:\\Users\\mathe\\Downloads\\Novo(a) Documento de Texto.txt"
    linhas = ler_arquivo(caminho_arquivo)
    
    print("Conteúdo do arquivo lido:")
    imprimir_lista_de_strings(linhas)

    # Criando autômato
    regexs = ["a", "b", "c"]
    lc_automato = Automato("My Automato", regexs)  # Estado inicial q0

    regexs2 = ["d", "e", "f"]  # Estado q1
    regexs3 = ["g", "h", "i"]  # Estado q2

    lc_automato.add_estado(regexs2, TipoEstado.NORMAL)
    lc_automato.add_estado(regexs3, TipoEstado.FINAL)

    lc_automato.add_transicao_entre_estados("q0", "q1", ["z"])
    lc_automato.add_transicao_entre_estados("q1", "q2", ["z"])

    print(lc_automato.transitar_entre_estados("z"))
    print(lc_automato.transitar_entre_estados("z"))


if __name__ == "__main__":
    main()
