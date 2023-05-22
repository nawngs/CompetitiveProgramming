#include<bits/stdc++.h>
#define pb push_back
#define int long long
using namespace std;
const int N = 2e5 + 5;
const int MOD = 1e9 + 7;

int n, m;
int d[N], una[N], una1[N];
vector<int> sta[N];

int add(int a, int b){
    a += b;
    if ( a >= MOD ) a -= MOD;
    if ( a < 0 ) a += MOD;
    return a;
}

int mul(int a, int b){
    return 1LL * a * b % MOD;
}

int pw2(int x){
    if ( x == 0 ) return 1;
    int tmp = pw2(x/2);
    if ( x % 2 ) return mul(tmp, mul(tmp, 2));
    else return mul(tmp, tmp);
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

//    if ( fopen("rsgraph.inp", "r") ){
//        freopen("rsgraph.inp", "r", stdin);
//        freopen("rsgraph.out", "w", stdout);
//    }

    cin >> n >> m;
    bool gra = 1;
    sta[0].pb(1);
    for (int i = 2; i <= n; i ++){
        cin >> d[i];
        if ( d[i] == 0 ) gra = 0;
        sta[d[i]].pb(i);
    }

    for (int i = 1; i <= m; i ++){
        int u, v;
        cin >> u >> v;

        if ( d[u] < d[v] ) swap(u, v);
       // cout << u << " " << v << " " << d[u] << " " << d[v] << '\n';
        if ( d[u] - d[v] > 1 ) gra = 0;
        else if ( d[u] == d[v] ) una[d[u]] ++;
        else if ( d[u] == d[v] + 1 ) una1[u] ++;
    }

    if ( !gra ) return cout << 0, 0;

    int ans = 1;
    for (int i = 1; i <= n; i ++){
        int tmp = sta[i].size();
        tmp = add(1LL * tmp * (tmp-1) / 2, -una[i]);
        ans = mul(ans, pw2(tmp));
    }

    for (int i = 1; i <= n; i ++) {
        for (int u : sta[i]) {
            ans = mul(ans, add(pw2(sta[i-1].size()-una1[u]), -(!una1[u])));
        }
    }
    cout << ans;

    return 0;
}
