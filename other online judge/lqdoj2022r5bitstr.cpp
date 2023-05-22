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
const ld ESP = 1e-9;
const ll INF = 1e9 + 7;
const ll LINF = 1E18;
const ll nmax = 2e5;
const ll MOD = 1e9 + 7;
const ll base = 2309;

void fre() {
	string finp = NAME + ".inp";
	string fout = NAME + ".out";
	freopen(finp.c_str(), "r", stdin);
	freopen(fout.c_str(), "w", stdout);
}

ll n, u, v, dp[2003];

void sol() {
	cin >> n >> u >> v;
	dp[0] = 1;
	for (int i = 1; i <= n; i++) {
		dp[i] = dp[i - 1];
		if (i >= v) {
			dp[i] = (dp[i] + dp[i - v]) % MOD;
			for (int j = 1; j <= min(u, v - 1); j++) {
				int pos = i - v + j;
				if (pos < u) continue;
				dp[i] = (dp[i] + (dp[u - j] * dp[pos - u]) % MOD) % MOD;
			}
		}
		cout << i << " " << dp[i] << '\n';
	}
	cout << dp[n] << '\n';
}

int main() {
	fast;
	//fre();
	int t = 1;
	cin >> t;
	while (t --) sol();
}