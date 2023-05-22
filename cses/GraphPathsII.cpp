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
const ll INF = 4e18;
const ll nmax = 2e5;
const ll MOD = 1e9 + 7;
const ll base = 2309;

void fre() {
	string finp = NAME + ".inp";
	string fout = NAME + ".out";
	freopen(finp.c_str(), "r", stdin);
	freopen(fout.c_str(), "w", stdout);
}

ll n, m, k, adj[103][103];

struct Matrix {
	ll a[103][103];
	void init1() {
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++) a[i][j] = adj[i][j];
	}
	void init() {
		memset(a, 0, sizeof(a));
		a[0][k - 1] = 1;
	}
};

Matrix nhan(Matrix a, Matrix b) {
	Matrix res;
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			res.a[i][j] = INF;
			for(int p = 1; p <= n; p++) res.a[i][j] = min(res.a[i][j], a.a[i][p] + b.a[p][j]);
		}
	}
	return res;
}

Matrix mu(Matrix a, ll b) {
	if (b == 1) return a;
	Matrix x = mu(a, b / 2);
	x = nhan(x, x);
	if (b % 2 == 1) x = nhan(x, a);
	return x;
}


void sol() {
	cin >> n >> m >> k;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++) adj[i][j] = INF;
	for (int i = 1; i <= m; i++) {
		ll u, v, c;
		cin >> u >> v >> c;
		adj[u][v] = min(adj[u][v], c);
	}
	Matrix f;
	f.init1();
	Matrix tam = mu(f, k);
	cout << (tam.a[1][n] <= 1e18 && tam.a[1][n] >= 0 ? tam.a[1][n] : -1);
}

int main() {
	fast;
	//fre();
	int t = 1;
	//cin >> t;
	while (t --) sol();
}
