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
    float a, b, h, sum = 0, x, result;
    printf("=====Shaiju Maharjan=====\n");
    printf("===== Composite Trapezoidal Rule =====\n");

    printf("Enter lower limit (a): ");
    scanf("%f", &a);

    printf("Enter upper limit (b): ");
    scanf("%f", &b);

    printf("Enter number of subintervals (n): ");
    scanf("%d", &n);

    h = (b - a) / n;

    // First term
    sum = f(a) + f(b);

    // Middle terms
    for (i = 1; i < n; i++)
    {
        x = a + i * h;
        sum = sum + 2 * f(x);
    }

    // Final result
    result = (h / 2) * sum;

    printf("Step size (h) = %f\n", h);
    printf("Value of integration = %f\n", result);

    return 0;
}

