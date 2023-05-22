#include <bits/stdc++.h>

#define ll long long

using namespace std;

ll n, k, dp[123][63], mu[123];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("WBRACKET.inp", "r", stdin);
    freopen("WBRACKET.out", "w", stdout);
    cin >> n >> k;
    dp[0][0] = 1;
    mu[0] = 1;
    for (int i = 1; i <= n; i++) {
        mu[i] = mu[i - 1] * 2;
        if (mu[i] >= 2 * k) mu[i] = 2 * k;
    }
    for (int i = 1; i <= n; i++)
        for (int j = 0; j <= n / 2; j++) {
            dp[i][j] = dp[i - 1][j + 1];
            if (j != 0) dp[i][j] += dp[i - 1][j - 1];
            if (dp[i][j] > k) dp[i][j] = k;
        }
    ll cur = 0;
    string ans = "";
    bool good = true;
    for (int i = 1; i <= n; i++) {
        //cout << good << " " << k << " " << mu[n - i] << '\n';
        if (k <= (good ? mu[n - i] - dp[n - i][cur + 1] : mu[n - i])) {
            ans += '(';
            cur ++;
        }
        else {
            k -= (good ? mu[n - i] - dp[n - i][cur + 1] : mu[n - i]);
            ans += ')';
            cur --;
        }
        good &= (cur >= 0);
    }
    cout << ans;
}
