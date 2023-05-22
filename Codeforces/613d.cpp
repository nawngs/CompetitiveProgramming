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

int n, h[100003], p[100003][20], in[100003], out[100003], timer = 0;

vector < int > adj[100003];

bool used[100003];

void dfs(int u, int e) {
	in[u] = ++ timer;
	h[u] = h[e] + 1;
	for (auto v : adj[u]) {
		if (v == e) continue;
		p[v][0] = u;
		dfs(v, u);
	}
	out[u] = timer;
}

int LCA(int u, int v) {
	if (h[u] > h[v]) swap(u, v);
	if (h[u] != h[v]) {
		for (int j = 18; j >= 0; j--) {
			if (h[p[v][j]] >= h[u]) {
				v = p[v][j];
			}
		}
	}
	//cout << u << " " << v << '\n';
	if (u == v) return u;
	for (int j = 18; j >= 0; j--) {
		if (p[u][j] != 0 && p[v][j] != p[u][j]) {
			u = p[u][j];
			v = p[v][j];
		}
	}
	return p[u][0];
}

pii calc(int u) {
	pii res = {0, 0};
	vector < int > path;
	for (auto v : adj[u]) {
		pii temp = calc(v);
		res.fi += temp.fi;
		res.se += temp.se;
	}
	if (!used[u]) {
		if (res.se <= 1) 
			return res;
		else 
			return {res.fi + 1, 0};
	} 
	else return {res.fi + res.se, 1};
}

void solve() {
	int k; cin >> k;
	vector < int > vertices;
	vertices.resize(k);
	for (auto &x : vertices) {
		cin >> x;
		used[x] = 1;
	}
	for (auto x : vertices) {
		if (used[p[x][0]]) {
			for (auto x : vertices) used[x] = 0;
			cout << -1 << '\n';
			return ;
		}
	}
	sort(vertices.begin(), vertices.end(), [&](int &x, int &y) {
		return in[x] < in[y];
	});
	for (int i = 1; i < k; i++) 
		vertices.push_back(LCA(vertices[i], vertices[i - 1]));
	sort(vertices.begin(), vertices.end(), [&](int &x, int &y) {
		return in[x] < in[y];
	});
	vertices.erase(unique(vertices.begin(), vertices.end()), vertices.end());
	stack < int > st;
	for (auto u : vertices) {
		adj[u].clear();
		while (st.size() && out[st.top()] < in[u]) 
			st.pop();
		if (st.size()) adj[st.top()].push_back(u);
		st.push(u);
	}
	cout << calc(vertices[0]).fi << '\n';
	for (auto x : vertices) used[x] = 0;
}

int main() {
	fast;
	//fre();
	cin >> n;
	for (int i = 1; i < n; i++) {
		int u, v; cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	dfs(1, 0);
	for (int j = 1; j <= 18; j++) 
		for (int i = 1; i <= n; i++) p[i][j] = p[p[i][j - 1]][j - 1];
	int q; cin >> q;
	while (q--)
		solve();
}
