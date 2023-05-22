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

const string NAME = "biba";
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

ll n;

vector < pii > tam;

struct Matrix {
	ll a[27][27];
	void init1() {
		memset(a, 0, sizeof(a));
		for (int i = 0; i < tam.size(); i++) {
			pii x = tam[i];
			pii temp;
			temp.fi = max(0, x.fi) + 1;
			temp.se = x.se - 1;
			for (int j = 0; j < tam.size(); j++) {
				if (tam[j] == temp) {
					a[i + 1][j + 1] = 1;
					break;
				}
			}
			temp.fi = x.fi - 1;
			temp.se = max(0, x.se) + 1;
			for (int j = 0; j < tam.size(); j++) {
				if (tam[j] == temp) {
					a[i + 1][j + 1] = 1;
					break;
				}
				
			}
		}
	}
	void init2() {
		memset(a, 0, sizeof(a));
		for (int i = 0; i < tam.size(); i++) 
			if (tam[i].fi == 0 && tam[i].se == 0) {
				a[1][i + 1] = 1;
				break;
			}
		
	}
};

Matrix nhan(Matrix a, Matrix b) {
	Matrix res;
	for(int i = 1; i <= 25; i++){
		for(int j = 1; j <= 25; j++){
			res.a[i][j] = 0;
			for(int p = 1; p <= 25; p++) res.a[i][j] = (res.a[i][j] + ((a.a[i][p] % MOD) * (b.a[p][j] % MOD)) % MOD) % MOD;
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
	for (int i = -2; i <= 2; i++)
		for (int j = -2; j <= 2; j++) tam.push_back({i, j});
	cin >> n;
	Matrix f;
	f.init1();
	Matrix g = mu(f, n);
	f.init2();
	f = nhan(f, g);
	ll res = 0;
	for (int i = 1; i <= 25; i++) res = (res + f.a[1][i]) % MOD;
	//for (int i = 1; i <= 25; i++) cout << tam[i - 1].fi << " " << tam[i - 1].se << ' ' << f.a[1][i] << '\n';
	cout << res;
}

int main() {
	fast;
	//fre();
	int t = 1;
	while (t --) sol();
}
