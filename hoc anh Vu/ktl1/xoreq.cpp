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

const string NAME = "xoreq";
const string NAME2 = "TEST";
const ll ESP = 1e-9;
const ll INF = 1e18;
const ll nmax = (1 << 21) + 5;
const ll MOD = 1e9 + 7;
const ll base = 2309;

void fre() {
	string finp = NAME + ".inp";
	string fout = NAME + ".out";
	freopen(finp.c_str(), "r", stdin);
	freopen(fout.c_str(), "w", stdout);
}

int n, a[500003], dp[nmax][2], s[500003], last[nmax];

int mul(int a, int b) {
	return (1ll * a * 1ll * b) % MOD;
}

int main() {
	fast;
	//fre();
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		a[i] ^= a[i - 1];
		s[i] = s[i - 1] + (!a[i]);
	}
	for (int i = 1; i < nmax; i++) dp[i][0] = 1;
	for (int i = 1; i <= n; i++) {
		if (a[i]) {
			dp[a[i]][0] = (dp[a[i]][0] + mul(dp[a[i]][1], s[i] - s[last[a[i]]])) % MOD;
			dp[a[i]][1] = (dp[a[i]][0] + dp[a[i]][1]) % MOD;
			last[a[i]] = i;
		}
	}
	if (a[n]) {
		cout << dp[a[n]][0] << '\n';
		return 0;
	}
	else {
		int ans = 0;
		for (int i = 1; i < nmax; i++) ans = (ans + dp[i][1]) % MOD;
		int tmp = 1;
		for (int i = 1; i < s[n]; i++) tmp = (tmp * 2) % MOD;
		cout << (ans + tmp) % MOD << '\n';
	}
}
