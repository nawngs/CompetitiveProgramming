#include <bits/stdc++.h>
#include <algorithm>
using namespace std;
#define FOR(i, a, b) for(int i = a; i <= b; ++i)
#define FOD(i, a, b) for(int i = a; i >= b; --i)
#define fi first
#define se second
#define pb push_back
#define eb emplace_back
#define ll long long
#define nmax 200007
void faster()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}
int n;
int p[nmax][20], sum[nmax][20], ans = 0, r1, r2, h[nmax], q1, q2;
int lca(int u, int v)
{
    if(h[u] < h[v]) swap(u, v);
    int tp = log2(h[u]);
    int tong = 0;
    FOD(i, tp, 0)
        if(h[u] - (1 << i) >= h[v])
        {
            tong += sum[u][i];
            u = p[u][i];
        }
    if(u == v) return tong;
    FOD(i, tp, 0)
        if(p[u][i] != 0 && p[u][i] != p[v][i])
        {
            tong += sum[u][i] + sum[v][i];
            u = p[u][i];
            v = p[v][i];
        }
    return tong + sum[u][0] + sum[v][0];
}
int main()
{
    faster();
   // freopen("LPath.inp","r",stdin);
   // freopen("LPath.out","w",stdout);
    cin >> n;
    r1 = r2 = 1;
    h[1] = 1;
    FOR(i, 2, n + 1)
    {
        int u, w;
        cin >> u >> w;
        h[i] = h[u] + 1;
        p[i][0] = u;
        sum[i][0] = w;
        for(int j = 1; (1 << j) <= n + 1; ++j)
            if(p[i][j - 1] != 0)
            {
                p[i][j] = p[p[i][j - 1]][j - 1];
                sum[i][j] = sum[i][j - 1] + sum[p[i][j - 1]][j - 1];
            }
        q1 = lca(r1, i);
        q2 = lca(r2, i);
        if(max(q1, q2) <= ans) continue;
        if(q1 > q2)
        {
            r2 = i;
        }
        else r1 = i;
        ans = max(q1, q2);
        cout << ans << '\n';
    }
    return 0;
}