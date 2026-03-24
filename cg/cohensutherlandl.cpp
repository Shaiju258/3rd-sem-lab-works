#include <iostream>
#include <winbgim.h>
using namespace std;

// Region codes
const int INSIDE = 0;
const int LEFT   = 1;
const int RIGHT  = 2;
const int BOTTOM = 4;
const int TOP    = 8;

int computeOutCode(double x, double y,
                   double xmin, double ymin,
                   double xmax, double ymax)
{
    int code = INSIDE;

    if (x < xmin) code |= LEFT;
    else if (x > xmax) code |= RIGHT;

    if (y < ymin) code |= BOTTOM;
    else if (y > ymax) code |= TOP;

    return code;
}

bool cohenSutherland(double &x1, double &y1,
                     double &x2, double &y2,
                     double xmin, double ymin,
                     double xmax, double ymax)
{
    int outcode1 = computeOutCode(x1, y1, xmin, ymin, xmax, ymax);
    int outcode2 = computeOutCode(x2, y2, xmin, ymin, xmax, ymax);

    while (true)
    {
        if ((outcode1 | outcode2) == 0)
            return true;            // Accept
        else if (outcode1 & outcode2)
            return false;           // Reject
        else
        {
            double x, y;
            int outcodeOut = outcode1 ? outcode1 : outcode2;

            if (outcodeOut & TOP)
            {
                x = x1 + (x2 - x1) * (ymax - y1) / (y2 - y1);
                y = ymax;
            }
            else if (outcodeOut & BOTTOM)
            {
                x = x1 + (x2 - x1) * (ymin - y1) / (y2 - y1);
                y = ymin;
            }
            else if (outcodeOut & RIGHT)
            {
                y = y1 + (y2 - y1) * (xmax - x1) / (x2 - x1);
                x = xmax;
            }
            else // LEFT
            {
                y = y1 + (y2 - y1) * (xmin - x1) / (x2 - x1);
                x = xmin;
            }

            if (outcodeOut == outcode1)
            {
                x1 = x; y1 = y;
                outcode1 = computeOutCode(x1, y1, xmin, ymin, xmax, ymax);
            }
            else
            {
                x2 = x; y2 = y;
                outcode2 = computeOutCode(x2, y2, xmin, ymin, xmax, ymax);
            }
        }
    }
}

int main()
{
    double x1, y1, x2, y2;
    double xmin, ymin, xmax, ymax;

	cout << "=====Shaiju Maharjan=====\n";
	cout << "===Cohen Sutherland (Line Clipping) ===\n\n";
    cout << "Enter line endpoints (x1 y1 x2 y2): ";
    cin >> x1 >> y1 >> x2 >> y2;

    cout << "Enter clipping window (xmin ymin xmax ymax): ";
    cin >> xmin >> ymin >> xmax >> ymax;

    initwindow(800, 600, "Cohen–Sutherland Line Clipping");

    // Draw clipping window
    setcolor(WHITE);
    rectangle(xmin, ymin, xmax, ymax);

    // Draw original line (RED)
    setcolor(RED);
    line(x1, y1, x2, y2);

    if (cohenSutherland(x1, y1, x2, y2, xmin, ymin, xmax, ymax))
    {
        // Draw clipped line (GREEN)
        setcolor(GREEN);
        line(x1, y1, x2, y2);
    }

    getch();
    closegraph();
    return 0;
}

