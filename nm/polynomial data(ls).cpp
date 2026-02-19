#include <stdio.h>
#include <math.h>
#define MAX 50

int main() {
    int n, m, i, j, k;
    double x[MAX], y[MAX], X[2*MAX+1], B[MAX+1], a[MAX+1], sum;
	
	printf("=====Shaiju Maharjan=====\n");
	printf("=====Polynomial Data=====\n");
    printf("Enter number of data points: ");
    scanf("%d", &n);

    printf("Enter values of x:\n");
    for(i = 0; i < n; i++)
        scanf("%lf", &x[i]);

    printf("Enter values of y:\n");
    for(i = 0; i < n; i++)
        scanf("%lf", &y[i]);

    printf("Enter degree of polynomial (m): ");
    scanf("%d", &m);

    for(i = 0; i <= 2*m; i++) {
        X[i] = 0;
        for(j = 0; j < n; j++)
            X[i] += pow(x[j], i);
    }

    for(i = 0; i <= m; i++) {
        B[i] = 0;
        for(j = 0; j < n; j++)
            B[i] += y[j] * pow(x[j], i);
    }

    double A[m+1][m+2];
    for(i = 0; i <= m; i++)
        for(j = 0; j <= m; j++)
            A[i][j] = X[i+j];

    for(i = 0; i <= m; i++)
        A[i][m+1] = B[i];

    for(i = 0; i <= m; i++) {
        for(k = i+1; k <= m; k++) {
            double t = A[k][i]/A[i][i];
            for(j = 0; j <= m+1; j++)
                A[k][j] -= t * A[i][j];
        }
    }

    for(i = m; i >= 0; i--) {
        a[i] = A[i][m+1];
        for(j = i+1; j <= m; j++)
            a[i] -= A[i][j] * a[j];
        a[i] /= A[i][i];
    }

    printf("\nLeast Squares Polynomial Coefficients:\n");
    for(i = 0; i <= m; i++)
        printf("a[%d] = %.6lf\n", i, a[i]);

    printf("\nLeast Squares Polynomial:\ny = ");
    for(i = 0; i <= m; i++) {
        if(i > 0)
            printf(" + ");
        printf("%.6lf*x^%d", a[i], i);
    }
    printf("\n");

    return 0;
}

