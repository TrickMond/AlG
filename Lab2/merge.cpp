#include <bits/stdc++.h>

using namespace std;
void merg(int a[], int left, int middle, int right)
{
    int f [300];
    int i=0,j=0;
    while(left + i < middle && middle + j < right)
    {
        if(a[i + left] <= a[middle + j])
        {
            f[i + j] = a[left + i];
            i++;
        }
        else
        {
            f[i + j] = a[middle + j];
            j++;
        }
    }
    while(i + left < middle)
    {
        f[i + j] = a[left + i];
        i++;
    }
    while(middle + j < j)
    {
        f[i + j] = a[middle + j];
        j++;
    }
    for (int k = 0; k < i + j; ++k)
        a[left + k] = f[k];
}
void mergeSort(int a[], int left, int right)
{
    if(left + 1 >= right)
        return;
    int middle = (left + right) / 2;
    mergeSort(a, left, middle);
    mergeSort(a, middle, right);
    merg(a, left, middle, right);
}

int main() {
//    freopen("race.in", "r", stdin);
//    freopen("race.out", "w", stdout);
    unsigned int count;
    cin >> count;
    int a [count];
    for (int i = 0; i < count; i++)
    {
        cin >> a[i];
    }
    mergeSort(a,0,count);
    for (int i = 0; i < count; i++)
    {
        cout << a[i] << " ";
    }
    return 0;
}
