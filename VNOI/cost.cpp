#pragma GCC optimize ("O2")
#include <bits/stdc++.h>

#define int ll
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

int n, m, src, snk;

struct Edge {
	int from, to, flow, capa, cost;
	Edge(int _from = 0, int _to = 0, int _capa = 0, long long _cost = 0) {
       	from = _from; to = _to; flow = 0; capa = _capa; cost = _cost;
   	}
};

int NumNode;

vector < vector < int > > adj;

vector < Edge > edges;

vector < int > dist, trc;

vector < bool > InQueue;

void init(int x) {
	NumNode = x;
	adj.resize(NumNode + 5, vector < int >());
	dist.resize(NumNode + 5);
	trc.resize(NumNode + 5);
	InQueue.resize(NumNode + 5);
}

void addEdge(int from, int to, int cap, int cost) {
	adj[from].push_back(edges.size());
	edges.push_back(Edge(from, to, cap, cost));
	adj[to].push_back(edges.size());
	edges.push_back(Edge(to, from, 0, -cost));
}

bool check(int s, int t) {
	for (int i = 1; i <= NumNode; i++) {
		dist[i] = INF;
		trc[i] = 0;
		InQueue[i] = false;
	}
	dist[s] = 0;
	InQueue[s] = 1;
	queue < int > que;
	que.push(s);
	while (que.size()) {
		auto u = que.front(); que.pop();
		InQueue[u] = false;
		for (auto id : adj[u]) {
			if (edges[id].capa > edges[id].flow) {
				int v = edges[id].to;
				if (dist[v] > dist[u] + edges[id].cost) {
					dist[v] = dist[u] + edges[id].cost;
					trc[v] = id;
					if (!InQueue[v]) que.push(v);
					InQueue[v] = 1;
				}
			}
		}
	}
	return (dist[t] != INF);
}

pii get_flow() {
	pii res = {0, 0};
	while (check(src, snk)) {
		int delta = INF;
		for (int u = snk; u != src; u = edges[trc[u]].from) 
			delta = min(delta, edges[trc[u]].capa - edges[trc[u]].flow);
		for (int u = snk; u != src; u = edges[trc[u]].from) {
			edges[trc[u]].flow += delta;
			edges[trc[u] ^ 1].flow -= delta;
		}
		res.fi += delta;
		res.se += delta * dist[snk];
	}
	return res;
}

int a[52];

string s[52];

signed main() {
	//fast;
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = 1; i <= n; i++) cin >> s[i];
	m = s[1].size();
	src = m + n + (m * n) + 1;
	snk = src + 1;
	init(snk);
	for (int i = 1; i <= m; i++) addEdge(src, i, 1, 0);
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++) if (s[i][j - 1] == 'Y') addEdge(j, i + m, 1, 0);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			addEdge(i + m, n + m + (i - 1) * m + j, 1, a[i] * (j * j) - (a[i] * (j - 1) * (j - 1)));
			addEdge(n + m + (i - 1) * m + j, snk, 1, 0);
		}
	}
	pii tam = get_flow();
	cout << (tam.fi == m ? tam.se : -1);
}
