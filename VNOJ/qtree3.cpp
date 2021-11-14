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

const string NAME = "";
const string NAME2 = "TEST";
const ll ESP = 1e-9;
const int INF = 1E9 + 7;
const ll nmax = 1e7;
const ll MOD = 1e9 + 7;

void fre() {
	string finp = NAME + ".inp";
	string fout = NAME + ".out";
	freopen(finp.c_str(), "r", stdin);
	freopen(fout.c_str(), "w", stdout);
}

//#######################################################################
// du lieu
int n, q, p[100005], cnt_child[100005], val[100005];

vector < int > adj[100005];

//#######################################################################
//dfs

void dfs(int u) {
	cnt_child[u] = 1;
	for (auto v : adj[u]) {
		if (v == p[u]) continue;
		p[v] = u;
		dfs(v);
		cnt_child[u] += cnt_child[v];
	}
}

//#######################################################################
// hld
int chain_head[100005], chain_ind[100005], pos_it[100005], nchain = 0, cnt = 0;

/*
chain_head[i] la vi tri dau tien cua chain thu i
chain_ind[i] la index chain cua i
pos_it[i] la vi tri cua i trong vay it
*/

void hld(int u) {
	if (chain_head[nchain] == 0) chain_head[nchain] = u;
	chain_ind[u] = nchain;
	pos_it[u] = ++cnt;
	val[cnt] = u;
	int max_v = -1;
	for (auto v : adj[u]) {
		if (v == p[u]) continue;
		if (max_v == -1 || cnt_child[v] > cnt_child[max_v]) max_v = v;
	}
	if (max_v != -1) hld(max_v);
	for (auto v : adj[u]) {
		if (v == p[u] || v == max_v) continue;
		nchain ++;
		hld(v);
	}
}
//#######################################################################
//it

int it[600005];

//#######################################################################
// update

void update_it(int node, int l, int r, int pos) {
	if (pos < l || pos > r) return ;
	if (l == r) {
		it[node] = it[node] == INF ?  pos : INF;
		return ;
	}
	int mid = (l + r) / 2;
	update_it(node * 2, l, mid, pos);
	update_it(node * 2 + 1, mid + 1, r, pos);
	it[node] = min(it[node * 2], it[node * 2 + 1]);
}

void update_tree(int u) {
	update_it(1, 1, n, pos_it[u]);
}

//#######################################################################
// query

int query_it(int node, int l, int r, int u, int v) {
	if (v < l || r < u) return  INF;
	if (u <= l && r <= v) return it[node];
	int mid = (l + r) / 2;
	return min(query_it(node * 2, l, mid, u, v), query_it(node * 2 + 1, mid + 1, r, u, v)); 
}

void query_tree(int u) {
	int ans = INF;
	int ind = chain_ind[u];
	while (1) {
		if (chain_head[ind] == 1) {
			ans = min(ans, query_it(1, 1, n, 1, pos_it[u]));
			break;
		}
		ans = min(ans, query_it(1, 1, n, pos_it[chain_head[ind]], pos_it[u]));
		u = p[chain_head[ind]];
		ind = chain_ind[u];
	}
	cout << (ans == INF ? -1 : val[ans]) << '\n';
}

void sol() {
	cin >> n >> q;
	for (int i = 1; i < n; i++) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	dfs(1);
	hld(1);
	//for (int i = 1; i <= n; i++) cout << val[i] << ' ';
	//cout << '\n';
	for (int i = 1; i <= 6 * n; i++) it[i] = INF;
	while (q --) {
		int x, y;
		cin >> x >> y;
		if (x == 0) update_tree(y);
		else query_tree(y);
	}
}

int main() {
	fast;
	//fre();
	int t = 1;
	//cin >> t;
	while (t --) sol();
}
