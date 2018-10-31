#include <iostream>
#include <fstream>

using namespace std;
int counter = -1;

int binsearch(int a[],int x,int left,int right)
{

int r = right, l = left;
while (1)
{
int mid = (left + right)/2;
if (x < a[mid])
{
right = mid ;
} else if (x > a[mid])
{
left = mid + 1;
} else
{
counter = 0;
int m = mid;
while ((m <= r) && (m >= l) && (a[m] == a[m+1]))
{
counter++;
m++;
}
while ((mid <= r) && (mid >= l) && (a[mid] == a[mid-1]))
{
counter++;
mid--;
}
return mid ;
}
if (left > right)
return -1;
}

}
int main()
{
int n;
cin >> n;
int a[n];
for (int i = 1; i <= n; i++)
cin >> a[i];
int k;
cin >> k;
int j[k];
for (int i = 1; i <= k; i++)
cin >> j[i];
for (int i = 1; i <= k; i++)
{
counter = 0;
int value = binsearch(a,j[i],0,n-1);
cout << value << " " << value + counter << endl;
}
return 0;
}
