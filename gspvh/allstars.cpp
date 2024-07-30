#include <bits/stdc++.h>
using namespace std;

#define real unreal

const int N = 7005;

int m, n, a[N][N], pref[N], cnt[N], p[N];
int real[255];

int32_t main() {
  cin.tie(0)->sync_with_stdio(0);
  if (fopen("allstars.inp", "r"))
    freopen("allstars.inp", "r", stdin),
    freopen("allstars.out", "w", stdout);
  for (int i = '0'; i <= '9'; i++)
    real[i] = i - '0';
  for (int i = 'A'; i <= 'Z'; i++)
    real[i] = 10 + i - 'A';
  for (int i = 'a'; i <= 'z'; i++)
    real[i] = 36 + i - 'a';
  real['#'] = 62;
  real['$'] = 63;
  cin >> m >> n;
  for (int i = 1; i <= m; i++) {
    string s; 
    cin >> s;
    for (int j = 0; j < n; j++) {
      a[i][j + 1] = real[(int)s[(j / 6)]] >> (j % 6) & 1;
      // if (a[i][j + 1]) cout << "*";
      // else cout << ".";
      // if (j == n - 1) cout << '\n';
    }
  }
  array<int, 3> ans {0, 0, 0};
  for (int j = 1; j <= n; j++) {
    for (int i = 1; i <= m; i++) {
      if (a[i][j]) ++pref[i];
      else pref[i] = 0;
      ++cnt[pref[i]];
    }
    int s = 0;
    for (int i = n; i > 0; i--) {
      s += cnt[i];
      if (s * i > ans[0]) 
        ans = {s * i, i, j};
    }
    for (int i = 1; i <= m; i++)
      cnt[pref[i]] = 0;
  }
  iota(p + 1, p + m + 1, 1);
  memset(pref, 0, sizeof pref);
  for (int j = 1; j <= ans[2]; j++) {
    for (int i = 1; i <= m; i++) {
      if (a[i][j]) ++pref[i];
      else pref[i] = 0;
    }
  }
  sort(p + 1, p + m + 1, [] (int x, int y) {
    return pref[x] > pref[y];
  });
  for (int i = 1; i <= m; i++) 
    cout << p[i] << ' ';
  cout << '\n';
  cout << "1 " << ans[0] / ans[1] << ' ' << ans[2] - ans[1] + 1 << ' ' << ans[2];
  // for (int i = 1; i <= m; i++)
    // for (int j = 1; j <= n; j++)
      // cerr << (a[p[i]][j]?'*':'.'), (j == n ? cerr << '\n', 0 : 0);
  return 0;
}