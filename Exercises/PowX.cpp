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

const string NAME = "PowX";
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

struct Matrix {
	int a[2][2];
	Matrix() {
		a[0][0] = 1;
		a[0][1] = a[1][0] = a[1][1] = 0;
	}
	void init(int x) {
		a[0][0] = x;
	}
};

Matrix nhan(Matrix a, Matrix b) {
	Matrix res;
	for(int i = 0; i <= 1; i++){
		for(int j = 0; j <= 1; j++){
			res.a[i][j] = 0;
			for(int k = 0; k <= 1; k++){
				res.a[i][j] = (res.a[i][j] + ((a.a[i][k] % MOD) * (b.a[k][j] % MOD)) % MOD) % MOD;
			}
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
	int x;
	cin >> x;
	Matrix a;
	a.init(x);
	a = mu(a, x);
	cout << a.a[0][0] << ' ';
}

int main() {
	fast;
	fre();
	int t = 1;
	cin >> t;
	while (t --) sol();
}
/*
x 0 	x 0
0 0 	0 0

x ^ 2 0
0     0
*/