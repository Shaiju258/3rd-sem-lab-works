#include <stdio.h>

float f(float x, float y) {
    return x + y;
}

int main() {
    float x0 = 0.0, y0 = 1.0, h;
    int steps;
    printf("===== Shaiju Maharjan =====\n");
    printf("===== Heun's Method =====\n");

    for(int k = 1; k <= 2; k++) {

        if(k == 1)
            h = 0.1;
        else
            h = 0.2;

        steps = (int)(0.4 / h);
        float x = x0;
        float y = y0;

        for(int i = 0; i < steps; i++) {

            float k1 = f(x, y);
            float k2 = f(x + h, y + h * k1);

            y = y + (h/2) * (k1 + k2);
            x = x + h;
        }

        printf("For h = %.1f, y(0.4) = %.6f\n", h, y);
    }

    return 0;
}
