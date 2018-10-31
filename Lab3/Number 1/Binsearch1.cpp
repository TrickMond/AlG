#include <bits/stdc++.h>
using namespace std;
int counter = 1;

int binsearchl(int a[],int x,int right)
{
    int left = -1, mid;
    while (left < right - 1)
    {
        mid = (left + right)/2;
        if (a[mid] < x)
        {
            left = mid;
        }
        else
        {
            right = mid;
        }
    }
    return ++right;
}
int binsearchr(int a[],int x,int right)
{
    int left = -1, mid;
    while (left < right - 1)
    {
        mid = (left + right)/2;
        if (a[mid] > x)
        {
            right = mid;
        }
        else
        {
            left = mid;
        }
    }
    return ++left;
}



int main()
{
    freopen("binsearch.in", "r", stdin);
    freopen("binsearch.out", "w", stdout);
    int number;
    cin >> number;
    int a[number + 10];
    for (int i = 0; i < number; i++)
        cin >> a[i];
    int number2;
    cin >> number2;
    int a2[number2 + 10];
    int left;
    for (int i = 0; i < number2; i++)
    {
        cin >> a2[i];
        int index1 = binsearchl(a,a2[i],number);
        int index2 = binsearchr(a,a2[i],number);
        if (index2 < index1)
            index2=index1= -1;
        cout << index1 << " " << index2 << endl;
    }
    return 0;
}
