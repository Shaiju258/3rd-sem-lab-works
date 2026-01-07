#include <stdio.h>
#define max 10

int main() {
    int n, i, j;
    float x[max], y[max][max];
    float xp, sum, term;
    
    printf("=====Shaiju Maharjan=====\n");
    printf("-----Central Divide Difference-----\n");
    printf("Enter the number of data points: ");
    scanf("%d", &n);

    printf("Enter the values of x: ");
    for (i = 0; i < n; i++) {
        scanf("%f", &x[i]);
    }

    printf("Enter the values of y:");
    for (i = 0; i < n; i++) {
        scanf("%f", &y[i][0]);
    }

    for (j = 1; j < n; j++) {
        for (i = 0; i < n - j; i++) {
            y[i][j] = (y[i + 1][j - 1] - y[i][j - 1]) / (x[i + j] - x[i]);
        }
    }

    printf("Enter the value of x to find f(x): ");
    scanf("%f", &xp);

    sum = y[0][0];
    term = 1;

    for (i = 1; i < n; i++) {
        term = term * (xp - x[i - 1]);
        sum = sum + term * y[0][i];
    }

    printf("The approximate value at x = %.3f is f(x) = %.3f\n", xp, sum);

    return 0;
}

