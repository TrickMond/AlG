#include <bits/stdc++.h>

using namespace std;


int part(unsigned int a[], int l, int r)
{
    unsigned int buffer [70001];
    int mid = (l + r) / 2;
    swap(a[mid], a[r]);
    if (l < mid)
        part(a,l,mid - 1);
    if (r > mid)
        part(a,mid + 1, r);
}


int main()
{
//    freopen("sort.in", "r", stdin);
//    freopen("sort.out", "w", stdout);
    int number;
    int j;
    cin >> number;
    unsigned int a [number];
    unsigned int buffer [number];
    for (int i = 1; i < number + 1 ; i++)
    {
        a[i-1] = i;
        if (i%2 == 0)
            buffer[i-1] = i;
    }
    for (int i = 0; i < number / 2; i++)
    {
        cout << buffer [i] << " ";
    }
}
