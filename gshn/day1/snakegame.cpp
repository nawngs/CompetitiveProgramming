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
const ll INF = 1e9;
const ll nmax = 2e5;
const ll MOD = 1e9 + 7;
const ll base = 2309;
const int dx[4] = {-1, 0, 0, 1};
const int dy[4] = {0, -1, 1, 0};

void fre() {
	string finp = NAME + ".inp";
	string fout = NAME + ".out";
	freopen(finp.c_str(), "r", stdin);
	freopen(fout.c_str(), "w", stdout);
}

int n, m, d[2003][2003], dp[2003][2003];

char a[2003][2003];

int main() {
	fast;
	//fre();
	cin >> m >> n;
	memset(d, 255, sizeof(d));
	queue < pii > q;
	pii start, finish;
	for (int i = 1; i <= m; i++) 
		for (int j = 1; j <= n; j++) {
			cin >> a[i][j];
			if (a[i][j] == '+') {
				d[i][j] = 0;
				q.push({i, j});
			}
			if (a[i][j] == 'P') start = {i, j};
			if (a[i][j] == 'C') finish = {i, j};
		}
	while (q.size()) {
		auto u = q.front();
		q.pop();
		for (int i = 0; i < 4; i++) {
			int newx = u.fi + dx[i];
			int newy = u.se + dy[i];
			if (newx < 1 || newx > m || newy < 1 || newy > n || d[newx][newy] != -1) continue;
			d[newx][newy] = d[u.fi][u.se] + 1;
			q.push({newx, newy});
		}
	}
	for (int i = 1; i <= m; i++) 
		for (int j = 1; j <= n; j++) dp[i][j] = -INF;
	dp[start.fi][start.se] = d[start.fi][start.se];
	priority_queue < piii, vector < piii > > heap;
	heap.push({dp[start.fi][start.se], start});
	while (heap.size()) {
		auto u = heap.top();
		heap.pop();
		if (u.fi != dp[u.se.fi][u.se.se]) continue;
		if (u.se == finish) {
			cout << u.fi << '\n';
			return 0;
		}
		for (int i = 0; i < 4; i++) {
			int newx = u.se.fi + dx[i];
			int newy = u.se.se + dy[i];
			if (newx < 1 || newy < 1 || newx > m || newy > n) continue;
			if (dp[newx][newy] < min(u.fi, d[newx][newy])) {
				dp[newx][newy] = min(u.fi, d[newx][newy]);
				heap.push({dp[newx][newy], {newx, newy}});
			}
		}
	}
 	cout << dp[finish.fi][finish.se];
}
