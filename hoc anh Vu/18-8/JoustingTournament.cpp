#include<bits/stdc++.h>
#define pi pair<int, int>
#define fi first
#define se second
using namespace std;
const int N = 1e5 + 5;

int n, c, Frank;
int Rank[N], s[N], e[N], win[N];
pi st[4*N];

void update(int id, int l, int r, int u, int val, int add){
    if ( l > u || r < u ) return;
    if ( l == r ){
        st[id].fi = val;
        st[id].se = add;
        return;
    }
    int mid = l + r >> 1;
    update(id*2, l, mid, u, val, add);
    update(id*2+1, mid+1, r, u, val, add);

    st[id].fi = max(st[id*2].fi, st[id*2+1].fi);
    st[id].se = st[id*2].se + st[id*2+1].se;
}

int get(int id, int l, int r, int u, int v){
    if ( l > r ) return -1;
    if ( l > v || r < u ) return -1;
    if ( u <= l && r <= v ) return st[id].fi;
    int mid = l + r >> 1;
    return max(get(id*2, l, mid, u, v), get(id*2+1, mid+1, r, u, v));
}

int bin(int k){
    int id = 1, l = 1, r = n;
    while ( l <= r ){
        if ( l == r ) break;
        int mid = l + r >> 1;
        if ( st[id*2].se >= k ) r = mid, id = id*2;
        else k -= st[id*2].se, l = mid + 1, id = id*2+1;
    }

    return l;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    if ( fopen("trash.inp", "r") ){
        freopen("trash.inp", "r", stdin);
        freopen("trash.out", "w", stdout);
    }

    cin >> n >> c >> Frank;
    Rank[n] = -1;
    for (int i = 1; i <= n; i ++){
        if ( i < n ) cin >> Rank[i];
        update(1, 1, n, i, Rank[i], 1);
    }

    // simulator the matches
    set<int> set_id;
    for (int i = 1; i <= n; i ++)
        set_id.insert(i);
    for (int i = 1, l, r; i <= c; i ++){
//        cout << "Round " << i << " : \n";

        cin >> l >> r;
        l ++, r ++;

        // find org
        l = bin(l);
        r = bin(r);
        s[i] = l, e[i] = r;
//        cout << l << ' ' << r << '\n';

        // erase
        int mx = get(1, 1, n, l, r);
        auto it = set_id.find(l);
        while ( *it <= r && it != set_id.end() ){
            if ( Rank[*it] == mx ){
                it ++; continue;
            }

//            cout << "Erase " << *it << '\n';

            update(1, 1, n, *it, -1, 0);
            it = set_id.erase(it);
        }
    }

    // calc number of win matches for each pos
    for (int i = 1; i <= n; i ++)
        update(1, 1, n, i, Rank[i], 1);
    for (int i = 1; i <= c; i ++)
        if ( get(1, 1, n, s[i], e[i]-1) < Frank )
            win[s[i]] ++, win[e[i]+1] --;

    // get ans
    int ans = win[1], pos = 1;
    for (int i = 2; i <= n; i ++){
        win[i] += win[i-1];
//        cout << win[i] <<  ' ';
        if ( ans < win[i] )
            pos = i, ans = win[i];
    }
//    cout << '\n';

    cout << pos-1;

    return 0;
}
