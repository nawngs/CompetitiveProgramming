#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll nm = 5e3, mm = 1e6;
int k, d[nm + 5][nm + 5];
string a, b;

void sub1() {
	ll j = 1;
	cin >> a;

	for (int i = 0; i < a.size(); ++i) {
		if (a[i] == 'B') {
			if (j % 2) ++j;
		}
		else {
			if (j % 2 == 0) ++j;
		}
		++j;
	}

	cout << mm - j + 1;
}

void sub23() {
	cin >> a >> b;
	ll n = a.size(), m = b.size();
	memset(d, 0x3f, sizeof d);
	a = ' ' + a;
	b = ' ' + b;
	d[0][0] = 0;
	for (int i = 0; i <= n; ++i) {
		for (int j = 0; j <= m; ++j) {
			if (d[i][j] > mm) continue;
			int cur = d[i][j] + 1, cur2 = cur;
			if (a[i + 1] == 'B') {
				if (cur % 2) ++cur;
				if (cur % 2 == 0) ++cur;
			}
			else {
				if (cur % 2 == 0) ++cur;
				if (cur % 2) ++cur;
			}
			if (b[j + 1] == 'B') {
				if (cur2 % 2) ++cur2;
				if (cur2 % 2 == 0) ++cur2;
			}
			else {
				if (cur2 % 2 == 0) ++cur2;
				if (cur2 % 2) ++cur2;
			}
			d[i + 1][j] = min(d[i + 1][j], cur - 1);
			d[i][j + 1] = min(d[i][j + 1], cur2 - 1);
		}
	}
	cout << mm - d[n][m];
}

signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	// freopen("B4.inp", "r", stdin);
	// freopen("B4.out", "w", stdout);
	
	cin >> k;
	if (k == 1) sub1();
	else sub23();
}