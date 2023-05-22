#include <bits/stdc++.h>

#define ll long long

using namespace std;

const int MOD = 1E9 + 19972207;

int r, c, a[63], allow[(1 << 10)][(1 << 10)];

int f[63][(1 << 10)][(1 << 10)], g[63][(1 << 10)][(1 << 10)], res[63][10];

void add(int &x, int y) {
    x += y;
    if (x > MOD) x -= MOD;
    if (x < 0) x += MOD;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("tetquymao.inp", "r", stdin);
    freopen("tetquymao.out", "w", stdout);
    cin >> r >> c;
    const int MAX_MSK = (1 << c) - 1;
    for (int i = 1; i <= r; i++)
        cin >> a[i];
    a[0] = a[r + 1] = 3;
    for (int msk1 = 0; msk1 < (1 << c); msk1++)
    for (int msk2 = 0; msk2 < (1 << c); msk2++) {
        int &res = allow[msk1][msk2]; res = MAX_MSK;
        for (int i = 0; i < c; i++) {
            if (msk2 >> i & 1) {
                if (i - 2 >= 0) res &= (MAX_MSK ^ (1 << (i - 2)));
                if (i + 2 < c) res &= (MAX_MSK ^ (1 << (i + 2)));
            }
            if (msk1 >> i & 1) {
                if (i - 1 >= 0) res &= (MAX_MSK ^ (1 << (i - 1)));
                if (i + 1 < c) res &= (MAX_MSK ^ (1 << (i + 1)));
            }
        }
    }
    f[0][0][0] = 1;
    for (int t = 0; t <= r; t++) {
        for (int pre = 0; pre < (1 << c); pre++)
        if (t > 0 && (a[t - 1] == 3 || __builtin_popcount(pre) % 3 == a[t - 1])) {
            for (int i = 0; i < c; i++)
                for (int msk = 0; msk < (1 << c); msk++)
                    if (!(msk >> i & 1))
                        add(f[t][pre][msk], f[t][pre][msk ^ (1 << i)]);

            for (int msk = 0; msk < (1 << c); msk++)
                if (a[t] != 3 && __builtin_popcount(msk) % 3 != a[t]) f[t][pre][msk] = 0;

        }
        if (t == r) break;
        for (int pre = 0; pre < (1 << c); pre++) 
            for (int cur = 0; cur < (1 << c); cur++) {
                add(f[t + 1][cur][allow[pre][cur]], f[t][pre][cur]);
            }
    }
    g[r + 1][0][0] = 1;
    for (int t = r + 1; t >= 0; t --) {
        for (int pre = 0; pre < (1 << c); pre++)
        if (t <= r && (a[t + 1] == 3 || __builtin_popcount(pre) % 3 == a[t + 1])) {
            for (int i = 0; i < c; i++)
                for (int msk = 0; msk < (1 << c); msk++)
                    if (!(msk >> i & 1))
                        add(g[t][msk][pre], g[t][msk ^ (1 << i)][pre]);

            for (int msk = 0; msk < (1 << c); msk++) 
                if (a[t] != 3 && __builtin_popcount(msk) % 3 != a[t]) g[t][msk][pre] = 0;
        }
        if (t == 0) break;
        for (int pre = 0; pre < (1 << c); pre++) 
        for (int cur = 0; cur < (1 << c); cur++) {
            add(g[t - 1][allow[pre][cur]][cur], g[t][cur][pre]);
        }
    }
    for (int i = 1; i <= r; i++)
        for (int pre = 0; pre < (1 << c); pre++)
        for (int cur = 0; cur < (1 << c); cur++) {
            ll temp = (1ll * f[i][pre][cur] * 1ll * g[i - 1][pre][cur]) % MOD;
            for (int j = 0; j < c; j++)
                if (cur >> j & 1) add(res[i][j], temp);
        }
    for (int i = 1; i <= r; i++) {
        for (int j = 0; j < c; j++) cout << res[i][j] << " ";
        cout << '\n';
    }
}
