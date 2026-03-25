# Trabalho-AP2
Trabalho de algoritmos e programação II
Mackenzie

Esse projeto, consiste em um tradutor de codigo Morse, desenvolvido em linguagem C O programa processa mensagens a partir de um arquivo de entrada **(entrada.txt)**, tratando espaços entre letras, sendo um espaço a separação das letras do codigo e 2 espaços sendo um espaço entre as letras, ele tambem trata a recuperação de caracteres corrompidos por meio da recursividade

# Estrutura do projeto
Optamos por modularizar o codigo em três arquivos principais
### Main.c
Inicia o programa chamando a função principal
### Morse.c
Aqui está o dicionario morse, a função de contagem de strings e a logica de busca recursiva para caracteres corrompidos
### Traduzir.c
Responsavel por abrir os arquivos, ler as linhas, separar os blocos de codigo e fazer o tratamento dos espaços
### Morse.h
Arquivo header que conecta os modulos do programa, contendo a definição da struct e os prototipos das funções

# Formato de uso
O programa busca um arquivo chamado **entrada.txt** onde estara o codigo morse, seguindo estas regras
### Separação das letras
Use apenas um espaço simples entre cada codigo morse
### Separação de palavras
Use dois espaços entre os codigos morse
### Caracteres corrompidos
Use * ao final de um codigo incompleto para ver todas as possiveis traduções para ele


## Integrantes do grupo
Pedro Henrique da Silva Dias  
Ra: 10769835  
Kauã dos Reis de Castro Souza  
Ra: 10738693  
Danilo Maciel  
Ra: 10419452  
