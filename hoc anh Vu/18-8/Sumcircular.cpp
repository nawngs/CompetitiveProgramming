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

ll n, M, d, k, a[503];

vector < ll > X, Y;

ll dis(ll x, ll y) {
	return min(abs(y - x), n - abs(y - x));
}

vector < ll > mul(vector < ll > A, vector < ll > B) {
	vector < ll > res;
	res.resize(n + 5);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) res[i] = (res[i] + A[j] * B[dis(i, j)]) % M;
	return res;
}

int main() {
	fast;
	cin >> n >> M >> d >> k;
	for (int i = 0; i < n; i++) cin >> a[i];
	X.resize(n + 5);
	Y = X;
	for (int i = 0; i < n; i++) if (dis(0, i) <= d) X[i] = 1;
	Y[0] = 1;
	while (k) {
		if (k & 1) Y = mul(Y, X);
		X = mul(X, X);
		k >>= 1;
	} 
	for (int i = 0; i < n; i++) {
		ll s = 0;
		for (int j = 0; j < n; j++) s = (s + Y[dis(i, j)] * a[j]) % M;
		cout << s << " ";
	}
}
	