#include<bits/stdc++.h>
#define simon "talltree"
#define pi pair<int, int>
#define fi first
#define se second
#define pb push_back
using namespace std;
const int N = 5e5 + 5;
const int MOD = 998244353;

int sub, n, q, timeDfs;
int sta[N], fin[N], hi[N], h[N];
vector<int> g[N];
struct node{
    pi com; int scom;
    pi hig; int shig;
} st[3*N];

int add(int a, int b){
    a += b;
    if ( a >= MOD ) a -= MOD;
    if ( a < 0 ) a += MOD;
    return a;
}

int mul(int a, int b){
    return 1LL * a * b % MOD;
}

void dfs(int u){
    sta[u] = ++timeDfs;
    for (int v : g[u])
        hi[v] = hi[u] + 1, dfs(v);
    fin[u] = timeDfs;
}

void build(int id, int l, int r){
    if ( l == r ){
        st[id].scom = 1;
        st[id].shig = h[l];
        return;
    }
    int mid = l + r >> 1;
    build(id*2, l, mid);
    build(id*2+1, mid+1, r);
    st[id].scom = add(st[id*2].scom, st[id*2+1].scom);
    st[id].shig = add(st[id*2].shig, st[id*2+1].shig);
}

void down(int id){
    for (int i = id*2; i <= id*2+1; i ++){
        st[i].com.se = add(st[i].com.se, st[id].com.se);
        st[i].com.fi = add(st[i].com.fi, mul(st[i].scom, st[id].com.se));

        st[i].hig.se = add(st[i].hig.se, st[id].hig.se);
        st[i].hig.fi = add(st[i].hig.fi, mul(st[i].shig, st[id].hig.se));
    }
    st[id].com.se = st[id].hig.se = 0;
}

void update(int id, int l, int r, int u, int v, int val1, int val2){
    if ( l > v || r < u ) return;
    if ( u <= l && r <= v ){
        st[id].com.fi = add(st[id].com.fi, mul(val1, st[id].scom));
        st[id].com.se = add(st[id].com.se, val1);

        st[id].hig.fi = add(st[id].hig.fi, mul(val2, st[id].shig));
        st[id].hig.se = add(st[id].hig.se, val2);

        return;
    }

    down(id);
    int mid = l + r >> 1;
    update(id*2, l, mid, u, v, val1, val2);
    update(id*2+1, mid+1, r, u, v, val1, val2);

    st[id].com.fi = add(st[id*2].com.fi, st[id*2+1].com.fi);
    st[id].hig.fi = add(st[id*2].hig.fi, st[id*2+1].hig.fi);
}

int get(int id, int l, int r, int u, int v){
    if ( l > v || r < u ) return 0;
    if ( u <= l && r <= v )
        return add(st[id].com.fi, st[id].hig.fi);

    down(id);
    int mid = l + r >> 1;

    return add(get(id*2, l, mid, u, v), get(id*2+1, mid+1, r, u, v));
}

int main(){

    cin >> sub >> n;
    for (int i = 2, u; i <= n; i ++)
        cin >> u, g[u].pb(i);

    dfs(1);

    for (int i = 1; i <= n; i ++) h[sta[i]] = hi[i];
    build(1, 1, n);

    string type;
    int u, k, l;
    cin >> q;
    while ( q -- ){
        cin >> type >> u;
        if ( type[0] == 'a' ){
            cin >> k >> l;
            k = add(0, k);
            l = add(0, l);

            int val1 = add(k, mul(l, hi[u]));
            int val2 = add(0, -l);

            update(1, 1, n, sta[u], fin[u], val1, val2);
        }
        else
            cout << get(1, 1, n, sta[u], type[0] == 'g' ? sta[u] : fin[u]) << ' ';
    }

    return 0;
}