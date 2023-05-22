#include <bits/stdc++.h>

#define name "light"
#define test "test"
#define ll long long
#define ld long double
#define fi first 
#define se second
#define pll pair < ll, ll >
#define pii pair < int, int >
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define sz(x) ((int)(x).size())
#define pb push_back
#define mp make_pair

using namespace std;

const ld EPS = 1e-9;
const int INF = 1e9 + 7;
const ll LINF = 1E18;
const int NMAX = 2e5;
const ll MOD = 1e9 + 7;
const ll BASE = 2309;

int n, m, k;

vector < vector < int > > a, s, b;

vector < vector < pii > > sw;

int main() {
	fast;
	if(fopen(name".inp", "r")) {
		freopen(name".inp", "r", stdin);
		freopen(name".out", "w", stdout);
	}
	//int t; cin >> t; while (t --) sol();
	cin >> n >> m >> k;
	a.resize(n + 3);
	sw.resize(n + 3);
	for (auto &x : a) x.resize(m + 3);
	for (auto &x : sw) x.resize(m + 3);
	s = a;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++) {
			cin >> a[i][j];
			s[i][j] = 0;
			sw[i][j] = {-1, -1};

		}
	while (k--) {
		int r, c, x, y; cin >> r >> c >> x >> y;
		sw[r][c] = {x, y};
	}
	int cnt1 = 0, cnt2 = 0;
	b = a;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++) {
			s[i][j] = s[i][j] + s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1];
			b[i][j] = b[i][j] + s[i][j];
			b[i][j] = (b[i][j] + 27) % 3;
			if (b[i][j] == 1) continue;
			if (sw[i][j] == mp(-1, -1)) {
				cnt1 = INF;
				break;
			}
			int chg = (1 - b[i][j] + 3) % 3;
			cnt1 += chg;
			s[i][j] += chg; s[i][sw[i][j].se + 1] -= chg; s[sw[i][j].fi + 1][j] -= chg; s[sw[i][j].fi + 1][sw[i][j].se + 1] += chg;
		}
	b = a;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++) s[i][j] = 0;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++) {
			s[i][j] = s[i][j] + s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1];
			b[i][j] = b[i][j] + s[i][j];
			b[i][j] = (b[i][j] + 27) % 3;
			if (b[i][j] == 2) continue;
			if (sw[i][j] == mp(-1, -1)) {
				cnt2 = INF;
				break;
			}
			int chg = 2 - b[i][j];
			cnt2 += chg;
			s[i][j] += chg; s[i][sw[i][j].se + 1] -= chg; s[sw[i][j].fi + 1][j] -= chg; s[sw[i][j].fi + 1][sw[i][j].se + 1] += chg;
		}
	if (cnt1 >= INF && cnt2 >= INF) cout << -1;
	else cout << min(cnt1, cnt2);
}