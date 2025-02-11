#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 10  // Tamanho do vetor de bits
#define HASH_COUNT 3  // Número de funções hash

int bloomFilter[SIZE]; // Vetor de bits inicializado com 0

// Simples função hash (usamos apenas somas de caracteres para exemplo)
int hash1(const char *str) {
    int hash = 0;
    while (*str) hash += *str++;
    return hash % SIZE;
}

int hash2(const char *str) {
    int hash = 1;
    while (*str) hash *= (*str++ + 1);
    return (hash % SIZE);
}

int hash3(const char *str) {
    int hash = 7;
    while (*str) hash = (hash * 31) + *str++;
    return (hash % SIZE);
}

// Adiciona uma palavra ao Filtro de Bloom
void add(const char *str) {
    bloomFilter[hash1(str)] = 1;
    bloomFilter[hash2(str)] = 1;
    bloomFilter[hash3(str)] = 1;
}

// Verifica se uma palavra pode estar presente
int check(const char *str) {
    return bloomFilter[hash1(str)] && bloomFilter[hash2(str)] && bloomFilter[hash3(str)];
}

int main() {
    add("João");
    add("Carlos");

    printf("João está presente? %s\n", check("João") ? "Sim" : "Não");
    printf("Carlos está presente? %s\n", check("Carlos") ? "Sim" : "Não");
    printf("Maria está presente? %s\n", check("Maria") ? "Sim" : "Não");  // Deve retornar "Não"

    return 0;
}
