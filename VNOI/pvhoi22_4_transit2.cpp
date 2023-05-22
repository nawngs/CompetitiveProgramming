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

const string NAME = "";
const string NAME2 = "TEST";
const ll ESP = 1e-9;
const ll INF = 1e9;
const ll nmax = 1e7;
const ll MOD = 1e9 + 7;

void fre() {
	string finp = NAME2 + ".inp";
	string fout = NAME2 + ".out";
	freopen(finp.c_str(), "r", stdin);
	freopen(fout.c_str(), "w", stdout);
}

int n, m, dist[1503][1503], dist_rev[1503][1503], f[19], dp[18][18][(1 << 17) - 1], q;

bool th = true;

vector < pii > adj[1503], adj_rev[1503];

bool getbit(int pos, int x) {
	return (x & 1 << pos);
}

void dijkstra(int pos) {
	priority_queue < pii, vector < pii > , greater < pii > > heap;
	for (int i = 1; i <= n; i++) dist[pos][i] = INF;

	dist[pos][pos] = 0;
	heap.push({0, pos});
	while (heap.size()) {
		auto u = heap.top();
		heap.pop();
		if (u.fi != dist[pos][u.se]) continue;
		for (auto v : adj[u.se]) {
			if (dist[pos][v.fi] > dist[pos][u.se] + v.se) {
				dist[pos][v.fi] = dist[pos][u.se] + v.se;
				heap.push({dist[pos][v.fi], v.fi});
			}
		}
	}
}

void dijkstra_rev(int pos) {
	priority_queue < pii, vector < pii > , greater < pii > > heap;
	for (int i = 1; i <= n; i++) dist_rev[pos][i] = INF;
	dist_rev[pos][pos] = 0;
	heap.push({0, pos});
	while (heap.size()) {
		auto u = heap.top();
		heap.pop();
		if (u.fi != dist_rev[pos][u.se]) continue;
		for (auto v : adj_rev[u.se]) {
			if (dist_rev[pos][v.fi] > dist_rev[pos][u.se] + v.se) {
				dist_rev[pos][v.fi] = dist_rev[pos][u.se] + v.se;
				heap.push({dist_rev[pos][v.fi], v.fi});
			}
		}
	}
}

void solve() {
	for (int i = 0; i < m; i++) 
		for (int j = 0; j < m; j++) 
			for (int bit = 0; bit < (1 << m); bit ++) dp[i][j][bit] = INF;

	for (int i = 0; i < m; i++) dp[i][i][(1 << i)] = 0;
	for (int i = 0; i < m; i++) {
		for (int bit = 0; bit < (1 << m); bit ++) {
			if (!getbit(i, bit)) continue;
			for (int finish = 0; finish < m; finish ++) {
				if (finish == i) continue;
				int tam = bit - (1 << finish);
				for (int pre = 0; pre < m; pre ++) {
					if (!getbit(pre, tam)) continue;
					if (pre == i && tam != (1 << i)) continue;
					dp[i][finish][bit] = min(dp[i][finish][bit], dp[i][pre][tam] + dist[f[pre]][f[finish]]);
				}
			}
 		}
	}
	while (q --) {
		int x, y;
		cin >> x >> y;
		int ans = INF;
		for (int i = 0; i < m; i++) 
			for (int j = 0; j < m; j++) {
				cout << dist_rev[f[i]][x] << " " << dp[i][j][(1 << m) - 1] << " " << dist[f[i]][y] << '\n';
				ans = min(ans, dist_rev[f[i]][x] + dp[i][j][(1 << m) - 1] + dist[f[j]][y]);
			}
		
		//cout << ans << ' ';
	}
}

void sol() {
	cin >> n >> m >> q;
	for (int i = 0; i < m; i++) cin >> f[i];
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			int x;
			cin >> x;
			if (i != j && x != 1) th = false;
			adj[i].push_back({j, x});
			adj_rev[j].push_back({i, x});
		}
	}
	for (int i = 0; i < m; i++) {
		dijkstra(f[i]);
		dijkstra_rev(f[i]);
		//for (int j = 1; j <= n; j++) cout << f[i] << " " << j << " " << dist[f[i]][j] << '\n';

	}
	solve();
}

int main() {
	fast;
	//fre();
	int t = 1;
	//cin >> t;
	while (t --) sol();
}