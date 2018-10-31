#include <bits/stdc++.h>
using namespace std;
int counter = 1;

bool check_top(int a[],int top, int siz)
{
    while (top*2+2 < siz)
    {
        if ((a[top] <= a[top*2+1]) && (a[top] <= a[top*2+2]) || (a[top] <= a[top*2+1]) && (a[top] > a[top*2+2]))
        {
            top++;
        } else
        return false;
    }
    return true;
}

int main()
{
//    freopen("isheap.in", "r", stdin);
//    freopen("isheap.out", "w", stdout);
    int number;
    cin >> number;
    int a[number + 10];
    for (int i = 0; i < number; i++)
        cin >> a[i];
    bool b = check_top(a,0,number);
    switch (b)
    {
    case 1:
        cout << "YES";
        break;
    default:
        cout << "NO";
    }
    return 0;
}
