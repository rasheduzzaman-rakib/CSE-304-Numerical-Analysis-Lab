#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    double a[n][n + 1], x[n];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n + 1; j++)
        {
            cin >> a[i][j];
        }
    }
    for (int i = 0; i < n - 1; i++)
    {
        if (a[i][i] == 0.0)
        {
            cout << "Mathematical Error!" << endl;
            return 0;
        }

        for (int j = i + 1; j < n; j++)
        {
            double xx = a[j][i] / a[i][i];

            for (int k = i; k < n + 1; k++)
            {
                a[j][k] -= xx * a[i][k];
            }
        }
    }
    x[n - 1] = a[n - 1][n] / a[n - 1][n - 1];

    for (int i = n - 2; i >= 0; i--)
    {
        x[i] = a[i][n];
        for (int j = i + 1; j < n; j++)
        {
            x[i] -= a[i][j] * x[j];
        }
        x[i] /= a[i][i];
    }
    cout << "\nSolution: " << endl;
    for (int i = 0; i < n; i++)
    {
        cout << setprecision(3) << fixed;
        cout << "x[" << i + 1 << "] = " << x[i] << endl;
    }

    return 0;
}

// 3
// 1 2 1 8
// 2 4 2 16
// 1 1 1 6

// 4
// 6 -2 2 4 16
// 12 -8 6 10 26
// 3 -13 9 3 -19
// -6 4 1 -18 -34