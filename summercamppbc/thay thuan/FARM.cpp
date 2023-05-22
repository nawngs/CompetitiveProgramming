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
const ll INF = 1e9 + 7;
const ll nmax = 2e5;
const ll MOD = 1e9 + 7;
const ll base = 2309;

void fre() {
	string finp = NAME + ".inp";
	string fout = NAME + ".out";
	freopen(finp.c_str(), "r", stdin);
	freopen(fout.c_str(), "w", stdout);
}

int n, k, p, q, dp[10003][10003], a[10003];

void sol() {
	cin >> n >> k >> q >> p;
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = 0; i <= n; i++)
		for (int j = 1; j <= q; j++) dp[i][j] = -INF;
	int res = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= q; j++) {
			int temp = min(j, p);
			int tam = (j / p) * p; 
			dp[i][j] = max(dp[i - 1][j], dp[max(0, i - k)][j - temp] + temp * a[i]);
			dp[i][j] = max(dp[i][j], dp[max(0, i - k)][tam] + (j - tam) * a[i]);
			res = max(res, dp[i][j]);
		}
	}
	cout << res;
}

int main() {
	//fast;
	//fre();
	int t = 1;
	//cin >> t;
	while (t --) sol();
}
