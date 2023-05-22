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
const ll nmax = 1e4 + 3;
const ll MOD = 1e9 + 7;
const ll base = 2309;

void fre() {
	string finp = NAME + ".inp";
	string fout = NAME + ".out";
	freopen(finp.c_str(), "r", stdin);
	freopen(fout.c_str(), "w", stdout);
}

int n, a[10003], b[10003], dp[nmax][nmax], m;

void sol() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) cin >> a[i];
	for (int i = 0; i < n; i++) cin >> b[i];
	for (int i = 0; i <= n * m; i++) 
		for (int j = 0; j <= n * m; j++) dp[i][j] = INF;
	dp[0][1] = a[0];
	for (int i = 0; i < n * m - 1; i++) {
		for (int j = 0; j < n * m; j++) {
			//cout << i << " " << j << " " << dp[i][j] << '\n';
			if (j != 0) dp[i + 1][j - 1] = min(dp[i + 1][j - 1], dp[i][j] + b[(i + 1) % n]);
			dp[i + 1][j + 1] = min(dp[i + 1][j + 1], dp[i][j] + a[(i + 1) % n]);
			//dp[i][j] = min(dp[i - 1][j - 1] + a[j % n], dp[i - 1][j + 1] + b[j % n]);
		}
	}
	cout << dp[n * m - 1][0];
}

int main() {
	//cout << !0 << '\n';
	fast;
	//fre();
	int t = 1;
	//cin >> t;
	while (t --) sol();
}

/*
#pragma GCC optimize ("
const ll base = 2309;

void fre() {
	string finp = NAME + ".inp";
	string fout = NAME + ".out";
	freopen(finp.c_str(), "r", stdin);
	freopen(fout.c_str(), "w", stdout);
}

ll n, a[10003], b[10003], dp[nmax][nmax / 2], m;

void sol() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) cin >> a[i];
	for (int i = 0; i < n; i++) cin >> b[i];
	for (int i = 0; i <= n * m; i++) dp[0][i] = INF;
	dp[0][1] = a[0];
	for (int i = 1; i < n * m; i++) {
		dp[i][0] = dp[i - 1][1] + b[i % n];
		for (int j = 1; j < n * m; j++) dp[i][j] = min(dp[i - 1][j - 1] + a[j % n], dp[i - 1][j + 1] + b[j % n]);
	}
	cout << dp[n * m - 1][0];
}

int main() {
	fast;
	//fre();
	int t = 1;
	//cin >> t;
	while (t --) sol();
}
*/
