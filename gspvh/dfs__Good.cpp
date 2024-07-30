#include <bits/stdc++.h>
#define fi first
#define se second
#define inf 0x3f3f3f3f3f3f3f3f
using namespace std;
using ll = long long;
const int nx=4e5+5;
int n, k, a[nx], l, r, mid, ans, sz[nx], cur[nx], f[nx], g[nx];
vector<int> adj[nx];
pair<int, int> tmp[nx];
bool ok;
void go(int p, int u)
{
    sz[u]=1;
    for(int v:adj[u])
    {
        if(v==p)
            continue;
        go(u, v);
        sz[u]+=sz[v];
    }
}
void dfs(int p, int u)
{
    cur[u]=0;
    f[u]=(a[u]>=mid);
    for(int v:adj[u])
    {
        if(v==p)
            continue;
        dfs(u, v);
        if(a[u]<mid)
            continue;
        if(f[v]==sz[v])
            f[u]+=f[v];
        else cur[u]=max(cur[u], f[v]);
    }
    f[u]+=cur[u];
}
void update(int u, int v)
{
    if(f[v]>=tmp[u].fi)
    {
        tmp[u].se=tmp[u].fi;
        tmp[u].fi=f[v];
    }
    else if(f[v]>tmp[u].se)
        tmp[u].se=f[v];
}
void dfs1(int p, int u)
{
    cur[u]=0;
    for(int v:adj[u])
    {
        if(v==p)
            continue;
        if(f[v]==sz[v])
            cur[u]+=f[v];
        else update(u, v);
    }
    int e=0;
    for(int v:adj[u])
    {
        if(v==p)
            continue;
        g[v]=cur[u];
        if(f[v]==sz[v])
            g[v]-=f[v];
        if(g[u]==n-sz[u])
            g[v]+=g[u];
        else e=g[v];
        if((f[v]==tmp[u].fi && f[v]<sz[v]) || f[v]==sz[v])
            e=max(e, tmp[u].se);
        else e=max(e, tmp[u].fi);
        g[v]+=e;
        if(a[u]<mid)
            g[v]=0;
        dfs1(u, v);
    }
}
void last(int p, int u)
{
    cur[u]=0;
    int e=0, cnt=0;
    if(g[u]==n-sz[u])
        cur[u]=g[u];
    else e=g[u];
    for(int v:adj[u])
    {
        if(v==p)
            continue;
        if(f[v]==sz[v])
            cnt+=f[v];
        else e=max(e, f[v]);
    }
    if(e+cnt>=k && a[u]>=mid)
        ok=1;
    for(int v:adj[u])
    {
        if(v==p)
            continue;
        last(u, v);
    }
}
bool check()
{
    for(int i = 1; i <= n; i++)
    {
        f[i]=g[i]=0;
        tmp[i]={0, 0};
    }
    dfs(0, 1);
    dfs1(0, 1);
    ok=0;
    last(0, 1);
    return ok;
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    // freopen("dfs.inp", "r", stdin);
    // freopen("dfs.out", "w", stdout);
    cin>>n>>k;
    for(int i = 1; i <= n; i++)
        cin>>a[i];
    for(int i = 1; i < n; i++)
    {
        int u, v;
        cin>>u>>v;
        adj[u].emplace_back(v);
        adj[v].emplace_back(u);
    }
    go(0, 1);
    ans=1;
    l=1;
    r=1e6;
    while(l<=r)
    {
        mid=(l+r)>>1;
        if(check())
        {
            ans=mid;
            l=mid+1;
        }
        else r=mid-1;
    }
    cout<<ans;
}