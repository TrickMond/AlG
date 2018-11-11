#include <bits/stdc++.h>

using namespace std;

pair <long long, long long> c[1000001]; // ���� �� �����
long long rB = -1; // ��������� �� ����� �����


void push(pair <long long, long long> ch) // ���������� � ���� �����
{
    rB++;
    c[rB] = ch;
}

void MakeHeap (pair <long long, long long> a[], long long RightBorder)
{
    long long parents_index;
    for (long long i =0; RightBorder > i; i++)
    {
    long long doughters_index = i;
        while (doughters_index!= 0)
        {
            parents_index = (doughters_index - 1)/2;
            if (a[parents_index].first <= a[doughters_index].first)
                break;
            swap (a[parents_index],a[doughters_index]);
            doughters_index = parents_index;
        }
    }
}

long long DeleteTop (pair <long long, long long> a[],long long RightBorder)
{
    long long max_value = a [0].first;
    a[0] = a[RightBorder - 1];
    long long parents_index = 0,
        max_doughters_index;
    while (true)
    {
        long long left_doughters_index = parents_index*2 + 1,
            right_doughters_index = parents_index*2 + 2;

        if (!(left_doughters_index >= RightBorder))
        {
            if (right_doughters_index >= RightBorder)
            right_doughters_index = parents_index;
        } else
            left_doughters_index = parents_index;


        if ((a[parents_index].first >= a[left_doughters_index].first) && (a[parents_index].first >= a[right_doughters_index].first))
            break;

        if (a[left_doughters_index].first > a [right_doughters_index].first)
        {
            max_doughters_index = left_doughters_index;
        } else
        {
            max_doughters_index = right_doughters_index;
        }
        swap (a[max_doughters_index], a[parents_index]);
        parents_index = max_doughters_index;
    }
    return max_value;
}

void HeapSort(pair <long long,long long> a[] ,long long RightBorder)
{

        MakeHeap(a,RightBorder);

        long long minimum = DeleteTop(a,RightBorder);
        printf ("%d\n", minimum);
}

int main()
{
    long long arrays_size,t;
    freopen ("priorityqueue.in","r",stdin);
    freopen ("priorityqueue.out","w",stdout);
    string s;
    pair <long long,long long> p;
    long long value,
        counter = 0,
        x,
        adress,
        key = 0,
        va;
    while (cin >> s)
    {
        switch (s[0])
        {
        case 'p':
            p.second = key + 1;
            scanf("%d",&value);
            p.first = value;
            push (p);
            MakeHeap(c, counter);
//            cout << "Pushed: => " << p.first << " KEY: " << p.second << endl;
            counter++;
            key++;
            break;
        case 'e':
            if (rB >= 0)
            {
                HeapSort(c,counter);
                counter--;
                rB--;
                break;
            } else printf ("*\n");
            break;
        case 'd':
            scanf("%d%d",&adress,&value);
            for (long long i = 0; i < key; i++)
            {
                if (c[i].second == adress)
                {
                    c[i].first = value;
                    MakeHeap(c, counter);
//                    printf ("Changed element with KEY %d to value %d\n",adress, c[i].first);
                }
            }
            break;
        }
    }
    return 0;
}
