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

int n, k, src, snk;

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

int l[5003], r[5003], c[5003];

signed main() {
	fast;
	cin >> n >> k;
	vector < int > roi_rac;
	for (int i = 1; i <= n; i++) {
		cin >> l[i] >> r[i] >> c[i];
		r[i] ++;
		roi_rac.push_back(l[i]);
		roi_rac.push_back(r[i]);
	}
	sort(roi_rac.begin(), roi_rac.end());
	roi_rac.erase(unique(roi_rac.begin(), roi_rac.end()), roi_rac.end());
	for (int i = 1; i <= n; i++) {
		l[i] = lower_bound(roi_rac.begin(), roi_rac.end(), l[i]) - roi_rac.begin() + 1;
		r[i] = lower_bound(roi_rac.begin(), roi_rac.end(), r[i]) - roi_rac.begin() + 1;
	}
	src = roi_rac.size() + 1;
	snk = src + 1;
	init(snk);
	addEdge(src, 1, k, 0);
	addEdge(roi_rac.size(), snk, k, 0);
	for (int i = 1; i < roi_rac.size(); i++) addEdge(i, i + 1, k, 0);
	for (int i = 1; i <= n; i++) addEdge(l[i], r[i], 1, -c[i]);
	cout << abs(get_flow().se);
}