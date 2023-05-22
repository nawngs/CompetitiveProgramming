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

const string NAME = "rx";
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

int k;
 
ll n;

struct Matrix {
	int a[101][101];
	void init1() {
		memset(a, 0, sizeof(a));
		for (int i = 0; i < k - 1; i++) a[i][i + 1] = 1;
		a[k - 1][1] = a[k - 1][k - 1] = 1;
	}
	void init() {
		memset(a, 0, sizeof(a));
		a[0][k - 1] = 1;
	}
};

Matrix nhan(Matrix a, Matrix b) {
	Matrix res;
	for(int i = 0; i < k; i++){
		for(int j = 0; j < k; j++){
			res.a[i][j] = 0;
			for(int p = 0; p < k; p++) res.a[i][j] = (res.a[i][j] + ((a.a[i][p] % MOD) * (b.a[p][j] % MOD)) % MOD) % MOD;
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
	cin >> n >> k;
	k ++;
	Matrix f;
	f.init1();
	Matrix tam = mu(f, n);
	f.init();
	cout << nhan(f, tam).a[0][k - 1];
}

int main() {
	fast;
	fre();
	int t = 1;
	//cin >> t;
	while (t --) sol();
}
