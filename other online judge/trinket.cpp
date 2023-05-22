#include <bits/stdc++.h>

#define int long long

using namespace std;

int n, a[100003], it[800003], vt[100003], lazy[800003], suff[100003], k;

vector < int > pos[100003];

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
    it[node] = max(it[node * 2], it[node * 2 + 1]);
}

void solve() {
    cin >> n >> k;
    for (int i = 1; i <= 100000; i++)
        pos[i].clear();
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        suff[a[i]] = n + 1;
        pos[a[i]].push_back(i);
        vt[i] = pos[a[i]].size() - 1;
    }
    memset(it, 0, sizeof(it));
    memset(lazy, 0, sizeof(lazy));
    int res = 0;
    for (int l = n; l >= 1; l--) {
        update(1, 1, n + 1, l, suff[a[l]], 1);
        if ((int)pos[a[l]].size() - 1 >= vt[l] + k) {
            int last = pos[a[l]][vt[l] + k];
            update(1, 1, n + 1, last, suff[a[l]], -k - 1);
            suff[a[l]] = last - 1;
        }
        //cout << l << " " << it[1] << '\n';
        res = max(res, it[1]);
    }
    cout << res << '\n';
}

signed main() {
    int t; cin >> t;
    while (t--) solve();
}