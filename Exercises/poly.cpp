#pragma GCC optimize ("O3")
#include <bits/stdc++.h>

#define ll long long
#define ld long double
#define fi first 
#define se second
#define pll pair < ll, ll >
#define pii pair < int, int >
#define slow ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

using namespace std;

const ll ESP = 1e-9;
const ll INF = 1e18;
const ll nmax = 1e7;
const ll MOD = 1e9 + 7;

ll x, n, powx[1000005];

void sol() {
	cin >> x >> n;
	powx[0] = 1;
	for (int i = 1; i <= n; i++) powx[i] = (powx[i - 1] * x) % MOD;
	ll ans = 0;
	for (int i = 1; i <= n; i++) ans = (ans + powx[i]) % MOD;
	cout << ans << '\n';
}

int main() {
    slow;
    int t;
	cin >> t;
	while (t --) sol();
}
