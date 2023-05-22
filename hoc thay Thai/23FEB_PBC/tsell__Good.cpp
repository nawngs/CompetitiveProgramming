#include<bits/stdc++.h>
using namespace std;
#define int long long
#define fi first
#define se second
#define pb push_back
#define ld long double
#define pii pair <int, int>
#define pli pair <int, int>
#define piii pair <int, pair <int, int>>
#define pdi pair <double, int>
#define pid pair <int, double>
void cmax(int& x, const int& y) {x = max(x, y);}
void cmin(pli& x, const pli& y) {x = min(x, y);}
int const nmax = 100007;
const int INF = (int) 1e18 + 7;
struct DinicFlow {
    int numNode, numEdge;
    vector<int> dist, head, work;
    vector<int> point, next;
    vector<int> flow, capa;

    DinicFlow(int n = 0) {
        numNode = n;
        numEdge = 0;
        dist.assign(n + 7, 0);
        head.assign(n + 7, -1);
        work.assign(n + 7, 0);
    }

    int addEdge(int u, int v, int c1, int c2 = 0) {
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
    int dfs(int s, int t, int f) {
        if (s == t) return f;
        for (int &i = work[s]; i >= 0; i = next[i]) if (flow[i] < capa[i] && dist[point[i]] == dist[s] + 1) {
            int d = dfs(point[i], t, min(f, capa[i] - flow[i]));
            if (d > 0) {
                flow[i] += d;
                flow[i ^ 1] -= d;
                return d;
            }
        }
        return 0;
    }

    int maxFlow(int s, int t) {
        int totFlow = 0;
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
int n, k;
int w[nmax];
vector <int> adj[nmax];
int nxt[nmax][20], h[nmax], jump[nmax][20];
void dfs(int u, int p)
{
    h[u] = h[p] + 1;
    nxt[u][0] = p;
    for(int i = 1; (1 << i) <= h[u]; ++i) nxt[u][i] = nxt[nxt[u][i - 1]][i - 1];
    for(int v: adj[u])
        if(v != p)
            dfs(v, u);
}
int cnt = 0;
main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> k;
    for(int i = 1; i <= n; ++i) cin >> w[i];
    for(int i = 1; i < n; ++i)
    {
        int u, v; cin >> u >> v;
        adj[u].pb(v); adj[v].pb(u);
    }
    dfs(1, 0);
    cnt = k;
    for(int i = 1; i <= n; ++i)
        for(int j = 0; (1 << j) <= h[i]; ++j)
            jump[i][j] = ++cnt;
    DinicFlow df(cnt + n + 2);
    for(int i = 1; i <= n; ++i) df.addEdge(cnt + i, cnt + n + 2, w[i]);
    for(int j = 0; (1 << j) <= n; ++j)
        for(int i = 1; i <= n; ++i)
            if(j == 0)
            {
                df.addEdge(jump[i][j], cnt + i, INF);
                df.addEdge(jump[i][j], cnt + nxt[i][0], INF);
            }
            else
            {
                if(nxt[i][j] == 0) continue;
                //cout << i << " " << (1 << j) << "p" << endl;
                df.addEdge(jump[i][j], jump[i][j - 1], INF);
                df.addEdge(jump[i][j], jump[nxt[i][j - 1]][j - 1], INF);
            }
    //cout << "HAHA" << endl;
    //cout << nxt[2][1] << endl;
    for(int i = 1; i <= k; ++i)
    {
        int u, v, c; cin >> u >> v >> c;
        df.addEdge(cnt + n + 1, i, c);
        if(h[u] < h[v]) swap(u, v);
        int tp = __lg(h[u]);
        for(int j = tp; j >= 0; --j)
            if(h[u] - (1 << j) >= h[v])
            {
                df.addEdge(i, jump[u][j], INF);
                u = nxt[u][j];
            }
        if(u == v)
        {
            df.addEdge(i, cnt + u, INF);
            continue;
        }
        for(int j = tp; j >= 0; --j)
            if(nxt[u][j] != nxt[v][j])
            {
                df.addEdge(i, jump[u][j], INF);
                df.addEdge(i, jump[v][j], INF);
                u = nxt[u][j];
                v = nxt[v][j];
            }
        df.addEdge(i, jump[u][0], INF);
        df.addEdge(i, jump[v][0], INF);
    }
    //cout << "HAHA" << endl;
    cout << df.maxFlow(cnt + n + 1, cnt + n + 2);
    return 0;
}