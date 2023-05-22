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
const ll INF = 1e9;
const ll nmax = 2e5;
const ll MOD = 1e9 + 7;
const ll base = 2309;

void fre() {
	string finp = NAME + ".inp";
	string fout = NAME + ".out";
	freopen(finp.c_str(), "r", stdin);
	freopen(fout.c_str(), "w", stdout);
}

int n, m, dp[10003];

void sol() {
	cin >> n >> m;
	for (int i = 0; i < (1 << n); i++) dp[i] = INF;
	dp[0] = 0;
	for (int i = 1; i <= m; i++) {
		int a, b;
		cin >> a >> b;
		int bit = 0;
		for (int j = 1; j <= b; j++) {
			int c;
			cin >> c;
			bit |= (1 << (c - 1));
		}
		for (int j = 0; j < (1 << n); j++) {
			dp[j | bit] = min(dp[j | bit], dp[j] + a);
			//cout << j << " " << dp[j] << '\n';
		}
	}
	
	cout << (dp[(1 << n) - 1] == INF ? -1 : dp[(1 << n) - 1]);
}

int main() {
	fast;
	//fre();
	int t = 1;
	//cin >> t;
	while (t --) sol();
}
