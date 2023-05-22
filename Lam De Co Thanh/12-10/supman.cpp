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

const string NAME = "supman";
const string NAME2 = "TEST";
const ld ESP = 1e-9;
const ll INF = 1e9 + 7;
const ll LINF = 1E18;
const ll nmax = 2e5;
const ll MOD = 1e9 + 7;
const ll base = 2309;

void fre() {
	string finp = NAME + ".inp";
	string fout = NAME + ".out";
	freopen(finp.c_str(), "r", stdin);
	freopen(fout.c_str(), "w", stdout);
}

int n, m, k, p[20], dp[(1 << 20)], dis[20][20];

bool invalid[20][20];

int calc(int u, int v) {
	if (u > v) 
		swap(u, v);
	int up = max(0, v - u - 1);
	int down = max(0, u + n - v - 1);
	if (up > down) 
		swap(up, down);
	if (down < 2 * up) return down;
	down -= 2 * up;
	return 2 * up + (down + 1) / 2;
}

int main() {
	fast;
	fre();
	cin >> n >> m >> k;
	for (int i = 0; i < 2 * m; i++) {
		cin >> p[i];
		p[i] --;
	}
	for (int i = 0; i < k; i++) {
		int u, v;
		cin >> u >> v;
		u --; v --;
		invalid[u][v] = invalid[v][u] = 1;
	}
	for (int i = 0; i < 2 * m; i++) 
		for (int j = 0; j < 2 * m; j++) 
			dis[i][j] = calc(p[i], p[j]);
	dp[0] = 0;
	for (int i = 1; i < (1 << (2 * m)); i++) {
		if (__builtin_popcount(i) % 2 == 1) continue;
		dp[i] = INF;
		int pos = -1;
		for (int p1 = 0; p1 < (2 * m); p1++) {
			if (((i >> p1) & 1)) {
				if (pos == -1) pos = p1;
				else 
					dp[i] = min(dp[i], dp[(i ^ (1 << p1)) ^ (1 << pos)] + dis[pos][p1]);
			}
		}
	}
	cout << dp[(1 << (2 * m)) - 1];
}
