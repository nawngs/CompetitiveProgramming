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

const string NAME = "rota";
const string NAME2 = "TEST";
const ll ESP = 1e-9;
const ll INF = 1e9+ 7;
const ll nmax = 2e5;
const ll MOD = 1e9 + 7;
const ll base = 2309;
const int x[4] = {-1, 0, 0, 1};
const int y[4] = {0, -1, 1, 0};

void fre() {
	string finp = NAME + ".inp";
	string fout = NAME + ".out";
	freopen(finp.c_str(), "r", stdin);
	freopen(fout.c_str(), "w", stdout);
}

int n, m, a[1003][1003], d[1003][1003];

int bfs() {
	queue < pii > que;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (a[i][j] == 2) {
				d[i][j] = 0;
				que.push({i, j});
			}
			else d[i][j] = INF;	
		}
	}
	while (que.size()) {
		auto u = que.front();
		que.pop();
		for (int i = 0; i < 4; i++) {
			int newx = u.fi + x[i];
			int newy = u.se + y[i];
			if(newx > 0 && newy > 0 && newx <= n && newy <= m && a[newx][newy] == 1){
				d[newx][newy] = d[u.fi][u.se] + 1;
				a[newx][newy] = 2;
				que.push({newx, newy});
			}
		}
	}
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (a[i][j] == 2) ans = max(ans, d[i][j]);
			if (a[i][j] == 1) return -1;
		}
	}
	return ans;
}

void sol() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++) 
		for (int j = 1; j <= m; j++) cin >> a[i][j];
	cout << bfs();
}

int main() {
	fast;
	fre();
	int t = 1;
	//cin >> t;
	while (t --) sol();
}
