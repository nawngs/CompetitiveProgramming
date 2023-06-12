#include <bits/stdc++.h>

#define pii pair < int, int >
#define piii pair < int, pii >
#define fi first
#define se second
#define pb push_back
#define SIZ(x) (int)(x.size())

using namespace std;

const int NMAX = 1000;
const int INF = 1E9 + 7;

struct Edge {
    int u, v, c;
	Edge(int _u, int _v, int _c) : u(_u), v(_v), c(_c) {};
};

int n, k, m, t, a[1003], pos[1003], f[NMAX + 3][(1 << 10) + 2], par[NMAX + 3], rnk[NMAX + 3];

vector < pii > adj[1003];

vector < Edge > temp;

bool minimize(int &x, int y) {
    if (x > y) {
        x = y;
        return true;
    }
    return false;
}

int find(int u) {
    if (u == par[u]) return u;
    return par[u] = find(par[u]);
}

bool join(int u, int v) {
    u = find(u), v = find(v);
    if (u == v) return false;
    par[u] = v;
    rnk[v] += rnk[u];
    return true;
}

int main() {
    //ios::sync_with_stdio(0);
    //cin.tie(0);cout.tie(0);
    cin >> n >> k >> m >> t;
    memset(pos, 255, sizeof(pos));
     for (int i = 0; i < k; i++) {
        cin >> a[i];
        pos[a[i]] = i;
    }
    for (int i = 1; i <= m; i++) {
        int u, v, c; cin >> u >> v >> c;
        adj[u].pb({v, c}); adj[v].pb({u, c});
        temp.push_back({u, v, c});
    }
     sort(temp.begin(), temp.end(), [](Edge &x, Edge &y) {
            return x.c < y.c;
    });
    if (t == 1) {
        if (k == n) {
            for (int i = 1; i <= n; i++) par[i] = i;
            int ans = 0;
            for (auto e : temp)
                if (join(e.u, e.v))
                    ans += e.c;
            cout << ans << '\n';
            return 0;
        }
        priority_queue < piii, vector < piii >, greater < piii > > heap;
        for (int i = 1; i <= n; i++) {
            for (int msk = 1; msk < (1 << k); msk++) f[i][msk] = INF;
            heap.push({0, {i, 0}});
        }
        for (int i = 0; i < k; i++) {
            f[a[i]][(1 << i)] = 0;
            heap.push({0, {a[i], (1 << i)}});
        }
        while (SIZ(heap)) {
            auto u = heap.top();
            heap.pop();
            if (u.fi != f[u.se.fi][u.se.se]) continue;
            for (auto v : adj[u.se.fi]) {
                int newmsk = u.se.se;
                if (minimize(f[v.fi][newmsk], u.fi + v.se))
                    heap.push({f[v.fi][newmsk], {v.fi, newmsk}});
            }
            for (int msk = u.se.se; msk < (1 << k); msk++) if ((msk & u.se.se) == u.se.se) {
                if (minimize(f[u.se.fi][msk], u.fi + f[u.se.fi][msk ^ u.se.se]))
                    heap.push({f[u.se.fi][msk], {u.se.fi, msk}});
            }
        }
        int res = INF;
        for (int i = 1; i <= n; i++)
            res = min(res, f[i][(1 << k) - 1]);
        cout << res;
    }
    else {
        int res = INF;
        for (int msk = 0; msk < (1 << k); msk++) {
            vector < Edge > edges;
            for (auto x : temp) {
                if (pos[x.u] != -1 && ((msk >> pos[x.u]) & 1)) continue;
                if (pos[x.v] != -1 && ((msk >> pos[x.v]) & 1)) continue;
                edges.push_back(x);
            }
            for (int i = 1; i <= n; i++) {
                par[i] = i;
                rnk[i] = 1;
            }
            int ans = 0;
            for (auto e : edges)
                if (join(e.u, e.v)) ans += e.c;
             if (!edges.empty() && rnk[find(edges[0].u)] == n - __builtin_popcount(msk)) res = min(res, ans);
        }
        cout << res << '\n';
    }
}
