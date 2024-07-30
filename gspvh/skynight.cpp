#include <bits/stdc++.h>
using namespace std;

#define real unreal

const int N = 5005;

int m, n, r, c, a[N][N];
int real[255];

inline int get(int x1, int y1, int x2, int y2) {
  return a[x2][y2] - a[x1 - 1][y2] - a[x2][y1 - 1] + a[x1 - 1][y1 - 1];
}

int32_t main() {
  cin.tie(0)->sync_with_stdio(0);
  if (fopen("skynight.inp", "r"))
    freopen("skynight.inp", "r", stdin),
    freopen("skynight.out", "w", stdout);
  for (int i = '0'; i <= '9'; i++)
    real[i] = i - '0';
  for (int i = 'A'; i <= 'Z'; i++)
    real[i] = 10 + i - 'A';
  for (int i = 'a'; i <= 'z'; i++)
    real[i] = 36 + i - 'a';
  real['#'] = 62;
  real['$'] = 63;
  int ans = 0;
  cin >> m >> n >> r >> c;
  for (int i = 1; i <= m; i++) {
    string s; 
    cin >> s;
    for (int j = 0; j < n; j++) 
      a[i][j + 1] = real[(int)s[(j / 6)]] >> (j % 6) & 1;
    for (int j = 1; j <= n; j++) {
      a[i][j] += a[i][j - 1] + a[i - 1][j] - a[i - 1][j - 1];
      if (i >= r && j >= c)
        ans = max(ans, get(i - r + 1, j - c + 1, i, j));
    }
  }
  cout << ans;
  return 0;
}