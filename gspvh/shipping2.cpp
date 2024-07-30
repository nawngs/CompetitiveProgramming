#include <bits/stdc++.h>

#define name "shipping"
#define ll long long
#define ld long double
#define fi first 
#define se second
#define pll pair < ll, ll >
#define pii pair < int, int >
#define piii pair < pii, int >
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
const int NMAX = 125000;
const int Q = 250000;
const ll MOD = 1e9 + 7;
const ll BASE = 2309;
const int LG = 17;

int n, m, k, d[11][NMAX + 3], low[Q + 3], high[Q + 3], res[Q + 3], nq;

piii shop[NMAX + 3];

pll buy[Q + 3];

vector < int > adj[NMAX + 3];

vector < pii > temp;

vector < int > q[11];

vector < int > dis[11][NMAX + 3]; // fi c se p

void bfs(int st) {
	for (int i = 1; i <= n; i++) d[st][i] = INF;
	d[st][st] = 0;
	queue < int > que;
	que.push(st);
	while (que.size()) {
		int u = que.front(); que.pop();
		for (auto v : adj[u]) if (d[st][v] == INF) {
			d[st][v] = d[st][u] + 1;
			que.push(v);
		}
	}
}

pll merge(const pll &x, const pll &y) {
	pll res;
	res.fi = x.fi + y.fi; res.se = x.se + y.se;
	return res;
}

struct BIT {
	int n;
	pll bit[NMAX + 3];	
	void init(int _) {
		n = _;
		for (int i = 1; i <= n; i++) bit[i] = {0, 0};
	}
	void update(int u, pll x) {
		while (u <= n) {
			bit[u] = merge(bit[u], x);
			u += (u & (-u));
		}
	}
	int walk(int cnt) {
		int cur = 0, pos = 0;
		for (int i = LG; i >= 0; i--) {
			if ((pos + (1 << i) < n) && (cur + bit[pos + (1 << i)].fi < cnt)) {
				pos += (1 << i);
				cur += bit[pos].fi;
			}
		}
		return pos + 1;
	}
	pll get(int u) {
		pll res = {0, 0};
		while (u) {
			res = merge(res, bit[u]);
			u -= (u & (-u));
		}
		return res;
	}
} tree;



void solve(int t) {
	for(auto x : q[t]) {
		low[x] = 0; 
		high[x] = m;
		res[x] = -1;
	}
	while (1) {
		bool ok = false;
		temp.clear();
		for (auto x : q[t]) {
			if (low[x] > high[x]) continue;
			temp.pb({(low[x] + high[x]) / 2, x});
		}
		sort(temp.begin(), temp.end(), greater < pii >());
		tree.init(k);
		for (int len = 0; len <= m; len++) {
			for (auto x : dis[t][len]) {
				int u = shop[x].se, c, p; tie(p, c) = shop[x].fi;
				tree.update(x, {1ll * c, 1ll * c * 1ll * p});
			}
			while (temp.size() && temp.back().fi == len) {
				int id = temp.back().se; temp.pop_back(); ok = 1;
				if (tree.get(k).fi < buy[id].fi) {
					low[id] = len + 1;
					continue;
				}
				int pos = tree.walk(buy[id].fi);
				pll val = tree.get(pos);
				//cout << len << " " << val.fi << " " << val.se << '\n';
				val.se -= (val.fi - buy[id].fi) * 1ll * shop[pos].fi.fi;
				if (val.se <= buy[id].se) {
					res[id] = len;
					high[id] = len - 1;
				}
				else low[id] = len + 1;
			}
		}
		if (!ok) break;
	}
}

int main() {
	fast;
	if(fopen(name".inp", "r")) {
		freopen(name".inp", "r", stdin);
		freopen(name".out", "w", stdout);
	}
	//int t; cin >> t; while (t --) sol();
	cin >> n >> m;
	for (int i = 1; i <= m; i++) {
		int u, v; cin >> u >> v;
		adj[u].pb(v); adj[v].pb(u);
	}
	for (int i = 1; i <= min(10, n); i++) bfs(i);
	cin >> k;
	for (int i = 1; i <= k; i++) 
		cin >> shop[i].se >> shop[i].fi.se >> shop[i].fi.fi;
	sort(shop + 1, shop + k + 1);
	for (int i = 1; i <= k; i++) {
		for (int j = 1; j <= min(10, n); j++) if (d[j][shop[i].se] != INF) 
			dis[j][d[j][shop[i].se]].pb(i);
	}
	cin >> nq;
	for (int i = 1; i <= nq; i++) {
		int u; cin >> u >> buy[i].fi >> buy[i].se;
		q[u].pb(i);
	}
	for (int t = 1; t <= min(10, n); t++) solve(t);
	for (int i = 1; i <= nq; i++) cout << res[i] << " ";
}