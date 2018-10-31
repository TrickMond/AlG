#include <bits/stdc++.h>

using namespace std;

struct Racer
{
    string country;
    string name;
    int place;
};
void merge(Racer *strana, Racer *f, int left, int middle, int right)
{
    int i=0,j=0;
    while(left + i < middle && middle + j < right)
    {
        if(strana[i + left].country <= strana[middle + j].country)
        {
            f[i + j] = strana[left + i];
            i++;
        }
        else
        {
            f[i + j] = strana[middle + j];
            j++;
        }
    }
    while(i + left < middle)
    {
        f[i + j] = strana[left + i];
        i++;
    }
    while(middle + j < j)
    {
        f[i + j] = strana[middle + j];
        j++;
    }
    for (int k = 0; k < i + j; ++k)
        strana[left + k] = f[k];
}
void mergeSort(Racer *strana, Racer *f, int left, int right)
{
    if(left + 1 >= right)
        return;
    int middle = (left + right) / 2;
    mergeSort(strana, f, left, middle);
    mergeSort(strana, f, middle, right);
    merge(strana, f, left, middle, right);
}

int main() {
//    freopen("race.in", "r", stdin);
//    freopen("race.out", "w", stdout);
    unsigned int count;
    cin >> count;
    Racer racers[count];
    Racer addtional[count];
    for (int i = 0; i < count; i++)
    {
        cin>>racers[i].country>>racers[i].name;
        racers[i].place = i+1;
    }
    mergeSort(racers,addtional,0,count);
    string country = "";
    for (int i = 0; i < count; i++)
    {
        if (racers[i].country != country)
        {
            country = racers[i].country;
            cout << "=== " << country << " ===" << endl;
        }
        cout << racers[i].name << endl;
    }
    return 0;
}
