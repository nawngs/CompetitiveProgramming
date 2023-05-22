#include <bits/stdc++.h>

using namespace std;

int n, d, a[2003], pos[2003], f[2003];

int dp[2003], it[8003];

void update(int node, int l, int r, int pos, int val) {
    if (pos < l || pos > r) return ;
    it[node] = max(it[node], val);
    if (l == r) return ;
    int mid = (l + r) / 2;
    update(node * 2, l, mid, pos, val); update(node * 2 + 1, mid + 1, r, pos, val);
}

int query(int node, int l, int r, int u, int v) {
    if (v < l || r < u) return 0;
    if (u <= l && r <= v) return it[node];
    int mid = (l + r) / 2;
    return max(query(node * 2, l, mid, u, v), query(node * 2 + 1, mid + 1, r, u, v));
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("noel.inp", "r", stdin);
    freopen("noel.out", "w", stdout);
    cin >> n >> d; n *= 2;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        pos[a[i]] = i;
    }
    int res = 1;
    for (int lst = 1; lst <= n; lst++) {
        memset(it, 0, sizeof(it));
        for (int i = lst + 1; i <= n; i++) {
            dp[i] = 0;
            for (int nxt = max(1, a[i] - d); nxt <= min(n, a[i] + d); nxt++)
                 if (pos[nxt] <= lst) {
                    f[nxt] = (pos[nxt] > 1 ? query(1, 1, n, 1, pos[nxt] - 1) : 0);
                    dp[i] = max(dp[i], f[nxt] + 1);
                 }
            res = max(res, dp[i]);
             for (int nxt = max(1, a[i] - d); nxt <= min(n, a[i] + d); nxt++)
                 if (pos[nxt] <= lst)
                    update(1, 1, n, pos[nxt], f[nxt] + 1);
        }
    }
    cout << res;
}
