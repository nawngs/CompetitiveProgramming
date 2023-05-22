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

const string NAME = "chords";
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

int n, match[2003], dp[2003][2003], pos[2003];

void trace(int i, int j) {
	if (i >= j) return ;
	if (dp[i][j] == dp[i][j - 1]) trace(i, j - 1);
	else {
		cout << pos[j] << " ";
		trace(i, match[j] - 1);
		trace(match[j] + 1, j);
	}
}

void sol() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		int u, v;
		cin >> u >> v;
		match[u] = v;
		match[v] = u;
		pos[u] = pos[v] = i;
	}
	for (int k = 1; k <= 2 * n; k++) {
		for (int i = 1; i <= 2 * n - k + 1; i++) {
			int j = i + k - 1;
			if (i == j) {
				dp[i][j] = 0;
				continue;
			}
			dp[i][j] = max(dp[i][j], dp[i][j - 1]);
			if (i <= match[j] && match[j] <= j) dp[i][j] = max(dp[i][j], dp[i][match[j] - 1] + dp[match[j] + 1][j] + 1);
		} 
	}
	cout << dp[1][2 * n] << '\n';
	trace(1, 2 * n);	
}

int main() {
	fast;
	fre();
	int t = 1;
	//cin >> t;
	while (t --) sol();
}
