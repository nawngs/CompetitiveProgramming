#include <bits/stdc++.h>

using namespace std;

int n, d, a[2003];

int dp[203][203][203];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    //freopen("noel.inp", "r", stdin);
    //freopen("noel.out", "w", stdout);
    cin >> n >> d; n *= 2;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    int res = 1;
    for (int lst = 1; lst <= n; lst++)
        for (int i = 1; i <= lst; i++)
            for (int j = lst + 1; j <= n; j++) {
                dp[i][j][lst] = max(dp[i - 1][j][lst], dp[i][j - 1][lst]);
                if (abs(a[i] - a[j]) <= d) dp[i][j][lst] = max(dp[i][j][lst], dp[i - 1][j - 1][lst] + 1);
                res = max(res, dp[i][j][lst]);
            }
    cout << res;
}
