#include <stdio.h>
#include <math.h>

int n;
float x[50], y[50];

/* Function obtained from normal equation */
float f(float b)
{
    float num = 0, den = 0;
    float sum1 = 0, sum2 = 0;
    float a;
    int i;

    /* Compute a for given b */
    for(i = 0; i < n; i++) {
        num += y[i] * exp(b * x[i]);
        den += exp(2 * b * x[i]);
    }
    a = num / den;

    /* Function f(b) */
    for(i = 0; i < n; i++) {
        sum1 += x[i] * y[i] * exp(b * x[i]);
        sum2 += x[i] * exp(2 * b * x[i]);
    }

    return (sum1 - a * sum2);
}

int main()
{
    int i;
    float b1, b2, bm;
    float err = 0.0001;
    float step = 0.1;
    float num = 0, den = 0, a;

    printf("===== Shaiju Maharjan =====\n");
    printf("===== Non-Linear Regression =====\n\n");

    /* Input data */
    printf("Enter number of data points: ");
    scanf("%d", &n);

    printf("Enter values of x:\n");
    for(i = 0; i < n; i++)
        scanf("%f", &x[i]);

    printf("Enter values of y:\n");
    for(i = 0; i < n; i++)
        scanf("%f", &y[i]);

    /* Finding initial guesses automatically */
    b1 = -10;
    b2 = b1 + step;

    while (b2 <= 10) {
        if (f(b1) * f(b2) < 0)
            break;
        b1 = b2;
        b2 = b1 + step;
    }

    if (b2 > 10) {
        printf("Unable to find suitable initial guesses.\n");
        return 0;
    }

    printf("\nInitial guesses found:\n");
    printf("b1 = %.2f, b2 = %.2f\n", b1, b2);

    /* Bisection Method */
    do {
        bm = (b1 + b2) / 2;

        if (f(b1) * f(bm) < 0)
            b2 = bm;
        else
            b1 = bm;

    } while (fabs(b2 - b1) > err);

    /* Final values of a and b */
    for(i = 0; i < n; i++) {
        num += y[i] * exp(bm * x[i]);
        den += exp(2 * bm * x[i]);
    }
    a = num / den;

    /* Output */
    printf("\nFinal Results:\n");
    printf("Value of b = %.6f\n", bm);
    printf("Value of a = %.6f\n", a);
    printf("Regression equation:\n");
    printf("y = %.6f e^(%.6f x)\n", a, bm);

    return 0;
}

