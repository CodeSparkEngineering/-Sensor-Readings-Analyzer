#include <stdio.h>
#include <stdlib.h>

int main() {
    int N;
    float *leituras;
    float soma = 0.0, media, minimo, maximo;

    // Passo a) Pedir ao usuário a quantidade de leituras
    printf("Quantas leituras? ");
    scanf("%d", &N);

    // Passo b) Alocar dinamicamente
    leituras = (float*) malloc(N * sizeof(float));
    if (leituras == NULL) {
        printf("Erro de alocação de memória!\n");
        return 1;
    }

    // Passo c) Ler os N valores
    printf("Digite as leituras:\n");
    for(int i = 0; i < N; i++) {
        scanf("%f", &leituras[i]);
    }

    // Passo d) Calcular soma, mínimo e máximo
    minimo = maximo = leituras[0];
    for(int i = 0; i < N; i++) {
        soma += leituras[i];
        if(leituras[i] < minimo) minimo = leituras[i];
        if(leituras[i] > maximo) maximo = leituras[i];
    }
    media = soma / N;

    // Passo e) Exibir resultados
    printf("\nResultado:\n");
    printf("- Média: %.2f\n", media);
    printf("- Mínimo: %.2f\n", minimo);
    printf("- Máximo: %.2f\n", maximo);

    // Liberar memória
    free(leituras);

    return 0;
}
