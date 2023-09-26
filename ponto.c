// A - (-8, 2)
// B - (-10, -4)
// C - (-6, -8)
// D - (2, -8)
// E - (0, -2)
// F - (-6, -4)
// G - (-2, 8)

// ponto.c
#include "ponto.h"
#include <math.h>

// Função para calcular a distância entre 2 ponttos específicos
float distancia(Ponto p1, Ponto p2) {
    float dx = p2.X - p1.X;
    float dy = p2.Y - p1.Y;
    return sqrt(dx * dx + dy * dy);
}