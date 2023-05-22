#include <bits/stdc++.h>

using namespace std;

int n, a[53], dp[53][53][53][53];

int solve(int l, int r, int pre, int suff) {
    if (l > r) return 0;
    if (pre > suff) return -(1 << 20);
    if (dp[l][r][pre][suff] != -1) return dp[l][r][pre][suff];
    if (l == r) {
        if (pre <= a[l] && a[l] <= suff) return 1;
        else return 0;
    }
    int res = 0;
    res = max(res, solve(l + 1, r, pre, suff)); res = max(res, solve(l, r - 1, pre, suff));

    if (pre <= a[l]) res = max(res, solve(l + 1, r, a[l], suff) + 1);
    if (a[r] <= suff) res = max(res, solve(l, r - 1, pre, a[r]) + 1);

    if (pre <= a[r]) res = max(res, solve(l + 1, r - 1, a[r], suff) + 1);
    if (a[l] <= suff) res = max(res, solve(l + 1, r - 1, pre, a[l]) + 1);
    if (pre <= a[r] && a[r] <= a[l] && a[l] <= suff) res = max(res, solve(l + 1, r - 1, a[r], a[l]) + 2);

    dp[l][r][pre][suff] = res;

    return res;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("subrev.in", "r", stdin);
    freopen("subrev.out", "w", stdout);
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    memset(dp, 255, sizeof(dp));
    cout << solve(1, n, 1, 50) << '\n';
}
