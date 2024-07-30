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
const int NMAX = 2e5;
const ll MOD = 1e9 + 7;
const ll BASE = 2309;

const int dx[] = {-2, -2, -1, -1, 1, 1, 2, 2};
const int dy[] = {-1, 1, -2, 2, -2, 2, -1, 1};

int n, m, d[53][103][103], kn, ass[53], t = 0, vs[103];

char a[103][103];

pii pos[53];

bool check(int x, int y) {
	if (x < 1 || y < 1 || x > n || y > m || a[x][y] == '#') return false;
	return true;
}

void bfs(int id) {
	queue < pii > que;
	que.push(pos[id]);
	d[id][pos[id].fi][pos[id].se] = 0;
	while (que.size()) {
		int i, j; tie(i, j) = que.front(); que.pop();
		for (int p = 0; p < 8; p++) {
			int newi = i + dx[p], newj = j + dy[p];
			if (!check(newi, newj) || d[id][newi][newj] != -1) continue;
			d[id][newi][newj] = d[id][i][j] + 1;
			que.push({newi, newj});	
		}
	}
}

bool dfs(const int &i, const int &mid, int u) {
	if (vs[u] == t) return false;
	vs[u] = t;
	for (int id = 1; id <= kn; id++) if (d[id][i][u] != -1 && d[id][i][u] <= mid) {
		if (ass[id] == -1 || dfs(i, mid, ass[id])) {
			ass[id] = u;
			return true;
		}
	}
	return false;
}

bool check(int x) {
	for (int i = 1; i <= n; i++) 
	for (int j = 1; j + kn - 1 <= m; j++) {
		memset(ass, 255, sizeof(ass));
		memset(vs, 0, sizeof(vs));
		bool ok = 1;
		for (int k = j; k <= j + kn - 1; k++) {
			t++;
			if (!dfs(i, x, k)) {
				ok = false;
				break;
			}
		}
		if (ok) return true;
	}
	return false;
}

int main() {
	fast;
	if(fopen(name".inp", "r")) {
		freopen(name".inp", "r", stdin);
		freopen(name".out", "w", stdout);
	}
	//int t; cin >> t; while (t --) sol();
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	for (int j = 1; j <= m; j++) 
		cin >> a[i][j];
	memset(d, 255, sizeof(d));
	for (int i = 1; i <= n; i++)
	for (int j = 1; j <= m; j++) if (a[i][j] == 'M') {
		pos[++ kn] = {i, j};
		bfs(kn);
	}
	int l = 0, r = n * m, mid, ans = -1;
	while (l <= r) {
		mid = (l + r) / 2;
		if (check(mid)) {
			ans = mid;
			r = mid - 1;
		}
		else l = mid + 1;
	}
	cout << ans;
}