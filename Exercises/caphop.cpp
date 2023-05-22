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

const string NAME = "CapHop";
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

int n, m, a[103];

vector < int > val;

map < int, int > f[103];

int main() {
	fast;
	fre();
	cin >> n >> m;
	int dem = 0;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		int x = a[i];
		for (int j = 2; j * j <= a[i]; j++) {
			if (x % j == 0) dem ++;
			while (x % j == 0) x /= j;
		}
		if (x != 1) dem ++;
	}
	int src = dem + 1;
	int snk = src + 1;
	DinicFlow df(snk);
	dem = 0;
	for (int i = 1; i <= n; i+=2) {
		int x = a[i];
		for (int j = 2; j * j <= a[i]; j++) {
			int cnt = 0;
			while (x % j == 0) {
				x /= j;
				cnt ++;
			}
			if (cnt == 0) continue;
			df.addEdge(src, ++dem, cnt);
			f[i][j] = dem;
		}
		if (x != 1) {
			df.addEdge(src, ++dem, 1);
			f[i][x] = dem;
		}
	}
	for (int i = 2; i <= n; i+=2){
		int x = a[i];
		for (int j = 2; j * j <= a[i]; j++) {
			int cnt = 0;
			while (x % j == 0) {
				x /= j;
				cnt ++;
			}
			if (cnt == 0) continue;
			df.addEdge(++dem, snk, cnt);
			f[i][j] = dem;
		}
		if (x != 1) {
			df.addEdge(++dem, snk, 1);
			f[i][x] = dem;
		}
	}
	for (int i = 1; i <= m; i++) {
		int u, v;
		cin >> u >> v;
		if (v % 2 == 1) swap(u, v);
		for (auto x : f[u]) {
			if (f[v][x.fi] != 0) {
				df.addEdge(x.se, f[v][x.fi], INF);
			}
		}
	}
	cout << df.maxFlow(src, snk);
}