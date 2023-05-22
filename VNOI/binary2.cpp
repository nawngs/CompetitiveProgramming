#pragma GCC optimize ("O3")
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
const ll nmax = 1e7;
const ll MOD = 1e9;

void fre() {
	string finp = NAME + ".inp";
	string fout = NAME + ".out";
	freopen(finp.c_str(), "r", stdin);
	freopen(fout.c_str(), "w", stdout);
}

ll n, k, s[1000003], dp[1000003];

void sol() {
	cin >> n >> k;
	dp[0] = s[0] = 1;
	for (int i = 1; i <= n; i++) {
		if (i <= k) dp[i] = (dp[i - 1] * 2) % MOD;
		else dp[i] = (s[i - 1] - s[i - k - 1] + MOD) % MOD;
		s[i] = (s[i - 1] + dp[i]) % MOD;
	} 
	cout << dp[n] << '\n';
}

int main() {
	fast;
	//fre();
	int t = 1;
	//cin >> t;
	while (t --) sol();
}
