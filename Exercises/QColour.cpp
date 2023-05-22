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
const ll nmax = 2e5;
const ll MOD = 1e9 + 7;
const ll base = 2309;

void fre() {
	string finp = NAME + ".inp";
	string fout = NAME + ".out";
	freopen(finp.c_str(), "r", stdin);
	freopen(fout.c_str(), "w", stdout);
}

int n, q, timer = 0, num[100003], tail[100003], c[100003], pos_it[100003];

vector < int > adj[100003];

ll it[400003];

void dfs(int u = 1, int e = 0) {
	num[u] = ++ timer;
	pos_it[timer] = u;
	for (auto v : adj[u]) {
		if (v == e) continue;
		dfs(v, u);
	}
	tail[u] = timer;
}

void build_tree(int node, int l, int r) {
	if (l == r) {
		it[node] = (1ll << c[pos_it[l]]);
		return ;
	}
	build_tree(node * 2, l, (l + r) / 2);
	build_tree(node * 2 + 1, (l + r) / 2 + 1, r);
	it[node] = (it[node * 2] | it[node * 2 + 1]);
}

void update(int node, int l, int r, int pos, int val) {
	if (pos < l || pos > r) return ;
	if (l == r) {
		it[node] = 0;
		it[node] = (1ll << val);
		return ;
	}
	int mid = (l + r) / 2;
	update(node * 2, l, mid, pos, val);
	update(node * 2 + 1, mid + 1, r, pos, val);
	it[node] = (it[node * 2] | it[node * 2 + 1]);
}

ll query(int node, int l, int r, int u, int v) {
	if (v < l || r < u) return -1;
	if (u <= l && r <= v) return it[node];
	int mid = (l + r) / 2;
	ll lnode = query(node * 2, l, mid, u, v);
	ll rnode = query(node * 2 + 1, mid + 1, r, u, v);
	if (lnode == -1) return rnode;
	if (rnode == -1) return lnode;
	return (rnode | lnode);	
}

bool getbit(ll x, ll pos) {
	return (x & (1ll << pos));
}

int main() {
	fast;
	cin >> n >> q;
	for (int i = 1; i <= n; i++) cin >> c[i];
	for (int i = 1; i < n; i++) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	dfs();
	build_tree(1, 1, n);
	while (q--) {
		int t;
		cin >> t;
		if (t == 1) {
			int u, new_c;
			cin >> u >> new_c;
			update(1, 1, n, num[u], new_c);
		}
		else {
			int u;
			cin >> u;
			ll tam = query(1, 1, n, num[u], tail[u]);
			ll dem = 0;
			for (int i = 0; i <= 60; i++) dem += getbit(tam, i);
			cout << dem << '\n';
		}
	}
}
