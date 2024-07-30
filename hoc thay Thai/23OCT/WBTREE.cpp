#include <bits/stdc++.h>

#define name ""
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

using namespace std;

const ld EPS = 1e-9;
const int INF = 1e9 + 7;
const ll LINF = 1E18;
const int NMAX = 2e5;
const ll MOD = 1e9 + 7;
const ll BASE = 2309;

int n, q, cnt[NMAX + 3], nchain = 0, cid[NMAX + 3], chead[NMAX + 3], in[NMAX + 3], pos[NMAX + 3], timer = 0, color[NMAX + 3], par[NMAX + 3];

string s;

vector < int > adj[NMAX + 3];

int dfs(int u) {
	cnt[u] = 1;
	for (auto v : adj[u]) cnt[u] += dfs(v);
	return cnt[u];
}

void hld(int u) {
	in[u] = ++ timer;
	pos[timer] = u;
	cid[u] = nchain;
	if (!chead[nchain]) chead[nchain] = u;
	int maxv = -1;
	for (auto v : adj[u]) if (maxv == -1 || cnt[maxv] < cnt[v]) maxv = v;
	if (maxv != -1) hld(maxv);
	for (auto v : adj[u]) if (v != maxv) {
		nchain ++;
		hld(v);
	}
}

struct Node {
	int cntd[2], dem;
	Node() {
		dem = 0;
		for (int i = 0; i < 2; i++) cntd[i] = 0;
	}
} it[6 * NMAX + 3];

void update(int node, int l, int r) {
	if ((it[node].cntd[0] != 0 || it[node].cntd[1] != 0) && l != r) {
		for (int i = 0; i < 2; i++) 
			it[node * 2].cntd[i] += it[node].cntd[i], it[node * 2 + 1].cntd[i] += it[node].cntd[i];
		it[node].cntd[0] = it[node].cntd[1] = 0;
	}
}

void build(int node, int l, int r) {
	if (l == r) {
		int i = pos[l]; it[node].dem = color[i];
		return ;
	}
	build(lnode); build(rnode);
	it[node].dem = it[node * 2].dem + it[node * 2 + 1].dem;
}

void update_color(int node, int l, int r, int u) {
	update(node, l, r);
	if (l == r) {
		int i = pos[l]; color[i] = color[i] ^ 1;
		it[node].dem = color[i];
		return ;
	}
	if (u <= (l + r) / 2) update_color(lnode, u);
	else update_color(rnode, u);
	it[node].dem = it[node * 2].dem + it[node * 2 + 1].dem;
}

int query_color(int node, int l, int r, int u, int v) {
	update(node, l, r);
	if (v < l || r < u) return 0;
	if (u <= l && r <= v) return it[node].dem;
	return query_color(lnode, u, v) + query_color(rnode, u, v);
}

pii query(int node, int l, int r, int u) {
	update(node, l, r);
	if (l == r) 
		return {it[node].cntd[0], it[node].cntd[1]};
	if (u <= (l + r) / 2) return query(lnode, u);
	else return query(rnode, u);
}

void update(int node, int l, int r, int u, int v, pii val) {
	update(node, l, r);
	if (v < l || r < u) return ;
	if (u <= l && r <= v) {
		it[node].cntd[0] += val.fi, it[node].cntd[1] += val.se;
		update(node, l, r);
		return ;
	}
	update(lnode, u, v, val); update(rnode, u, v, val);
}

void change(int u, int sign) {
	pii temp = query(1, 1, n, in[u]);
	if (color[u] == 0) temp.fi ++, temp.se = 0;
	else temp.fi = 0, temp.se ++;
	temp.fi *= sign, temp.se *= sign;
	int co = color[u];
	u = par[u];
	int id = cid[u];
	while (u) {
		int head = chead[id];
		if (query_color(1, 1, n, in[head], in[u]) == (in[u] - in[head] + 1) * co) {
			update(1, 1, n, in[head], in[u], temp);
			u = par[head], id = cid[u];
		}
		else {
			int l = in[head], r = in[u], mid, ans;
			while (l <= r) {
				mid = (l + r) / 2;
				if (query_color(1, 1, n, mid, in[u]) != (in[u] - mid + 1) * co) {
					ans = mid;
					l = mid + 1;
				}
				else r = mid - 1;
			}
			update(1, 1, n, ans, in[u], temp);
			break;
		}
	}
}

int get(int u) {
	int id = cid[u];
	int co = color[u];
	while (u) {
		int head = chead[id];
		if (query_color(1, 1, n, in[head], in[u]) == (in[u] - in[head] + 1) * co) {
			if (head == 1 || color[par[head]] != co) {
				pii temp = query(1, 1, n, in[head]);
				if (co == 0) return temp.fi + 1;
				else return temp.se + 1;
			}
			u = par[head]; id = cid[u];
		}
		else {
			int l = in[head], r = in[u], mid, ans;
			while (l <= r) {
				mid = (l + r) / 2;
				if (query_color(1, 1, n, mid, in[u]) == (in[u] - mid + 1) * co) {
					ans = mid;
					r = mid - 1;
				}
				else l = mid + 1;
			}
			pii temp = query(1, 1, n, ans);
			if (co == 0) return temp.fi + 1;
			else return temp.se + 1;
		}
	}
	assert(0);
}

int main() {
	fast;
	if(fopen(name".inp", "r")) {
		freopen(name".inp", "r", stdin);
		freopen(name".out", "w", stdout);
	}
	//int t; cin >> t; while (t --) sol();
	cin >> n >> q >> s;
	s = ' ' + s;
	for (int i = 1; i <= n; i++) color[i] = s[i] - '0';
	for (int i = 2; i <= n; i++) {
		cin >> par[i];
		adj[par[i]].pb(i);
	}
	dfs(1); hld(1);
	build(1, 1, n);
	for (int i = timer; i > 1; i--) {
		int updp = in[par[i]];
		pii temp = query(1, 1, n, in[i]);
		if (color[i] == 0) temp.fi ++, temp.se = 0;
		else temp.fi = 0, temp.se++;
		update(1, 1, n, updp, updp, temp);
	}
	while (q--) {
		int t, u; cin >> t >> u;
		if (t == 1) {
			change(u, -1);
			update_color(1, 1, n, in[u]);
			change(u, 1);
		}
		else cout << get(u) << '\n';
	}
}