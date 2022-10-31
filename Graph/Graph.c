#include "includes.h"
#include "math.h"

int main()
{
    const int ox = 150;
    const int oy = 100;

    double* y = (double*)malloc(ox * sizeof(double));
    double i = 0.5;

    while(i < 75.0) {
        int index = i / 0.5;
        y[index] = ln(1 / i) * sin(exp(i / 20.0));
        i = i + 0.5;
    }

    int** screen = (int**)malloc(oy * sizeof(int*));
    for (int i = 0; i < oy; i++)
        screen[i] = (int*)calloc(ox, sizeof(int));

    //Заполняем матрицу
    for (int i = 1; i < ox; i++) {
        double pointY = y[i];
        if ((pointY > 5) || (pointY < -5))
            continue;
        int index = (oy/2) - (pointY / 0.1);
        screen[index][i] = 1;
    }

    for (int i = 0; i < oy; i++) {
        if (i == oy / 2){
            for (int j = 0; j < ox; j++)
                printf("-");
            printf("\n");
        }
        for (int j = 0; j < ox; j++)
            if (screen[i][j] == 1)
                printf("*");
            else if (j == 0)
                printf("|");
            else
                printf(" ");
        printf("\n");
    }
}