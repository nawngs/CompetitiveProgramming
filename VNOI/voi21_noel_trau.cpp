#include <bits/stdc++.h>

using namespace std;

int n, d, a[203], dp[203][203][203];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("noel.inp", "r", stdin);
    freopen("noel.ans", "w", stdout);
    cin >> n >> d; n *= 2;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    int res = 0;
    for (int lst = 1; lst <= n; lst++)
        for (int i = 1; i <= lst; i++)
            for (int j = lst + 1; j <= n; j++) {
                dp[lst][i][j] = max(dp[lst][i][j - 1], dp[lst][i - 1][j]);
                if (abs(a[i] - a[j]) <= d) dp[lst][i][j] = max(dp[lst][i][j], dp[lst][i - 1][j - 1] + 1);
                res = max(res, dp[lst][i][j]);
            }
    cout << res;
}
