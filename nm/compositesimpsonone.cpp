#include <stdio.h>
#include <math.h>

// Function to be integrated
float f(float x)
{
    // Example: f(x) = x^2
    return x * x;
}

int main()
{
    int n, i;
    float a, b, h, x, sum = 0, result;
    printf("=====Shaiju Maharjan=====\n");
    printf("===== Composite Simpson's 1/3 Rule =====\n");

    printf("Enter lower limit (a): ");
    scanf("%f", &a);

    printf("Enter upper limit (b): ");
    scanf("%f", &b);

    printf("Enter number of subintervals (n - even): ");
    scanf("%d", &n);

    if (n % 2 != 0)
    {
        printf("Error: n must be even.\n");
        return 0;
    }

    h = (b - a) / n;

    sum = f(a) + f(b);

    for (i = 1; i < n; i++)
    {
        x = a + i * h;

        if (i % 2 == 0)
            sum += 2 * f(x);   // even index
        else
            sum += 4 * f(x);   // odd index
    }

    result = (h / 3) * sum;

    printf("Step size (h) = %f\n", h);
    printf("Value of integration = %f\n", result);

    return 0;
}

