#include <stdio.h>

double calcDet2(double m[2][2]) {
    return (m[0][0] * m[1][1]) - (m[0][1] * m[1][0]);
}

double calcDet3(double m[3][3]) {
    return ((m[0][0] * m[1][1] * m[2][2])+(m[0][1] * m[1][2] * m[2][0])+(m[0][2] * m[1][0] * m[2][1])) - ((m[2][0] * m[1][1] * m[0][2])+(m[2][1] * m[1][2] * m[0][0])+(m[2][2] * m[1][0] * m[0][1]));
}


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

    printf("Digite qual o valor de n, que eh o numero de linhas e colunas da matriz quadrada:\n");

    int n = 0;
    scanf("%d", &n);



    if (n == 0) {
        printf("Essa matriz eh uma matriz nula e seu determinante é igual 0.\n");
    } else 



    if (n == 1) { 
        printf("O determinante dessa matriz eh o próprio elemento.");

    } else



    if (n == 2) { 
        printf("Digite os elementos da matriz 2x2 (elementos linha por linha):\n");

        double m[2][2];

        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 2; j++) {
                scanf("%lf", &m[i][j]);
            }
        }

        double det = calcDet2(m);

        if (det == 0) { 
            printf("Nao eh possivel realizar a regra de cramer, pois o valor do determinante eh 0.\n");

        } else printf("O determinante da matriz eh: %.2lf\n", det);

        //fazer a regra de cramer

    } 

    
    
    
    else if (n == 3) {
        printf("Digite os elementos da matriz 3x3 (linha por linha):\n");

        double m[3][3];
        
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                scanf("%lf", &m[i][j]);
            }
        }  
        
        double det = calcDet3(m);

        if (det == 0) {
            printf("Nao eh possivel realizar a regra de cramer, pois o valor do determinante eh 0.\n");
        } else printf("O determinante da matriz eh: %.2lf\n", det);

        //fazer a regra de cramer
    
    }
    




    else if (n == 4) {
        printf("Digite os elementos da matriz 4x4 (linha por linha):\n");

        double m[4][4];
        
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                scanf("%lf", &m[i][j]);
            }

        }

        double det = calcDet4(m);

        if (det == 0) {
            printf("Nao eh possivel realizar a regra de cramer, pois o valor do determinante eh 0.\n");
        } else printf("O determinante da matriz eh: %.2lf\n", det);

        // fazer a regra de cramer

    } else printf("A calculadora de Determinantes nao suporta esse tamanho de Matriz\n");


return 0;
}