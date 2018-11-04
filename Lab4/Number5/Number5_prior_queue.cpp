#include <bits/stdc++.h>

using namespace std;

int result [100000];
pair <int, int> c[10001]; // стек из чисел
int rB = -1; // указатель на конец стека


void push(pair <int, int> ch) // добавление в стек числа
{
    rB++;
    c[rB] = ch;
}

void MakeHeap (pair <int,int> a[], int RightBorder)
{
    int parents_index;
    for (int i =0; RightBorder > i; i++)
    {
    int doughters_index = i;
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

int DeleteTop (pair <int,int> a[],int RightBorder)
{
    int max_value = a [0].first;
    a[0] = a[RightBorder - 1];
    int parents_index = 0,
        max_doughters_index;
    while (true)
    {
        int left_doughters_index = parents_index*2 + 1,
            right_doughters_index = parents_index*2 + 2;

        if (left_doughters_index >= RightBorder) // Индекс дочерней записи выпадает из дерева
            left_doughters_index = parents_index;
        if (right_doughters_index >= RightBorder)
            right_doughters_index = parents_index;

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

int HeapSort(pair <int,int> a[] ,int RightBorder)
{
    if (RightBorder != 0)
    {

        MakeHeap(a,RightBorder);

        int minimum = DeleteTop(a,RightBorder);
        return minimum;
    }
    else return -1;
}

int main()
{
    int arrays_size,t;
//    freopen ("priorityqueue.in","r",stdin);
//    freopen ("priorityqueue.out","w",stdout);
    string s;
    pair <int,int> p;
    int value,
        counter = 0,
        x,
        adress,
        r = 0,
        va;
    while (cin >> s)
    {
        switch (s[0])
        {
        case 'p':
            p.second = r + 1;
            cin >> value;
            p.first = value;
            push (p);
            counter++;
            r++;
            break;
        case 'e':

            x = HeapSort(c,counter);
            if (x!=-1)
            {
                cout << x << endl;
                counter--;
                rB--;
            } else cout << '*' << endl;
            break;
        case 'd':
            cin >> adress >> value;
            for (int i = 0; i < counter; i++)
            {
                if (c[i].second == adress)
                {
                    c[i].first = value;
                }
            }
            break;
        }
    }
	return 0;
}
