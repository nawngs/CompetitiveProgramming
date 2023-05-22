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

const string NAME = "strings";
const string NAME2 = "TEST";
const ll ESP = 1e-9;
const ll INF = 1e18;
const ll nmax = 2e5;
const ll MOD = 1e9 + 19972207;
const ll base = 2309;

void fre() {
	string finp = NAME + ".inp";
	string fout = NAME + ".out";
	freopen(finp.c_str(), "r", stdin);
	freopen(fout.c_str(), "w", stdout);
}

ll l, dp[1000003];

bool check[1000003];


string a, b;

void sol() {
	cin >> l >> a >> b;	
	dp[0] = max(0, b[0] - a[0] - 1);
	check[0] = (a[0] == b[0]);
	for (int i = 1; i < l; i++) {
		dp[i] = (dp[i - 1] * 26) % MOD;
		if (check[i - 1]) {
			if (i < a.size()) dp[i] = (dp[i] + max(0, b[i] - a[i] - 1)) % MOD;
			else dp[i] = (dp[i] + b[i] - 'a') % MOD;
		}
		else {
			if (i < a.size()) dp[i] = (dp[i] + 'z' - a[i]) % MOD;
			if (i == a.size()) dp[i] = (dp[i] + 26) % MOD;
			if (i < b.size()) dp[i] = (dp[i] + b[i] - 'a') % MOD;
		}
		//cout << i << " " << dp[i] << '\n';
		check[i] = (check[i - 1] && (i < a.size() && i < b.size() && a[i] == b[i]));	
		dp[i] %= MOD;
	}
	cout << (dp[l - 1] + (l < b.size() && !check[l - 1])) % MOD;
}

int main() {
	fast;
	//fre();
	int t = 1;
	//cin >> t;
	while (t --) sol();
}
