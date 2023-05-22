#pragma GCC optimize ("O2")
#include <bits/stdc++.h>

#define ll long long
#define int ll
#define ld long double
#define fi first 
#define se second
#define pll pair < ll, ll >
#define pii pair < int, int >
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

using namespace std;

const string NAME = "hotel";
const string NAME2 = "TEST";
const ll ESP = 1e-9;
const ll INF = 1e18;
const ll nmax = 2e5;
const ll MOD = 1e9 + 7;
const ll base = 2309;

void fre() {
	string finp = NAME + ".inp";
	string fout = NAME + ".out";
	freopen(finp.c_str(), "r", stdin);
	freopen(fout.c_str(), "w", stdout);
}

struct Offer {
	int start, finish, m0nesy; //600k do ban nhu cc
} a[1003];

int n, k, src, snk;

struct Edge {
	int from, to, flow, capa, cost, id;
	Edge(int _from = 0, int _to = 0, int _capa = 0, long long _cost = 0, ll _id = -1) {
       	from = _from; to = _to; flow = 0; capa = _capa; cost = _cost; id = _id;
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

int addEdge(int from, int to, int capa, long long cost, ll id = -1) {
    adj[from].push_back(edges.size());
    edges.push_back(Edge(from, to, capa, cost, id));
    adj[to].push_back(edges.size());
    edges.push_back(Edge(to, from, 0, -cost, id));
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


main() {
	fast;
	//fre();
	cin >> n >> k;
	vector < int > val;
	for (int i = 1; i <= n; i++) {
		int s, t, v;
		cin >> s >> t >> v;
		a[i].start = s;
		a[i].finish = s + t;
		a[i].m0nesy = v;
		val.push_back(a[i].start);
		val.push_back(a[i].finish);
	}
	sort(val.begin(), val.end());
	val.erase(unique(val.begin(), val.end()), val.end());
	src = val.size() + 1;
	snk = src + 1;
	init(snk);
	for (int i = 1; i <= n; i++) {
		a[i].start = lower_bound(val.begin(), val.end(), a[i].start) - val.begin() + 1;
		a[i].finish = lower_bound(val.begin(),val.end(), a[i].finish) - val.begin() + 1;
		addEdge(a[i].start, a[i].finish, 1, -a[i].m0nesy, i);
	}
	addEdge(src, 1, k, 0);
	for (int i = 0; i < val.size() - 1; i++) addEdge(i + 1, i + 2, k, 0);
	addEdge(val.size(), snk, k, 0);
	cout << abs(get_flow().se) << '\n';
	for (int i = 1; i <= n; i++) {
		for (auto id : adj[a[i].start]) {
			if (edges[id].to == a[i].finish && edges[id].id == i) {
				cout << edges[id].flow << ' ';
				break;
			}
		}
	}
}
