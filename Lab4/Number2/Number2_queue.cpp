#include <bits/stdc++.h>

using namespace std;

int leftB = -1, // указатель на начало ("голову") очереди
    rightB = -1, // указатель на конец ("хвост") очереди
    v[1000001]; // очередь
addToQueue(int value) // добавление в конец очереди
{
    rightB++;
    v[rightB] = value;
}
removeFromQueue () // удаление с начала очереди, и вывод элемента на жкран
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
