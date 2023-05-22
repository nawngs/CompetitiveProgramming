#include <bits/stdc++.h>

#define name ""
#define test "test"
#define ll long long
#define ld long double
#define fi first 
#define se second
#define pll pair < ll, ll >
#define pii pair < int, int >
#define plii pair < int, pii >
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define sz(x) ((int)(x).size())
#define pb push_back
#define mp make_pair

using namespace std;

const ld EPS = 1e-9;
const int INF = 1e9 + 7;
const ll LINF = 1E18;
const int NMAX = 5e4;
const ll MOD = 1e9 + 7;
const ll BASE = 2309;
const int BLOCK_SIZE = 50;

int n, m, b[NMAX + 3], p[NMAX + 3], d1[NMAX + 3], d2[NMAX + 3][BLOCK_SIZE + 3];

vector < int > home[NMAX + 3];

vector < pii > adj[NMAX + 3];

bool vs[NMAX + 3];

bool minimize(int &x, int y) {
	if (x > y) {
		x = y;
		return true;
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
	for (int i = 0; i < m; i++) {
		cin >> b[i] >> p[i];
		if (p[i] <= BLOCK_SIZE) home[b[i]].push_back(i);
		else {
			int cur = b[i] - p[i], dem = 1;
			while (cur >= 0) {
				adj[b[i]].push_back({cur, dem});
				cur -= p[i]; dem ++;
			}
			cur = b[i] + p[i], dem = 1;
			while (cur <= n) {
				adj[b[i]].push_back({cur, dem});
				cur += p[i]; dem ++;
			}
		}
	}
	for (int i = 0; i <= n; i++) {
		d1[i] = INF;
		for (int j = 1; j <= BLOCK_SIZE; j++) d2[i][j] = INF;
	}
	priority_queue < plii, vector < plii >, greater < plii > > heap;
	heap.push({0, {b[0], p[0]}});
	if (p[0] <= BLOCK_SIZE) d2[b[0]][p[0]] = 0;
	else d1[b[0]] = 0;
	while (!heap.empty()) {
		auto u = heap.top(); heap.pop();
		int val = u.fi, x = u.se.fi, y = u.se.se;
		if (y <= BLOCK_SIZE && val != d2[x][y]) continue;
		if (y > BLOCK_SIZE && val != d1[x]) continue;
		if (x == b[1]) {
			cout << val << '\n';
			return 0;
		}
		if (y <= BLOCK_SIZE) {
			if (minimize(d1[x], val)) heap.push({val, {x, BLOCK_SIZE + 1}});
			int newx = x - y;
			if (newx >= 0 && minimize(d2[newx][y], val + 1)) heap.push({d2[newx][y], {newx, y}});
			newx = x + y;
			if (newx <= n && minimize(d2[newx][y], val + 1)) heap.push({d2[newx][y], {newx, y}});
		}
		else {
			for (auto v : adj[x]) 
				if (minimize(d1[v.fi], val + v.se)) 
					heap.push({d1[v.fi], {v.fi, BLOCK_SIZE + 1}});
		}
		if (!vs[x]) {
			for (auto v : home[x]) 
				if (p[v] <= BLOCK_SIZE && minimize(d2[x][p[v]], val)) 
					heap.push({val, {x, p[v]}});
			vs[x] = 1;
		}
	}
	cout << -1 << '\n';
}