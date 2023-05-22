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
const ll ESP = 1e-9;
const ll INF = 1e9 + 7;
const ll nmax = 2e5;
const ll MOD = 1e9 + 7;
const ll base = 2309;

void fre() {
	string finp = NAME + ".inp";
	string fout = NAME + ".out";
	freopen(finp.c_str(), "r", stdin);
	freopen(fout.c_str(), "w", stdout);
}

struct Edge {
	int from, to, capa, flow;
	Edge (int _from = 0, int _to = 0, int _capa = 0) {
		from = _from;
		to = _to;
		capa = _capa;
		flow = 0;
	}
};

vector < Edge > edges;

int n, m, a[103], b[103], EdgeId[213][213], trace[213];

bool vs[213];

vector < int > adj[213];

void add_edge(int u, int v, int c) {
	adj[u].push_back(edges.size());
	edges.push_back(Edge(u, v, c));
	adj[v].push_back(edges.size());
	edges.push_back(Edge(v, u, 0));
	EdgeId[u][v] = adj[u].back();
}

bool find(int s, int t) {
	memset(vs, false, sizeof(vs));
	queue < int > q;
	vs[s] = 1;
	q.push(s);
	while (q.size()) {
		int u = q.front();
		q.pop();
		for (int id : adj[u]) {
			if (edges[id].flow < edges[id].capa && !vs[edges[id].to]) {
				vs[edges[id].to] = 1;
				trace[edges[id].to] = id;
				q.push(edges[id].to);
			}
		}
	}
	return vs[t];
}

int max_flow(int s, int t) {
	int flow = 0;
	while (find(s, t)) {
		int delta = INF;
		for (int u = t; u != s; u = edges[trace[u]].from) {
			delta = min(delta, edges[trace[u]].capa - edges[trace[u]].flow);
		}
		for (int u = t; u != s; u = edges[trace[u]].from) {
			edges[trace[u]].flow += delta;
			edges[trace[u] ^ 1].flow -= delta;
		}
		flow += delta;
	}
	return flow;
}

int main() {
	fast;
	cin >> n >> m;
	int suma = 0, sumb = 0;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		suma += a[i];
	}
	for (int i = 1; i <= n; i++) {
		cin >> b[i];
		sumb += b[i];
	}
	if (suma != sumb) {
		cout << "NO" << '\n';
		return 0;	
	}
	int src = 2 * n + 1;
	int snk = 2 * n + 2;
	for (int i = 1; i <= n; i++) add_edge(src, i, a[i]);
	for (int i = 1; i <= n; i++) add_edge(n + i, snk, b[i]);
	for (int i = 1; i <= n; i++) add_edge(i, i + n, INF);
	for (int i = 1; i <= m; i++) {
		int u, v;
		cin >> u >> v;
		add_edge(u, v + n, INF);
		add_edge(v, u + n, INF);
	}
	int res = max_flow(src, snk);
	if (res < suma) {
		cout << "NO" << '\n';
		return 0;	
	}
	cout << "YES" << '\n';
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) 
			cout << (EdgeId[i][n + j] == 0 ? 0 : edges[EdgeId[i][n + j]].flow) << ' ';

			//cout << i << " " << j << " " << EdgeId[i][n + j] << '\n';
		cout << '\n';
	}
}
