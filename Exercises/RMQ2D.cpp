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

const string NAME = "rmq2d";
const string NAME2 = "TEST";
const ll ESP = 1e-9;
const ll INF = 1e18;
const ll nmax = 2e5;
const ll MOD = 1e9 + 7;
const ll base = 2309;

void fre() {
	string finp = NAME + ".inp";
	string fout = NAME + ".out";
	freopen(finp.c_str(), "r", stdin);
	freopen(fout.c_str(), "w", stdout);
}

int n, m, st[803][803][12][12];

void sol() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			int x;
			cin >> x;
			st[i][j][0][0] = x;
		}
	}	
	for (int k = 1; k <= 10; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				if (j + (1 << k) - 1 > m) break;
				int len = (1 << (k - 1));
				st[i][j][0][k] = min(st[i][j][0][k - 1], st[i][j + len][0][k - 1]);
			}
		}
	}
	for (int t = 1; t <= 10; t++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				if (i + (1 << t) - 1 > n) break;
				int len = (1 << (t - 1));
				st[i][j][t][0] = min(st[i][j][t - 1][0], st[i + len][j][t - 1][0]);
			}
		}
	}
	for (int t = 1; t <= 10; t++) {
		for (int k = 1; k <= 10; k++) {
			for (int i = 1; i <= n; i++) {
				for (int j = 1; j <= m; j++) {
					if (i + (1 << t) - 1 > n || j + (1 << k) - 1 > m) continue;
					int len1 = (1 << (t - 1));
					int len2 = (1 << (k - 1));
					st[i][j][t][k] = min(st[i][j][t - 1][k - 1], 
									 min(st[i + len1][j][t - 1][k - 1], 
									 min(st[i][j + len2][t - 1][k - 1], st[i + len1][j + len2][t - 1][k - 1])));
				}
			}
		}
	}
	int q;
	cin >> q;
	while (q --) {
		int x, y, u, v;
		cin >> x >> y >> u >> v;
		int t1 = log2(u - x + 1);
		int t2 = log2(v - y + 1);
		//cout << st[x][y][t1][t2] << " " << st[u - (1 << t1) + 1][y][t1][t2] << " " << st[x][v - (1 << t2) + 1][t1][t2] << " " << st[u - (1 << t1) + 1][v - (1 << t2) + 1][t1][t2] << '\n';
		cout << min(st[x][y][t1][t2], min(st[u - (1 << t1) + 1][y][t1][t2], min(st[x][v - (1 << t2) + 1][t1][t2], st[u - (1 << t1) + 1][v - (1 << t2) + 1][t1][t2]))) << '\n';
	}
}

int main() {
	fast;
	fre();
	int t = 1;
	//cin >> t;
	while (t --) sol();
}
