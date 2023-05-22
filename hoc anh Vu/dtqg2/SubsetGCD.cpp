#include <bits/stdc++.h>

#define name ""
#define test "test"
#define ll long long
#define ld long double
#define fi first 
#define se second
#define pll pair < ll, ll >
#define pii pair < int, int >
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define sz(x) ((int)(x).size())
#define pb push_back
#define mp make_pair

using namespace std;

const ld EPS = 1e-9;
const int INF = 1e9 + 7;
const ll LINF = 1E18;
const int NMAX = 2e6;
const ll MOD = 1e9 + 7;
const ll BASE = 2309;

int n, q, phi[NMAX + 3], a[200003], cnt[NMAX + 3];

ll pw[NMAX + 3], res = 0;

vector < int > prime;

vector < pii > divisor[NMAX + 3];

int add(int x, int y) {
	int z = (x + y);
	if (z >= MOD) z -= MOD;
	if (z < 0) z += MOD;
	return z;
}

int sub(int x, int y) {
	int z = (x - y);
	if (z >= MOD) z -= MOD;
	if (z < 0) z += MOD;
	return z;
}

void update(int pos, int val, int x, int chg) {
	if (pos == sz(divisor[x])) {
		res = sub(res, 1ll * sub(pw[cnt[val]], 1) * 1ll * phi[val] % MOD);
		cnt[val] += chg;
		res = add(res, 1ll * sub(pw[cnt[val]], 1) * 1ll * phi[val] % MOD);
		return ;
	}
	for (int i = 0; i <= divisor[x][pos].fi; i++) {
		update(pos + 1, val, x, chg);
		val *= divisor[x][pos].se;
	}
}

int main() {
	fast;
	if(fopen(name".inp", "r")) {
		freopen(name".inp", "r", stdin);
		freopen(name".out", "w", stdout);
	}
	//int t; cin >> t; while (t --) sol();
	pw[0] = 1;
	for (int i = 1; i <= NMAX; i++) {
		phi[i] = i;
		pw[i] = (pw[i - 1] * 2) % MOD;
	}
	for (int i = 2; i <= NMAX; i++) {
		if (phi[i] == i) {
			prime.push_back(i);
			phi[i] = i - 1;
			for (int j = 2 * i; j <= NMAX; j+=i) 
				phi[j] = (phi[j] / i) * (i - 1);
		}
	}
	for (auto x : prime) {
		for (int i = x; i <= NMAX; i+=x) {
			int v = i, dem = 0;
			while (v % x == 0) {
				dem ++;
				v /= x;
			}
			divisor[i].push_back({dem, x});
		} 
	}
	cin >> n >> q;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		update(0, 1, a[i], 1);
	}
	cout << res << '\n';
	while (q--) {
		int t, x; cin >> t >> x;
		if (t == 1) update(0, 1, x, 1);
		else update(0, 1, x, -1);
		cout << res << '\n';
	}
}