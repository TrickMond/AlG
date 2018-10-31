#include <bits/stdc++.h>

using namespace std;

int leftB = -1,rightB = -1, v[1000001];
addToQueue(int value)
{
    rightB++;
    v[rightB] = value;
}
removeFromQueue ()
{
    leftB++;
    printf("%d\n",v[leftB]);
}
int main()
{
    freopen("queue.in","r",stdin);
    freopen("queue.out","w",stdout);
    char s;
    int number,value;
    scanf("%d", &number);
    for (int i = 0; i < number; i++)
    {
        scanf("\n%c", &s);
        if (s=='+')
        {
            scanf("%d", &value);
            addToQueue (value);
        } else
        {
            removeFromQueue();
        }
    }
	return 0;
}
