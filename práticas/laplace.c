#include <stdio.h>

double calcDet5(double mt[3][3]) {
    return ((mt[0][0] * mt[1][1] * mt[2][2])+(mt[0][1] * mt[1][2] * mt[2][0])+(mt[0][2] * mt[1][0] * mt[2][1])) - ((mt[2][0] * mt[1][1] * mt[0][2])+(mt[2][1] * mt[1][2] * mt[0][0])+(mt[2][2] * mt[1][0] * mt[0][1]));
}

double calcDet4(double m[4][4]) {
    double det = 0;
    double mt[3][3];

    for (int j = 0; j < 4; j++) {
        int mti = 0, mtj = 0;

        for (int i = 1; i < 4; i++) {
            mtj = 0;
            for (int k = 0; k < 4; k++) {
                if (k == j) continue;
                mt[mti][mtj] = m[i][k];
                mtj++;
            }
            mti++;
        }

        double cofator = ((j % 2 == 0) ? 1 : -1) * m[0][j] * calcDet5(mt);
        det += cofator;
    }

    return det;
}

int main(void) {

    printf("Digite os elementos da matriz 4x4 (linha por linha):\n");

    double m[4][4];
    
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            scanf("%lf", &m[i][j]);
        }

    }

    double det = calcDet4(m);

    if (det == 0) {
        printf("Não é possível realizar a regra de cramer, pois o valor do determinante eh 0.\n");
    } else printf("O determinante da matriz eh: %.2lf\n", det);


    return 0;
}