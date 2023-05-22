#include <bits/stdc++.h>

#define ll long long

using namespace std;

ll n, a[23], b[23], h;

namespace ac {
    ll cnta[(1 << 20)], sb[(1 << 20)];
    void solve() {
        for (int i = 0; i < (1 << n); i++) cnta[i] = sb[i] = 0;
        for (int i = 1; i < (1 << n); i++) {
            ll sa = 0;
            for (int j = 0; j < n; j++)
                if ((i >> j) & 1) {
                    sa += a[j];
                    sb[i] += b[j];
                }
            if (sa >= h) cnta[i] ++;
        }
        for (int j = 0; j < n; j++)
            for (int i = (1 << n) - 1; i >= 0; i--)
                if ((i >> j) & 1) cnta[i ^ (1 << j)] += cnta[i];
        ll res = 0;
         for (int i = 1; i < (1 << n); i++) {
            if (sb[i] < h) continue;
            res += cnta[(((1 << n) - 1) ^ i)];
         }
         cout << res << '\n';
    }
}

namespace sub1 {
    ll res = 0, f[15];
    void back_track(int pos) {
        if (pos == n) {
            ll sa = 0, sb = 0;
            for (int i = 0; i < n; i++) {
                if (f[i] == 0 || f[i] == 2) sa += a[i];
                if (f[i] == 1 || f[i] == 2) sb += b[i];
            }
            if (sa >= h && sb >= h) res ++;
            return ;
        }
        for (int i = 0; i < 3; i++) {
            f[pos] = i;
            back_track(pos + 1);
        }
    }
    void solve() {
        res = 0;
        memset(f, 0, sizeof(f));
        back_track(0);
        cout << res << '\n';
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int t; cin >> t;
    while (t--) {
        cin >> n >> h;
        for (int i = 0; i < n; i++) cin >> a[i];
        for (int i = 0; i < n; i++) cin >> b[i];
         if (n <= 12) sub1:: solve();
         else ac::solve();
    }
}
