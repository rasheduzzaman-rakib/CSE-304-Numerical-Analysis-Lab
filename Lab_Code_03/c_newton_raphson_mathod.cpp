#include <bits/stdc++.h>
#include <iomanip>
#include <cmath>

using namespace std;

double fun(double x)
{

    return pow(x, 3) - x - 1;
}
double dfun(double x)
{
    return 3 * pow(x, 2) - 1;
}
void newton(double a, double b)
{
    double x0, x1;
    int n = 0;
    x0 = a + b / 2;

    cout << endl;
    cout << "n" << setw(20) << "a" << setw(20) << "f(a)" << setw(20) << "b" << setw(20) << "f(b)" << setw(20) << "c" << setw(20) << "f(c)" << setw(20) << "Update" << endl;

    while (true)
    {
        fun(x0);
        x1 = x0 - (fun(x0) / dfun(x0));
        cout << n++ << setw(20) << a << setw(20) << fun(a) << setw(20) << b << setw(20) << fun(b) << setw(20) << x0 << setw(20) << fun(x0);
        if (abs(fun(x1)) <= 0.00005)
        {
            cout << endl;
            cout << "Root is approximately: " << x1 << endl;
            break;
        }
        x0 = x1;
    }
}

int main()
{
    double a, b;
    cout << "Enter First Point: ";
    cin >> a;
    cout << "Enter Second Point: ";
    cin >> b;

    if (a < b && fun(a) * fun(b) < 0)
    {
        newton(a, b);
    }
    else
    {
        cout << "Invalid Input: Ensure a < b and f(a) * f(b) < 0." << endl;
    }

    return 0;
}
