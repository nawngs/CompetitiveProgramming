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

const string NAME = "sweet";
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

ll n, m, dp[303][303], s[303][303];

vector < ll > a[303];

void sol() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		a[i].clear();
		for (int j = 1; j <= m; j++) {
			int x; cin >> x;
			a[i].push_back(x);
		}
		sort(a[i].begin(), a[i].end());
		s[i][0] = 0;
		for (int j = 0; j < m; j++) s[i][j + 1] = s[i][j] + a[i][j];
	}
	for (int i = 0; i <= n; i++)
		for (int j = 0; j <= n; j++)
			dp[i][j] = LINF;
	dp[0][0] = 0;
	for (int i = 1; i <= n; i++) 
		for (int j = i; j <= n; j++) {
			for (int k = 0; k <= min(1ll * j, m); k++) 
				dp[i][j] = min(dp[i][j], dp[i - 1][j - k] + s[i][k] + k * k);
		}
	cout << dp[n][n] << '\n';
}

int main() {
	fast;
	//fre();
	int t = 1;
	cin >> t;
	while (t --) sol();
}
