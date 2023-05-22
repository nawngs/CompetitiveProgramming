#include <bits/stdc++.h>

#define SIZ(x) ((int)(x).size())
#define ll long long

using namespace std;

const ll MOD = 1E9 + 7;

struct Matrix {
    int n, m;
    vector < vector < ll > > a;
    void init(int _n = 0, int _m = 0) {
        n = _n; m = _m;
        a.assign(n + 3, vector < ll > ());
        for (int i = 1; i <= n; i++)
            a[i].assign(m + 3, 0);
    }
    Matrix operator * (const Matrix &oth) {
        assert(m == oth.n);
        Matrix res; res.init(n, oth.m);
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= oth.m; j++)
                for (int k = 1; k <= m; k++)
                    res.a[i][j] = (res.a[i][j] + a[i][k] * oth.a[k][j]) % MOD;
        return res;
    }
};

int n;

ll k;

Matrix mu(Matrix a, ll b) {
    if (b == 1) return a;
    Matrix x = mu(a, b / 2);
    x = x * x;
    if (b % 2 == 1) x = x * a;
    return x;
}

signed main() {
    cin >> n >> k;
    Matrix pw; pw.init(n, n);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            cin >> pw.a[i][j];
    pw = mu(pw, k);
    Matrix f; f.init(1, n);
    for (int i = 1; i <= n; i++) f.a[1][i] = 1;
    f = f * pw;
    ll res = 0;
    for (int i = 1; i <= n; i++) res = (res + f.a[1][i]) % MOD;
    cout << res;
}
