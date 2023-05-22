#include <bits/stdc++.h>

#define ll long long

using namespace std;

ll n, q, f[(1 << 20)], g[(1 << 20)], a[(1 << 20)];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n >> q;
    for (int i = 0; i < (1 << n); i++) {
        char c; cin >> c;
        a[i] = c - '0';
        f[i] = g[i] = c - '0';
    }
    for (int i = 0; i < n; i++)
        for (int j = 0; j < (1 << n); j++)
            if (j >> i & 1)
                f[j] += f[j ^ (1 << i)];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < (1 << n); j++)
            if (!(j >> i & 1))
                g[j] += g[j ^ (1 << i)];
    while (q--) {
        string s; cin >> s;
        reverse(s.begin(), s.end());
        vector < int > v0, v1, v2;
        int msk1 = 0, msk2 = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] == '0') v0.push_back(i);
            if (s[i] == '1') {
                v1.push_back(i);
                msk1 ^= (1 << i);
            }
            if (s[i] == '?') {
                v2.push_back(i);
                msk2 ^= (1 << i);
            }
        }
        int len = min(v0.size(), min(v1.size(), v2.size()));
        if (len == (int)v0.size()) {
            ll res = 0;
            for (int j = 0; j < (1 << (int)v0.size()); j++) {
                int newmsk = msk1;
                for (int i = 0; i < (int)v0.size(); i++) if (j >> i & 1) newmsk ^= (1 << v0[i]);
                if (__builtin_popcount(j) & 1) res -= g[newmsk];
                else res += g[newmsk];
            }
            cout << res << '\n';
            continue;
        }
        if (len == (int)v1.size()) {
            ll res = 0;
            for (int j = 0; j < (1 << (int)v1.size()); j++) {
                int newmsk = msk2;
                for (int i = 0; i < (int)v1.size(); i++) if (j >> i & 1) newmsk ^= (1 << v1[i]);
                if ((__builtin_popcount(j) + v1.size()) & 1) res -= f[newmsk];
                else res += f[newmsk];
            }
            cout << res << '\n';
            continue;
        }
        if (len == (int)v2.size()) {
            ll res = 0;
            for (int j = 0; j < (1 << (int)v2.size()); j++) {
                int newmsk = msk1;
                for (int i = 0; i < (int)v2.size(); i++) if (j >> i & 1) newmsk ^= (1 << v2[i]);
                res += a[newmsk];
            }
            cout << res << '\n';
            continue;
        }

    }
}
