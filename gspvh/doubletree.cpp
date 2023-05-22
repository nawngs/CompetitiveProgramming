#include <bits/stdc++.h>

#define name "doubletree"
#define test "test"
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
 
    DinicFlow(int n = 0) {
        numNode = n;
        numEdge = 0;
        dist.assign(n + 7, 0);
        head.assign(n + 7, -1);
        work.assign(n + 7, 0);
    }
 
    int addEdge(int u, int v, long long c1, long long c2 = 0) {
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
 
    int maxFlow(int s, int t) {
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

int n, par1[230], par2[230], a[230];

bool vs[230];

vector < int > adj1[230], adj2[230];

void dfs1(int u) {
	vs[u] = 1;
	for (auto v : adj1[u]) {
		if (vs[v]) continue;
		par1[v] = u;
		dfs1(v);
	}
}

void dfs2(int u) {
	vs[u] = 1;
	for (auto v : adj2[u]) {
		if (vs[v]) continue;
		par2[v] = u;
		dfs2(v);
	}
}

void sol() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		adj1[i].clear(); adj2[i].clear();
	}
	for (int i = 1; i < n; i++) {
		int u, v; cin >> u >> v;
		adj1[u].push_back(v); adj1[v].push_back(u);
	}
	for (int i = 1; i < n; i++) {
		int u, v; cin >> u >> v;
		adj2[u].push_back(v); adj2[v].push_back(u);
	}
	for (int i = 1; i <= n; i++) cin >> a[i];
	int ans = 0;
	for (int root = 1; root <= n; root++) {
		memset(vs, 0, sizeof(vs));
		dfs1(root);
		memset(vs, 0, sizeof(vs));
		dfs2(root);
		int src = n + 1, snk = n + 2, res = a[root];
		DinicFlow df(snk);
		for (int i = 1; i <= n; i++) {
			if (i == root) continue;
			if (a[i] >= 0) {
				df.addEdge(src, i, a[i]);
				res += a[i];
			}
			else df.addEdge(i, snk, -a[i]);
			if (par1[i] != root) df.addEdge(i, par1[i], INF);
			if (par2[i] != root) df.addEdge(i, par2[i], INF);
		}
		ans = max(ans, res - df.maxFlow(src, snk));
	}
	cout << ans << '\n';
}

int main() {
	fast;
	if(fopen(name".inp", "r")) {
		freopen(name".inp", "r", stdin);
		freopen(name".out", "w", stdout);
	}
	int O; cin >> O;
	int t; cin >> t; while (t --) sol();
}