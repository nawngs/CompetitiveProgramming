#include <bits/stdc++.h>

#define name "roller"
#define ll long long
#define ld long double
#define fi first 
#define se second
#define pll pair < ll, ll >
#define pii pair < int, int >
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define SZE(x) ((int)(x).size())
#define pb push_back
#define mp make_pair
#define lnode node * 2, l, (l + r) / 2
#define rnode node * 2 + 1, (l + r) / 2 + 1, r

using namespace std;

const ld EPS = 1e-9;
const int INF = 1e9 + 7;
const ll LINF = 1E18;
const int NMAX = 500;
const ll MOD = 1e9 + 7;
const ll BASE = 2309;

int n, m, k, l, X1, Y1, d, id[NMAX + 3][NMAX + 3][3];

bool invalid[NMAX + 3][NMAX + 3];

struct State {
	int x, y, d;
	State(int _x = 0, int _y = 0, int _d = 0) : x(_x), y(_y), d(_d) {}
};

const int dx[] {0, 0, 1};
const int dy[] {0, 1, 0};
const string Direction = "UDLR";
const State directions[3][4] = {
	{State(-2, 0, 2), State(1, 0, 2), State(0, -2, 1), State(0, 1, 1)},
	{State(-1, 0, 1), State(1, 0, 1), State(0, -1, 0), State(0, 2, 0)},
	{State(-1, 0, 0), State(2, 0, 0), State(0, -1, 2), State(0, 1, 2)}
};

bool valid(int i, int j, int d) {
	if (!(1 <= i && 1 <= j && i <= n && j <= m && !invalid[i][j])) return false;
	i += dx[d], j += dy[d];
	if (!(1 <= i && 1 <= j && i <= n && j <= m && !invalid[i][j])) return false;
	return true;
}

namespace sub2 {
	void solve() {
		string res = "";
		for (int i = 1; i <= m / 3; i++) {
			for (int j = 1; j <= n / 3 * 2; j++) res += 'D';
			res += 'R';
			for (int j = 1; j < n; j++) res += 'U';
			if (i * 3 != m) res += 'R';
		}
		if (m % 3 != 0) for (int j = 1; j <= n / 3 * 2; j++) res += 'D';
		cout << res;
	}
}

vector < pair < int, char > > adj[NMAX * NMAX * 3 + 5];

bool vs[NMAX * NMAX * 3 + 5];

void dfs(int u) {
	vs[u] = 1;
	for (auto v : adj[u]) if (!vs[v.fi]) {
		cout << v.se;
		dfs(v.fi);
		if (v.se == 'U') cout << "D";
		if (v.se == 'D') cout << "U";
		if (v.se == 'L') cout << "R";
		if (v.se == 'R') cout << "L";
	}
}

int main() {
	fast;
	if(fopen(name".inp", "r")) {
		freopen(name".inp", "r", stdin);
		freopen(name".out", "w", stdout);
	}
	//int t; cin >> t; while (t --) sol();
	cin >> n >> m >> k >> l >> X1 >> Y1 >> d;
	for (int i = 1; i <= k; i++) {
		int x, y; cin >> x >> y;
		invalid[x][y] = 1;
 	}
 	if (n % 3 == 1 && (m + 1) % 3 != 0 && k == 0 && X1 == 1 && Y1 == 1 && d == 0) {
 		sub2::solve();
 		return 0;
 	}
 	int curid = 0;
 	for (int i = 1; i <= n; i++)
 	for (int j = 1; j <= m; j++)
 	for (int d = 0; d < 3; d++) id[i][j][d] = ++ curid;
 	for (int i = 1; i <= n; i++)
 	for (int j = 1; j <= m; j++) 
 	for (int d = 0; d < 3; d++) if (valid(i, j, d)) {
 		for (int nxt = 0; nxt < 4; nxt++) {
 			int newi = i + directions[d][nxt].x, newj = j + directions[d][nxt].y, newd = directions[d][nxt].d;
 			if (!valid(newi, newj, newd)) continue;
 			adj[id[i][j][d]].pb({id[newi][newj][newd], Direction[nxt]});
 		}
 	}
 	dfs(id[X1][Y1][d]);
}