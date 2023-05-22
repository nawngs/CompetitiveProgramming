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

const string NAME = "move1";
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

int n, m, q, dist[2003][2003];

string s[2003];

void bfs() {
	deque < pii > dq;
	for (int i = 1; i <= n; i++) 
		for (int j = 1; j <= m; j++) {
			if (s[i][j] == '*') {
				dist[i][j] = 0;
				dq.push_back({i, j});
			}
			else dist[i][j] = INF;
		}
	while (dq.size()) {
		auto u = dq.front();
		dq.pop_front();
		for (int i = 0; i < 4; i++) {
			int newx = u.fi + changex[i];
			int newy = u.se + changey[i];
			if (newx == 0 || newy == 0 || newx > n || newy > m) continue;
			int w = (s[newx][newy] != s[u.fi][u.se]);
			if (dist[newx][newy] > dist[u.fi][u.se] + w) {
				dist[newx][newy] = dist[u.fi][u.se] + w;
				if (w == 0) dq.push_front({newx, newy});
				else dq.push_back({newx, newy});
			}
		}
	}
}

void sol() {
	cin >> n >> m >> q;
	for (int i = 1; i <= n; i++) {
		cin >> s[i];
		s[i] = ' ' + s[i];
	}
	bfs();
	while (q--) {
		int i, j;
		cin >> i >> j;
		cout << dist[i][j] << '\n';
	}
}

int main() {
	fast;
	fre();
	int t = 1;
	//cin >> t;
	while (t --) sol();
}
