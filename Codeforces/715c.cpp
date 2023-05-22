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

int n, m, cnt_child[100003];

ll mu[100003], inv[100003];

ll res = 0;

bool used[100003];

vector < pii > adj[100003];

unordered_map < int, ll > cnt;

long long get_inv(ll a, ll b){
 	return 1 < a ? (b - get_inv(b % a, a) * b / a) : 1;
}

int dfs(int u, int e = 0) {
	cnt_child[u] = 1;
	for (auto x : adj[u]) {
		int v = x.fi;
		if (v == e || used[v]) continue;
		cnt_child[u] += dfs(v, u);
	}
	return cnt_child[u];
}

int get_centroid(int u, int sze, int e = 0) {
	for (auto x : adj[u]) {
		int v = x.fi;
		if (used[v] || v == e) continue;
		if (cnt_child[v] * 2 > sze) return get_centroid(v, sze, u);
	}
	return u;
}

void dfs2(int u, int e, int len, ll val) {
	cnt[val] ++;
	for (auto x : adj[u]) {
		int v = x.fi;
		int c = x.se;
		if (v == e || used[v]) continue ;
		dfs2(v, u, len + 1, (c * mu[len] + val) % m);
	}
}

void dfs3(int u, int e, int len, ll val, ll val_rev, bool first_time) {
	if (first_time) res += 1ll * (val == 0) + 1ll * (val_rev == 0);
	int x = ((m - val) * inv[len] + m) % m;
	res += cnt[x];
	for (auto x : adj[u]) {
		int v = x.fi;
		int c = x.se;
		if (v == e || used[v]) continue ;
		dfs3(v, u, len + 1, (val * 10 + c) % m, (c * mu[len] + val_rev) % m, first_time);
	} 
}

void centroid(int u = 1) {
	int C = get_centroid(u, dfs(u));
	used[C] = 1;
	cnt.clear();
	for (auto v : adj[C]) {
		if (!used[v.fi]) {
			v.se %= m;
			dfs3(v.fi, C, 1, v.se, v.se, 1);
			dfs2(v.fi, C, 1, v.se);
		}
	}
	cnt.clear();
	reverse(adj[C].begin(), adj[C].end());
	for (auto v : adj[C]) {
		if (!used[v.fi]) {
			v.se %= m;
			dfs3(v.fi, C, 1, v.se, v.se, 0);
			dfs2(v.fi, C, 1, v.se);
		}
	}
	for (auto v : adj[C]) 
		if (!used[v.fi]) centroid(v.fi);
	
}

main() {
	fast;
	cin >> n >> m;
	mu[0] = 1, inv[0] = 1;;
	mu[1] = 10, inv[1] = get_inv(10, m);
	for (int i = 2; i <= n; i++) {
		mu[i] = (mu[i - 1] * 10) % m;
		inv[i] = (inv[i - 1] * inv[1]) % m;
	}
	for (int i = 1; i < n; i++) {
		int u, v, c;
		cin >> u >> v >> c;
		u ++;
		v ++;
		adj[u].push_back({v, c});
		adj[v].push_back({u, c}); 
	}
	centroid();
	cout << res;
}
