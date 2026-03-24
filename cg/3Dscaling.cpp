#include <graphics.h>
#include <iostream>
using namespace std;

struct Point3D {
    float x, y, z;
};

// Scaling function
void scale(Point3D &p, float sx, float sy, float sz) {
    p.x *= sx;
    p.y *= sy;
    p.z *= sz;
}

// Draw cube with simple 3D projection
void drawCube(Point3D p[], int color) {

    setcolor(color);

    int edges[12][2] = {
        {0,1},{1,2},{2,3},{3,0},
        {4,5},{5,6},{6,7},{7,4},
        {0,4},{1,5},{2,6},{3,7}
    };

    for(int i=0; i<12; i++) {

        int x1 = p[edges[i][0]].x + p[edges[i][0]].z/2 + 300;
        int y1 = p[edges[i][0]].y + p[edges[i][0]].z/2 + 200;

        int x2 = p[edges[i][1]].x + p[edges[i][1]].z/2 + 300;
        int y2 = p[edges[i][1]].y + p[edges[i][1]].z/2 + 200;

        line(x1, y1, x2, y2);
    }
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, (char*)"");

    Point3D cube[8], cube2[8];

    cout << "===== Shaiju Maharjan =====\n";
    cout << "=== 3D Scaling ===\n";

    // User input
    cout << "Enter 8 points of cube (x y z):\n";
    for(int i=0; i<8; i++) {
        cout << "Point " << i+1 << ": ";
        cin >> cube[i].x >> cube[i].y >> cube[i].z;
        cube2[i] = cube[i];
    }

    float sx, sy, sz;
    cout << "Enter scaling factors (sx sy sz): ";
    cin >> sx >> sy >> sz;

    // Draw original cube
    drawCube(cube, WHITE);

    // Apply scaling
    for(int i=0; i<8; i++)
        scale(cube2[i], sx, sy, sz);

    // Draw scaled cube
    drawCube(cube2, GREEN);

    // Display text
    setcolor(WHITE);
    outtextxy(10, 10, (char*)"3D Scaling");
    outtextxy(10, 30, (char*)"Name: Shaiju Maharjan");
    outtextxy(10, 50, (char*)"WHITE: Original Cube");
    outtextxy(10, 70, (char*)"GREEN: Scaled Cube");

    getch();
    closegraph();
    return 0;
}
