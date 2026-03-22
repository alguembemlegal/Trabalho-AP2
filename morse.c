#include <stdio.h>
#include <sttring.h>
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

//busca letras que começam com o prefixo
void buscar_corrompido(char *prefixo, int indice_dic){
    //Parar caso todo dicionario já tenha sido percorrido
    if(indice_dic >= TOTAL_LETRAS) return;

    int i = 0;
    int igual = 1; //começamos acreditando que o codigo combina com a letra do dicionario

    //Comparação do codigo corrompido com o codigo da letra atual
    while (prefixo[i] != '\0'){
        if (prefixo[i] != DICIONARIO[indice_dic].codigo[j]){
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