#include <bits/stdc++.h>

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
const ll dx[4] = {-1, -1, 1, 1};
const ll dy[4] = {-1, 1, -1, 1};

void fre() {
	string finp = NAME + ".inp";
	string fout = NAME + ".out";
	freopen(finp.c_str(), "r", stdin);
	freopen(fout.c_str(), "w", stdout);
}

ll m, n, a[5003], f[5003][5003][4], g[5003][5003][4];

pll b[5003];

vector < pll > temp;

ll dist(const pll &x) {
	return x.fi * x.fi + x.se * x.se;
}

int main() {
	fast;
	cin >> m >> n;
	for (int i = 1; i <= m; i++)
		for (int j = 1; j <= n; j++) {
			cin >> a[(i - 1) * n + j];
			b[(i - 1) * n + j] = {i, j};
		}
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++) temp.push_back({i, j});
	sort(temp.begin(), temp.end(), [&](pll &x, pll &y) {
		return x.fi * x.fi + x.se * x.se < y.fi * y.fi + y.se * y.se;
	});
	for (int i = 1; i <= n * m; i++) {
		for (int k = 0; k < temp.size(); k++) {
				for (int sze = 0; sze < 4; sze++) {
					f[i][k][sze] = LINF;
					g[i][k][sze] = -LINF;
				}
			}
		f[i][0][1] = g[i][0][1] = a[i];
	}
	int pre = 0;
	for (int k = 1; k < temp.size(); k++) {
		if (dist(temp[k]) > dist(temp[k - 1])) pre = k - 1;
		for (int i = 1; i <= n * m; i++) {
			for (int sze = 1; sze < 4; sze++) {
				for (int p = 0; p < 4; p++) {
					ll newi = b[i].fi + dx[p] * temp[k].fi;
					ll newj = b[i].se + dy[p] * temp[k].se;
					if (newi < 1 || newj < 1 || newi > m || newj > n) continue;
					int temp = (newi - 1) * n + newj;
					f[i][k][sze] = min(f[i][k][sze], f[temp][pre][sze - 1] + a[i]);
					g[i][k][sze] = max(g[i][k][sze], g[temp][pre][sze - 1] + a[i]);
					if (sze == 3) {
						f[i][k][sze] = min(f[i][k][sze], f[temp][pre][sze] + a[i]);
						g[i][k][sze] = max(g[i][k][sze], g[temp][pre][sze] + a[i]);
					}
				}
				f[i][k][sze] = min(f[i][k][sze], f[i][k - 1][sze]);
				g[i][k][sze] = max(g[i][k][sze], g[i][k - 1][sze]);
			}
		}
	}
	ll resf = LINF, resg = -LINF;
	for (int i = 1; i <= m * n; i++) {
			resf = min(resf, f[i][temp.size() - 1][3]);
			resg = max(resg, g[i][temp.size() - 1][3]);
		}
	cout << max(abs(resf), abs(resg));
}