#include <bits/stdc++.h>
using namespace std;
double fun(double x)
{
    return pow(x, 3) - x - 1;
}
void bisection(double a, double b)
{
    double c;
    int n = 0;
    cout << endl;
    cout << "n" << setw(20) << "f(a)" << setw(20) << "b" << setw(20) << "f(b)" << setw(20) << "c" << setw(20) << "f(c)" << setw(20) << "Update" << endl;
    while (true)
    {
        cout << ++n << setw(20) << a << setw(20) << fun(a) << setw(20) << b << setw(20) << fun(b) << setw(20);
        c = (a + b) / 2;
        cout << c << setw(20) << fun(c) << endl;
        if (fun(c) == 0)
        {
            cout << "Exact root found at c = " << c << endl;
            break;
        }
        else if (fun(a) * fun(c) < 0)
        {
            b = c;
        }
        else if (fun(c) * fun(b) < 0)
        {
            a = c;
        }
        if (abs(fun(c)) <= 0.00005)
        {
            cout << endl;
            cout << "Root is approximately: " << c << endl;
            break;
        }
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
        bisection(a, b);
    }
    else
    {
        cout << "Invalid Input: Ensure a < b and f(a) * f(b) < 0." << endl;
    }
    return 0;
}