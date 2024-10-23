#include <bits/stdc++.h>
#include <iomanip>
#include <cmath>

using namespace std;

double fun(double x)
{
    return pow(x, 3) - x - 1;
}

void falsePosition(double a, double b)
{
    double c;
    int n = 0;
    cout << endl;
    cout << "n" << setw(20) << "a" << setw(20) << "f(a)" << setw(20) << "b" << setw(20) << "f(b)"
         << setw(20) << "c" << setw(20) << "f(c)" << setw(20) << "Update" << endl;

    while (true)
    {
        c = b - (fun(b) * (a - b)) / (fun(a) - fun(b));
        cout << n++ << setw(20) << a << setw(20) << fun(a) << setw(20) << b
             << setw(20) << fun(b) << setw(20) << c << setw(20) << fun(c);

        // Determine which point was updated
        string update = (fun(a) * fun(c) < 0) ? "a" : "b";

        if (abs(fun(c)) < 0.00005)
        {
            cout << "                " << update << endl; // Display final update
            cout << endl;
            cout << "Root is approximately: " << c << endl;
            break;
        }

        // Update the interval
        if (fun(a) * fun(c) < 0)
        {
            b = c;
        }
        else
        {
            a = c;
        }

        cout << "                " << update << endl; // Print update for this iteration
    }
}

int main()
{
    double a, b;
    cout << "Enter First Point (a): ";
    cin >> a;
    cout << "Enter Second Point (b): ";
    cin >> b;

    if (a < b && fun(a) * fun(b) < 0)
    {
        falsePosition(a, b);
    }
    else
    {
        cout << "Invalid Input: Ensure a < b and f(a) * f(b) < 0." << endl;
    }

    return 0;
}
