#include <bits/stdc++.h>

#define name "funkcija"
#define ll long long
#define ld long double
#define fi first 
#define se second
#define pll pair < ll, ll >
#define pii pair < int, int >
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define SZE(x) ((int)(x).size())
#define pb push_back
#define mp make_pair
#define lnode node * 2, l, (l + r) / 2
#define rnode node * 2 + 1, (l + r) / 2 + 1, r
#define int ll

using namespace std;

const ld EPS = 1e-9;
const int INF = 1e9 + 7;
const ll LINF = 1E18;
const int N = 3e5;
const ll MOD = 998244353;
const ll BASE = 2309;

ll n, dp[26][N + 3], l[26], r[26], s[26][N + 3];

bool vs[26];

vector < pii > adj[26];

string low, high;

void dfs(int u) {
	vs[u] = 1;
	for (auto v : adj[u]) dfs(v.fi);
	for (int i = l[u]; i <= r[u]; i++) {
		dp[u][i] = 1;
		for (auto v : adj[u]) {
			if (v.se == 0) dp[u][i] = (dp[u][i] * (s[v.fi][N] - s[v.fi][i - 1] + MOD)) % MOD; // u < v
			else dp[u][i] = (dp[u][i] * s[v.fi][i]) % MOD; // u > v
		}
	}
	// for (int i = l[u]; i <= r[u]; i++) if (dp[u][i] != 0) cout << u << " " << i << " " << dp[u][i] << '\n';
	for (int i = 1; i <= N; i++) 
		s[u][i] = (s[u][i - 1] + dp[u][i]) % MOD;
}

signed main() {
	fast;
	if(fopen(name".inp", "r")) {
		freopen(name".inp", "r", stdin);
		freopen(name".out", "w", stdout);
	}
	//int t; cin >> t; while (t --) sol();
	cin >> n >> n;
	for (int i = 0; i < n; i++) {
		cin >> low >> high;
		l[i] = 1, r[i] = N;
		if (low.size() == 1 && 'a' <= low[0] && low[0] <= 'z') adj[low[0] - 'a'].pb({i, 0});
		else l[i] = stoi(low);
		if (high.size() == 1 && 'a' <= high[0] && high[0] <= 'z') adj[high[0] - 'a'].pb({i, 1});
		else r[i] = stoi(high);
	}
	ll res = 1;
	for (int i = 0; i < n; i++) if (!vs[i]) {
		dfs(i);
		res = (res * s[i][N]) % MOD;
	}
	cout << res;
}