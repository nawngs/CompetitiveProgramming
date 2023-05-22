#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define pb push_back
#define piii pair <pair <int, int>, int>
void cmax(ll& x, ll y) {x = max(x, y);}
void cmin(ll& x, ll y) {x = min(x, y);}
int const nmax = 100005;
int n, a[nmax], s;
vector <int> type[nmax];
int it[nmax * 4], lazy[nmax * 4];
void build(int node, int l, int r)
{
    it[node] = lazy[node] = 0;
    if(l == r) return;
    int mid = (l + r) >> 1;
    build(node << 1, l, mid);
    build(node << 1 | 1, mid + 1, r);
}
void down(const int& node)
{
    if(lazy[node] == 0) return;
    it[node << 1] += lazy[node];
    it[node << 1 | 1] += lazy[node];
    lazy[node << 1] += lazy[node];
    lazy[node << 1 | 1] += lazy[node];
    lazy[node] = 0;
    return;
}
void update(int node, int l, int r, int u, int v, int val)
{
    if(v < l || r < u) return;
    if(u <= l && r <= v)
    {
        it[node] += val;
        lazy[node] += val;
        return;
    }
    int mid = (l + r) >> 1;
    down(node);
    update(node << 1, l, mid, u, v, val);
    update(node << 1 | 1, mid + 1, r, u, v, val);
    it[node] = max(it[node << 1], it[node << 1 | 1]);
}
void solve()
{
    cin >> n >> s;
    for(int i = 1; i <= n; ++i) cin >> a[i];
    for(int i = 1; i <= 100000; ++i) type[i].clear();
    //cout << "HAHA" << endl;
    build(1, 1, n);
    int ans = 0;
    for(int i = 1; i <= n; ++i)
    {
        type[a[i]].pb(i);
        if(type[a[i]].size() <= s)
        {
            update(1, 1, n, 1, i, 1);
        }
        else
        {
            int tp = type[a[i]].size();
            // 0 1 2 ... tp - 1
            int l = type[a[i]][tp - s - 1];
            int r = type[a[i]][tp - s];
            int nl = (tp - s - 2 >= 0 ? type[a[i]][tp - s - 2] : 0);
            update(1, 1, n, l + 1, i, 1);
            update(1, 1, n, nl + 1, l, -s);
        }
        ans = max(ans, it[1]);
    }
    cout << ans << '\n';
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int ntest;
    cin >> ntest;
    while(ntest--) solve();
    return 0;
}