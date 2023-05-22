#pragma GCC optimize ("O2")
#include <bits/stdc++.h>

#define ll long long
#define ld long double
#define fi first 
#define se second
#define pll pair < ll, ll >
#define pii pair < int, int >
#define piii pair < int, pii >
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

using namespace std;

const string NAME = "";
const string NAME2 = "TEST";
const ll ESP = 1e-9;
const ll INF = 1e9 + 7;
const ll nmax = 2e5;
const ll MOD = 1e9 + 7;
const ll base = 2309;
const int dx[4] = {0, 0, 1, -1};
const int dy[4] = {1, -1, 0, 0};

void fre() {
	string finp = NAME + ".inp";
	string fout = NAME + ".out";
	freopen(finp.c_str(), "r", stdin);
	freopen(fout.c_str(), "w", stdout);
}

int n, m, p, a[303][303], dp[303][303], d[303][303];

vector < pii > pos[90003];

void getmin(int &x, int y) {
	x = min(x, y);
	return ;
}

void dijkstra(int i) {
	priority_queue < piii, vector < piii >, greater < piii > > heap;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++) d[i][j] = INF;
		for (auto x : pos[i]) {
			heap.push({dp[x.fi][x.se], x});
			d[x.fi][x.se] = dp[x.fi][x.se];
		}
		while (heap.size()) {
			auto u = heap.top();
			heap.pop();
			if (u.fi != d[u.se.fi][u.se.se]) continue;
			for (int i = 0; i < 4; i++) {
				int newi = u.se.fi + dx[i];
				int newj = u.se.se + dy[i];
				if (newi < 1 || newj < 1 || newi > n || newj > m) continue;
				if (d[newi][newj] > u.fi + 1) {
					d[newi][newj] = u.fi + 1;
					heap.push({d[newi][newj], {newi, newj}});
				}
			}	
		}
	for (auto x : pos[i + 1]) dp[x.fi][x.se] = d[x.fi][x.se];
}

int main() {
	fast;
	cin >> n >> m >> p;
	for (int i = 1; i <= n; i++) 
		for (int j = 1; j <= m; j++) {
			cin >> a[i][j];
			pos[a[i][j]].push_back({i, j});
			if (a[i][j] == 1) dp[i][j] = (i - 1) + (j - 1);
			else dp[i][j] = INF;
		}
	pos[0].push_back({1, 1});
	for (int i = 1; i < p; i++) {
		if (pos[i].size() * pos[i + 1].size() <= m * n) {
			for (auto x : pos[i]) 
				for (auto y : pos[i + 1]) getmin(dp[y.fi][y.se], dp[x.fi][x.se] + abs(y.fi - x.fi) + abs(y.se - x.se));
		
		}
		else dijkstra(i);
	}
	cout << dp[pos[p][0].fi][pos[p][0].se];
}
