//[FINISHED]
#include <bits/stdc++.h>

#define name ""
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
const int NMAX = 6e6;
const ll MOD = 1e9 + 7;
const ll BASE = 2309;
const int dx[] = {-1, 0, 0, 1};
const int dy[] = {0, -1, 1, 0};

int n, m, sz;

vector < vector < int > > dis;

vector < string > a;

pii s, g;

struct Data {
	int i, j, x, y, chgx, chgy;
	Data(int _i, int _j, int _x, int _y) : i(_i), j(_j), x(_x), y(_y) {};
};

int main() {
	fast;
	if(fopen(name".inp", "r")) {
		freopen(name".inp", "r", stdin);
		freopen(name".out", "w", stdout);
	}
	//int t; cin >> t; while (t --) sol();
	cin >> n >> m >> sz >> s.fi >> s.se >> g.fi >> g.se;
	a.resize(n + 1); dis.resize(n + 1);
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		a[i] = ' ' + a[i];
		dis[i].assign(m + 1, -1);
	}
	queue < pii > q1; q1.push(s); dis[s.fi][s.se] = 0;
	queue < Data > q2;
	while (1) {
		while (q1.size()) {
			int i, j; tie(i, j) = q1.front(); q1.pop();
			if (mp(i, j) == g) {
				cout << dis[i][j] << ' ';
				return 0;
			}
			for (int p = 0; p < 4; p++) {
				int newi = i + dx[p], newj = j + dy[p];
				if (newi < 1 || newj < 1 || newi > n || newj > m || dis[newi][newj] != -1) continue;
				if (a[newi][newj] == '.') {
					dis[newi][newj] = dis[i][j];
					q1.push({newi, newj});
				}
				else {
					dis[newi][newj] = dis[i][j] + 1;
					q2.push({newi, newj, sz - 1, sz - 1});
				}
			}
		}
		
		while (q2.size()) {
			auto u = q2.front(); q2.pop();
			q1.push({u.i, u.j});
			for (int p = 0; p < 4; p++) {
				int newi = u.i + dx[p], newj = u.j + dy[p], newx = u.x - (dx[p] != 0), newy = u.y - (dy[p] != 0);
				if (newi < 1 || newj < 1 || newi > n || newj > m || newx < 0 || newy < 0 || dis[newi][newj] != -1) continue;
				dis[newi][newj] = dis[u.i][u.j];
				q2.push({newi, newj, newx, newy});
			}
		}
	}
}