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

const string NAME = "transet";
const string NAME2 = "TEST";
const ll ESP = 1e-9;
const ll INF = 1e18;
const ll nmax = 1e7;
const ll MOD = 1e9 + 7;

void fre() {
	string finp = NAME + ".inp";
	string fout = NAME + ".out";
	freopen(finp.c_str(), "r", stdin);
	freopen(fout.c_str(), "w", stdout);
}

int n, k, s, dp[1005][55];

vector < int > adj[1005];


void sol() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> k;
		for (int j = 1; j <= k; j++) {
			int x;
			cin >> x;
			adj[x].push_back(i);
		}
		dp[i][1] = k;
	}
	cin >> s;
	for (int t = 1; t < s; t++) {
		for (int i = 1; i <= n; i++) {
			for (auto u : adj[i]) {
				dp[u][t + 1] = max(dp[u][t + 1], dp[i][t] + dp[u][1] - 1);
			}
		}
	}
	int ans = 0;
	for (int i = 1; i <= n; i++) ans = max(ans, dp[i][s]);
	cout << ans;
}

int main() {
	fast;
	fre();
	int t = 1;
	//cin >> t;
	while (t --) sol();
}
