#include <bits/stdc++.h>
#define ll long long
 
using namespace std;
 
ll n, k, a[100003], b[100003], s[100003];
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("trip.inp", "r", stdin);
    freopen("trip.out", "w", stdout);
    cin >> n >> k;
    for (int i = 1; i <= n; i++) cin >> a[i];
    sort(a + 1, a + n + 1);
    b[1] = 0;
    for (int i = 2; i <= n; i++) b[i] = (k - ((a[i] - a[1]) % k)) % k;
    sort(b + 1, b + n + 1);
    for (int i = 1; i <= n; i++) s[i] = s[i - 1] + b[i];
    ll ans = 1e18;
    b[0] = -1;
    for (int i = 1; i <= n; i++) {
        if (b[i] == b[i - 1]) continue;
        ll tam = k * (i - 1) - (b[i] * (i - 1) - s[i - 1]);
        ll tam2 = (s[n] - s[i]) - (b[i] * (n - i));
        ans = min(ans, tam + tam2);
    }
    cout << ans;
}