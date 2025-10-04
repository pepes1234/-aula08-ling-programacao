#include <stdio.h>
#define ALUNOS 5
#define DISCIPLINAS 4

// funcao para inserir todas as notas (passagem por referencia)
void inserir_notas(float notas[][DISCIPLINAS]) {
    for (int i = 0; i < ALUNOS; i++) {
        printf("digite as notas do aluno %d:\n", i + 1);
        for (int j = 0; j < DISCIPLINAS; j++) {
            printf("  disciplina %d: ", j + 1);
            scanf("%f", &notas[i][j]);
        }
    }
}

// funcao para exibir matriz de notas formatada (passagem por valor)
void exibir_notas(const float notas[][DISCIPLINAS]) {
    printf("\nnotas dos alunos:\n");
    printf("        ");
    for (int j = 0; j < DISCIPLINAS; j++) {
        printf("disc %d ", j + 1);
    }
    printf("\n");
    for (int i = 0; i < ALUNOS; i++) {
        printf("aluno %d: ", i + 1);
        for (int j = 0; j < DISCIPLINAS; j++) {
            printf("%6.2f ", notas[i][j]);
        }
        printf("\n");
    }
}

// funcao para calcular media de um aluno especifico (passagem por valor)
float calcular_media_aluno(const float notas[][DISCIPLINAS], int aluno) {
    float soma = 0;
    for (int j = 0; j < DISCIPLINAS; j++) {
        soma += notas[aluno][j];
    }
    return soma / DISCIPLINAS;
}

// funcao para calcular media de uma disciplina especifica (passagem por valor)
float calcular_media_disciplina(const float notas[][DISCIPLINAS], int disciplina) {
    float soma = 0;
    for (int i = 0; i < ALUNOS; i++) {
        soma += notas[i][disciplina];
    }
    return soma / ALUNOS;
}

// funcao para determinar situacao do aluno (aprovado ou reprovado)
void exibir_situacao_alunos(const float notas[][DISCIPLINAS]) {
    printf("\nsituacao dos alunos:\n");
    for (int i = 0; i < ALUNOS; i++) {
        float media = calcular_media_aluno(notas, i);
        printf("aluno %d: media = %.2f - %s\n", i + 1, media, (media >= 6.0) ? "aprovado" : "reprovado");
    }
}

// funcao para exibir relatorio final
void exibir_relatorio_final(const float notas[][DISCIPLINAS]) {
    exibir_notas(notas);
    printf("\nmedias por aluno:\n");
    for (int i = 0; i < ALUNOS; i++) {
        printf("aluno %d: %.2f\n", i + 1, calcular_media_aluno(notas, i));
    }
    printf("\nmedias por disciplina:\n");
    for (int j = 0; j < DISCIPLINAS; j++) {
        printf("disciplina %d: %.2f\n", j + 1, calcular_media_disciplina(notas, j));
    }
    exibir_situacao_alunos(notas);
}

int main() {
    float notas[ALUNOS][DISCIPLINAS] = {0};
    int opcao;
    do {
        printf("\nmenu do sistema de gestao de notas\n");
        printf("1 - inserir notas\n");
        printf("2 - exibir notas\n");
        printf("3 - calcular medias por aluno\n");
        printf("4 - calcular medias por disciplina\n");
        printf("5 - exibir aprovados/reprovados\n");
        printf("6 - exibir relatorio final\n");
        printf("0 - sair\n");
        printf("escolha uma opcao: ");
        scanf("%d", &opcao);
        switch (opcao) {
            case 1:
                inserir_notas(notas);
                break;
            case 2:
                exibir_notas(notas);
                break;
            case 3: {
                int aluno;
                printf("digite o numero do aluno (1 a %d): ", ALUNOS);
                scanf("%d", &aluno);
                if (aluno >= 1 && aluno <= ALUNOS) {
                    printf("media do aluno %d: %.2f\n", aluno, calcular_media_aluno(notas, aluno - 1));
                } else {
                    printf("aluno invalido\n");
                }
                break;
            }
            case 4: {
                int disciplina;
                printf("digite o numero da disciplina (1 a %d): ", DISCIPLINAS);
                scanf("%d", &disciplina);
                if (disciplina >= 1 && disciplina <= DISCIPLINAS) {
                    printf("media da disciplina %d: %.2f\n", disciplina, calcular_media_disciplina(notas, disciplina - 1));
                } else {
                    printf("disciplina invalida\n");
                }
                break;
            }
            case 5:
                exibir_situacao_alunos(notas);
                break;
            case 6:
                exibir_relatorio_final(notas);
                break;
            case 0:
                printf("saindo...\n");
                break;
            default:
                printf("opcao invalida\n");
        }
    } while (opcao != 0);
    return 0;
}