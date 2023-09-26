// PONTOS
// A - (-8, 2)
// B - (-10, -4)
// C - (-6, -8)
// D - (2, -8)
// E - (0, -2)
// F - (-6, -4)
// G - (-2, 8)

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "ponto.h"

int main() {
    FILE *arquivo;
    int numVertices;

    // Abre o arquivo de entrada
    arquivo = fopen("vertices.txt", "r");

    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return 1;
    }

    // Lê o número de vértices
    fscanf(arquivo, "%d", &numVertices);

    // Aloca espaço para armazenar os vértices
    Ponto *vertices = (Ponto *)malloc(numVertices * sizeof(Ponto));

    if (vertices == NULL) {
        printf("Erro de alocação de memória.\n");
        return 1;
    }

    // Lê os vértices do arquivo e imprime-os
    printf("\n\nOs pontos lidos do arquivo:\n");
    for (int i = 0; i < numVertices; i++) {
        fscanf(arquivo, "%f %f", &vertices[i].X, &vertices[i].Y);
        printf("(%0.2f, %0.2f)\n", vertices[i].X, vertices[i].Y);
    }

    // Fecha o arquivo
    fclose(arquivo);

    // Calcula a área do polígono
    float area = 0.0;

    for (int i = 0; i < numVertices; i++) {
        int j = (i + 1) % numVertices; // Próximo vértice
        area += (vertices[i].X * vertices[j].Y) - (vertices[j].X * vertices[i].Y);
    }

    area = 0.5 * fabs(area);

    // Exibe a área do polígono
    printf("\nA área do polígono é %.2f\n", area);

    // Libera a memória alocada
    free(vertices);

    return 0;
}



