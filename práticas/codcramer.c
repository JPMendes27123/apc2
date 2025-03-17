#include <stdio.h>

//Declaracao das funcoes

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

//Inicio codigo

int main(void) {

    printf("Digite qual o valor de n, que eh o numero de linhas e colunas da matriz quadrada:\n");

    int n = 0;
    scanf("%d", &n);

    //MATRIZ 0X0

    if (n == 0) {
        printf("Essa matriz eh uma matriz nula e seu determinante eh igual 0.\n");
    } else 

    //MATRIZ 1X1

    if (n == 1) { 
        printf("O determinante dessa matriz eh o proprio elemento.");

    } else

    //MATRIZ 2X2

    if (n == 2) { 
        printf("Digite os elementos da matriz 2x2 (elementos linha por linha):\n");

        double m[2][2];

        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 2; j++) {
                scanf("%lf", &m[i][j]);
            }
        }

        printf("Digite os termos independentes do sistema linear:\n");

        double mtermosidp[2];

        for (int i = 0; i < 2; i++) {
        scanf("%lf", &mtermosidp[i]);
        }

        double det = calcDet2(m);

        if (det == 0) { 
            printf("Nao eh possivel realizar a regra de cramer, pois o valor do determinante eh 0 e existem infinitas solucoes.\n");
            return 0;
        } else printf("O determinante da matriz eh: %.2lf\n", det);

        double mtemp1[2][2];
        double mtemp2[2][2];
    
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                mtemp1[i][j] = m[i][j];
                mtemp2[i][j] = m[i][j];
            }

            mtemp1[i][0] = mtermosidp[i];
            mtemp2[i][1] = mtermosidp[i];

        }

        double detx = calcDet2(mtemp1);
        double dety = calcDet2(mtemp2);

        double x = detx/det;
        double y = dety/det;

        printf("Os Valores de X e Y sao: %.2lf, %.2lf.\n", x, y);

    } 

    //MATRIZ 3X3
    
    
    else if (n == 3) {
        printf("Digite os elementos da matriz 3x3 dos indices das variaveis (linha por linha):\n");

        double m[3][3];
        
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                scanf("%lf", &m[i][j]);
            }
        }  

        printf("Digite os termos independentes do sistema linear:\n");

        double mtermosidp[3];

        for (int i = 0; i < 3; i++) {
        scanf("%lf", &mtermosidp[i]);
        }
        
        double det = calcDet3(m);

        if (det == 0) {
            printf("Nao eh possivel realizar a regra de cramer, pois o valor do determinante eh 0.\n");
            return 0;
        } else printf("O determinante da matriz eh: %.2lf\n", det);

        double mtemp1[3][3];
        double mtemp2[3][3];
        double mtemp3[3][3];
    
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                mtemp1[i][j] = m[i][j];
                mtemp2[i][j] = m[i][j];
                mtemp3[i][j] = m[i][j];
            }

            mtemp1[i][0] = mtermosidp[i];
            mtemp2[i][1] = mtermosidp[i];
            mtemp3[i][2] = mtermosidp[i];
        }

        double detx = calcDet3(mtemp1);
        double dety = calcDet3(mtemp2);
        double detz = calcDet3(mtemp3);

        double x = detx/det;
        double y = dety/det;
        double z = detz/det;

        printf("Os Valores de X, Y e Z sao: %.2lf, %.2lf, %.2lf.\n", x, y, z);
    }
    
    //MATRIZ 4X4

    else if (n == 4) {
        printf("Digite os elementos da matriz 4x4 (linha por linha):\n");

        double m[4][4];
        
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                scanf("%lf", &m[i][j]);
            }

        }

        printf("Digite os termos independentes do sistema linear:\n");

        double mtermosidp[4];

        for (int i = 0; i < 4; i++) {
        scanf("%lf", &mtermosidp[i]);
        }

        double det = calcDet4(m);

        if (det == 0) {
            printf("Nao eh possivel realizar a regra de cramer, pois o valor do determinante eh 0.\n");
            return 0;
        } else printf("O determinante da matriz eh: %.2lf\n", det);

        double mtemp1[4][4];
        double mtemp2[4][4];
        double mtemp3[4][4];
        double mtemp4[4][4];
    
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                mtemp1[i][j] = m[i][j];
                mtemp2[i][j] = m[i][j];
                mtemp3[i][j] = m[i][j];
                mtemp4[i][j] = m[i][j];
            }

            mtemp1[i][0] = mtermosidp[i];
            mtemp2[i][1] = mtermosidp[i];
            mtemp3[i][2] = mtermosidp[i];
            mtemp4[i][3] = mtermosidp[i];
        }
        
        double detx = calcDet4(mtemp1);
        double dety = calcDet4(mtemp2);
        double detz = calcDet4(mtemp3);
        double deth = calcDet4(mtemp4);
        
        double x = detx/det;
        double y = dety/det;
        double z = detz/det;
        double h = deth/det;

        printf("Os Valores de X, Y, Z e H sao: %.2lf, %.2lf, %.2lf, %.2lf.\n", x, y, z, h);

    } else printf("A calculadora de Determinantes nao suporta esse tamanho de Matriz\n");


return 0;
}