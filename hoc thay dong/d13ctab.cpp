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
const int NMAX = 2e5;
const ll MOD = 1e9 + 7;
const ll BASE = 2309;

int a[103][103], b[103][103], n, color[203], res = 0, cnt = 0;

vector < pii > adj[203];

vector < int > troll;

void dfs(int u, int c) {
	color[u] = c;
	cnt += color[u];
	troll.push_back(u);
	for (auto v : adj[u]) {
		if (color[v.fi] == -1) {
			dfs(v.fi, (c ^ v.se));
			continue;
		}
		if (color[v.fi] != (c ^ v.se)) {
			cout << -1 << '\n';
			exit(0);
		}
	}
}

int main() {
	fast;
	if(fopen(name".inp", "r")) {
		freopen(name".inp", "r", stdin);
		freopen(name".out", "w", stdout);
	}
	//int t; cin >> t; while (t --) sol();
	cin >> n;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++) 
			cin >> a[i][j];
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++) {
			cin >> b[i][j];
			if (b[i][j] == 0 && a[i][j] != 0) {
				cout << -1 << '\n';
				return 0;	
			}
			if (b[i][j] != 0 && a[i][j] == 0) {
				cout << -1 << '\n';
				return 0;
			}
			if (a[i][j] == 0 && a[i][j] == b[i][j]) continue;
			if (b[i][j] != a[i][j]) {
				adj[i].push_back({n + j, 1});
				adj[n + j].push_back({i, 1});
			}
			if (b[i][j] == a[i][j]) {
				adj[i].push_back({n + j, 0});
				adj[n + j].push_back({i, 0});
			}
		}
	memset(color, 255, sizeof(color));
	for (int i = 1; i <= n; i++) 
		if (color[i] == -1) {
			troll.clear();
			int temp; cnt = 0; dfs(i, 0);
			for (auto x : troll) color[x] = -1;
			temp = cnt; cnt = 0; dfs(i, 1);
			res += min(temp, cnt);
		}
	cout << res;
}