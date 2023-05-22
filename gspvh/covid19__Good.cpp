#include <bits/stdc++.h>
using namespace std;
#define print(x) cout<<"["<<(x)<<"]"
#define int ll
using ll = long long;
const int N = 5e5 + 5;
const ll mod = 998244353;
const ll INF = 1e9;
struct node {
    ll mind, hs_min, sum, lz;
} seg[4*N];
void normalize(ll& x) {
    if (x < 0) x += mod;
}
ll add(ll x, ll y) {
    normalize(x); normalize(y);
    x += y;
    if (x >= mod) x-= mod;
    return x;
}
ll sub(ll x, ll y) {
    normalize(x); normalize(y);
    x -= y;
    if (x < 0) x += mod;
    return x;
}
ll mul(ll x, ll y) {
    normalize(x); normalize(y);
    x *= y;
    x %= mod;
    return x;
}
ll pw[N], pref[N];
ll get_pw(int l, int r) {
    return sub(pref[r], pref[l - 1]);
}
int n, k, q;
void comb(node &res, node x, node y) {
    res.mind = min(x.mind, y.mind);
    //cout << x.mind << " " << y.mind << '\n';
    res.sum = add(x.sum, y.sum);
    res.hs_min = 0;
    if (res.mind == x.mind) res.hs_min = add(res.hs_min, x.hs_min);
    if (res.mind == y.mind) res.hs_min = add(res.hs_min, y.hs_min);
}
void build(int root, int tl, int tr) {
    if (tl == tr) {
        seg[root].mind = INF;
        seg[root].hs_min = pw[tl];
        seg[root].sum = mul(pw[tl], -1);
        seg[root].lz = INF;
        return;
    }
    int tm = (tl + tr) / 2;
    build(2*root, tl, tm);
    build(2*root + 1, tm + 1, tr);
    seg[root].lz = INF;
    comb(seg[root], seg[2*root], seg[2*root + 1]);
}
void upd(int root, int tl, int tr, ll v) {
    if (v >= INF) return;
    if (v < seg[root].mind) {
        seg[root].mind = v;
        seg[root].hs_min = get_pw(tl, tr);
        seg[root].sum = mul(seg[root].hs_min, seg[root].mind);
    } else {
        seg[root].sum = add(mul(sub(get_pw(tl, tr), seg[root].hs_min), v), mul(seg[root].hs_min, seg[root].mind));
    }
    seg[root].lz = min(seg[root].lz, v);
}
void update(int root, int tl, int tr, int l, int r, ll v) {
    if (tl > r || tr < l) return;
    if (tl >= l && tr <= r) {
        upd(root, tl, tr, v);
        return;
    }
    int tm = (tl + tr) / 2;
    ll x = seg[root].lz;
    seg[root].lz = INF;
    upd(2*root, tl, tm, x);
    upd(2*root + 1, tm + 1, tr, x);
    update(2*root, tl, tm, l, r, v);
    update(2*root + 1, tm + 1, tr, l, r, v);
    comb(seg[root], seg[2*root], seg[2*root + 1]);
}
ll get_min(int root, int tl, int tr, int l, int r) {
    if (tl > r || tr < l) return INF;
    if (tl >= l && tr <= r) return seg[root].mind;
    int tm = (tl + tr) / 2;
    ll x = seg[root].lz;
    seg[root].lz = INF;
    upd(2*root, tl, tm, x);
    upd(2*root + 1, tm + 1, tr, x);
    return min(get_min(2*root, tl, tm, l, r),
               get_min(2*root + 1, tm + 1, tr, l, r));
}
ll get_sum(int root, int tl, int tr, int l, int r) {
    if (tl > r || tr < l) return INF;
    if (tl >= l && tr <= r) return seg[root].sum;
    int tm = (tl + tr) / 2;
    ll x = seg[root].lz;
    seg[root].lz = 0;
    upd(2*root, tl, tm, x);
    upd(2*root + 1, tm + 1, tr, x);
    return add(get_sum(2*root, tl, tm, l, r),
               get_sum(2*root +1, tm + 1, tr, l, r));
}
void pro(int root, int tl, int tr) {
    if (tl == tr) {
        print(seg[root].hs_min);
        return;
    }
    int tm = (tl + tr) / 2;
    pro(2*root, tl, tm);
    pro(2*root + 1, tm + 1, tr);
}
void xout() {
    for (int i = 1; i <= n; i++) print(get_min(1, 1, n, i, i));
    cout << '\n';
}
signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    // freopen("covid19.inp", "r", stdin);
    // freopen("covid19.out", "w", stdout);
    int t;
    cin >> t >> n >> k >> q;
    pw[0] = 1;
    for (int i = 1; i <= n; i++)
    pw[i] = mul(pw[i - 1], (n + 1)),
    pref[i] = add(pref[i - 1], pw[i]);
    build(1, 1, n);
    //xout();
    //cout << seg[1].sum << '\n';
    //for (int i = 1; i < 2*n; i++) cout << seg[i].mind << " ";
    for (int i = 1; i <= k; i++) {
        int x;
        cin >> x;
        update(1, 1, n, x, x, 0);
    }
    //xout();
    cout << get_sum(1, 1, n, 1, n) << '\n';
    //cout << seg[1].sum << '\n';
    while (q--) {
        char x;
        int u, v;
        cin >> x >> u >> v;
        if (x == 'D') {
            ll p1 = get_min(1, 1, n, u, u) + 1;
            ll p2 = get_min(1, 1, n, v, v) + 1;
            if (p1 < p2 - 1) update(1, 1, n, v, v, p1);
            if (p2 < p1 - 1) update(1, 1, n, u, u, p2);
        } else {
            ll p = get_min(1, 1, n, u, v) + 1;
            update(1, 1, n, u, v, p);
        }
        cout << get_sum(1, 1, n, 1, n) << '\n';
    }
}