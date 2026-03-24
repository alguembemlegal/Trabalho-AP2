#include <stdio.h>
#include "morse.h"

//função para abrir o arquivo e traduzir
void traduzir(const char *nome_arquivo){
    FILE *file = fopen(nome_arquivo, "r"); //Abrimos o arquivo na função "r" que é apenas de leitura
    
    //validamos a abertura do arquivo
    if(file == NULL){
        printf("Erro ao abrir o arquivo\n");
        return;
    }

    char linha[1024]; //definimos o tamanho do buffer em 1024, um tamanho seguro parar armazenar uma linha
    //usaremos fgets para ler uma linha inteira por vez e não termos a leitura parada no primeiro espaço
    while (fgets(linha, sizeof(linha), file)){

        char codigo[50]; //variavel para construir as letras
        int i = 0; //percorre a linha
        int j = 0; //controla a posição (var codigo)
        
        //percorre a linha até chegar no fim 
        while(linha[i] != '\0'){
            if (linha[i] == '.' || linha[i] == '-' || linha[i] == '*'){
                codigo[j] = linha[i];
                j++; 
            }
            else if(linha[i] == ' ' || linha[i] == '\n'){ //procura espaço ou quebra de linha
                if(j>0){ 
                    codigo[j] = '\0'; // colocamos o ponto final na string
                    processar_codigo(codigo); //chama a tradução para letra
                    j=0; // zeramos o j para podermos seguir para a proxima letra
                }
                if(linha[i] == ' ' && linha[i+1]== ' '){ // caso o espaço atual e o proximo tambem for espaço
                    printf(" "); //separa as palavras
                    i++; //
                }
            }
            i++; //segue para o proximo caractere da linha
        }
        if(j > 0){ // se o arquivo acabar e ainda tiver simbolos na var codigo
                    codigo[j] = '\0'; //finaliza a string
                    processar_codigo(codigo);
                    j = 0;
                } 
        printf("\n");
    }
    fclose(file);
}