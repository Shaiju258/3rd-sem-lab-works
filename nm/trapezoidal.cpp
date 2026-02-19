#include <stdio.h>
#include <math.h>

float f(float x)
{
    return x * x;
}

int main()
{
    float a, b, h, result;
	printf("=====Shaiju Maharjan=====\n");
	printf("===== Trapezoidal Rule =====\n");

    printf("Enter lower limit (a): ");
    scanf("%f", &a);

    printf("Enter upper limit (b): ");
    scanf("%f", &b);

    h = b - a;

    result = (h / 2) * (f(a) + f(b));

    printf("Step size (h) = %f\n", h);
    printf("Value of integration = %f\n", result);

    return 0;
}

