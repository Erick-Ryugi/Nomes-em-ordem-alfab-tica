#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

#define MAX_NOMES 100
#define MAX_TAM_NOME 50

void bubbleSort(char nomes[][MAX_TAM_NOME], int n) {
    int i, j;
    char temp[MAX_TAM_NOME];

    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (strcmp(nomes[j], nomes[j + 1]) > 0) {
                // Troca os nomes
                strcpy(temp, nomes[j]);
                strcpy(nomes[j], nomes[j + 1]);
                strcpy(nomes[j + 1], temp);
            }
        }
    }
}

int main() {
    setlocale(LC_ALL, "Portuguese");

    char nomes[MAX_NOMES][MAX_TAM_NOME];
    int num_nomes, i;

    printf("Digite o número de nomes que deseja ordenar: ");
    scanf("%d", &num_nomes);
    getchar(); // Limpar o buffer de entrada

    if (num_nomes > MAX_NOMES) {
        printf("Número de nomes excede o máximo permitido.\n");
        return 1;
    }

    printf("Digite os nomes um por um:\n");
    for (i = 0; i < num_nomes; i++) {
        printf("Nome %d: ", i + 1);
        fgets(nomes[i], MAX_TAM_NOME, stdin);
        nomes[i][strcspn(nomes[i], "\n")] = '\0'; // Remover o newline
    }

    // Chama a função Bubble Sort para ordenar os nomes
    bubbleSort(nomes, num_nomes);

    // Imprime os nomes ordenados
    printf("\nNomes em ordem alfabética:\n");
    for (i = 0; i < num_nomes; i++) {
        printf("%s\n", nomes[i]);
    }

    return 0;
}

