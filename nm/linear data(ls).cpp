#include <stdio.h>

int main() {
    int n, i;
    float x[100], y[100];
    float sum_x = 0, sum_y = 0, sum_x2 = 0, sum_xy = 0;
    float a, b;

	printf("=====Shaiju Maharjan=====\n");
	printf("=====Linear Regression=====\n");
    printf("Enter number of data points: ");
    scanf("%d", &n);

    printf("Enter values of x:\n");
    for(i = 0; i < n; i++) {
        scanf("%f", &x[i]);
        sum_x += x[i];
        sum_x2 += x[i] * x[i];
    }

    printf("Enter values of y:\n");
    for(i = 0; i < n; i++) {
        scanf("%f", &y[i]);
        sum_y += y[i];
        sum_xy += x[i] * y[i];
    }

    b = (n * sum_xy - sum_x * sum_y) / (n * sum_x2 - sum_x * sum_x);
    a = (sum_y - b * sum_x) / n;

    printf("\nLeast Squares Approximation Line:\n");
    printf("y = %.2f + %.2fx\n", a, b);

    return 0;
}

