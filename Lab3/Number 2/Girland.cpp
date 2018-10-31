#include <bits/stdc++.h>

using namespace std;


bool garland(double h[], int n)
{
    for (int i = 2; i < n; i++)
    {
        h[i] = (h[i - 1] + 1) * 2 - h[i-2];
        if (h[i] <= 0)
        return false;
    }
    return true;
}


int main()
{
    freopen ("garland.in","r",stdin);
    freopen ("garland.out","w",stdout);
    int n;
    cin >> n;
    double h[n];
    cin >> h[0];

    double max, min;
    max = h[0];
    min = 0;

    while (true)
    {
        h[1] = (min + max)/2;
        if (h[1] == min || h[1] == max)
        break;
        if (garland(h,n))
        max = h[1];
        else
        min = h[1];
    }

    cout << fixed << setprecision(2) << h[n-1];
}
