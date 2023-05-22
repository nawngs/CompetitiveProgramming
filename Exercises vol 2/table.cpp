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

const string NAME = "";
const string NAME2 = "TEST";
const ld ESP = 1e-9;
const ll INF = 1e9 + 7;
const ll LINF = 1E18;
const ll nmax = 2e5;
const ll MOD = 1e9 + 7;
const ll base = 2309;
const ll B = 700;

void fre() {
	string finp = NAME + ".inp";
	string fout = NAME + ".out";
	freopen(finp.c_str(), "r", stdin);
	freopen(fout.c_str(), "w", stdout);
}

struct Data {
	int x, y, u, v, w;
	Data(int _x, int _y, int _u, int _v, int _w) : x(_x), y(_y), u(_u), v(_v), w(_w) {};
};

int m, n, Q, a[503][503], s[503][503], d[503][503];

vector < Data > upd;

void build() {
	memset(d, 0, sizeof(d));
	for (auto i : upd) {
		d[i.x][i.y] += i.w;
		d[i.x][i.v + 1] -= i.w;
		d[i.u + 1][i.y] -= i.w;
		d[i.u + 1][i.v + 1] += i.w;
	}
	upd.clear();
	for (int i = 1; i <= m; i++)
		for (int j = 1; j <= n; j++) {
			d[i][j] += d[i - 1][j] + d[i][j - 1] - d[i - 1][j - 1];
			a[i][j] += d[i][j];
			s[i][j] = s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1] + a[i][j];
		}
}

signed main() {
	fast;
	cin >> m >> n >> Q;
	for (int i = 1; i <= m; i++) 
		for (int j = 1; j <= n; j++) {
			cin >> a[i][j];
			s[i][j] = s[i][j - 1] + s[i - 1][j] - s[i - 1][j - 1] + a[i][j];
		}
	while (Q--) {
		if (Q % B == 0) build();
		int t;
		cin >> t;
		if (t == 1) {
			int x, y, u, v, w;
			cin >> x >> y >> u >> v >> w;
			upd.push_back({x, y, u, v, w});
		}
		else {
			int x, y, u, v;
			cin >> x >> y >> u >> v;
			int ans = s[u][v] - s[x - 1][v] - s[u][y - 1] + s[x - 1][y - 1];
			for (auto i : upd) {
				i.x = max(i.x, x);
				i.y = max(i.y, y);
				i.u = min(i.u, u);
				i.v = min(i.v, v);
				//cout << i.x << " " << i.y << " " << i.u << " " << i.v << '\n';
				if (i.x > i.u || i.y > i.v) continue;
				ans += (i.u - i.x + 1) * (i.v - i.y + 1) * i.w;
			}
			cout << ans << '\n';
		}
	}
}
