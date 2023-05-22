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

const string NAME = "rooks";
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

int n, m, src, snk, res[53];

bool check[53][53];

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

vector < int > temp;

void init(int n) {
	NumNode = n;
	adj.assign(NumNode + 7, vector<int>());
    dist.assign(NumNode + 7, 0);
    trc.assign(NumNode + 7, -1);
    InQueue.assign(NumNode + 7, false);
}

int addEdge(int from, int to, int capa, long long cost) {
    adj[from].push_back(edges.size());
    edges.push_back(Edge(from, to, capa, cost));
    adj[to].push_back(edges.size());
    edges.push_back(Edge(to, from, 0, -cost));
    return edges.size() - 2;
}

bool Ford_Bellman(int s, int t) {
	for (int i = 1; i <= NumNode; i++) {
		dist[i] = INF;
		trc[i] = -1;
		InQueue[i] = false;
	}
	queue < int > q;
	dist[s] = 0;
	q.push(s);
	InQueue[s] = 1;
	while (q.size()) {
		int u = q.front();
		q.pop(); 
		InQueue[u] = false;
		for (auto id : adj[u]) {
			if (edges[id].capa > edges[id].flow) {
				int v = edges[id].to;
				if (dist[v] > dist[u] + edges[id].cost) {
					dist[v] = dist[u] + edges[id].cost;
					trc[v] = id;
					if (!InQueue[v]) {
						q.push(v);
						InQueue[v] = 1;
					}
				}
			}
		}
	}
	return dist[t] != INF;
}

pii get_flow() {
	int flow = 0;
	int cost = 0;
	while (Ford_Bellman(src, snk)) {
		int delta = INF;
		for (int u = snk; u != src; u = edges[trc[u]].from) delta = min(delta, edges[trc[u]].capa - edges[trc[u]].flow);
		for (int u = snk; u != src; u = edges[trc[u]].from) {
			edges[trc[u]].flow += delta;
			edges[trc[u] ^ 1].flow -= delta;
		}
		flow += delta;
		cost += delta * dist[snk];
	}
	return {flow, cost};
}


int main() {
	fast;
	fre();
	cin >> n >> m;
	src = 2 * (n + m) + 1;
 	snk = src + 1;
	init(snk);
	for (int i = 1; i <= n; i++) {
		addEdge(src, i, 1, 0);
		addEdge(n + i, snk, 1, 0);
	}
	int sumc = 0;
	for (int ily = 1; ily <= m; ily++) {
		int b, l, t, r, c;
		cin >> b >> l >> t >> r >> c;
		sumc += c;
		for (int i = b; i <= t; i++) {
			for (int j = l; j <= r; j++) {
				check[i][j] = 1;
				addEdge(i, 2 * n + (ily - 1) * 2 + 1, 1, 0);
				addEdge(2 * n + ily * 2, n + j, 1, 0);
			}
		}
		addEdge(2 * n + (ily - 1) * 2 + 1, 2 * n + ily * 2, c, -1);
	}
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++) if (!check[i][j]) addEdge(i, n + j, 1, 0);
	auto tam = get_flow();
	if (tam.fi == n && abs(tam.se) == sumc) {
		cout << "YES" << '\n';
		for (int i = 1; i <= n; i++) {
			for (auto id : adj[i]) {
				if (edges[id].to <= 2 * n && edges[id].flow == 1) {
					res[i] = edges[id].to - n;
					break;
				}
			}
		}
		for (int ily = 1; ily <= m; ily++) {
			int left = 2 * n + ily * 2 - 1;
			int right = left + 1;
			temp.clear();
			for (auto id : adj[right]) 
				if (edges[id].to <= 2 * n && edges[id].flow == 1) temp.push_back(edges[id].to - n);
			for (auto id : adj[left]) 
				if (edges[id].to <= n) {
					int tam = id ^ 1;
					if (edges[tam].flow == 1) {
						res[edges[tam].from] = temp.back();
						temp.pop_back();
					}
				}
		}
		for (int i = 1; i <= n; i++) cout << res[i] << " ";
	}
	else cout << "NO" << '\n';
}
