#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_TEXTO 10000
#define DESLOCAMENTO 3

void limparBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

void lerArquivo(char texto[]) {
    char nomeArquivo[100];
    FILE *arquivo;
    char caractere;
    int i = 0;

    printf("Digite o nome do arquivo de entrada: ");
    scanf("%s", nomeArquivo);

    arquivo = fopen(nomeArquivo, "r");

    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }

    while ((caractere = fgetc(arquivo)) != EOF && i < MAX_TEXTO - 1) {
        texto[i] = caractere;
        i++;
    }

    texto[i] = '\0';

    fclose(arquivo);

    printf("\nArquivo lido com sucesso!\n");
    printf("\nConteudo do arquivo:\n");
    printf("%s\n", texto);
}

void criptografar(char texto[]) {
    int i;

    if (strlen(texto) == 0) {
        printf("Nenhum texto foi carregado.\n");
        return;
    }

    for (i = 0; texto[i] != '\0'; i++) {
        if (isupper(texto[i])) {
            texto[i] = ((texto[i] - 'A' + DESLOCAMENTO) % 26) + 'A';
        } else if (islower(texto[i])) {
            texto[i] = ((texto[i] - 'a' + DESLOCAMENTO) % 26) + 'a';
        }
    }

    printf("\nTexto criptografado com sucesso!\n");
    printf("\nTexto criptografado:\n");
    printf("%s\n", texto);
}

void descriptografar(char texto[]) {
    int i;

    if (strlen(texto) == 0) {
        printf("Nenhum texto foi carregado.\n");
        return;
    }

    for (i = 0; texto[i] != '\0'; i++) {
        if (isupper(texto[i])) {
            texto[i] = ((texto[i] - 'A' - DESLOCAMENTO + 26) % 26) + 'A';
        } else if (islower(texto[i])) {
            texto[i] = ((texto[i] - 'a' - DESLOCAMENTO + 26) % 26) + 'a';
        }
    }

    printf("\nTexto descriptografado com sucesso!\n");
    printf("\nTexto descriptografado:\n");
    printf("%s\n", texto);
}

void salvarArquivo(char texto[]) {
    char nomeArquivo[100];
    FILE *arquivo;

    if (strlen(texto) == 0) {
        printf("Nenhum texto foi carregado para salvar.\n");
        return;
    }

    printf("Digite o nome do arquivo de saida: ");
    scanf("%s", nomeArquivo);

    arquivo = fopen(nomeArquivo, "w");

    if (arquivo == NULL) {
        printf("Erro ao salvar o arquivo.\n");
        return;
    }

    fprintf(arquivo, "%s", texto);

    fclose(arquivo);

    printf("\nArquivo salvo com sucesso!\n");
}

int main() {
    char texto[MAX_TEXTO] = "";
    int opcao;

    do {
        printf("\n===== MENU =====\n");
        printf("1 - Ler arquivo texto\n");
        printf("2 - Criptografar\n");
        printf("3 - Descriptografar\n");
        printf("4 - Salvar arquivo\n");
        printf("5 - Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);
        limparBuffer();

        switch (opcao) {
            case 1:
                lerArquivo(texto);
                break;

            case 2:
                criptografar(texto);
                break;

            case 3:
                descriptografar(texto);
                break;

            case 4:
                salvarArquivo(texto);
                break;

            case 5:
                printf("Encerrando o programa...\n");
                break;

            default:
                printf("Opcao invalida. Tente novamente.\n");
        }

    } while (opcao != 5);

    return 0;
}