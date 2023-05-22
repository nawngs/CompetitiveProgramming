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

const string NAME = "";
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

ll n, m, s[5003][5003];

ll calc(int u, int v, int x, int y) {
	return s[x][y] - s[u - 1][y] - s[x][v - 1] + s[u - 1][v - 1];
}

void sol() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		string str;
		cin >> str;
		str = ' ' + str;
		for (int j = 1; j <= m; j++) s[i][j] = s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1] + (str[j] - '0');

	}
	ll res = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			int l = 0, r = min(n - i, m - j), mid, ans = -1;
			while (l <= r) {
				mid = (l + r) / 2;
				if (calc(i, j, i + mid, j + mid) == 0) {
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
