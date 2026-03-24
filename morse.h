#ifndef MORSE_H
#define MORSE_H

// Definição da struct com o dicionario morse
typedef struct {
    char letra;
    char *codigo;
} DicionarioMorse;

// prototipo das funções
void traduzir(const char *nome_arquivo);
void processar_codigo(char *codigo);
void buscar_corrompido(char *prefixo, int indice_dic);
int contar_tamanho(char *texto);

#endif