#include <bits/stdc++.h>

using namespace std;

int main()
{
//    freopen("sort.in", "r", stdin);
//    freopen("sort.out", "w", stdout);
    int number;
    cin >> number;
    unsigned int a [number];
    for (int i = 1; i < number + 1 ; i++)
    {
        a [i-1] = i;
    }

    for (int i = 0; i < number; i++)
    {
        swap(a[i], a[i / 2]);
    }
    for (int i = 0; i < number; i++)
    {
        cout << a [i] << " ";
    }
}
