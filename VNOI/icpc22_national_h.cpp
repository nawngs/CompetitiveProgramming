#include <bits/stdc++.h>

#define int ll
#define ll long long
#define pll pair < ll, ll >
#define fi first
#define se second
#define cll const ll&

using namespace std;

const ll MOD = 998244353;

map < ll, pll > f;

ll n;

pll solve(ll x) {
    if (x < 0) return {0, 0};
    if (x <= 1) return {0, 1};
    if (f.find(x) != f.end())
        return f[x];
    ll total = 0, num = 0;
    ll mid = (x / 2);
    pll temp1 = solve(mid), temp2 = solve(x - mid);
    total = (temp1.fi * temp2.se + temp2.fi * temp1.se) % MOD;
    num = (temp1.se * temp2.se) % MOD;
    temp1 = solve(mid - 1); temp2 = solve(x - mid - 2);
    total = (total + temp1.fi * temp2.se * 2 + temp2.fi * temp1.se * 2) % MOD;
    total = (total + (temp1.se * temp2.se % MOD) * 12) % MOD;
    num = (num + 2 * temp1.se * temp2.se) % MOD;
    temp1 = solve(mid - 2); temp2 = solve(x - mid - 1);
    total = (total + temp1.fi * temp2.se * 2 + temp2.fi * temp1.se * 2) % MOD;
    total = (total + (temp1.se * temp2.se % MOD) * 12) % MOD;
    num = (num + 2 * temp1.se * temp2.se) % MOD;
    temp1 = solve(mid - 1), temp2 = solve(x - mid - 1);
    total = (total + (temp1.fi * temp2.se) % MOD * 4 + (temp2.fi * temp1.se) % MOD * 4) % MOD;
    total = (total + (f[2].fi * temp1.se) % MOD * temp2.se) % MOD;
    num = (num + (4 * temp1.se) % MOD * temp2.se) % MOD;
    f[x] = {total, num};
    return f[x];
}

signed main() {
    cin >> n;
    f[2] = {12, 5};
    cout << solve(n).fi;
}