#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define ii pair<int, int>
int const nmax = 2e5 + 5;
int n, q;
char s;
int a[nmax];
vector <int> adj[nmax];
int par[nmax], sz[nmax];
int chain[nmax], head[nmax], tin[nmax], tout[nmax];
struct segment
{
    int it[nmax * 4];
    void down(int node)
    {
        it[node << 1] += it[node];
        it[node << 1 | 1] += it[node];
        it[node] = 0;
    }
    void update(int node, int l, int r, int u, int v, int val)
    {
        if(v < l || r < u) return;
        if(u <= l && r <= v)
        {
            it[node] += val;
            return;
        }
        int mid = (l + r) >> 1;
        down(node);
        update(node << 1, l, mid, u, v, val);
        update(node << 1 | 1, mid + 1, r, u, v, val);
    }
    int get(int node, int l, int r, int x)
    {
        if(l == r) return it[node];
        int mid = (l + r) >> 1;
        down(node);
        if(x <= mid) return get(node << 1, l, mid, x);
        return get(node << 1 | 1, mid + 1, r, x);
    }
} t[2];
struct BIT
{
    int bit[nmax];
    void update(int i, int val)
    {
        for(; i <= n; i += i & (-i)) bit[i] += val;
    }
    int sum(int i)
    {
        int ans = 0;
        for(; i > 0; i -= i & (-i)) ans += bit[i];
        return ans;
    }
    int query(int x, int y)
    {
        return sum(y) - sum(x - 1);
    }
} t2;
void dfs(int u, int p)
{
    par[u] = p;
    sz[u] = 1;
    for(int v: adj[u])
        if(v != p)
        {
            dfs(v, u);
            sz[u] += sz[v];
        }
}
void hld(int u)
{
    chain[u] = chain[0];
    if(!head[chain[u]]) head[chain[u]] = u;
    tin[u] = ++tin[0];
    if(a[u]) t2.update(tin[u], 1);
    int mx = 0;
    for(int v: adj[u])
        if(v != par[u] && sz[v] > sz[mx])
            mx = v;
    if(mx) hld(mx);
    tout[u] = tin[0];
    for(int v: adj[u])
        if(v != par[u] && v != mx)
        {
            chain[0]++;
            hld(v);
        }
}
void update(int u, int val, int id) // update tren 1 doan cung mau ?
{
    int uchain = chain[u];
    int l, r, m, res;
    while(1)
    {
        if(uchain == chain[1])
        {
            if(t2.query(tin[1], tin[u]) == (tin[u] - tin[1] + 1) * id)
            {
                t[id].update(1, 1, n, tin[1], tin[u], val);
            }
            else
            {
                l = tin[1], r = tin[u];
                while(l <= r)
                {
                    m = (l + r) >> 1;
                    if(t2.query(m, tin[u]) != (tin[u] - m + 1) * id)
                    {
                        res = m;
                        l = m + 1;
                    }
                    else r = m - 1;
                }
                t[id].update(1, 1, n, res, tin[u], val);
            }
            break;
        }
        else
        {
            if(t2.query(tin[head[uchain]], tin[u]) == (tin[u] - tin[head[uchain]] + 1) * id)
            {
                t[id].update(1, 1, n, tin[head[uchain]], tin[u], val);
                u = par[head[uchain]];
                uchain = chain[u];
            }
            else
            {
                l = tin[head[uchain]], r = tin[u];
                while(l <= r)
                {
                    m = (l + r) >> 1;
                    if(t2.query(m, tin[u]) != (tin[u] - m + 1) * id)
                    {
                        res = m;
                        l = m + 1;
                    }
                    else r = m - 1;
                }
                t[id].update(1, 1, n, res, tin[u], val);
                break;
            }
        }
    }
}
int count_node(int u)
{
    int id = a[u];
    int uchain = chain[u];
    int l, r, m, res;
    while(1)
    {
        if(uchain == chain[1])
        {
            if(t2.query(tin[1], tin[u]) == (tin[u] - tin[1] + 1) * id)
            {
                return t[id].get(1, 1, n, tin[1]);
            }
            else
            {
                l = tin[1], r = tin[u];
                while(l <= r)
                {
                    m = (l + r) >> 1;
                    if(t2.query(m, tin[u]) == (tin[u] - m + 1) * id)
                    {
                        res = m;
                        r = m - 1;
                    }
                    else l = m + 1;
                }
                return t[id].get(1, 1, n, res);
            }
        }
        else
        {
            if(t2.query(tin[head[uchain]], tin[u]) == (tin[u] - tin[head[uchain]] + 1) * id)
            {
                if(a[par[head[uchain]]] != id) return t[id].get(1, 1, n, tin[head[uchain]]);
                u = par[head[uchain]];
                uchain = chain[u];
            }
            else
            {
                l = tin[head[uchain]], r = tin[u];
                while(l <= r)
                {
                    m = (l + r) >> 1;
                    if(t2.query(m, tin[u]) == (tin[u] - m + 1) * id)
                    {
                        res = m;
                        r = m - 1;
                    }
                    else l = m + 1;
                }
                return t[id].get(1, 1, n, res);
            }
        }
    }
}
void change_color(int u)
{
    int id = a[u];
    int uchain = chain[u];
    int l, r, m, res;
    // tu mau id chuyen sang mau id ^ 1
    // hien tai thi mau id van dang duoc update tu u len par[u] va cac dinh khac
    // con mau id ^ 1 thi van dang dung lai o u
    int val = t[id].get(1, 1, n, tin[u]);
    //cout << "HAHA " << u << " " << a[u] << " " << val << endl;
    if(u != 1) update(par[u], -val, id);
    t[id].update(1, 1, n, tin[u], tin[u], -1);
    if(id == 0) t2.update(tin[u], 1);
    else t2.update(tin[u], -1);
    a[u] ^= 1;
    id ^= 1;
    t[id].update(1, 1, n, tin[u], tin[u], 1);
    val = t[id].get(1, 1, n, tin[u]);
    if(u != 1) update(par[u], val, id);
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> q;
    for(int i = 1; i <= n; ++i)
    {
        cin >> s;
        a[i] = s - '0';
        //cout << i << " " << a[i] << endl;
    }
    for(int i = 2; i <= n; ++i)
    {
        int x; cin >> x;
        adj[i].push_back(x);
        adj[x].push_back(i);
    }
    dfs(1, 0);
    chain[0] = 1;
    hld(1);
    /*for(int i = 1; i <= n; ++i)
    {
        cout << i << " par: " << par[i] << endl;
    }*/
    for(int i = 1; i <= n; ++i) update(i, 1, a[i]);
    while(q--)
    {
        int type, u;
        cin >> type >> u;
        if(type == 1) change_color(u);
        else cout << count_node(u) << '\n';
    }
    return 0;
}
/*
6 2
001011
1 1 2 2 3
1 5
2 5
*/