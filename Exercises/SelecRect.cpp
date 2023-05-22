#pragma GCC optimize ("O2")
#include <bits/stdc++.h>

#define ll long long
#define ld long double
#define fi first 
#define se second
#define pll pair < ll, ll >
#define pii pair < int, int >
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

using namespace std;

const string NAME = "selecrect";
const string NAME2 = "TEST";
const ld ESP = 1e-9;
const ll INF = 1e9 + 7;
const ll LINF = 1E18;
const ll nmax = 2e5;
const ll MOD = 1e9 + 7;
const ll base = 2309;
const int dx[4] = {-1, 0, 0, 1};
const int dy[4] = {0, -1, 1, 0};

void fre() {
	string finp = NAME + ".inp";
	string fout = NAME + ".out";
	freopen(finp.c_str(), "r", stdin);
	freopen(fout.c_str(), "w", stdout);
}

int n, m, a[1003][1003];

bool vs[1003][1003];

vector < pii > temp;

void dfs(int x, int y) {
	vs[x][y] = 1;
	for (int i = 0; i < 4; i++) {
		int newx = x + dx[i];
		int newy = y + dy[i];
		if (newx < 1 || newy < 1 || newx > n || newy > m || vs[newx][newy] || a[newx][newy] > a[x][y]) continue;
		dfs(newx, newy);
	}
}

void sol() {
	cin >> n >> m;
	temp.clear();
	for (int i = 1; i <= n; i++) 
		for (int j = 1; j <= m; j++) {
			cin >> a[i][j];
			vs[i][j] = 0;
			temp.push_back({i, j});
		}
	sort(temp.begin(), temp.end(), [&](pii &x, pii &y) {
		return a[x.fi][x.se] > a[y.fi][y.se];
	});
	int res = 0;
	for (auto x : temp) {
		if (vs[x.fi][x.se]) continue;
		res ++;
		dfs(x.fi, x.se);
	}
	cout << res << '\n';
}

int main() {
	fast;
	fre();
	int t = 1;
	cin >> t;
	while (t --) sol();
}
