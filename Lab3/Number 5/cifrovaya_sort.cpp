#include <fstream>
#include <vector>
#include <iostream>


using namespace std;

void CountingSort(vector<string> &arr, int phase)
{
    int range = 'z' - 'A' + 1;
    vector<int> c(range);
    vector<string> b(arr.size());
    for (int i = 0; i < range; i++)
    c[i] = 0;
    for (int i = 0; i < arr.size(); i++)
    c[arr[i][phase] - 'A']++;
    for (int i = 1; i < range; i++)
    c[i] = c[i] + c[i - 1];
    for (int i = arr.size() - 1; i >= 0; i--)
    b[--c[arr[i][phase] - 'A']] = arr[i];
    arr = b;
}

void RadixSort(vector<string> &arr, int lon_g, int phase_1)
{
    for (int i = lon_g - 1; i >= lon_g - phase_1; i--)
    CountingSort(arr, i);
}

int main()
{
    freopen ("radixsort.in","r",stdin);
    freopen ("radixsort.out","w",stdout);
    int size, lon_g, phase_1;
    cin >> size >> lon_g >> phase_1;
    vector<string> arr(size);
    for (int i = 0; i < size; i++)
    cin >> arr[i];
    RadixSort(arr, lon_g, phase_1);
    for (int i = 0; i < size; i++)
    cout << arr[i] << endl;
    return 0;
}
