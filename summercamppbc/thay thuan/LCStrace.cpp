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

int n, m, a[1003], b[1003], dp[1003][1003];

pii trace[1003][1003];

void sol() {
	cin >> n;	
	for (int i = 1; i <= n; i++) cin >> a[i];
	cin >> m;
	for (int i = 1; i <= m; i++) cin >> b[i];
	memset(dp, 255, sizeof(dp));
	dp[0][0] = 0;
	for (int i = 1; i <= n; i++) {
		dp[i][0] = 0;
		trace[i][0] = {0, 0};
	}
	for (int j = 1; j <= m; j++) {
		dp[0][j] = 0;
		trace[0][j] = {0, 0};
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (a[i] == b[j]) {
				dp[i][j] = dp[i - 1][j - 1] + 1;
				trace[i][j] = {i, j};
			}
			else {
				dp[i][j] = max(dp[i - 1][j - 1], max(dp[i - 1][j], dp[i][j - 1]));
				if (dp[i][j] == dp[i - 1][j - 1]) trace[i][j] = trace[i - 1][j - 1];
				if (dp[i][j] == dp[i - 1][j]) trace[i][j] = trace[i - 1][j];
				if (dp[i][j] == dp[i][j - 1]) trace[i][j] = trace[i][j - 1];

			}
		}
	}
	cout << dp[n][m] << '\n';
	pii pos = trace[n][m];
	vector < int > res;
	res.clear();
	while (pos.fi != 0 && pos.se != 0) {
		if (a[pos.fi] == b[pos.se]) {
			res.push_back(a[pos.fi]);
			pos = trace[pos.fi - 1][pos.se - 1];
		}
	}
	reverse(res.begin(), res.end());
	for (auto x : res) cout << x << " ";
}

int main() {
	fast;
	//fre();
	int t = 1;
	//cin >> t;
	while (t --) sol();
}
