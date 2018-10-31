#include <bits/stdc++.h>

using namespace std;

int rightB = -1, v[1000001], po = 0;

void push (int value)
{
    rightB++;
    v[rightB] = value;
}

void pop()
{
    printf("%d\n", v[rightB]);
    rightB--;
}

char s;

int main()
{
    freopen ("stack.in","r",stdin);
    freopen("stack.out","w",stdout);
    int number,value;
    scanf("%d", &number);
    for (int i = 0; i < number; i++)
    {
        scanf("\n%c", &s);
        if (s=='+')
        {
            scanf("%d", &value);
            push (value);
        } else
        {
            pop();
        }
    }
    return 0;
}
