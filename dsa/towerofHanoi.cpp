#include <iostream>
using namespace std;

int step = 1;

void towerOfHanoi(int n, char source, char auxiliary, char destination)
{
    if (n == 1)
    {
        cout << "Step " << step++ 
             << " : Move disk 1 from " 
             << source << " -> " << destination << endl;
        return;
    }

    towerOfHanoi(n - 1, source, destination, auxiliary);

    cout << "Step " << step++ 
         << " : Move disk " << n 
         << " from " << source << " -> " << destination << endl;
    towerOfHanoi(n - 1, auxiliary, source, destination);
}

int main()
{
    int n;

    cout << "===== Shaiju Maharjan =====\n";
    cout << "      TOWER OF HANOI       \n";
    cout << "==============================\n";
    cout << "Enter number of disks: ";
    cin >> n;

    if (n <= 0)
    {
        cout << "Number of disks must be positive.\n";
        return 0;
    }

    cout << "\n--- Steps to solve Tower of Hanoi ---\n\n";

    towerOfHanoi(n, 'A', 'B', 'C');

    cout << "\nTotal steps required = " << step - 1 << endl;

    return 0;
}

