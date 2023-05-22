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

const string NAME = "cock";
const string NAME2 = "TEST";
const ll ESP = 1e-9;
const ll INF = 1e18;
const ll nmax = 2e5;
const ll MOD = 1e9 + 7;
const ll base = 2309;
const int x[4] = {-1, 0, 0, 1};
const int y[4] = {0, -1, 1, 0};

void fre() {
	string finp = NAME + ".inp";
	string fout = NAME + ".out";
	freopen(finp.c_str(), "r", stdin);
	freopen(fout.c_str(), "w", stdout);
}

ll n, a[303][303], k, row[303][303], cnt[303][303][303];

void sol() {
	cin >> n >> k;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++) a[i][j] = 0;
	for (int i = 1; i <= k; i++) {
		int pox,poy;
		cin >> pox >> poy;
		a[pox][poy] = 1;
	}
	memset(row, 0, sizeof(row));
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++) row[i][j] = row[i][j - 1] + a[i][j];
	ll ans = 0;
	for (int l = 1; l <= n; l++) {
		for (int r = l; r <= n; r++) {
			for (int i = 1; i <= n; i++) {
				if (row[i][r] - row[i][l - 1] + row[i + 1][r] - row[i + 1][l - 1] == 0) 
					for (int j = i; j >= 1; j--) {
						if (a[j][l] == 1 || a[j][r] == 1 || a[j][l - 1] == 1 || a[j][r + 1] == 1) break;
						if (row[j][r] - row[j][l - 1] + row[j - 1][r] - row[j - 1][l - 1] == 0) ans ++;
					}
			}
		}
	}
	cout << ans << '\n';
}

int main() {
	fast;
	fre();
	int t = 1;
	cin >> t;
	while (t --) sol();
}
