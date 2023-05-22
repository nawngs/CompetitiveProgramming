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

int n, res[3001], a[3001];

vector < int > adj[3003];

bitset < 3502 > pt[3001];

bool valid[501];

void sol() {
	for (int i = 1; i <= n; i++) {
			pt[i] = 0;
			cin >> a[i];
			for (auto x : adj[i]) pt[i][x] = 1;
			pt[i][0] = (a[i] != 1);
		}
		memset(res, 255, sizeof(res));
		for (int i = 1; i <= n; i++) {
			int tam = pt[i]._Find_next(0);
			if (tam == pt[i].size() && pt[i][0] == 1) {
				cout << -1 << '\n';
				return ;
			}
			if (tam == pt[i].size()) continue;
			for (int j = 1; j <= n; j++) if (j != i && pt[j][tam] == 1) pt[j] ^= pt[i]; 
			res[tam] = i;
		}
		vector < int > ans;
		ans.clear();
		for (int i = 1; i <= n; i++) {
			if (res[i] == -1) continue;
			res[i] = pt[res[i]][0];
			if (res[i] == 1) ans.push_back(i);
		}
		cout << ans.size() << " ";
		for (auto x : ans) cout << x << " ";
		cout << '\n';
}

int main() {
	fast;
	//fre();
	int t;
	cin >> n >> t;
	for (int i = 1; i <= n; i++) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
		adj[i].push_back(i);
	}
	for (int i = 1; i <= n; i++) for (auto x : adj[i]) pt[i][x] = 1;
	for (int q = 1; q <= t; q++) {
		for (int i = 1; i <= n; i++) {
			cin >> a[i];
			pt[i][n + q] = (!a[i]);
		}
	}
	memset(res, 255, sizeof(res));
	memset(valid, 1, sizeof(valid));
	for (int i = 1; i <= n; i++) {
		int tam = pt[i]._Find_first();
		if (tam > n) {
			for (int j = 1; j <= t; j++) if (pt[i][n + j] == 1) valid[j] = false;
			continue;
		}
		for (int j = 1; j <= n; j++) if (j != i && pt[j][tam] == 1) pt[j] ^= pt[i]; 
		res[tam] = i;
	}
	for (int i = 1; i <= t; i++) {
		if (!valid[i]) {
			cout << -1 << '\n';
			continue;
		}
		vector < int > ans;
		for (int j = 1; j <= n; j++) {
			if (res[j] == -1) continue;
			if (pt[res[j]][n + i] == 1) ans.push_back(j);
		}
		cout << ans.size() << ' ';
		for (auto x : ans) cout << x << " ";
		cout << '\n';
	}
}
