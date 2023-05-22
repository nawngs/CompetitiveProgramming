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

struct Black_Area {
	int top, bottom, left, right;
} a[52];

int n, m;

vector < int > row, col;

pii NodeRow[105], NodeCol[105];

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

int main() {
	fast;
	cin >> n >> m;
	for (int i = 1; i <= m; i++) {
		cin >> a[i].top >> a[i].left >> a[i].bottom >> a[i].right;
		row.push_back(a[i].top);
		row.push_back(a[i].bottom + 1);
		col.push_back(a[i].left);
		col.push_back(a[i].right + 1);
	}
	row.push_back(1);
	row.push_back(n + 1);
	col.push_back(1);
	col.push_back(n + 1);
	sort(row.begin(), row.end());
	row.erase(unique(row.begin(), row.end()), row.end());
	sort(col.begin(), col.end());
	col.erase(unique(col.begin(), col.end()), col.end());
	int NumRow = 0, NumCol = 0, src, snk;
	for (int i = 0; i < row.size() - 1; i++) NodeRow[++ NumRow] = {row[i], row[i + 1] - 1};
	for (int i = 0; i < col.size() - 1; i++) NodeCol[++ NumCol] = {col[i], col[i + 1] - 1};
	src = NumRow + NumCol + 1;
	snk = src + 1;
	DinicFlow df(snk);
	for (int i = 1; i <= NumRow; i++) df.addEdge(src, i, NodeRow[i].se - NodeRow[i].fi + 1);
	
	for (int i = 1; i <= NumCol; i++) df.addEdge(NumRow + i, snk, NodeCol[i].se - NodeCol[i].fi + 1);
	for (int i = 1; i <= NumRow; i++) 
		for (int j = 1; j <= NumCol; j++) 
			for (int k = 1; k <= m; k++) {
				if (a[k].top <= NodeRow[i].fi && a[k].bottom >= NodeRow[i].se
				 && a[k].left <= NodeCol[j].fi && a[k].right >= NodeCol[j].se) {
					df.addEdge(i, NumRow + j, INF);
				}
			}
	cout << df.maxFlow(src, snk);
}
