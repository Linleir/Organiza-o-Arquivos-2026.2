import sys

TAM_REG = 300

if len(sys.argv) != 3:
    print("Uso: python3 buscacep.py [ARQUIVO] [CEP]")
    sys.exit(1)

nome_arquivo = sys.argv[1]
cep = sys.argv[2]

arquivo = open(nome_arquivo, "rb")

arquivo.seek(0, 2)
tamanho = arquivo.tell()
total_registros = tamanho // TAM_REG

contador = 0
inicio = 0
fim = total_registros - 1
achou = False

while inicio <= fim:
    contador += 1
    meio = (inicio+fim)//2
    arquivo.seek(meio*TAM_REG)
    registro = arquivo.read(TAM_REG).decode("latin-1")
    cep_registro = registro[290:298]

    if cep_registro == cep:
        print(f"Achei o CEP {cep} na posição {meio}")
        print(registro)
        achou = True
        break
    elif cep > cep_registro:
        inicio = meio + 1
    else:
        fim = meio - 1

if not achou:
    print(f"CEP {cep} não encontrado")

print(f"Contador: {contador}")

arquivo.close()
