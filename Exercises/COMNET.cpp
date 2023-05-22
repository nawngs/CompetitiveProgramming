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

const string NAME = "comnet";
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

int n, m;

pii a[500001];

vector < int > adj[500001];

bool vs[500001];

void dfs(int u) {
	vs[u] = 1;
	for (auto v : adj[u]) {
		if (!vs[v]) dfs(v);
	}
}

bool check(int x) {
	for (int i = 1; i <= n; ++i) {
		adj[i].clear(); 
		vs[i] = false;
	}
	for (int i = 1; i <= x; ++i) adj[a[i].fi].push_back(a[i].se);
	dfs(1);
	return vs[n];
}

void sol() {
	cin >> n >> m;
	for (int i = 1; i <= m; ++i) cin >> a[i].fi >> a[i].se;
	int l = 1, r = m, mid, ans = -1;
	while (l <= r) {
		mid = (l + r) / 2;
		if (check(mid)) {
			ans = mid;
			r = mid - 1;
		}
		else l = mid + 1;
 	}
 	cout << ans;
}

int main() {
	fast;
	fre();
	int t = 1;
	//cin >> t;
	while (t --) sol();
}
