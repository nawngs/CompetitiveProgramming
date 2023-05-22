#include <bits/stdc++.h>

#define ll long long
#define pii pair < int, int >
#define fi first
#define se second

using namespace std;

const ll nmax = 2e6;

ll n, f[nmax + 3];

vector < pii > prime;

void sieve() {
    for (int i = 1; i <= nmax; i++) f[i] = i;
    for (int i = 2; i * i <= nmax; i++)
        if (f[i] == i) for (int j = i * i; j <= nmax; j+=i) f[j] = i;
}

void update(int val) {
    while (val > 1) {
        bool add = true;
        for (auto &x : prime) {
            if (x.fi == f[val]) {
                add = false;
                x.se ++;
                break;
            }
        }
        if (add) prime.push_back(make_pair(f[val], 1));
        val /= f[val];
    }
}

void solve() {
    prime.clear();
    cin >> n;
    update(n);
    update(n + 1);
    update(n + 2);
    ll res1 = 1, res2 = 1;
    for (auto x : prime) {
        res1 *= (x.se + 1);
        res2 *= (2 * x.se + 1);
    }
    cout << (res2 - 2 * res1 + 1) / 2 << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("div.inp", "r", stdin);
    freopen("div.out", "w", stdout);
    int t; cin >> t;
    sieve();
    while (t--) solve();
}
