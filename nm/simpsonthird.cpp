#include <stdio.h>
#include <math.h>

float f(float x)
{
    return x * x;
}

int main()
{
    float a, b, h, x0, x1, x2, x3, result;
    
	printf("=====Shaiju Maharjan=====\n");
    printf("===== Simple Simpson's 3/8 Rule =====\n");

    printf("Enter lower limit (a): ");
    scanf("%f", &a);

    printf("Enter upper limit (b): ");
    scanf("%f", &b);

    h = (b - a) / 3;

    x0 = a;
    x1 = a + h;
    x2 = a + 2*h;
    x3 = b;

    result = (3*h/8) * (f(x0) + 3*f(x1) + 3*f(x2) + f(x3));

    printf("Step size (h) = %f\n", h);
    printf("Value of integration = %f\n", result);

    return 0;
}

