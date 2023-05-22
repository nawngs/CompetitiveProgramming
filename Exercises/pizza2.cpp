#include <bits/stdc++.h>

#define ll long long

using namespace std;

const ll INF = 1E16;

struct Store {
    ll s, p, id;
} a[100003];

struct Customer {
    ll c, id;
    vector < ll > InValid;
} b[100003];

ll n, m, val[100003], it[800003], lazy[800003], res[100003];

void build_tree(int node, int l, int r) {
    if (l == r) {
        it[node] = a[l].p + a[l].s;
        return ;
    }
    int mid = (l + r) / 2;
    build_tree(node * 2, l, mid);
    build_tree(node * 2 + 1, mid + 1, r);
    it[node] = min(it[node * 2], it[node * 2 + 1]);
}

void update(int node, int l, int r) {
    if (lazy[node] != 0) {
        it[node] += lazy[node];
        if (l != r) {
            lazy[node * 2] += lazy[node];
            lazy[node * 2 + 1] += lazy[node];
        }
        lazy[node] = 0;
    }
}

void update(int node, int l, int r, int u, int v, int val) {
    update(node, l, r);
    if (v < l || r < u) return ;
    if (u <= l && r <= v) {
        lazy[node] = val;
        update(node, l, r);
        return ;
    }
    int mid = (l + r) / 2;
    update(node * 2, l, mid, u, v, val);
    update(node * 2 + 1, mid + 1, r, u, v, val);
    it[node] = min(it[node * 2], it[node * 2 + 1]);
}

ll query(int node, int l, int r, int u, int v) {
    update(node, l, r);
    if (v < l || r < u) return INF;
    if (u <= l && r <= v) return it[node];
    int mid = (l + r) / 2;
    return min(query(node * 2, l, mid, u, v), query(node * 2 + 1, mid + 1, r, u, v));
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("pizza2.inp", "r", stdin);
    freopen("pizza2.out", "w", stdout);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> a[i].s >> a[i].p;
        a[i].id = i;
    }
    sort(a + 1, a + n + 1, [&](Store &x, Store &y) {
         return x.s < y.s;
    });
    for (int i = 1; i <= n; i++) val[a[i].id] = i;
    for (int i = 1; i <= m; i++) {
        cin >> b[i].c;
        b[i].id = i;
        int k; cin >> k;
        b[i].InValid.push_back(0);
        while (k--) {
            int x;
            cin >> x;
            b[i].InValid.push_back(val[x]);
        }
        b[i].InValid.push_back(n + 1);
        sort(b[i].InValid.begin(), b[i].InValid.end());
    }
    sort(b + 1, b + m + 1, [&](Customer &x, Customer &y) {
         return x.c < y.c;
    });
    build_tree(1, 1, n);
    int cur = 0;
    for (int i = 1; i <= m; i++) {
        if (cur > 0)
            update(1, 1, n, 1, cur, b[i].c - b[i - 1].c);
        while (cur + 1 <= n && a[cur + 1].s <= b[i].c) {
            cur ++;
            update(1, 1, n, cur, cur, b[i - 1].c + b[i].c - 2 * a[cur].s);
        }
        if (cur + 1 <= n) update(1, 1, n, cur + 1, n,b[i - 1].c - b[i].c);
        ll &ans = res[b[i].id];
        ans = INF;
        for (int j = 0; j < b[i].InValid.size() - 1; j++) {
            if (b[i].InValid[j] + 1 <= b[i].InValid[j + 1] - 1)
                ans = min(ans, query(1, 1, n, b[i].InValid[j] + 1, b[i].InValid[j + 1] - 1));
        }
    }
    for (int i = 1; i <= m; i++) cout << res[i] << " ";
}
