#pragma GCC optimize ("O2")
#include <bits/stdc++.h>

#define ll long long
#define ld long double
#define fi first 
#define se second
#define pll pair < ll, ll >
#define pii pair < int, int >
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

using namespace std;

const string NAME = "";
const string NAME2 = "TEST";
const ll ESP = 1e-9;
const ll INF = 1e18;
const ll nmax = 2e5;
const ll MOD = 1e9 + 7;
const ll base = 2309;

void fre() {
	string finp = NAME + ".inp";
	string fout = NAME + ".out";
	freopen(finp.c_str(), "r", stdin);
	freopen(fout.c_str(), "w", stdout);
}

ll n, a[1000003], dp[1000003];

int main() {
	fast;
	//fre();
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];
	ll val_min = -a[1], val_max = a[1];
	ll ans = 0;
	for (int i = 2; i <= n; i++) {
		dp[i] = max(val_min + a[i], val_max - a[i]);
		val_min = max(val_min, dp[i - 1] - a[i]);
		val_max = max(val_max, dp[i - 1] + a[i]);
		ans = max(ans, dp[i]);
	}
	cout << ans;
}
