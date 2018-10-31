#include<bits/stdc++.h>

using namespace std;

int n;
long long a[1111111], ans;

void merges (int l, int r) {

    if (l + 1 >= r) {
        return;
    }

    int m = (l + r) / 2;
    merges (l, m);
    merges (m, r);

    int i = l;
    int j = m;
    vector<long long> v;

    while ((i < m) && (j < r)) {
        if (a[i] > a[j]) {
            v.push_back(a[j]);
            j++;
            ans += m - i;
        } else {
            v.push_back(a[i]);
            i++;
        }
    }

    while (i < m) {
        v.push_back(a[i]);
        i++;
    }
    while (j < r) {
        v.push_back(a[j]);
        j++;
    }

    i = 0;
    for (int k = l; k < r; ++k) {
        a[k] = v[i++];
    }
}

int main() {

    freopen("inversions.in", "r", stdin);
    freopen("inversions.out", "w", stdout);

    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    merges(0, n);

    cout << ans;

    return 0;
}
