#include <stdio.h>

float f(float x, float y)
{
    return x + y;
}

int main()
{
    float x0 = 0, y0 = 1;
    float h, xn = 0.4;
    int steps, i;

    printf("===== Shaiju Maharjan =====\n");
    printf("=== Runge-Kutta 4th Order Method ===\n");
    printf("Enter step size (h): ");
    scanf("%f", &h);

    steps = (xn - x0) / h;

    printf("\nSteps:\n");
    for(i = 1; i <= steps; i++)
    {
        float k1 = h * f(x0, y0);
        float k2 = h * f(x0 + h/2, y0 + k1/2);
        float k3 = h * f(x0 + h/2, y0 + k2/2);
        float k4 = h * f(x0 + h, y0 + k3);

        y0 = y0 + (k1 + 2*k2 + 2*k3 + k4) / 6;
        x0 = x0 + h;

        printf("x = %.2f, y = %.6f\n", x0, y0);
    }

    printf("\nApproximate value at x = 0.4 is y = %.6f\n", y0);

    return 0;
}
