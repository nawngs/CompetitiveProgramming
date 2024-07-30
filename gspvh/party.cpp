// Judges with GCC >= 12 only needs Ofast
#pragma GCC optimize("O3,no-stack-protector,fast-math,unroll-loops,tree-vectorize")
// MLE optimization
// #pragma GCC optimize("conserve-stack")
// Old judges
// #pragma GCC target("sse4.2,popcnt,lzcnt,abm,mmx,fma,bmi,bmi2")
// New judges. Test with assert(__builtin_cpu_supports("avx2"));
// #pragma GCC target("avx2,popcnt,lzcnt,abm,bmi,bmi2,fma,tune=native")
// Atcoder
// #pragma GCC target("avx2,popcnt,lzcnt,abm,bmi,bmi2,fma")
#include <bits/stdc++.h>
using namespace std;
#define int short
const int N = 2005;
int n, a[N], dp[N][N];
void trace(int l, int r) {
    if (l > r) return;
    for (int i = l+1; i <= r; i += 2) {
        if ((a[l] == a[i]) + dp[l+1][i-1] + dp[i+1][r] == dp[l][r]) {
            cout << l << " " << i << '\n';
            trace(l+1, i-1);
            trace(i+1, r);
            return;
        }
    }

}
signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    freopen("party.inp", "r", stdin);
    freopen("party.out", "w", stdout);
    cin >> n;
    for (int i = 1; i <= n; i++)  cin >> a[i];
    for (int i = 1; i < n; i++) dp[i][i+1] = (a[i] == a[i+1]);
    for (int i = n - 3; i >= 1; i--) {
        for (int j = i + 3; j <= n; j+=2) {
            dp[i][j] = max(dp[i][j], (int)((a[i] == a[j]) + dp[i+1][j-1]));
            for (int r = i+1; r < j; r+=2) 
                dp[i][j] = max(dp[i][j], (int)(dp[i][r] + dp[r+1][j]));
        }
    }
    cout << dp[1][n] << '\n';
    //trace(1, n);
}