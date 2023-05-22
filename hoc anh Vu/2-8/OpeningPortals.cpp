#include <bits/stdc++.h>

#define ll long long

using namespace std;

ll n, k, a[4000003], b[4000003], s[4000003], dp[4000003][2][2];

ll get(int l, int r) {
	if (l == 0) return s[r];
    return s[r] - s[l - 1];
}

void sol() {
    cin >> n >> k;
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) cin >> b[i];
    s[0] = b[0];
    for (int i = 1; i <= n + k; i++) s[i] = s[i - 1] + b[(i % n)];
    for (int i = 0; i < n; i++) 
        for (int j = 0; j < 2; j++)
            for (int p = 0; p < 2; p++) dp[i][j][p] = -1e17;
    dp[0][1][1] = a[0] - get(0, k - 1);
    dp[0][0][0] = 0;
    for (int i = 1; i < n; i++) {
        dp[i][0][0] = max(dp[i - 1][0][1], dp[i - 1][0][0]);
        dp[i][0][1] = max(dp[i - 1][0][1] - b[(i + k - 1) % n] + a[i], dp[i - 1][0][0] - get(i, i + k - 1) + a[i]);
        dp[i][1][0] = max(dp[i - 1][1][0], dp[i - 1][1][1]);
        if (i + k - 1 >= n) dp[i][1][1] = max(dp[i - 1][1][1] + a[i], dp[i - 1][1][0] - get(i, n - 1) + a[i]);
        else dp[i][1][1] = max(dp[i - 1][1][1] + a[i] - b[(i + k - 1) % n], dp[i - 1][1][0] + a[i] - get(i, i + k - 1));
    }
    cout << max({dp[n - 1][0][0], dp[n - 1][0][1], dp[n - 1][1][0], dp[n - 1][1][1]}) << '\n';
}

int main() {
    int t;
    cin >> t;
    while (t--) sol();
} //asdasd

