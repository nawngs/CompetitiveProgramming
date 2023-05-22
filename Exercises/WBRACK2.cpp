#include <bits/stdc++.h>

#define ll long long

using namespace std;

ll n, k, dp[123][123], Ckn[245][245];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("WBRACK2.inp", "r", stdin);
    freopen("WBRACK2.out", "w", stdout);
    cin >> n >> k;
    dp[0][0] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= n; j++) {
            if (j > i) break;
            if (i != 0) dp[i][j] += dp[i - 1][j];
            if (j != 0) dp[i][j] += dp[i][j - 1];
        }
    }
    for (int i = 0; i <= 2 * n; i++)
        for (int j = 0; j <= 2 * n; j++) {
            if (i == 0 || i == j) Ckn[i][j] = 1;
            else Ckn[i][j] = Ckn[i][j - 1] + Ckn[i - 1][j - 1];
        }
    bool good = 1;
    ll cnt1 = n, cnt2 = n, cur = 0;
    string res = "";
    for (int i = 1; i <= 2 * n; i++) {
        if (cnt2 == 0 || (cnt1 != 0 && k <= (good ? Ckn[cnt2][2 * n - i] - dp[cnt2][cnt1 - 1] : Ckn[cnt2][2 * n - i]))) {
            res += '(';
            cnt1 --;
            cur ++;
        }
        else {
            k -= (good ? Ckn[cnt2][2 * n - i] - dp[cnt2][cnt1 - 1] : Ckn[cnt2][2 * n - i]);
            res += ')';
            cnt2 --;
            cur --;
        }
        if (cur < 0) good = false;
    }
    cout << res;
}
