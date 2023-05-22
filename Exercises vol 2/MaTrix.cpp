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

const string NAME = "maTrix";
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

int n, m, k, a[503][503], b[503][503];

void sol() {
	cin >> n >> m >> k;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++) cin >> a[i][j];

	for (int i = 1; i <= m; i++)
		for (int j = 1; j <= k; j++) cin >> b[i][j];

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= k; j++) {
			int res = 0;
			for (int p = 1; p <= m; p++) res += a[i][p] * b[p][j];
			cout << res << " ";
		}
		cout << '\n';
	}
}

int main() {
	fast;
	fre();
	int t = 1;
	//cin >> t;
	while (t --) sol();
}
