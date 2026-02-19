#include <stdio.h>
#include <math.h>

// Function to be integrated
float f(float x)
{
    // Example function: f(x) = x^2
    return x * x;
}

int main()
{
    int n, i;
    float a, b, h, x, sum = 0.0, result;
    printf("=====Shaiju Maharjan=====\n");
    printf("===== Composite Simpson's 3/8 Rule =====\n");

    printf("Enter lower limit (a): ");
    scanf("%f", &a);

    printf("Enter upper limit (b): ");
    scanf("%f", &b);

    printf("Enter number of subintervals (n - multiple of 3): ");
    scanf("%d", &n);

    if (n % 3 != 0)
    {
        printf("Error: n must be a multiple of 3.\n");
        return 0;
    }

    h = (b - a) / n;

    // First and last terms
    sum = f(a) + f(b);

    for (i = 1; i < n; i++)
    {
        x = a + i * h;

        if (i % 3 == 0)
            sum += 2 * f(x);   // multiples of 3
        else
            sum += 3 * f(x);   // others
    }

    result = (3 * h / 8) * sum;

    printf("Step size (h) = %f\n", h);
    printf("Value of integration = %f\n", result);

    return 0;
}

