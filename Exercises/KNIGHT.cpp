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

const string NAME = "KNIGHT";
const string NAME2 = "TEST";
const ll ESP = 1e-9;
const ll INF = 1e18;
const ll nmax = 2e5;
const ll MOD = 1e9 + 7;
const ll base = 2309;
const int dx[8] = {-2, -2, -1, -1, 1, 1, 2, 2};
const int dy[8] = {-1, 1, -2, 2, -2, 2, -1, 1};

void fre() {
	string finp = NAME + ".inp";
	string fout = NAME + ".out";
	freopen(finp.c_str(), "r", stdin);
	freopen(fout.c_str(), "w", stdout);
}

int n, m, dem = 0, cnt = 0;

char a[1003][1003];

pii par[1003][1003];

void dfs(int u, int v) {
	cnt ++;
	par[u][v] = {1, 1};
	for (int i = 0; i < 8; i++) {
		int newu = u + dx[i];
		int newv = v + dy[i];
		if (newu < 1 || newv < 1 || newu > n || newv > m || par[newu][newv] != make_pair(-1, -1)) continue;
		dfs(newu, newv);
	}
}

void sol() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++) {
			cin >> a[i][j];	
			if (a[i][j] == '.') par[i][j] = {-1, -1};
			dem += (a[i][j] == '.');
		}
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (par[i][j] == make_pair(-1, -1)) {
				cnt = 0;
				dfs(i, j);
				ans = max(ans, cnt);
			}
		}
	}
	cout << ans;
}

int main() {
	fast;
	fre();
	int t = 1;
	//cin >> t;
	while (t --) sol();
}
