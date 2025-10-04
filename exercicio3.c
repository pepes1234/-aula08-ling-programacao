#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define TAM 101

// funcao para ler uma string do usuario (max 100 caracteres)
void ler_string(char *str) {
    printf("digite uma string: ");
    fgets(str, TAM, stdin);
    size_t len = strlen(str);
    if (len > 0 && str[len - 1] == '\n') {
        str[len - 1] = '\0';
    }
}

// funcao para contar caracteres (por valor)
int contar_caracteres(const char *str) {
    return strlen(str);
}

// funcao para inverter string in-place (por referencia)
void inverter_string(char *str) {
    int i = 0, j = strlen(str) - 1;
    while (i < j) {
        char temp = str[i];
        str[i] = str[j];
        str[j] = temp;
        i++;
        j--;
    }
}

// funcao para converter para maiuscula in-place (por referencia)
void para_maiuscula(char *str) {
    for (int i = 0; str[i] != '\0'; i++) {
        str[i] = toupper((unsigned char)str[i]);
    }
}

// funcao para converter para minuscula in-place (por referencia)
void para_minuscula(char *str) {
    for (int i = 0; str[i] != '\0'; i++) {
        str[i] = tolower((unsigned char)str[i]);
    }
}

// funcao para contar numero de palavras (por valor)
int contar_palavras(const char *str) {
    int count = 0, in_word = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        if (!isspace((unsigned char)str[i]) && in_word == 0) {
            in_word = 1;
            count++;
        } else if (isspace((unsigned char)str[i])) {
            in_word = 0;
        }
    }
    return count;
}

// funcao para exibir o menu
void exibir_menu() {
    printf("=== manipulador de strings ===\n");
    printf("1. contar caracteres\n");
    printf("2. inverter string\n");
    printf("3. converter maiuscula\n");
    printf("4. converter minuscula\n");
    printf("5. contar palavras\n");
    printf("0. sair\n");
}

int main() {
    char str[TAM];
    int opcao;
    ler_string(str);
    do {
        exibir_menu();
        printf("opcao: ");
        scanf("%d", &opcao);
        getchar(); // limpar o \n do buffer
        switch (opcao) {
            case 1:
                printf("a string possui %d caracteres.\n", contar_caracteres(str));
                break;
            case 2:
                inverter_string(str);
                printf("string invertida: %s\n", str);
                break;
            case 3:
                para_maiuscula(str);
                printf("string maiuscula: %s\n", str);
                break;
            case 4:
                para_minuscula(str);
                printf("string minuscula: %s\n", str);
                break;
            case 5:
                printf("a string possui %d palavras.\n", contar_palavras(str));
                break;
            case 0:
                printf("saindo...\n");
                break;
            default:
                printf("opcao invalida\n");
        }
        printf("\n");
    } while (opcao != 0);
    return 0;
}
