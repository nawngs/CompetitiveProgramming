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

ll n, x[103], k;

bool getbit(ll a, ll pos){
	return (a & 1ll << pos);
}

ll countbits(ll x){
	ll dem = 0;
	for(int i = 0; i <= 61; i++){
		if(getbit(x, i)) dem ++;
	}
	return dem;
}

struct Matrix {
	ll a[101][101];
	void init1() {
		memset(a, 0, sizeof(a));
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++) a[i][j] = (countbits(x[i] ^ x[j]) % 3 == 0);
	}
	void init() {
		memset(a, 0, sizeof(a));
		for (int i = 1; i <= n; i++) a[1][i] = 1;
	}
};

Matrix nhan(Matrix a, Matrix b) {
	Matrix res;
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			res.a[i][j] = 0;
			for(int p = 1; p <= n; p++) res.a[i][j] = (res.a[i][j] + ((a.a[i][p] % MOD) * (b.a[p][j] % MOD)) % MOD) % MOD;
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
	for (int i = 1; i <= n; i++) cin >> x[i];
	if (k == 1) {
		cout << n << '\n';
		return ;
	}
	Matrix f;
	f.init1();
	k --;
	Matrix tam = mu(f, k);
	f.init();
	f = nhan(f, tam);
	ll res = 0;
	for (int i = 1; i <= n; i++) res = (res + f.a[1][i]) % MOD;
	cout << res;
}

int main() {
	fast;
	//fre();
	int t = 1;
	//cin >> t;
	while (t --) sol();
}
