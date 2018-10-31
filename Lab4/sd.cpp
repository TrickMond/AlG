#include <bits/stdc++.h>

using namespace std;

int main()
{
    int kurs,sem;
    cin >> sem;
    switch (sem/2+1)
    {
    case 1:
        printf("1 kurs");
        break;
    case 2:
        printf("2 kurs");
        break;
    case 3:
        printf("3 kurs");
        break;
    case 4:
        printf("4 kurs");
        break;
    }
	return 0;
}
