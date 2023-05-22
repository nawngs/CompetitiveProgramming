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
const ll MOD = 998244353;
const ll base = 2309;

void fre() {
	string finp = NAME + ".inp";
	string fout = NAME + ".out";
	freopen(finp.c_str(), "r", stdin);
	freopen(fout.c_str(), "w", stdout);
}

ll n, m, a[6][6], k, ans = 0;

void back_track(int i, int j) {
	//cout << i << " " << j << '\n';
	if (i == n + 1) {
		for (int p = 2; p <= n; p++) {
			for (int q = 2; q <= m; q++) {
				int temp = (a[p][q] + a[p - 1][q] + a[p][q - 1] + a[p - 1][q - 1]);
				if (temp != 0 && temp != 2 && temp != 4) return ;
			}
		}
		ans ++;
		ans %= 998244353;
		return ;
	}
	if (a[i][j] == -1) { 
		for (int c = 0; c <= 1; c++) {
			a[i][j] = c;
			if (j == m) back_track(i + 1, 1);
			else back_track(i, j + 1);
			a[i][j] = -1;
		}
	}
	else {
		if (j == m) back_track(i + 1, 1);
		else back_track(i, j + 1);
	}
}

void sol() {
	memset(a, 255, sizeof(a));
	cin >> n >> m >> k;
	for (int i = 1; i <= k; i++) {
		int x, y, c;
		cin >> x >> y >> c;
		a[x][y] = c;
	}
	back_track(1, 1);
	cout << ans;
}

int main() {
	fast;
	//fre();
	int t = 1;
	//cin >> t;
	while (t --) sol();
}
