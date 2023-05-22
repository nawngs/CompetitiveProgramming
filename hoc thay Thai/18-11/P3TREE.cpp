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
const ld ESP = 1e-9;
const ll INF = 1e9 + 7;
const ll LINF = 1E18;
const ll nmax = 1e5;
const ll MOD = 1e9 + 7;
const ll base = 2309;

void fre() {
	string finp = NAME + ".inp";
	string fout = NAME + ".out";
	freopen(finp.c_str(), "r", stdin);
	freopen(fout.c_str(), "w", stdout);
}

int n, p[4], in[nmax + 3], out[nmax + 3], timer = 0, cnt[nmax + 3], it[4 * nmax + 3], par[nmax + 3];

ll res = 0;

vector < int > adj[nmax + 3];

void update(int node, int l, int r, int pos, int val) {
	if (pos < l || pos > r) return ;
	it[node] += val;
	if (l == r) 
		return ;
	int mid = (l + r) / 2;
	update(node * 2, l, mid, pos, val);
	update(node * 2 + 1, mid + 1, r, pos, val);
}

int query(int node, int l, int r, int u, int v) {
	if (v < l || r < u) return 0;
	if (u <= l && r <= v) return it[node];
	int mid = (l + r) / 2;
	return query(node * 2, l, mid, u, v) + query(node * 2 + 1, mid + 1, r, u, v);
}

void dfs(int u, int e) {
	in[u] = ++ timer;
	for (auto v : adj[u]) {
		if (v == e) continue;
		par[v] = u;
		dfs(v, u);
	}
	out[u] = timer;
}

void dfs(int u) {
	int bigger_than_u = 0, smaller_than_u = 0;
	int bigger_than_u_cur, smaller_than_u_cur;
	for (auto v : adj[u]) {
		if (v == par[u]) continue;
		dfs(v);
		bigger_than_u_cur = cnt[v];
		smaller_than_u_cur = (out[v] - in[v] + 1) - cnt[v];
		if (p[2] == 1) res += 1ll * bigger_than_u * bigger_than_u_cur;
		if (p[2] == 2) {
			res += 1ll * bigger_than_u * smaller_than_u_cur;
			res += 1ll * bigger_than_u_cur * smaller_than_u;
		}
		if (p[2] == 3) res += 1ll * smaller_than_u_cur * smaller_than_u;
		bigger_than_u += bigger_than_u_cur;
		smaller_than_u += smaller_than_u_cur;
	}
	int bigger_than_u_rem = n - u - bigger_than_u;
	int smaller_than_u_rem = u - 1 - smaller_than_u;
	if (p[2] == 1) res += 1ll * bigger_than_u_rem * bigger_than_u;
	if (p[2] == 2) {
		res += 1ll * bigger_than_u_rem * smaller_than_u;
		res += 1ll * smaller_than_u_rem * bigger_than_u;
	}
	if (p[2] == 3) res += 1ll * smaller_than_u_rem * smaller_than_u;
}

int main() {
	fast;
	//fre();
	cin >> n;
	for (int i = 1; i <= 3; i++)
		cin >> p[i];
	for (int i = 1; i < n; i++) {
		int u, v; cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	dfs(1, 0);
	for (int i = n; i >= 1; i--) {
		update(1, 1, n, in[i], 1);
		for (auto v : adj[i]) {
			if (v == par[i]) continue;
			cnt[v] = query(1, 1, n, in[v], out[v]);
		}
	}
	memset(it, 0, sizeof(it));
	dfs(1);
	cout << res;
}
