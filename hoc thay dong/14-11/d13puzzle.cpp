//#pragma GCC optimize ("O2")
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

int n, m, id = 0, V = 0, E = 0, scc = 0;

map < pair < int, int >, int > mp;

vector < pii > up, down, Left, Right;

vector < int > adj[1000003];

bool vs[1000003];

int add(int x, int y) {
	if (mp.find({x, y}) == mp.end()) {
		mp[{x, y}] = ++ id;
	}
	int u = mp[{x, y}];
	if (x == 0) up.push_back({y, u});
	if (y == 0) Left.push_back({x, u});
	if (x == n) down.push_back({y, u});
	if (y == n) Right.push_back({x, u});
	return u; 
}

void add_edge(int u, int v) {
	adj[u].push_back(v);
	adj[v].push_back(u);
}

void add_side(vector < pii > vec) {
	sort(vec.begin(), vec.end());
	vec.erase(unique(vec.begin(), vec.end()), vec.end());
	for (int i = 1; i < (int)vec.size(); i++) 
		add_edge(vec[i - 1].se, vec[i].se);
}

void dfs(int u) {
	vs[u] = 1; V++;
	for (auto v : adj[u]) {
		E ++;
		if (!vs[v]) 
			dfs(v);
	}
}

signed main() {
	fast;
	//fre();
	cin >> n >> m;
	add(0, 0);
	add(0, n);
	add(n, 0);
	add(n, n);
	for (int i = 1; i <= m; i++) {
		int x, y; cin >> x >> y;
		int a = add(x - 1, y - 1), b = add(x - 1, y), c = add(x, y - 1), d = add(x, y);
		add_edge(a, b);
		add_edge(a, c);
		add_edge(b, d);
		add_edge(c, d);
	}
	add_side(up); add_side(Left); add_side(down); add_side(Right);
	for (int i = 1; i <= id; i++) {
		sort(adj[i].begin(), adj[i].end());
		adj[i].erase(unique(adj[i].begin(), adj[i].end()), adj[i].end());
	}
	int res = 0;
	for (int i = 1; i <= id; i++) {
		if (!vs[i]) {
			E = V = 0;
			dfs(i);
			res += E / 2 - V + 1;
		}
	}
	cout << res - m;
}
