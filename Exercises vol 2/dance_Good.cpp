#include<bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 1005;
int a[N]; ll dp[N][N];
int n, k;
int main() {
  cin.tie(0)->sync_with_stdio(0); cout.tie(0);
  if (fopen("dance.inp", "r")) 
    freopen("dance.inp", "r", stdin),
    freopen("dance.out", "w", stdout);
  cin >> n >> k;
  for (int i = 0; i < n; ++i)
    cin >> a[i];
  sort(a, a + n);
  for (int i = 0; i < n-1; ++i)
    a[i] = a[i + 1] - a[i];
  memset(dp, 0x3f, sizeof(dp));
  dp[0][0] = dp[1][0] = 0;
  for (int i = 2; i <= n; ++i) for (int j = 0; j <= k; ++j) {
    dp[i][j] = dp[i - 1][j];
    if (j > 0) dp[i][j] = min(dp[i][j], dp[i-2][j-1] + a[i-2]);
  }
  cout << dp[n][k];
	return 0;
}