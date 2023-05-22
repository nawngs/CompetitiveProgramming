#include<bits/stdc++.h>
#define pb push_back
#define pi pair<int, int>
#define fi first
#define se second
using namespace std;
const int N = 5e5 + 5;

int n;
vector<int> adj[N];

namespace sub1{
    int par[15], a[15], c[15];
    int tc[15], d[15], cnt[15], up[15];

    void dfs(int u, int pu){
        for (int v : adj[u]) if ( v != pu ){
            par[v] = u;
            dfs(v, u);
        }
    }

    void solve(){
        dfs(1, 0);
        for (int i = 1; i <= n; i ++)
            a[i] = i;
        for (int i = 1; i <= n; i ++)
            c[i] = n + 1;

        do{
            if ( a[1] != 1 ) continue;
            for (int i = 1; i <= n; i ++)
                d[i] = cnt[i] = up[i] = 0;

            int cur = 1;
            tc[1] = 1;
            d[1] = 1;
            up[1] = 0;

            for (int i = 2; i <= n; i ++){
                if ( d[par[a[i]]] && cnt[par[a[i]]] < ( up[par[a[i]]] ? 1 : 2 ) ){
                    tc[a[i]] = tc[par[a[i]]];
                    up[a[i]] = 1;
                    cnt[par[a[i]]] ++;
                }
                else tc[a[i]] = ++cur;
                d[a[i]] = 1;
            }

            for (int i = 1; i <= n; i ++) if ( c[i] != tc[i] ){
                if ( c[i] < tc[i] ) break;

                for (int j = 1; j <= n; j ++)
                    c[j] = tc[j];

                break;
            }
        }while ( next_permutation(a+1, a+1+n) );

        for (int i = 1; i <= n; i ++)
            cout << c[i] << ' ';
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

//    if ( fopen("trash.inp", "r") ){
//        freopen("trash.inp", "r", stdin);
//        freopen("trash.out", "w", stdout);
//    }

    cin >> n;
    for (int i = 1; i < n; i ++){
        int u, v;
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }

    if ( n <= 10 ) sub1::solve();

    return 0;
}
