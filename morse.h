#ifndef MORSE_H
#define MORSE_H

// Definição da struct com o dicionario morse
typedef struct {
    char letra;
    char *codigo;
} MorseMap;

// prototipo das funções
void traduzir_arquivo(const char *nome_arquivo);
void processar_codigo(char *codigo);
void buscar_corrompido(char *prefixo, int indice_dic);

#endif