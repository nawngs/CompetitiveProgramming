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
const ll MOD = 1234567890;
const ll base = 2309;

void fre() {
	string finp = NAME + ".inp";
	string fout = NAME + ".out";
	freopen(finp.c_str(), "r", stdin);
	freopen(fout.c_str(), "w", stdout);
}

ll dp[1000005];

ll n, k;

void sol(ll n, ll k) {
	if (k == 0) {
		cout << min(n - 1, 1ll * 1234567891) << '\n';
		return ;
	}
	dp[1] = 0;
	ll sum = 0;
	for (int i = 2; i <= n; i++) {
		dp[i] = sum + i - 1;
		sum += dp[i];
		if (i > k) sum -= dp[i - k];
		if (dp[i] > 1234567890) {
			cout << dp[i] << '\n';
			return ;
		}
	}
	cout << dp[n] << '\n';
	return ;
}

int main() {
	fast;
	//fre();
	int t = 1;
	while (cin >> n >> k) {
		if (n == 0 && n == k) return 0;
		sol(n, k);
	}
}
