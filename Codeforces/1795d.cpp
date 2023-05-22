#include <bits/stdc++.h>

#define ll long long

using namespace std;

const ll MOD = 998244353;

int n, a[300003];

ll mu(ll a, ll b) {
    if (b == 0) return 1;
    ll x = mu(a, b / 2);
    x = (x * x) % MOD;
    if (b % 2 == 1) x = (x * a) % MOD;
    return x;
}

ll C(ll k, ll n) {
    ll up = 1, down = 1;
    for (int i = 1; i <= n; i++)
        up = (up * i) % MOD;
    for (int i = 1; i <= n - k; i++)
        down = (down * i) % MOD;
    for (int i = 1; i <= k; i++)
        down = (down * i) % MOD;
    return (up * mu(down, MOD - 2)) % MOD;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    ll res = 1;
    for (int i = 1; i <= n; i+=3) {
        vector < ll > temp;
        temp.push_back(a[i] + a[i + 1]); temp.push_back(a[i] + a[i + 2]); temp.push_back(a[i + 1] + a[i + 2]);
        sort(temp.begin(), temp.end());
        if (temp[0] == temp[2]) res *= 3;
        else if (temp[1] == temp[2])  res *= 2;
        res %= MOD;
    }
    cout << (res * C(n / 6, n / 3)) % MOD;
}
