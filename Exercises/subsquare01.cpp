#pragma GCC optimize ("O3")
#include <bits/stdc++.h>

#define ll long long
#define ld long double
#define fi first 
#define se second
#define pll pair < ll, ll >
#define pii pair < int, int >
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

using namespace std;

const string NAME = "subsquare01";
const string NAME2 = "TEST";
const ll ESP = 1e-9;
const ll INF = 1e18;
const ll nmax = 1e7;
const ll MOD = 1e9 + 7;

void fre() {
	string finp = NAME + ".inp";
	string fout = NAME + ".out";
	freopen(finp.c_str(), "r", stdin);
	freopen(fout.c_str(), "w", stdout);
}

int n, m, a[5003][5003], s[5003][5003];

int calc(int x, int y, int size_sq) {
	return s[x + size_sq][y + size_sq] - s[x - 1][y + size_sq] - s[x + size_sq][y - 1] + s[x - 1][y - 1];
}

void sol() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		string str;
		cin >> str;
		str = ' ' + str;
		for (int j = 1; j <= m; j++) {
			a[i][j] = str[j] - '0';	
			s[i][j] = s[i][j - 1] + s[i - 1][j] - s[i - 1][j - 1] + a[i][j];
		}
	}
	ll res = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (a[i][j] == 1) continue;
			int l = 0, r = min(n - i, m - j), ans, mid;
			while (l <= r) {
				mid = (l + r) / 2;
				if (calc(i, j, mid) == 0) {
					ans = mid;
					l = mid + 1;
				}
				else r = mid - 1;
			}
			res += ans + 1;
		}
	}
	cout << res;
}

int main() {
	fast;
	//fre();
	int t = 1;
	//cin >> t;
	while (t --) sol();
}
