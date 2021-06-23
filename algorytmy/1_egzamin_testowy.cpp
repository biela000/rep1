#include<bits/stdc++.h>
#define FOR(n) for (int i = 0; i < n; ++i)
using namespace std;

int n, m;
int a[1000];
string tab[1000];
int res;

void Solve() {
    cin >> n >> m;
    FOR(n) {
        cin >> tab[i];
    }
    FOR(m) {
        cin >> a[i];
    }
    FOR(m) {
        int ct[5] = {};
        for (int o = 0; o < n; ++o) {
            ct[tab[o][i] - 65]++;
        }
        int MAX = INT_MIN;
        for (int o = 0; o < 5; ++o) {
            if (MAX < ct[o]) {
                MAX = ct[o];
            }
        }
        res += MAX * a[i];
    }
    cout << res << "\n";
}

int main() {
    ios::sync_with_stdio(0);
    cin.ignore(0);
    Solve();
    return 0;
}