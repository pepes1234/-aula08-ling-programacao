#include <stdio.h>

#define TAM 10

// funcao para preencher o array com dados do usuario (por referencia)
void preencher_array(int *arr, int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        printf("numero %d: ", i + 1);
        scanf("%d", &arr[i]);
    }
}

// funcao para exibir o array (por valor, usando const)
void exibir_array(const int *arr, int tamanho) {
    printf("[");
    for (int i = 0; i < tamanho; i++) {
        printf("%d", arr[i]);
        if (i < tamanho - 1) printf(", ");
    }
    printf("]\n");
}

// funcao para encontrar o maior valor do array (por valor)
int maior_valor(const int *arr, int tamanho) {
    int maior = arr[0];
    for (int i = 1; i < tamanho; i++) {
        if (arr[i] > maior) maior = arr[i];
    }
    return maior;
}

// funcao para encontrar o menor valor do array (por valor)
int menor_valor(const int *arr, int tamanho) {
    int menor = arr[0];
    for (int i = 1; i < tamanho; i++) {
        if (arr[i] < menor) menor = arr[i];
    }
    return menor;
}

// funcao para calcular a media dos valores (por valor)
double media_array(const int *arr, int tamanho) {
    int soma = 0;
    for (int i = 0; i < tamanho; i++) {
        soma += arr[i];
    }
    return (double)soma / tamanho;
}

// funcao para ordenar o array em ordem crescente (por referencia)
void ordenar_array(int *arr, int tamanho) {
    for (int i = 0; i < tamanho - 1; i++) {
        for (int j = 0; j < tamanho - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main() {
    int numeros[TAM];
    // preencher o array
    printf("digite %d numeros:\n", TAM);
    preencher_array(numeros, TAM);
    // exibir array original
    printf("array original: ");
    exibir_array(numeros, TAM);
    // maior valor
    int maior = maior_valor(numeros, TAM);
    printf("maior valor: %d\n", maior);
    // menor valor
    int menor = menor_valor(numeros, TAM);
    printf("menor valor: %d\n", menor);
    // media
    double media = media_array(numeros, TAM);
    printf("media: %.2lf\n", media);
    // ordenar array
    ordenar_array(numeros, TAM);
    printf("array ordenado: ");
    exibir_array(numeros, TAM);
    return 0;
}
