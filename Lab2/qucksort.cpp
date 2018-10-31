#include <bits/stdc++.h>

using namespace std;

int partition(long long a[], int l, int r)
{
    int random = l + rand() % (r - l);
    swap(a[random], a[l]);
    long long v = a [ l ];
    int i = l;
    int j = r;
    while (i <= r)
    {
        while (a[i] < v)
        i++;
        while (a[j] > v)
        j--;
        if (i >= j)
            break;
        swap (a [i++], a[j--]);
    }
    return j;
}
void qucksort (long long a[], int l, int r)
{
    if (l < r)
        {
            int q = partition (a,l,r);
            qucksort(a,l,q);
            qucksort(a,q + 1, r);
        }
}
//int n;
//cin�n;
//long long arr[n];
//for (int i=0;i<n;i++){
//cin�arr[i];
//}
//quickSort(arr, 0, n - 1);
//for (int i = 0; i < n; i++)
//cout�arr[i]�' ';
//return 0;

int main()
{
    freopen("sort.in", "r", stdin);
    freopen("sort.out", "w", stdout);
    int number;
    cin >> number;
    long long a [number];
    for (int i = 0; i < number; i++)
    {
        cin >> a [i];
    }
    qucksort(a,0,number - 1);
    for (int i = 0; i < number; i++)
    {
        cout << a [i] << " ";
    }
}
