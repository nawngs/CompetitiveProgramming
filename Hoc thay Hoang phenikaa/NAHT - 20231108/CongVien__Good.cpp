#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
using ll = long long;

const int N = 2e5+5;

//--------------------------------------
int n, q, a[N];
vector<int> adj[N];

int timer, tin[N], rev[N], tout[N];
int up[N][20], ln[N][20], nn[N][20], xd[N];

void initDfs(int u, int pr) {
    tin[u] = ++timer; rev[tin[u]] = u;
    up[u][0] = pr; ln[u][0] = a[pr];
    for (int j = 1; j <= 18; j++) {
        up[u][j] = up[up[u][j-1]][j-1];
        ln[u][j] = max(ln[u][j-1], ln[up[u][j-1]][j-1]);
    }

    nn[u][0] = u; xd[u] = u;
    for (int j = 18; j >= 0; j--) {
        if (ln[nn[u][0]][j] <= a[u])
            nn[u][0] = up[nn[u][0]][j];

        if (ln[xd[u]][j] < a[u])
            xd[u] = up[xd[u]][j];
    }
    xd[u] = up[xd[u]][0];
    if (a[xd[u]] < a[u] || xd[u] == u) {
        xd[u] = 0;
    }

    nn[u][0] = up[nn[u][0]][0];
    if (nn[u][0] == 1 && a[1] <= a[u]) {
        nn[u][0] = 0;
    }
    for (int j = 1; j <= 18; j++) {
        nn[u][j] = nn[nn[u][j-1]][j-1];
    }

    for (auto v : adj[u]) if (v != pr) {
        initDfs(v, u);
    }
    tout[u] = timer;
}

bool isAnc(int u, int v) {
    return (u == 0 || (tin[u] <= tin[v] && tout[u] >= tout[v]));
}

int d[N], par[N], head[N];

int initHld(int u, int pr) {
    d[u] = d[pr] + 1;
    par[u] = pr;
    int size = 1, ln = 0;

    for (auto& v : adj[u]) if (v != pr) {
        int cur = initHld(v, u);
        size += cur;
        if (cur > ln) {
            ln = cur;
            swap(v, adj[u][0]);
        }
    }

    return size;
}

void decompose(int u, int h) {
    head[u] = h;
    if (adj[u].size() > 1 || u == 1)
        decompose(adj[u][0], h);

    for (auto v : adj[u]) if (v != par[u] && v != adj[u][0]) {
        decompose(v, v);
    }
}

struct SegmentTree {
    vector<int> seg[N*4];
    void build(int l = 1, int r = n, int id = 1) {
        if (l == r) {
            int u = xd[rev[l]];
            seg[id].push_back((u != rev[l] ? d[u] : 0));
            return;
        }
        int mid = (l+r) / 2;
        build(l, mid, id*2);
        build(mid+1, r, id*2 + 1);
        merge(seg[id*2].begin(), seg[id*2].end(),
              seg[id*2 + 1].begin(), seg[id*2 + 1].end(),
              inserter(seg[id], seg[id].begin()));
    }

    int get(int u, int v, int val, int l = 1, int r = n, int id = 1) {
        if (l > v || r < u) return 0;
        if (l >= u && r <= v) {
            return lower_bound(seg[id].begin(), seg[id].end(), val) - seg[id].begin();
        }
        int mid = (l+r) / 2;
        return get(u, v, val, l, mid, id*2) + 
               get(u, v, val, mid+1, r, id*2 + 1);
    }
} segTree;

void init() {
    initHld(1, 1);
    initDfs(1, 1);
    decompose(1, 1);
}

int LCA(int u, int v) {
    if (isAnc(u, v)) return u;
    if (isAnc(v, u)) return v;
    for (int j = 18; j >= 0; j--) {
        if (!isAnc(up[u][j], v))
            u = up[u][j];
    }
    return up[u][0];
}

pair<int, int> getLeft(int u, int c) { //vertex, steps
    int cnt = 1;
    // cout << u << ' ' << nn[u][0] << ' ' << '\n';
    for (int j = 18; j >= 0; j--) {
        if (!isAnc(nn[u][j], c)) {
            // cout << u << ' ' << nn[u][j] << '\n';
            u = nn[u][j];
            cnt += (1 << j);
        }
    }
    if (nn[u][0] == c) {
        u = nn[u][0];
        cnt++;
    }
    return {u, cnt};
}

int getMax(int u, int c) {
    int kq = a[u];
    for (int j = 18; j >= 0; j--) {
        if (!isAnc(up[u][j], c)) {
            kq = max(kq, ln[u][j]);
            u = up[u][j];
        }
    }
    kq = max(kq, ln[u][0]);
    return kq;
}

int query2(int a, int b, int val) {
    // cout << a << ' ' << b << '\n';
    int kq = 0;
    for (; head[a] != head[b]; b = par[head[b]]) {
        if (d[head[a]] > d[head[b]]) swap(a, b);
        // cout << head[b] << ' ' << tin[b] << ", " << val << '\n';
        kq += segTree.get(tin[head[b]], tin[b], val);
    }
    if (d[a] > d[b]) swap(a, b);
    // cout << head[3] << ' ' << head[4] << '\n';
    kq += segTree.get(tin[a], tin[b], val);
    return kq;
}

int query(int u, int v) {
    int kq = 0;
    int c = LCA(u, v);

    int ln, cnt;
    tie(ln, cnt) = getLeft(u, c);
    kq += cnt; ln = a[ln];

    int lim = v;
    for (int i = 18; i >= 0; i--) {
        int tmp = up[lim][i];
        if (isAnc(tmp, c)) continue;
        if (getMax(tmp, c) > ln) {
            lim = tmp;
        }
    }

    if (lim == v && a[v] <= ln) return kq;
    // cout << v << ' ' << lim << ", " << kq << ' ' << xd[v] << ' ' << xd[lim] << '\n';
    return kq + query2(v, lim, d[c]);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> n >> q;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i < n; i++) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    if (n > 1) {
        init();
        segTree.build();
    }

    int last = 0;
    while (q--) {
        int u, v; cin >> u >> v;
        // u = (u + last) % n + 1;
        // v = (v + last) % n + 1;
        if (n == 1) cout << 1 << '\n';
        else cout << (last = query(u, v)) << '\n';
    }
}