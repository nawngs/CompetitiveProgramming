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
#define ld long double
#define nmax 50007
void faster()
{
    ios_base::sync_with_stdio(false);   
    cin.tie(NULL);
    cout.tie(NULL);
}

vector < pair < int , ll > > adj[nmax];
int n, m, k;
pair < int , ll > a[nmax];
ll d[nmax]; 
ll t[nmax];

void Dijkstra()
{
    FOR(i, 1, n) d[i] = -1e18;
    d[n] = 0;
    set < pair < ll , int > > myset;
    myset.clear();
    myset.insert({0, n});
    while(myset.size())
    {
        auto p = *myset.rbegin();
        myset.erase(p);
        ll val = p.fi;
        int u = p.se;
        if(val < d[u]) continue;
        for(auto V: adj[u])
        {
            int v = V.fi;
            ll w = V.se;
            if(d[v] < d[u] - w)
            {
                d[v] = d[u] - w;
                myset.insert({d[v] , v});
            }
        }
    }

}

void Dijkstra2()
{
    set < pair < ll , int > > myset;
    myset.clear();
    FOR(i, 1, n)
        t[i] = -1e18;
    FOR(i, 1, k)
    {
        t[a[i].fi] = d[a[i].fi] + a[i].se;
        myset.insert({t[a[i].fi] , a[i].fi});
    }
    while(myset.size())
    {
        auto p = *myset.rbegin();
        myset.erase(p);
        ll val = p.fi;
        int u = p.se;
        if(val < t[u]) continue;
        for(auto V: adj[u])
        {
            int v = V.fi;
            ll w = V.se;
            if(t[v] < t[u] - w)
            {
                t[v] = t[u] - w;
                myset.insert({t[v] , v});
            }
        }
    }
}

int main()
{
    
    faster();
    freopen("Trove.inp","r",stdin);
    freopen("Trove.out","w",stdout);  
    cin >> n >> m >> k;

    while(m--)
    {
        int u, v;
        ll w;
        cin >> u >> v >> w;
        adj[u].pb({v, w});
        adj[v].pb({u, w});
    }
    FOR(i, 1, k) cin >> a[i].fi >> a[i].se;
    Dijkstra();
    Dijkstra2();
    //FOR(i, 1, n - 1) cout << d[i] << '\n';
    //FOR(i, 1, n - 1) cout << t[i] << '\n';
    FOR(i, 1, n - 1)
        cout << (t[i] >= d[i]) << '\n';
    return 0;

}