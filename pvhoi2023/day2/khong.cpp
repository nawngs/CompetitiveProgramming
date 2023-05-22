#include <bits/stdc++.h>

#define ll long long
#define pll pair < ll, ll >
#define fi first
#define se second

using namespace std;

const int NMAX = 200311;

ll n, q;

pll a[NMAX + 5];

namespace sub1 {
    void solve() {
        while (q--) {
            char c; cin >> c;
            ll l, r, x, y;
            if (c == 'A') {
                cin >> l >> r >> x >> y;
                ll s = x;
                for (int i = l; i <= r; i++) {
                    ll tam = s;
                    while (tam % 2 == 0) {
                        a[i].fi ++;
                        tam /= 2;
                    }
                    while (tam % 5 == 0) {
                        a[i].se ++;
                        tam /= 5;
                    }
                }
                s += y;
            }
            if (c == 'G') {
                cin >> l >> r >> x >> y;
                pll s = make_pair(0, 0), chg = {0, 0};
                while (x != 0 && x % 2 == 0) {
                    s.fi ++;
                    x /= 2;
                }
                while (x != 0 && x % 5 == 0) {
                    s.se ++;
                    x /= 5;
                }
                while (y != 0 && y % 2 == 0) {
                    chg.fi ++;
                    y /= 2;
                }
                while (y != 0 && y % 5 == 0) {
                    chg.se ++;
                    y /= 5;
                }
                //cout << chg.fi << " " << chg.se << '\n';
                for (int i = l; i <= r; i++) {
                    a[i].fi += s.fi; a[i].se += s.se;
                    s.fi += chg.fi; s.se += chg.se;
                }
            }
            if (c == 'C') {
                int l, r; cin >> l >> r;
                pll total = make_pair(0, 0);
                for (int i = l; i <= r; i++) {
                    total.fi += a[i].fi; total.se += a[i].se;
                }
                cout << min(total.fi, total.se) << ' ';
            }
        }
    }
}

pll it[6 * NMAX + 3], lazy[6 * NMAX + 3];

pll operator + (const pll &x, const pll &y) {
    pll res;
    res.fi = x.fi + y.fi; res.se = x.se + y.se;
    return res;
}

void build(int node, int l, int r) {
    if (l == r) {
        it[node] = a[l];
        return ;
    }
    int mid = (l + r) / 2;
    build(node * 2, l, mid); build(node * 2 + 1, mid + 1, r);
    it[node] = it[node * 2] + it[node * 2 + 1];
}

void update(int node, int l, int r) {
    if (lazy[node] != make_pair(0ll, 0ll)) {
        it[node].fi += lazy[node].fi * (r - l + 1);
        it[node].se += lazy[node].se * (r - l + 1);
        if (l != r) {
            lazy[node * 2] = lazy[node * 2] + lazy[node];
            lazy[node * 2 + 1] = lazy[node * 2 + 1] + lazy[node];
        }
        lazy[node] = {0ll, 0ll};
    }
}

void update(int node, int l, int r, int u, int v, pll val) {
    update(node, l, r);
    if (v < l || r < u) return ;
    if (u <= l && r <= v) {
        lazy[node] = val;
        update(node, l, r);
        return ;
    }
    int mid = (l + r) / 2;
    update(node * 2, l, mid, u, v, val); update(node * 2 + 1, mid + 1, r, u, v, val);
    it[node] = it[node * 2] + it[node * 2 + 1];
}

pll query(int node, int l, int r, int u, int v) {
    update(node, l, r);
    if (v < l || r < u) return {0, 0};
    if (u <= l && r <= v) return it[node];
    int mid = (l + r) / 2;
    return query(node * 2, l, mid, u, v) + query(node * 2 + 1, mid + 1, r, u, v);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    freopen("khong.inp", "r", stdin);
    freopen("khong.out", "w", stdout);
    int O; cin >> O;
    cin >> n >> q;
    for (int i = 1; i <= n; i++) {
        int x; cin >> x;
        while (x != 0 && x % 2 == 0) {
            a[i].fi ++;
            x /= 2;
        }
        while (x != 0 && x % 5 == 0) {
            x /= 5;
            a[i].se ++;
        }
    }
    if (O == 1) {
        sub1::solve();
        return 0;
    }
    build(1, 1, n);
    while (q--) {
        char c; cin >> c;
        ll l, r, x, y;
        if (c == 'A' || c == 'G') {
            cin >> l >> r >> x >> y;
            pll chg = {0, 0};
            while (x != 0 && x % 2 == 0) {
                x /= 2;
                chg.fi ++;
            }
            while (x != 0 && x % 5 == 0) {
                x /= 5;
                chg.se ++;
            }
            update(1, 1, n, l, r, chg);
        }
        else {
            cin >> l >> r;
            pll temp = query(1, 1, n, l, r);
            cout << min(temp.fi, temp.se) << ' ';
        }
    }
}
