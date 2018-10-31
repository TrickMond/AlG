#include <bits/stdc++.h>

using namespace std;

void QuickSort(int a[], int left, int right, int k)
{
    int i = left;
    int j = right;
    int m = a[(left + right) / 2];
    while (i <= j)
    {
        while (a[i] < m) ++i;
        while (a[j] > m) --j;
        if (i <= j)
            swap(a[i++], a[j--]);
    }
    if (left < j && k <= j)
        QuickSort(a, left, j, k);
    if (i < right && k >= i)
        QuickSort(a, i, right, k);
}

int main()
{
    freopen("kth.in", "r", stdin);
    freopen("kth.out", "w", stdout);

    int n, k, A, B, C;
    cin >> n >> k;

    int a[n];
    cin >> A >> B >> C >> a[0] >> a[1];

    for (int i = 2; i < n; i++)
        a[i] = A * a[i - 2] + B * a[i - 1] + C;

    QuickSort(a, 0, n - 1, k - 1);

    cout << a[k - 1] << endl;

    return 0;
}
