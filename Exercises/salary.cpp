#include <bits/stdc++.h>

#define pii pair < int, int >
#define fi first
#define se second

using namespace std;

int n, m, a[20], b[20];

pii dp[1 << 20];

void solve() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < m; i++) cin >> b[i];
    dp[0] = {0, 0};
    for (int i = 1; i < (1 << m); i++) {
        dp[i] = {-1, -1};
        for (int j = 0; j < m; j++) {
            if ((i >> j) & 1) {
                if (dp[i].fi > dp[i ^ (1 << j)].fi) continue;
                if (dp[i ^ (1 << j)].se + b[j] <= a[dp[i ^ (1 << j)].fi]) {
                    dp[i] = dp[i ^ (1 << j)];
                    dp[i].se += b[j];
                }
                if (dp[i].se == a[dp[i].fi]) {
                    dp[i].fi ++;
                    dp[i].se = 0;
                }
                if (dp[i].fi == n) {
                    cout << "Yes" << '\n';
                    return ;
                }
            }
        }
    }
    cout << "No" << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("salary.inp", "r", stdin);
    freopen("salary.out", "w", stdout);
    int t;
    cin >> t;
    while (t--) solve();
}
