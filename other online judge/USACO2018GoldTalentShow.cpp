#include <bits/stdc++.h>

#define ll long long

using namespace std;

const double BASE = 1E3;
const int INF = 1E9 + 7;

ll n, W, w[253];

double t[253], v[253], dp[2][1003];

bool check(double x) {
    x /= BASE;
    for (int i = 1; i <= n; i++) {
        v[i] = t[i] - w[i] * x;
    }
    for (int i = 0; i <= 1; i++)
        for (int j = 0; j <= W; j++)
            dp[i][j] = -INF;
    dp[0][0] = 0;
    for (int t = 1; t <= n; t++) {
        int i = t & 1;
        for (int j = 0; j <= W; j++)
            dp[i][j] = -INF;
        for (int j = 0; j <= W; j++) {
            dp[i][j] = max(dp[i][j], dp[i ^ 1][j]);
            dp[i][min(W, j + w[t])] = max(dp[i][min(W, j + w[t])], dp[i ^ 1][j] + v[t]);
        }
    }
    return dp[n & 1][W] >= 0;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("talent.in", "r", stdin);
    freopen("talent.out", "w", stdout);
    cin >> n >> W;
    for (int i = 1; i <= n; i++) {
        cin >> w[i] >> t[i];
    }
    int l = 0, r = 1e9, mid, ans = -1;
    while (l <= r) {
        mid = (l + r) / 2;
        if (check(mid)) {
            ans = mid;
            l = mid + 1;
        }
        else r = mid - 1;
    }
    cout << ans;
}
