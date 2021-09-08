#pragma GCC optimize ("O3")
#include <bits/stdc++.h>
#define ll long long
#define fi first
#define se second
#define pll pair < long long, long long >


using namespace std;

const ll INF = 1e18 + 7;

struct Edge {
	ll u, v, c;
	Edge(ll _u, ll _v, ll _c) : u(_u), v(_v), c(_c) {};
};

ll n, m, f[805][805], cnt[805][805], edge[805][805], pre[805];

bool check[805];

vector < pll > adj[805];

vector < Edge > e;

void dijkstra(int p) {
	if (check[p] == false) return ;
	priority_queue < pll, vector < pll > , greater < pll > > heap;
	for (int i = 1; i <= n; i++) {
		cnt[p][i] = f[p][i] = INF;
		pre[i] = -1;
	}
	f[p][p] = 0;
	cnt[p][p] = 1;
	heap.push({f[p][p], p});
	while (heap.size()) {
		auto u = heap.top();
		//cout << u.fi << " " << u.se << '\n';

		heap.pop();
		if (u.fi != f[p][u.se]) continue;
		for (auto v : adj[u.se]) {
			if (check[v.fi]) {
				if (f[p][v.fi] > f[p][u.se] + v.se) {
					f[p][v.fi] = f[p][u.se] + v.se;
					pre[v.fi] = u.se == p ? v.fi : pre[u.se];
					//pre[v.fi] = pre[u.se];
					cnt[p][v.fi] = cnt[p][u.se] + 1;
					heap.push({f[p][v.fi], v.fi});
				}
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("tour.inp", "r", stdin);
	freopen("tour.out", "w", stdout);
	cin >> n >> m;
	memset(check, true, sizeof(check));
	for (int i = 1; i <= m; i++) {
		ll u, v, c;
		cin >> u >> v >> c;
		e.push_back({u, v, c});
		edge[u][v] = c;
		edge[v][u] = c;
		adj[u].push_back({v, c});
		adj[v].push_back({u, c});
	}
	//cout << e.size() << '\n';
	ll ans = INF, pos1, pos2, pos3, dem;
	for (int i = 1; i <= n; i++) {
		dijkstra(i);
		for (auto edge : e) {
			//cout << pre[edge.u] << " " << pre[edge.v] << '\n';
			if (pre[edge.u] == pre[edge.v] || pre[edge.u] == -1 || pre[edge.v] == -1) continue;
			//cout << f[i][edge.u] + edge.c + f[i][edge.v] << '\n';
			if (ans > f[i][edge.u] + edge.c + f[i][edge.v]) {
				ans = f[i][edge.u] + edge.c + f[i][edge.v];
				pos3 = i;
				pos1 = pre[edge.u];
				pos2 = pre[edge.v];
				dem = cnt[i][edge.u] + cnt[i][edge.v] - 1;
			}
		}
	}
	//cout << pos1 << " " << pos2 << " " << pos3 << '\n';
	if (ans == INF) {
		cout << 0 << '\n';
		return 0;
	}
	cout << 1 << '\n' << ans << '\n' << dem << '\n';
	check[pos3] = false;
	for (int i = 1; i <= n; i++) dijkstra(i);
	vector < ll > res;
	res.clear();
	while (1) {
		res.push_back(pos1);
		if (pos1 == pos2) {
			//res.push_back(pos1);
			break;
		}
		for (int i = 1; i <= n; i++) 
			if (f[pos1][i] + f[i][pos2] == f[pos1][pos2] && f[pos1][i] == edge[pos1][i] && pos1 != i) {
				//cout << pos1 << " " << i << '\n';
				pos1 = i;
				break;
			}
	}
	for (int i = 0; i < res.size(); i++) cout << res[i] << " ";
	cout << pos3;
}
