#pragma GCC optimize("O3,no-stack-protector,fast-math,unroll-loops,tree-vectorize")
#include <bits/stdc++.h>

using namespace std;
#define task "code"
#define ll long long

const int mod = 1e9 + 7;
const int MAXA = 1e7;

int n, m, l, r;
int f[MAXA+3], ans, temp = 0;

int pw (int a, int n) {
    ll ans = 1;
    for (; n; n >>= 1, a = 1LL * a * a % mod)
        if (n & 1) ans = 1LL * ans * a % mod;
    return ans;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n >> m >> l >> r;

    for (int i = m; i >= l; -- i) {
        if (i == m || (m-i)/i+1 != (m-i-1)/(i+1)+1)
            temp = pw((m - i) / i + 1, n);

        f[i] = temp;
        for (int j = (i << 1); j <= m; j += i) f[i] = (1LL * f[i] + 2*mod - f[j]) % mod;
        if (i <= r) ans = (ans + f[i]) % mod;
    }


    cout << ans;

    return 0;
}
