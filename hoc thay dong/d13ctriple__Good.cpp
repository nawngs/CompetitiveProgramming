#include <bits/stdc++.h>
#define ii pair<int, int>
#define fi first
#define se second
#define inf 0x3f3f3f3f3f3f3f3f
using namespace std;
using ll = long long;
const ll mod=1e9+7;
const int nx=2e5+5;
const int LG=18;
int n, a[nx], up[nx][LG], h[nx], mark[nx], t=0, in[nx], out[nx], prime, par[nx];
vector<int> adj[nx], v, ed[nx], cur;
bool b[nx];
ll cup[nx], cdown[nx], ans=0;
stack<int> st;
void buh()
{
    memset(b, 1, sizeof(b));
    b[0]=b[1]=0;
    for(int i = 2; i < sqrt(nx); i++)
        if(b[i])
        for(int j = i*i; j < nx; j+=i)
            b[j]=0;
    for(int i = 2; i <= 200000; i++)
        if(b[i])
            v.emplace_back(i);
}
void dfs(int u)
{
    in[u]=++t;
    for(int v:adj[u])
    {
        if(v==up[u][0])
            continue;
        h[v]=h[u]+1;
        up[v][0]=u;
        for(int i = 1; i < LG; i++)
            up[v][i]=up[up[v][i-1]][i-1];
        dfs(v);
    }
    out[u]=++t;
}
int jump(int u, int k)
{
    for(int i = 0; i < LG; i++)
        if(k>>i&1)
            u=up[u][i];
    return u;
}
int lca(int u, int v)
{
    if(h[u]<h[v])
        swap(u, v);
    u=jump(u, h[u]-h[v]);
    if(u==v)
        return u;
    for(int i = LG-1; i >= 0; i--)
        if(up[u][i]!=up[v][i])
            u=up[u][i], v=up[v][i];
    return up[u][0];
}
int dist(int u, int v)
{
    int p=lca(u, v);
    return h[u]+h[v]-2*h[p];
}
bool cmp(int u, int v)
{
    return in[u]<in[v];
}
void dfs1(int p, int u)
{
    cdown[u]=(a[u]%prime==0);
    for(int v:ed[u])
    {
        if(v==p)
            continue;
        par[v]=u;
        dfs1(u, v);
        cdown[u]+=cdown[v];
    }
}
void dfs2(int p, int u)
{
    ll tmp=0;
    for(int v:ed[u])
    {
        if(v==p)
            continue;
        tmp=tmp+cdown[v];
    }
    for(int v:ed[u])
    {
        if(v==p)
            continue;
        cup[v]=cup[u]+(a[u]%prime==0)+tmp-cdown[v];
        dfs2(u, v);
    }
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    buh();
    cin>>n;
    for(int i = 1; i <= n; i++)
        cin>>a[i];
    for(int i = 1; i < n; i++)
    {
        int u, v;
        cin>>u>>v;
        adj[u].emplace_back(v);
        adj[v].emplace_back(u);
    }
    dfs(1);
    for(int c:v)
    {
        prime=c;
        cur.clear();
        for(int i = 1; i <= n; i++)
        {
            cup[i]=cdown[i]=0;
            if(a[i]%c==0)
            {
                ed[i].clear();
                cur.emplace_back(i);
                mark[i]=c;
            }
        }
        if(cur.size()<2)
            continue;
        for(int i = 1; i < cur.size(); i++)
        {
            int tmp=lca(cur[i], cur[i-1]);
            if(mark[tmp]<c)
            {
                mark[tmp]=c;
                cur.emplace_back(tmp);
                ed[tmp].clear();
            }
        }
        sort(cur.begin(), cur.end(), cmp);
        while(st.size())
            st.pop();
        st.push(cur[0]);
        for(int i = 1; i < cur.size(); i++)
        {
            while(st.size() && out[st.top()]<out[cur[i]])
                st.pop();
            if(st.size())
                ed[st.top()].emplace_back(cur[i]);
            st.push(cur[i]);
        }
        dfs1(0, cur[0]);
        dfs2(0, cur[0]);
        for(int i = 1; i < cur.size(); i++)
        {
            ll w=dist(cur[i], par[cur[i]]);
            ans=(ans+w*cdown[cur[i]]%mod*(cup[cur[i]]*(cup[cur[i]]-1)/2%mod)%mod)%mod;
            ans=(ans+w*cup[cur[i]]%mod*(cdown[cur[i]]*(cdown[cur[i]]-1)/2%mod)%mod)%mod;
        }
    }
    cout<<ans;
}
