#include <bits/stdc++.h>

using namespace std;

void merg(vector < pair <string, string> > &a,int left, int middle, int right) {
    int cursore1 = 0, cursore2 = 0;
    vector < pair <string, string> > result;
    while ( ( (left + cursore1) < middle) && ( (middle + cursore2) < right) )
    {
        if (a[left + cursore1].first <= a[middle + cursore2].first)
        {
            result.push_back(a [left + cursore1++]);
        } else
        {
            result.push_back( a [middle + cursore2++]);
        }
    }
    while (left + cursore1 < middle)
    {
        result.push_back( a [left + cursore1++]);
    }
    while (middle + cursore2 < right)
    {
        result.push_back( a [middle + cursore2++]);
    }
    for (int i = 0; i < (cursore1 + cursore2); i++)
    {
            a[left + i] = result [i];
    }
}
void mergeSortRecursive(vector < pair <string, string> > &a, int left, int right){
if (left + 1 >= right)
    return;
int middle = (left + right) / 2;
mergeSortRecursive(a,left, middle);
mergeSortRecursive(a,middle, right);
merg(a,left, middle, right);
}

int main ()
{

    long number;
    pair <string, string> tabbles_line;
    vector < pair <string, string> > v;
    int n;
    freopen("race.in", "r", stdin);
    freopen("race.out", "w", stdout);
    cin >> number;
    for (int i = 0; i < number; i++)
    {
        cin >> tabbles_line.first >> tabbles_line.second ;
        v.push_back(tabbles_line);
    }
    mergeSortRecursive(v,0,number);

    string country = "";
    for (int i = 0; i < v.size(); i++)
    {
        if (v[i].first != country)
        {
            country = v[i].first;
            cout << "=== " << country << " ===" << endl;
        }
        cout << v[i].second << endl;
    }
//    fclose (stdout);
//    fclose (stdin);
return 0;
}

