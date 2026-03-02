#include <stdio.h>

float f(float x, float y) {
    return x + y;
}

int main() {
    float x0 = 0.0, y0 = 1.0, h;
    int steps;
    printf("===== Shaiju Maharjan =====\n");
    printf("===== RK 4th Order Method =====\n");

    for(int k = 1; k <= 2; k++) {

        if(k == 1)
            h = 0.1;
        else
            h = 0.2;

        steps = (int)(0.4 / h);
        float x = x0;
        float y = y0;

        for(int i = 0; i < steps; i++) {

            float k1 = h * f(x, y);
            float k2 = h * f(x + h/2, y + k1/2);
            float k3 = h * f(x + h/2, y + k2/2);
            float k4 = h * f(x + h, y + k3);

            y = y + (k1 + 2*k2 + 2*k3 + k4)/6;
            x = x + h;
        }

        printf("For h = %.1f, y(0.4) = %.6f\n", h, y);
    }

    return 0;
}
