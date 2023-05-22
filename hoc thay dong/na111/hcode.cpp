#include <bits/stdc++.h>

#define name "hcode"
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
const int BLOCK_SIZE = 150;

struct Edge {
	int u, v;
	char t;
} a[400003];

int n, m, k, window[40003], color[40003], dp[40003], dem = 0;

bool vs[40003];

vector < int > adj[40003], comp;

vector < pii > same;

void dfs(int u) {
	dem ++;
	vs[u] = 1;
	for (auto v : adj[u]) {
		//if (color[v] != -1 && color[v] != color[u] &&  color[u] != -1) cout << color[u] << " " << color[v] << '\n';
		if (vs[v]) continue;
		color[v] = color[u];
		dfs(v);
	}
}

bool check(int x) {
	for (int i = 1; i <= n; i++) {
		adj[i].clear();
		dp[i] = 0;
		color[i] = -1;
		vs[i] = 0;
	}
	for (int i = 1; i <= x; i++) {
		if (a[i].t == '=') 
			adj[a[i].u].push_back(a[i].v), adj[a[i].v].push_back(a[i].u);
		else {
			if (a[i].t == '>') color[a[i].u] = 1;
			else color[a[i].u] = 0;
			color[a[i].v] = 1 - color[a[i].u];
		}
	}
	int rem = k;
	for (int i = 1; i <= n; i++) {
		if (color[i] != -1 && !vs[i]) {
			dem = 0; dfs(i);
			if (color[i] == 0) rem -= dem;
		}
	}
	comp.clear();
	for (int i = 1; i <= n; i++) {
		if (color[i] == -1 && !vs[i]) {
			dem = 0; dfs(i);
			comp.push_back(dem);
		}
	}
	if (comp.empty()) return rem == 0;
	same.clear();
	sort(comp.begin(), comp.end());
	int pre = comp[0], cnt = 1;
	for (int i = 1; i < sz(comp); i++) {
		if (pre == comp[i]) cnt ++;
		else {
			same.push_back({pre, cnt});
			cnt = 1;
			pre = comp[i];
		}
	}
	same.push_back({pre, cnt});
	dp[0] = 1;
	for (int h = 0; h < sz(same); h++) {
		for (int i = 0; i < same[h].fi; i++) window[i] = 0;
		for (int i = 1; i <= rem; i++) {
			if (i >= same[h].fi) window[i % same[h].fi] += dp[i - same[h].fi];
			if (i - same[h].fi * same[h].se >= 0) window[i % same[h].fi] -= dp[i - same[h].fi * same[h].se];
		}
		for (int i = rem; i >= 1; i--) {
			if (window[i % same[h].fi] > 0) dp[i] = 2;
			if (i - same[h].fi * same[h].se >= 0) dp[i] += dp[i - same[h].fi * same[h].se];
			window[i % same[h].fi] -= dp[i - same[h].fi];
			if (i - same[h].fi * same[h].se >= 0) window[i % same[h].fi] += dp[i - same[h].fi * same[h].se];
			dp[i] = min(dp[i], 2);
		}
		//cout << same[h].fi << " " << same[h].se << " " << dp[rem] << '\n';
		if (dp[rem] > 1) return false;
	}
	return dp[rem] == 1;
}

void sol() {
	cin >> n >> m >> k;
	for (int i = 1; i <= m; i++) 
		cin >> a[i].u >> a[i].t >> a[i].v;
	int l = 0, r = m, mid, ans = -1;
	while (l <= r) {
		mid = (l + r) / 2;
		if (check(mid)) {
			ans = mid;
			r = mid - 1;
		}
		else l = mid + 1;
 	}
 	cout << ans << '\n';
}

int main() {
	fast;
	if(fopen(name".inp", "r")) {
		freopen(name".inp", "r", stdin);
		freopen(name".out", "w", stdout);
	}
	int t; cin >> t; while (t --) sol();
}