#include <stdio.h>
#include <math.h>

double g(double x) {
    return cos(x);
}

double f(double x) {
    return x - cos(x);
}

int main() {
    double x0, x1;
    int iteration = 0;
    printf("=====Shaiju Maharjan=====\n");
    printf("To find the root of f(x) = x - cos(x) using Fixed Point Iteration\n");
    printf("Enter initial guess: ");
    scanf("%lf", &x0);

    while (iteration < 20) {
        iteration++;

        x1 = g(x0);

        printf("Iteration %d: x = %.6f, f(x) = %.6f\n",
               iteration, x1, f(x1));

        if (fabs(x1 - x0) < 0.001) {
            break;
        }

        x0 = x1;
    }

    printf("\nEstimated root: %.6f", x1);
    printf("\nf(%.6f) = %.6f", x1, f(x1));
    printf("\nTotal number of iterations: %d\n", iteration);

    return 0;
}
