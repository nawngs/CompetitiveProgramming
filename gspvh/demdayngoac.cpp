#include <bits/stdc++.h>
using namespace std;

const int N = 630000 * 2 + 5, mod = 1e9 + 19972207;
int fac[N], inv[N];

inline int nCr(int n, int r) {
  if (r > n) return 0;
  return 1LL * fac[n] * inv[r] % mod * inv[n - r] % mod;
}

int pw(int a, int b) {
  int ans = 1;
  for (; b; b /= 2, a = 1LL * a * a % mod)
    if (b & 1) ans = 1LL * ans * a % mod;
  return ans;
}

int32_t main() {
  cin.tie(0)->sync_with_stdio(0);
  string s;
  cin >> s;
  int n = s.size();
  vector<int> open(n + 3, 0), close(n + 3, 0);
  for (int i = 1; i <= n; i++) open[i] = open[i - 1] + (s[i - 1] == '(');
  for (int i = n; i > 0; i--) close[i] = close[i + 1] + (s[i - 1] == ')');
  fac[0] = 1;
  for (int i = 1; i < N; i++) fac[i] = 1LL * fac[i - 1] * i % mod;
  inv[N - 1] = pw(fac[N - 1], mod - 2);
  for (int i = N - 2; i >= 0; i--) inv[i] = 1LL * inv[i + 1] * (i + 1) % mod;
  int ans = 0;
  for (int i = 1; i < n; i++) if (s[i - 1] == '(' && open[i] > 0 && close[i + 1] > 0) {
    ans += nCr(open[i] - 1 + close[i + 1], close[i + 1] - 1);
    if (ans >= mod) ans -= mod;
  }
  cout << ans;
  return 0;
}