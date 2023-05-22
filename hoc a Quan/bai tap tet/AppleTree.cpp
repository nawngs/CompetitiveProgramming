#include <bits/stdc++.h>

#define int ll
#define name ""
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
const ll MOD = 1e9 + 7;
const ll BASE = 2309;

ll n, a[100003], dp[100003], cnt[100003];

vector < int > adj[100003];

ll mul(ll a, ll b) {
	if (a == 0 || b == 0) return 0;
	if (LINF / a < b) return LINF;
	return a * b;
}

void dfs(int u, int e) {
	ll Lcm = 1, val = LINF, dem = 0;
	for (auto v : adj[u]) {
		if (v == e) continue;
		dfs(v, u);
		dem ++;
		ll temp = __gcd(Lcm, cnt[v]);
		Lcm /= temp; Lcm = mul(Lcm, cnt[v]);
		val = min(val, dp[v]);
	}
	if (dem == 0) dp[u] = a[u], cnt[u] = 1;
	else {
		cnt[u] = mul(Lcm, dem);
		dp[u] = val / Lcm * Lcm * dem;
	}
	//cout << u << " " << dp[u] << " " << cnt[u] << '\n';
}

main() {
	fast;
	if(fopen(name".inp", "r")) {
		freopen(name".inp", "r", stdin);
		freopen(name".out", "w", stdout);
	}
	//int t; cin >> t; while (t --) sol();
	cin >> n;
	ll s = 0;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		s += a[i];
	}
	for (int i = 1; i < n; i++) {
		int u, v; cin >> u >> v;
		adj[u].push_back(v); adj[v].push_back(u);
	}
	dfs(1, 0);
	cout << s - dp[1];
}