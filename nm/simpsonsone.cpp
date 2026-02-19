#include <stdio.h>
#include <math.h>

float f(float x)
{
    return x * x;
}

int main()
{
    float a, b, h, m, result;
	printf("=====Shaiju Maharjan=====\n");
    printf("===== Simpson's 1/3 Rule =====\n");

    printf("Enter lower limit (a): ");
    scanf("%f", &a);

    printf("Enter upper limit (b): ");
    scanf("%f", &b);

    h = (b - a) / 2;
    m = (a + b) / 2;

    result = (h / 3) * (f(a) + 4 * f(m) + f(b));

    printf("Step size (h) = %f\n", h);
    printf("Value of integration = %f\n", result);

    return 0;
}

