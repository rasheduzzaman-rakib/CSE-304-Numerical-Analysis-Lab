#include <bits/stdc++.h>
using namespace std;
int main()
{
    double ans = 0;
    int n;
    cout << "Enter value of Column without x and y: ";
    cin >> n;
    double x[n];
    double y[n];
    cout << "Enter value of x and y: ";
    for (int i = 1; i <= n; i++)
    {
        cin >> x[i] >> y[i];
    }
    cout << "Enter Finding value: ";
    double xx;
    cin >> xx;
    for (int i = 1; i <= n; i++)
    {
        double k = 1;
        for (int j = 1; j <= n; j++)
        {
            if (i != j)
            {
                k = k * (xx - x[j]) / (x[i] - x[j]);
            }
        }
        ans = ans + (k * y[i]);
    }
    cout << endl
         << "Interpolated value " << xx << " is " << ans;
}