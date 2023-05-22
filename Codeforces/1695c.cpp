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

int n, m, a[1003][1003], maxa[1003][1003], mina[1003][1003];

void sol() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++) cin >> a[i][j];
	if ((n + m) % 2 == 0) {
		cout << "NO" << '\n';
		return ;
	}
	maxa[1][1] = mina[1][1] = a[1][1];
	for (int i = 2; i <= n; i++) maxa[i][1] = mina[i][1] = maxa[i - 1][1] + a[i][1];
	for (int j = 2; j <= m; j++) maxa[1][j] = mina[1][j] = maxa[1][j - 1] + a[1][j];
	for (int i = 2; i <= n; i++)
		for (int j = 2; j <= m; j++) {
			maxa[i][j] = max(maxa[i - 1][j], maxa[i][j - 1]) + a[i][j];
			mina[i][j] = min(mina[i - 1][j], mina[i][j - 1]) + a[i][j];
		}
	if (maxa[n][m] % 2 == 1 || maxa[n][m] < 0 || mina[n][m] > 0) cout << "NO" << '\n';
	else cout << "YES" << '\n';
}

int main() {
	fast;
	//fre();
	int t = 1;
	cin >> t;
	while (t --) sol();
}
