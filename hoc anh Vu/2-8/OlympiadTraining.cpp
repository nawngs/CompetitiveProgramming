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

ll n, m, q, f[(1 << 20)];

pll a[10003][20];

void sol() {
	cin >> n >> m >> q;	
	for (int i = 0; i < (1 << n); i++) f[i] = 0;

	for (int j = 0; j < n; j++)
		for (int i = 1; i <= m; i++) {
			cin >> a[i][j].fi;
			a[i][j].se = j;
		}
	for (int i = 1; i <= m; i++) {
		sort(a[i], a[i] + n);

		int tam = 0;
		for (int j = 0; j < n; j++) {
			f[tam] -= a[i][j].fi;
			tam ^= (1 << a[i][j].se);
			f[tam] += a[i][j].fi;
		}
	}
	for (int bit = 0; bit < n; bit++) {
		for (int i = (1 << n) - 1; i >= 0; i--) if (i & (1 << bit)) f[i ^ (1 << bit)] += f[i];
		
	}
	while (q--) {
		int x;
		cin >> x;
		ll ans = LINF;
		for (int i = 1; i < (1 << n); i++) if (__builtin_popcount(i) == x) ans = min(ans, f[i]);
		cout << ans << '\n';
	}
}

int main() {
	fast;
	//fre();
	int t = 1;
	cin >> t;
	while (t --) sol();
}
