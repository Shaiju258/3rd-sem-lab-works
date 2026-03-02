#include <stdio.h>

float f(float x, float y) {
    return x + y;
}

int main() {
    float x0 = 0.0, y0 = 1.0, h;
    int steps;
    printf("===== Shaiju Maharjan =====\n");
    printf("===== Euler Method =====\n");

    for(int k = 1; k <= 2; k++) {

        if(k == 1)
            h = 0.1;
        else
            h = 0.2;

        steps = (int)(0.4 / h);
        float x = x0;
        float y = y0;

        for(int i = 0; i < steps; i++) {
            y = y + h * f(x, y);
            x = x + h;
        }

        printf("For h = %.1f, y(0.4) = %.6f\n", h, y);
    }

    return 0;
}
