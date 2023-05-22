#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
#define fi first
#define se second
#define int ll
int m, a, b;
map<pii, int> mp;
void fib(ll n, ll&x, ll&y){
    if(n==0){
        x = 0;
        y = 1;
        return ;
    }
    if(n&1){
        fib(n-1, y, x);
        y=(y+x)%m;
    }else{
        ll a, b;
        fib(n>>1, a, b);
        y = (a*a+b*b)%m;
        x = (a*b + a*(b-a+m))%m;
    }
}
void solve1() {
    int k = 6*m + 2;
    int x = 0, y = 1;
    for (int i = 0; i <= k; i++) {
        if (x == a && y == b) return cout << i << '\n', void();
        int tmp = y;
        y = x + y;
        if (y >= m) y -= m;
        x = tmp;
    }
    cout << -1 << '\n';
}
void solve() {
    mp.clear();
    cin >> m >> a >> b;
    if (!a && !b) return cout << 0 << '\n', void();
    if (m <= 1e6) {
        solve1();
        return;
    }
    int k = sqrt(6*m + 2);
    for (int i = 0; i < k; i++) {
        mp[{a, b}] = i;
        b = b - a;
        if (b < 0) b += m;
        swap(a, b);
    }
    ll x, y;
    pii tmp;
    for (int i = 0; i < k; i++) {
        fib(1LL * i*k, x, y);
        tmp = {x, y};
        if (mp.count(tmp))
            return cout << 1LL * i*k + mp[tmp] << '\n', void();
    }
    cout << -1 << '\n';
}
signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    freopen("kfib.inp", "r", stdin);
    freopen("kfib.out", "w", stdout);
    int t;
    cin >> t;
    while (t--)
        solve();
}