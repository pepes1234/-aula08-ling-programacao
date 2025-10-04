
#include <stdio.h>

// funcao para exibir o menu
void menu() {
    printf("=== calculadora ===\n");
    printf("1. somar\n");
    printf("2. subtrair\n");
    printf("3. multiplicar\n");
    printf("4. dividir\n");
    printf("0. sair\n");
}

// funcao para obter a opcao do usuario
int readUserOption() {
    int verify, input;
    do {
        verify = scanf("%d", &input);
        if (verify != 1 || input < 0 || input > 4) {
            printf("opcao invalida, digite novamente:\n");
            while (getchar() != '\n');
        }
    } while (input < 0 || input > 4 || verify != 1);
    return input;
}

// funcao para obter dois numeros do usuario (por referencia)
void readUserValues(double *n1, double *n2) {
    printf("digite o primeiro numero: ");
    while (scanf("%lf", n1) != 1) {
        printf("entrada invalida, digite um numero: ");
        while (getchar() != '\n');
    }
    printf("digite o segundo numero: ");
    while (scanf("%lf", n2) != 1) {
        printf("entrada invalida, digite um numero: ");
        while (getchar() != '\n');
    }
}

// funcao para somar (por valor)
double somar(double a, double b) {
    return a + b;
}

// funcao para subtrair (por valor)
double subtrair(double a, double b) {
    return a - b;
}

// funcao para multiplicar (por valor)
double multiplicar(double a, double b) {
    return a * b;
}

// funcao para dividir (por valor)
double dividir(double a, double b) {
    if (b == 0) {
        // tratamento para divisao por zero
        printf("erro: divisao por zero\n");
        return 0;
    }
    return a / b;
}

// funcao para exibir o resultado
void exibir_resultado(double resultado) {
    printf("resultado: %.2lf\n", resultado);
}

int main() {
    int opcao;
    double a, b, resultado;
    while (1) {
        menu();
        opcao = readUserOption();
        if (opcao == 0) {
            // sair do programa
            printf("saindo...\n");
            break;
        }
        if (opcao >= 1 && opcao <= 4) {
            readUserValues(&a, &b);
            switch (opcao) {
                case 1:
                    resultado = somar(a, b);
                    exibir_resultado(resultado);
                    break;
                case 2:
                    resultado = subtrair(a, b);
                    exibir_resultado(resultado);
                    break;
                case 3:
                    resultado = multiplicar(a, b);
                    exibir_resultado(resultado);
                    break;
                case 4:
                    if (b == 0) {
                        printf("erro: divisao por zero\n");
                    } else {
                        resultado = dividir(a, b);
                        exibir_resultado(resultado);
                    }
                    break;
            }
        } else {
            printf("opcao invalida\n");
        }
        printf("\n");
    }
    return 0;
}
