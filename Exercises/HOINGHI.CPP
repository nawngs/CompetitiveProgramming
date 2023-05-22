#pragma GCC optimize ("O2")
#include <bits/stdc++.h>

#define int ll
#define ll long long
#define ld long double
#define fi first 
#define se second
#define pll pair < ll, ll >
#define pii pair < int, int >
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

using namespace std;

const string NAME = "hoinghi";
const string NAME2 = "TEST";
const ld ESP = 1e-9;
const ll INF = 1e9 + 7;
const ll LINF = 1E18;
const ll nmax = 2e5;
const ll MOD = 1e9 + 7;
const ll base = 1001;
const int dx[] = {-1, 0, 0, 1};
const int dy[] = {0, -1, 1, 0};

void fre() {
  string finp = NAME + ".inp";
  string fout = NAME + ".out";
  freopen(finp.c_str(), "r", stdin);
  freopen(fout.c_str(), "w", stdout);
}

int n, s, dis[2 * base + 5][2 * base + 5], res[2];

bool th[2 * base + 5][2 * base + 5];

void update(int i, int j) {
  if (dis[i][j] == -1) return ;
  int val = dis[i][j], d = (dis[i][j] & 1);
  for (int i = 1; i <= s - val; i++) {
    //cout << (d ^ (i & 1)) << " " << res[d ^ (i & 1)] << " " << i + 1 << '\n';
    res[d ^ (i & 1)] += i + 1;
  }
} 

main() {
  fast;
  fre();
  cin >> n >> s;
  int maxx = base, minx = base, maxy = base, miny = base;
  for (int i = 1; i <= n; i++) {
    int x, y; cin >> x >> y;
    x += base; y += base;
    th[x][y] = 1;
    maxx = max(maxx, x); minx = min(minx, x);
    maxy = max(maxy, y); miny = min(miny, y);
  }
  minx --; miny --; maxx ++; maxy ++;
  queue < pii > q;
  memset(dis, 255, sizeof(dis));
  dis[base][base] = 0; q.push({base, base});
  while (q.size()) {
    int i = q.front().fi, j = q.front().se; q.pop();
    //cout << i << " " << j << " " << dis[i][j] << '\n';
    res[dis[i][j] & 1] ++;
    if (dis[i][j] == s) continue;
    for (int p = 0; p < 4; p++) {
      int newi = i + dx[p]; 
      int newj = j + dy[p];
     // cout << i << " " << j << " " << newi << " " << newj << " " << dis[newi][newj] << '\n';
      if (newi < minx || newj < miny || newi > maxx || newj > maxy || th[newi][newj] || dis[newi][newj] != -1) continue;
      dis[newi][newj] = dis[i][j] + 1;
      q.push({newi, newj});
    }
  }
  for (int j = miny + 1; j < maxy; j++) {
    if (dis[minx][j] != -1) {
      int val = dis[minx][j], d = (dis[minx][j] & 1);
      res[d] += (s - val) / 2;
      res[d ^ 1] += (s - val + 1) / 2;
    }
    if (dis[maxx][j] != -1) {
      int val = dis[maxx][j], d = (dis[maxx][j] & 1);
      res[d] += (s - val) / 2;
      res[d ^ 1] += (s - val + 1) / 2;
    }
  }
  for (int i = minx + 1; i < maxx; i++) {
    if (dis[i][miny] != -1) {
      int val = dis[i][miny], d = (dis[i][miny] & 1);
      res[d] += (s - val) / 2;
      res[d ^ 1] += (s - val + 1) / 2;
    }
    if (dis[i][maxy] != -1) {
      int val = dis[i][maxy], d = (dis[i][maxy] & 1);
      res[d] += (s - val) / 2;
      res[d ^ 1] += (s - val + 1) / 2;
    }
  }
  update(maxx, maxy); update(minx, maxy); update(maxx, miny); update(minx, miny);
  cout << res[0] << " " << res[1] << '\n';
}
