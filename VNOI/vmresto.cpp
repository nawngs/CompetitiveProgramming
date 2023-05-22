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

ll n, a[103][103], calc[103][103], tam[103];

void sol() {
	cin >> n;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++) cin >> a[i][j];

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (i == j) continue;
			ll sumi, sumj;
			sumi = sumj = 0;
			for (int k = 1; k <= n; k++) {
				sumi += a[i][k];
				sumj += a[j][k];
			}
			calc[i][j] = sumj - sumi;
		}
	}
	for (int i = 1; i <= n; i++) tam[i] = i;
	sort(tam + 1, tam + n + 1, [](ll &x, ll &y) {
		ll demx = 0, demy = 0;
		for (int i = 1; i <= n; i++) {
			if (calc[x][i] < 0) demx ++;
			if (calc[y][i] < 0) demy ++;
		}
		return demx > demy;
	});
	ll s = 0;
	for (int i = 2; i <= n; i++) {
		a[tam[i]][tam[i]] = a[tam[i - 1]][tam[i - 1]] + calc[tam[i]][tam[i - 1]];
		s += a[tam[i]][tam[i]];
	}
	ll s2 = 0;
	for (int i = 1; i <= n; i++) s2 += a[tam[1]][i];
	ll change = (s2 - s) / (n - 1);
	for (int i = 1; i <= n; i++) a[i][i] += change;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) cout << a[i][j] << " ";
		cout << '\n';
	}
}

int main() {
	fast;
	//fre();
	int t = 1;
	//cin >> t;
	while (t --) sol();
}
