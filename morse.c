#include <stdio.h>
#include "morse.h"

//definição global do numero de letras
#define TOTAL_LETRAS 26 

const DicionarioMorse DICIONARIO[] = {
    {'A', ".-"}, {'B', "-..."}, {'C', "-.-."}, {'D', "-.."}, {'E', "."},
    {'F', "..-."}, {'G', "--."}, {'H', "...."}, {'I', ".."}, {'J', ".---"},
    {'K', "-.-"}, {'L', ".-.."}, {'M', "--"}, {'N', "-."}, {'O', "---"},
    {'P', ".--."}, {'Q', "--.-"}, {'R', ".-."}, {'S', "..."}, {'T', "-"},
    {'U', "..-"}, {'V', "...-"}, {'W', ".--"}, {'X', "-..-"}, {'Y', "-.--"},
    {'Z', "--.."}
};

//contar os caracteres
//como ainda não aprendemos as bibliotecas de string
//decidimos fazer manualmente ao invés de usar 'strlen'
int contar_tamanho(char *texto){
    int contagem = 0;
    while (texto[contagem] != '\0'){
        contagem++;
    }
    return contagem;
}

//busca letras que começam com o prefixo
void buscar_corrompido(char *prefixo, int indice_dic){
    //Parar caso todo dicionario já tenha sido percorrido
    if(indice_dic >= TOTAL_LETRAS) return;

    int i = 0;
    int igual = 1; //começamos acreditando que o codigo combina com a letra do dicionario

    //Comparação do codigo corrompido com o codigo da letra atual
    //Como tambem ainda não aprendemos 'strncmp' decidemos fazer o processo manual
    while (prefixo[i] != '\0'){
        if (prefixo[i] != DICIONARIO[indice_dic].codigo[i]){
            igual = 0; // se um simbolo . ou - for diferente, não são iguais
            break;
        }
        i++;
    }

    // caso apos percorrer todas as letras, a variavel igual continuar valendo 1.
    if (igual == 1) {
        printf("%c", DICIONARIO[indice_dic].letra); //se forem iguais, imprime a letra
    }

    // Chama a função novamente para testar a proxima letra;
    buscar_corrompido(prefixo, indice_dic + 1);
}

void processar_codigo(char *codigo){
    int tam = contar_tamanho(codigo);

    //identificaremos se a letra termina cmo * (Seria corrompida)
    if (codigo[tam - 1] == '*'){
        codigo[tam - 1] = '\0'; //removemos o * 
        //imprimos os colchetes segundo o enunciado para terem todas as opções possiveis dentro
        printf("[");
        buscar_corrompido(codigo, 0); //chamamos a recursão para encontrar as opções
        printf("]");
    }else{
        //comparação manual ao inves de 'strncmp'
        for(int i = 0; i < TOTAL_LETRAS; i++){
            int j = 0;
            int igual = 1;

            //checagem se os tamanhos são iguais
            if(contar_tamanho(DICIONARIO[i].codigo) != tam){
                igual = 0;
            }else{
                //se o tamanho for igual, comparamos os simbolos um a um
                while(codigo[j] != '\0'){
                    //Se for encontrado diferenças, é marcado como diferente (igual = 0)
                    if(codigo[j] != DICIONARIO[i].codigo[j]){
                        igual = 0;
                        break;
                    }
                    j++;
                }
            }
            //significa que o codigo morse é identico
            if(igual == 1){
                printf("%c", DICIONARIO[i].letra); //imprime a tradução
                return;
            }
        }
    }
}