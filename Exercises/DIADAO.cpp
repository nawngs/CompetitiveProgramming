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

const string NAME = "diadao";
const string NAME2 = "TEST";
const ll ESP = 1e-9;
const ll INF = 1e9;
const ll nmax = 2e5;
const ll MOD = 1e9 + 7;
const ll base = 2309;
const int changex[4] = {-1, 0, 0, 1};
const int changey[4] = {0, -1, 1, 0};

void fre() {
	string finp = NAME + ".inp";
	string fout = NAME + ".out";
	freopen(finp.c_str(), "r", stdin);
	freopen(fout.c_str(), "w", stdout);
}

int k, x, y, a[1005][1005], dist[1005][1005];

void bfs() {
	deque < pii > dq;
	for (int i = 0; i <= 1001; i++)
		for (int j = 0; j <= 1001; j++) dist[i][j] = INF;
	dist[x][y] = 0;
	dq.push_back({x, y});
	while (dq.size()) {
		auto u = dq.front();
		dq.pop_front();
		for (int i = 0; i < 4; i++) {
			int newx = u.fi + changex[i];
			int newy = u.se + changey[i];
			if (newx < 0 || newy < 0 || newx > 1001 || newy > 1001) continue;
			int w = a[newx][newy];
			if (dist[newx][newy] > dist[u.fi][u.se] + w) {
				dist[newx][newy] = dist[u.fi][u.se] + w;
				if (w == 0) dq.push_front({newx, newy});
				else dq.push_back({newx, newy});
			}
		}
	}
	cout << dist[0][0];
}

void sol() {
	cin >> k >> x >> y;	
	for (int i = 1; i <= k; i++) {
		int u, v;
		 cin >> u >> v;
		 a[u][v] = 1;
	}
	bfs();
}

int main() {
	fast;
	fre();
	int t = 1;
	//cin >> t;
	while (t --) sol();
}
