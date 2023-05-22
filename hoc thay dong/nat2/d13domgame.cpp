#include <bits/stdc++.h>

#define name ""
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
const int NMAX = 1e6;
const ll MOD = 1e9 + 7;
const ll BASE = 2309;
const int di[] = {-1, 0, 0, 1};
const int dj[] = {0, -1, 1, 0};

int n, m, id[10003][10003], cnt, assigned[10003], t = 0, visited[10003];

bool connected[2003][2003];

char a[10003][10003];

vector < int > adj[4003], pos[2];

bool kuhn(int u) {
	if (visited[u] == t) return false;
	visited[u] = t;
	for (auto v : adj[u]) {
		if (!assigned[v] || kuhn(assigned[v])) {
			assigned[u] = v;
			assigned[v] = u;
			return true;
		}
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
		for (int j = 1; j <= m; j++) {
			cin >> a[i][j];
			if (a[i][j] == '#') continue;
			id[i][j] = ++ cnt;
			pos[(i + j) % 2].pb(id[i][j]);
		}
	int temp = cnt / 2;
	if (temp * (temp - 1) >= NMAX) {
		cout << NMAX << '\n';
		return 0;
	}
	int res = temp * (temp - 1);
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++) if (a[i][j] == '.')
			for (int p = 0; p < 4; p++) {
				int newi = i + di[p], newj = j + dj[p];
				if (newi < 1 || newj < 1 || newi > n || newj > m || a[newi][newj] == '#') continue;
				adj[id[i][j]].push_back(id[newi][newj]);
			}
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++) if (a[i][j] == '.' && (i + j) % 2 == 1) {
			t++; kuhn(id[i][j]);
		}
	for (int i = 1; i <= n; i++) 
		for (int j = 1; j <= m; j++) if (a[i][j] == '.' && (i + j) % 2 == 1) {
			queue < pii > que;
			connected[id[i][j]][id[i][j]] = 1;
			que.push({id[i][j], 1});
			while (!que.empty()) {
				auto u = que.front(); que.pop();
				if (u.se) {
					if (connected[id[i][j]][assigned[u.fi]]) continue;
					connected[id[i][j]][assigned[u.fi]] = 1;	
					que.push({assigned[u.fi], 0});
				}
				else {
					for (auto v : adj[u.fi]) {
						if (connected[id[i][j]][v]) continue;
						connected[id[i][j]][v] = 1;
						que.push({v, 1});
					}
				}
			}
		}
	for (auto x : pos[1])
		for (auto y : pos[0]) 
			if (!connected[x][y]) res ++;
	cout << min(NMAX, res);
}