#include <bits/stdc++.h>

#define name ""
#define ll long long
#define ld long double
#define fi first 
#define se second
#define pll pair < ll, ll >
#define pii pair < int, int >
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define sz(x) ((int)(x).size())
#define pb push_back
#define mp make_pair

using namespace std;

const ld EPS = 1e-9;
const int INF = 1e9 + 7;
const ll LINF = 1E18;
const int NMAX = 2e5;
const ll MOD = 1e9 + 7;
const ll BASE = 2309;

struct DinicFlow {
    static const long long INF = (long long) 1e18 + 7;
    int numNode, numEdge;
    vector<int> dist, head, work;
    vector<int> point, next;
    vector<long long> flow, capa;
    void init(int n) {
    	numNode = n;
        numEdge = 0;
        dist.assign(n + 7, 0);
        head.assign(n + 7, -1);
        work.assign(n + 7, 0);
    }
    int addEdge(int u, int v, long long c1, long long c2 = 0) {
    	// clog << u << ' ' << v << ' ' << c1 << endl;
        int ret = numEdge;
        point.push_back(v); capa.push_back(c1); flow.push_back(0); next.push_back(head[u]); head[u] = numEdge++;
        point.push_back(u); capa.push_back(c2); flow.push_back(0); next.push_back(head[v]); head[v] = numEdge++;
        return ret;
    }
 
    bool bfs(int s, int t) {
        queue<int> q;
        for (int i = 1; i <= numNode; i++) dist[i] = -1;
        dist[s] = 0; q.push(s);
        while (!q.empty()) {
            int u = q.front(); q.pop();
            for (int i = head[u]; i >= 0; i = next[i]) if (flow[i] < capa[i] && dist[point[i]] < 0) {
                dist[point[i]] = dist[u] + 1;
                q.push(point[i]);
            }
        }
        return dist[t] >= 0;
    }
    long long dfs(int s, int t, long long f) {
        if (s == t) return f;
        for (int &i = work[s]; i >= 0; i = next[i]) if (flow[i] < capa[i] && dist[point[i]] == dist[s] + 1) {
            long long d = dfs(point[i], t, min(f, capa[i] - flow[i]));
            if (d > 0) {
                flow[i] += d;
                flow[i ^ 1] -= d;
                return d;
            }
        }
        return 0;
    }
 
    long long maxFlow(int s, int t) {
        long long totFlow = 0;
        while (bfs(s, t)) {
            for (int i = 1; i <= numNode; i++) work[i] = head[i];
            while (true) {
                int d = dfs(s, t, INF);
                if (d == 0) break;
                totFlow += d;
            }
        }
        return totFlow;
    }
 
    int getFlow(int id) const {
        return flow[id];
    }
 
    bool visited(int node) const {
        return dist[node] >= 0;
    }
};

DinicFlow df;

int n, k, a[10003], start[10003], finish[10003], w[10003], par[10003][20], h[10003], id[10003][20];

vector < int > adj[10003];

void dfs(int u, int e) {
	h[u] = h[e] + 1;
	for (auto v : adj[u]) {
		if (v == e) continue;
		par[v][0] = u;
		dfs(v, u);
	}
}

void LCA(int person, int u, int v) {
	if (h[u] > h[v]) swap(u, v);
	if (h[u] != h[v]) {
		for (int j = 15; j >= 0; j--) 
			if (h[par[v][j]] >= h[u]) {
				df.addEdge(person, id[v][j], INF);
				v = par[v][j];
			}
		// cout << h[5] << " " << h[par[2][1]] << " " << par[6][0] << '\n';
	}
	if (u == v) {
		df.addEdge(person, u + k, INF);
		return ;
	}
	//cout << u << " " << v << " " << h[u] << " " << h[v] << '\n';
	for (int j = 15; j >= 0; j--) {
		if (par[u][j] != par[v][j]) {
			df.addEdge(person, id[u][j], INF); df.addEdge(person, id[v][j], INF);
			u = par[u][j]; v = par[v][j];
		}
	}
	df.addEdge(person, id[u][0], INF); df.addEdge(person, id[v][0], INF);
}

int main() {
	fast;
	if(fopen(name".inp", "r")) {
		freopen(name".inp", "r", stdin);
		freopen(name".out", "w", stdout);
	}
	//int t; cin >> t; while (t --) sol();
	cin >> n >> k;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	for (int i = 1; i < n; i++) {
		int u, v; cin >> u >> v;
		adj[u].pb(v); adj[v].pb(u);
	}
	for (int i = 1; i <= k; i++) 
		cin >> start[i] >> finish[i] >> w[i];
	dfs(1, 0);
	int cur = k + n;
	for (int j = 0; j <= 15; j++) {
		for (int i = 1; i <= n; i++) {
			if (par[i][0] == 0) continue;
			id[i][0] = ++ cur;
			if (j == 0) continue;
			par[i][j] = par[par[i][j - 1]][j - 1];
			if (par[i][j] == 0) continue;
			id[i][j] = ++ cur;
		}
	}
	int src = cur + 1, snk = src + 1;
	df.init(snk);
	for (int i = 1; i <= n; i++) {
		if (par[i][0] == 0) continue;
		df.addEdge(id[i][0], k + i, INF); df.addEdge(id[i][0], k + par[i][0], INF);
		for (int j = 1; j <= 15; j++) {
			if (par[i][j] == 0) break;
			df.addEdge(id[i][j], id[i][j - 1], INF); df.addEdge(id[i][j], id[par[i][j - 1]][j - 1], INF);
		}
	}
	for (int i = 1; i <= n; i++) {
		df.addEdge(k + i, snk, a[i]);
	}
	for (int i = 1; i <= k; i++) {
		df.addEdge(src, i, w[i]);
		LCA(i, start[i], finish[i]);
	}
	cout << df.maxFlow(src, snk);
} 