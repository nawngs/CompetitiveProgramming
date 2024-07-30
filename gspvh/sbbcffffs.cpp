#include <bits/stdc++.h>

#define name "sbbcffffs"
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
const int NMAX = 4e5;
const ll MOD = 1e9 + 7;
const ll BASE = 2309;

int n, k, m, in[NMAX + 3], low[NMAX + 3], scc = 0, ava[NMAX + 3], id[NMAX + 3], deg[NMAX + 3];

bool ok = 1;

vector < int > adj[NMAX + 3], G[NMAX + 3]; // n + 2 * k	

stack < int > st;

string a, b, c;

void dfs(int u) {
	// cout << u << '\n';
	in[u] = low[u] = ++ in[0];
	st.push(u);
	for (auto v : adj[u]) {
		if (id[v] != 0) continue;
		if (!in[v]) {
			dfs(v);
			low[u] = min(low[u], low[v]);
		}
		else low[u] = min(low[u], in[v]);
	}
	if (in[u] == low[u]) {
		ava[++ scc] = INF;
		int dem = 0;
		while (st.top() != u) {
			if (st.top() <= n) {
				dem ++;
				ava[scc] = st.top();
			}
			id[st.top()] = scc; st.pop();
		}
		if (st.top() <= n) {
			dem ++;
			ava[scc] = st.top();
		}
		id[st.top()] = scc; st.pop();
		if (dem > 2) ok = false;
		if (dem == 0) ava[scc] = -INF;
		// if (dem == 1) cout << 123 << " " << scc << " " << ava[scc] << '\n';
	}
}

int main() {
	fast;
	if(fopen(name".inp", "r")) {
		freopen(name".inp", "r", stdin);
		freopen(name".out", "w", stdout);
	}
	//int t; cin >> t; while (t --) sol();
	cin >> n >> k >> m;
	for(int i = 1; i <= k; i++) {
		adj[n + i].pb(n + k + i);
		// cout << "edges " << n + i << ": ";
		// cout << n + i << " " << n + k + i << '\n';
		int x; cin >> x;
		if (x <= n) {
			adj[n + i].pb(x);
			adj[x].pb(n + k + i);
			// cout << n + i << " " << x << '\n';
			// cout << x << " " << n + k + i << '\n';
		}
		else {
			adj[n + i].pb(x);
			adj[k + x].pb(n + k + i);
			// cout << n + i << " " << x << '\n';
			// cout << k + x << " " << n + k + i << '\n';
		}
		cin >> x;
		if (x <= n) {
			adj[n + i].pb(x);
			adj[x].pb(n + k + i);
			// cout << n + i << " " << x << '\n';
			// cout << x << " " << n + k + i << '\n';
		}
		else {
			adj[n + i].pb(x);
			adj[k + x].pb(n + k + i);
			// cout << n + i << " " << x << '\n';
			// cout << k + x << " " << n + k + i << '\n';
		}
	}
	for (int i = 1; i <= m; i++) {
		int x, y;
		// cout << "edges " << i << " " << '\n';
		cin >> a >> b >> c;
		if (a == "MIN") {
			x = stoi(b), y = stoi(c);
			adj[y].pb(x);
			// cout << y << " " << n + x << '\n';
		} 
		if (a == "MAX") {
			x = stoi(b), y = stoi(c);
			adj[x + k].pb(y);
			// cout << n + x + k << " " << y << '\n';
		}
		if (b == "<") {
			x = stoi(a), y = stoi(c);
			if (x > n) x += k;
			adj[x].pb(y);
			// cout << x << " " << y << '\n';
		}
		if (b == ">") {
			x = stoi(c), y = stoi(a);
			if (x > n) x += k;
			adj[x].pb(y);
			// cout << x << " " << y << '\n';
		}
	}
	for (int i = 1; i <= n + 2 * k; i++) if (!in[i]) dfs(i);
	if (!ok) {
		cout << -1 << '\n';
		return 0;
	}
	for (int i = 1; i <= n + 2 * k; i++) 
		for (auto v : adj[i]) if (id[i] != id[v]) {
			G[id[i]].pb(id[v]);
			deg[id[v]] ++;
		}
	priority_queue < pii, vector < pii >, greater < pii > > heap;
	for (int i = 1; i <= scc; i++) if (deg[i] == 0) heap.push({ava[i], i});
	while(heap.size()) {
		auto u = heap.top(); heap.pop();
		if (u.fi != -INF) cout << u.fi << " ";
		for (auto v : G[u.se]) {
			deg[v] --;
			if (!deg[v]) heap.push({ava[v], v});
		}
	}
}