#pragma GCC optimize ("O3")
#include <bits/stdc++.h>

#define ll long long
#define ld long double
#define fi first 
#define se second
#define pll pair < ll, ll >
#define pii pair < int, int >
#define piii pair < int, pii >
#define fastflow ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define FOR(i, a, b) for (int i = a; i <= b; i++)
#define ROF(i, a, b) for (int i = a; i >= b; i--)

using namespace std;

const ll ESP = 1e-9;
const ll INF = 1e18;
const ll nmax = 1e7;
const ll MOD = 1e9 + 7;

int n, m, l, scc, res[200005];

vector < int > adj[200005], adj2[200005];

bool vs[200005];

piii val[200005];

void readINP() {
	cin >> n >> m >> l;
	FOR(i, 1, m) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	FOR(i, 1, l) {
		int u, v;
		cin >> u >> v;
		adj2[u].push_back(v);
		adj2[v].push_back(u);
	}
}

void dfs(int sub, int u, int e, vector < int > adj[]) {
	vs[u] = true;
	if (sub == 1) val[u].fi = scc;
	else val[u].se.fi = scc;
	for (auto v : adj[u]) {
		if (vs[v]) continue;
		dfs(sub, v, u, adj);
	}
}

void build(int sub, vector < int > adj[]) {
	memset(vs, false, sizeof(vs));
	scc = 0;
	for (int i = 1; i <= n; i++) {
		if (!vs[i]) {
			scc ++;
			dfs(sub, i, 0, adj);
		}
	}
}

int main() {
	fastflow;
	readINP();

	build(1, adj);
	build(2, adj2);

	for (int i = 1; i <= n; i++) val[i].se.se = i;
	sort(val + 1, val + n + 1, [](piii &x, piii &y) {
		return (x.fi < y.fi) || (x.fi == y.fi && x.se.fi < y.se.fi);
	});
	val[n + 1] = {0, {0, 0}};
	queue < int > que;
	que.push(val[1].se.se);
	for (int i = 2; i <= n + 1; i++) {
		if (val[i].fi == val[i - 1].fi && val[i - 1].se.fi == val[i].se.fi) {
			que.push(val[i].se.se);
		}
		else {
			int cnt = que.size();
			while (que.size()) {
				res[que.front()] = cnt;
				que.pop();
			}
			que.push(val[i].se.se);
		}
	}
	for (int i = 1; i <= n; i++) cout << res[i] << ' ';
}