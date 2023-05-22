#pragma GCC optimize ("O2")
#include <bits/stdc++.h>

#define ll long long
#define ld long double
#define fi first 
#define se second
#define pll pair < ll, ll >
#define pii pair < int, int >
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define segg hotel
#define hotel place

using namespace std;

const string NAME = "";
const string NAME2 = "TEST";
const ll ESP = 1e-9;
const ll INF = 1e9 + 7;
const int SINF = 5e8;
const ll nmax = 2e5;
const ll MOD = 1e9 + 7;
const ll base = 2309;
const int dx[4] = {-1, 0, 0, 1};
const int dy[4] = {0, -1, 1, 0};

void fre() {
	string finp = NAME + ".inp";
	string fout = NAME + ".out";
	freopen(finp.c_str(), "r", stdin);
	freopen(fout.c_str(), "w", stdout);
}

int n, m, src, snk;

pii home, lover, segg, hater;

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
		//cout << u << '\n';
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

int get_id(pii pos) {
	return (pos.fi - 1) * m + pos.se;
}

int main() {
	fast;
	//fre();
	while (cin >> n >> m && n != 0 && m != 0) {
		cin >> home.fi >> home.se >> lover.fi >> lover.se >> segg.fi >> segg.se >> hater.fi >> hater.se;
		src = n * m + 1;
		snk = src + 1;
		init(snk);
		addEdge(src, get_id(home), 1, 0);
		addEdge(get_id(segg), snk, 1, 0);
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				pii cur = make_pair(i, j);
				for (int ily = 0; ily < 4; ily++) {
					int newi = i + dx[ily];
					int newj = j + dy[ily];
					pii can_we_hang_out = make_pair(newi, newj);
					if (newi < 1 || newj < 1 || newi > n || newj > m) continue;
					if (cur == hater) addEdge(get_id(cur), get_id(can_we_hang_out), 0, 1);
					else if (can_we_hang_out == lover) addEdge(get_id(cur), get_id(can_we_hang_out), 1, 1);
					else addEdge(get_id(cur), get_id(can_we_hang_out), can_we_hang_out != hater, 1); 
				} 
			}
		}
		auto tam = get_flow();
		cout << tam.fi << " " << tam.se << '\n';
	}
}
