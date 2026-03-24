#include <graphics.h>
#include <iostream>
#include <conio.h>

using namespace std;

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    // Original triangle points
    int x1 = 100, y1 = 100;
    int x2 = 150, y2 = 50;
    int x3 = 200, y3 = 100;

    // Translation values P(x, y)
    int tx = 50;
    int ty = 30;

    // Print original points
    cout << "=====Shaiju Maharjan=====\n";
    cout << "===Translate===\n";
    cout << "Original Triangle Points:\n";
    cout << "A(" << x1 << ", " << y1 << ")\n";
    cout << "B(" << x2 << ", " << y2 << ")\n";
    cout << "C(" << x3 << ", " << y3 << ")\n\n";

    // Translated points
    int x1t = x1 + tx;
    int y1t = y1 + ty;

    int x2t = x2 + tx;
    int y2t = y2 + ty;

    int x3t = x3 + tx;
    int y3t = y3 + ty;

    // Print translated points
    cout << "Translation Point P(" << tx << ", " << ty << ")\n\n";
    cout << "Translated Triangle Points:\n";
    cout << "A'(" << x1t << ", " << y1t << ")\n";
    cout << "B'(" << x2t << ", " << y2t << ")\n";
    cout << "C'(" << x3t << ", " << y3t << ")\n";

    // Draw original triangle
    setcolor(WHITE);
    line(x1, y1, x2, y2);
    line(x2, y2, x3, y3);
    line(x3, y3, x1, y1);

    // Draw translated triangle
    setcolor(RED);
    line(x1t, y1t, x2t, y2t);
    line(x2t, y2t, x3t, y3t);
    line(x3t, y3t, x1t, y1t);

    getch();
    closegraph();
    return 0;
}

