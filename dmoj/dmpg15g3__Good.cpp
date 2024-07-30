#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>

using namespace std;

int N, LK, RK, LC, RC;
char A[200002];
vector<int> adj[200001];
bool bad[200001];
int sz[200001];
vector<vector<pair<int, int>>> V;
vector<pair<int, int>> all;
int bit[200006];
long long ans;

void add(int x, int v)
{
    for(x++; x<=200005; x+=x&-x)
        bit[x]+=v;
}

int sum(int x)
{
    int ret=0;
    for(x++; x>0; x-=x&-x)
        ret+=bit[x];
    return ret;
}

void dfs(int u, int p)
{
    sz[u]=1;
    for(auto& v: adj[u]) if(v!=p && !bad[v])
    {
        dfs(v, u);
        sz[u]+=sz[v];
    }
}

void dfs2(int u, int p, int K, int C)
{
    if(A[u]=='K')
        K++;
    else
        C++;
    V.back().push_back(make_pair(K, C));
    all.push_back(make_pair(K, C));
    for(auto& v: adj[u]) if(v!=p && !bad[v])
        dfs2(v, u, K, C);
}

long long work(vector<pair<int, int>>& v, int R0, int R1)
{
    if(R0<0 || R1<0)
        return 0;
    long long ret=0;
    int j=0;
    for(int i=v.size()-1; i>=0; i--)
    {
        while(j<(int)v.size() && v[i].first+v[j].first<=R0)
        {
            add(v[j].second, 1);
            j++;
        }
        ret+=sum(R1-v[i].second);
        if(j>=i && v[i].first*2<=R0 && v[i].second*2<=R1)
            ret--;
    }
    for(int i=0; i<j; i++)
        add(v[i].second, -1);
    return ret/2;
}

long long work(vector<pair<int, int>>& v)
{
    sort(v.begin(), v.end());
    return work(v, RK, RC)-work(v, LK-1, RC)-work(v, RK, LC-1)+work(v, LK-1, LC-1);
}

void solve(int u)
{
    dfs(u, -1);
    while(1)
    {
        int idx=-1;
        for(auto& v: adj[u]) if(!bad[v] && (idx==-1 || sz[v]>sz[idx]))
            idx=v;
        if(sz[idx]*2<=sz[u])
            break;
        sz[u]-=sz[idx];
        sz[idx]+=sz[u];
        u=idx;
    }
    if((A[u]=='K' && LK<=1 && LC==0) || (A[u]=='C' && LC<=1 && LK==0))
        ans++;
    if((A[u]=='K' && RK==0) || (A[u]=='C' && RC==0))
        goto skip;
    if(A[u]=='K')
        LK--, RK--;
    else
        LC--, RC--;
    V.clear();
    all.clear();
    for(auto& v: adj[u]) if(!bad[v])
    {
        V.push_back(vector<pair<int, int>>());
        dfs2(v, u, 0, 0);
        for(auto& it: V.back())
            if(LK<=it.first && it.first<=RK && LC<=it.second && it.second<=RC)
                ans++;
    }
    ans+=work(all);
    for(auto& it: V)
        ans-=work(it);
    if(A[u]=='K')
        LK++, RK++;
    else
        LC++, RC++;
    skip:;
    bad[u]=true;
    cout << u << " " << ans << '\n';
    for(auto& v: adj[u]) if(!bad[v])
        solve(v);
}

int dfs_bf(int u, int p, int K, int C)
{
    if(A[u]=='K')
        K++;
    else
        C++;
    int ret=0;
    if(LK<=K && K<=RK && LC<=C && C<=RC)
        ret++;
    for(auto& v: adj[u]) if(v!=p)
        ret+=dfs_bf(v, u, K, C);
    return ret;
}

long long solve_bf()
{
    long long ret=0;
    for(int i=1; i<=N; i++)
    {
        ret+=dfs_bf(i, -1, 0, 0);
        if(LK<=(A[i]=='K') && (A[i]=='K')<=RK && LC<=(A[i]=='C') && (A[i]=='C')<=RC)
            ret++;
    }
    return ret/2;
}

int main()
{
    scanf("%d%d%d%d%d", &N, &LK, &RK, &LC, &RC);
    scanf("%s", A+1);
    int a, b;
    for(int i=1; i<N; i++)
    {
        scanf("%d%d", &a, &b);
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    solve(1);
    printf("%lld\n", ans);
    //printf("%lld\n", solve_bf());
    return 0;
}
