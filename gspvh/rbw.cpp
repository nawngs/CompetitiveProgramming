#include <bits/stdc++.h>

#define name "rbw"
#define test "test"
#define ll long long
#define ld long double
#define fi first 
#define se second
#define pll pair < ll, ll >
#define pii pair < int, int >
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define sz(x) ((int)(x).size())
#define pb push_back
#define mp make_pair

using namespace std;

const ld EPS = 1e-9;
const int INF = 1e9 + 7;
const ll LINF = 1E18;
const int NMAX = 2e5;
const ll MOD = 998244353;
const ll BASE = 2309;

int n;

ll dp[500003][2];

vector < int > adj[500003];

ll mu(ll a, ll b) {
	if (b == 0) return 1;
	ll x = mu(a, b / 2); x = (x * x) % MOD;
	if (b % 2 == 1) x = (x * a) % MOD;
	return x;
}

void dfs(int u) {
	/*
	tinh dp[u] ca xuoi va nguoc roi tru ra 2 truong hop
	 +) cac thang con co so phan tu chan
	 +) cac thang con co so phan tu le va so thang con la le
	*/
	dp[u][0] = 0; dp[u][1] = 1;
	ll sc = 1, sl1 = 1, sl2 = 1;
	bool isleaf = 1;
	for (auto v : adj[u]) {
		isleaf = 0;
		dfs(v);
		ll pre0 = dp[u][0], pre1 = dp[u][1];
		dp[u][0] = (pre0 * dp[v][0] + pre1 * dp[v][1]) % MOD;
		dp[u][1] = (pre0 * dp[v][1] + pre1 * dp[v][0]) % MOD;
		sc = (sc * (dp[v][0])) % MOD;
		sl1 = (sl1 * (1 + dp[v][1])) % MOD;
		sl2 = (sl2 * (1 - dp[v][1] + MOD)) % MOD;
	}
	if (!isleaf) {
		dp[u][0] = (dp[u][0] * 2) % MOD;
		dp[u][1] = (dp[u][1] * 2) % MOD;
		dp[u][1] = (dp[u][1] - sc + MOD) % MOD;
		ll cl = (sl1 + sl2) % MOD;
		cl = (cl * mu(2, MOD - 2)) % MOD;
		ll sl = (sl1 - cl + MOD) % MOD;
		dp[u][0] = (dp[u][0] - sl + MOD) % MOD;
	}
	dp[u][0] ++;
	//cout << u << " " << dp[u][0] << " " << dp[u][1] << '\n';
}

int main() {
	fast;
	if(fopen(name".inp", "r")) {
		freopen(name".inp", "r", stdin);
		freopen(name".out", "w", stdout);
	}
	//int t; cin >> t; while (t --) sol();
	int O; cin >> O;
	cin >> n;
	for (int i = 2; i <= n; i++) {
		int p; cin >> p;
		adj[p].push_back(i);
	}
	dfs(1);
	cout << (dp[1][0] + dp[1][1] - 1 + MOD) % MOD;
}