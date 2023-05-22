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


int M, A, B;

map < pii, int > g;

struct Matrix {
	ll a[2][2];
	Matrix() {
		a[0][0] = 0;
		a[0][1] = a[1][0] = a[1][1] = 1;
	}
};

Matrix nhan(Matrix a, Matrix b) {
	Matrix res;
	for(int i = 0; i <= 1; i++){
		for(int j = 0; j <= 1; j++){
			res.a[i][j] = 0;
			for(int k = 0; k <= 1; k++){
				res.a[i][j] = (res.a[i][j] + ((a.a[i][k] % M) * (b.a[k][j] % M)) % M) % M;
			}
		}
	}
	return res;
}

Matrix mu(Matrix a, int b) {
	if (b == 1) return a;
	Matrix x = mu(a, b / 2);
	x = nhan(x, x);
	if (b % 2 == 1) x = nhan(x, a);
	return x;
}

void sol() {
	cin >> M >> A >> B;
	g.clear();
	int cur = 0, K = sqrt(6 * M + 1);
	for (int i = 0; i <= K; i++) {
		g[{A, B}] = cur;
		cur ++;
		int C = B - A;
		if (C < 0) C += M;
		B = A;
		A = C;
	}
	Matrix f;
	for (int i = 0; i <= K; i++) {
		Matrix tam = mu(f, i * K + 1);
		pii temp = make_pair(tam.a[0][0], tam.a[0][1]);
		if (g.find(temp) != g.end()) {
			cout << i * K + g[temp] << '\n';
			return ;
		}
	}
	cout << -1 << '\n';
}

int main() {
	fast;
	//fre();
	int t = 1;
	cin >> t;
	while (t --) sol();
}
