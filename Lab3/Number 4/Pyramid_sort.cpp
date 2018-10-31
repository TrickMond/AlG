#include <bits/stdc++.h>

using namespace std;

int result [100000];

void MakeHeap (int a[], int RightBorder)
{
    int parents_index;
    for (int i =0; RightBorder > i; i++)
    {
    int doughters_index = i;
        while (doughters_index!= 0)
        {
            parents_index = (doughters_index - 1)/2;
            if (a[parents_index] >= a[doughters_index])
                break;
            swap (a[parents_index],a[doughters_index]);
            doughters_index = parents_index;
        }
    }
}

int DeleteTop (int a[],int RightBorder)
{
    int max_value = a [0];
    a [0] = a [RightBorder - 1];
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

        if ((a[parents_index] >= a[left_doughters_index]) && (a[parents_index] >= a[right_doughters_index]))
            break;

        if (a[left_doughters_index] > a [right_doughters_index])
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

void HeapSort(int a[] ,int RightBorder)
{
    MakeHeap(a,RightBorder);
    for (int i = RightBorder ; i > 0 ; i--)
    {
        int maximum = DeleteTop(a,i);
        result[i - 1] = maximum;
    }
}
int main()
{
    int arrays_size,t;
    freopen ("sort.in","r",stdin);
    freopen ("sort.out","w",stdout);
    cin >> arrays_size;
    int a[arrays_size + 10];
    for (int i = 0; i < arrays_size; i++)
        cin >> a[i];
    HeapSort(a,arrays_size);
    for (int i = 0; i < arrays_size; i++)
        cout << result[i] << " ";
	return 0;
}
