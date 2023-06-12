#include <bits/stdc++.h>

#define pii pair < int, int >
#define fi first
#define se second

using namespace std;

int m, n;

pii a[52], b[52];

int aa[52], bb[52];

bool check(int x, int y) {
	if (y > n && a[x].fi > 0) return false;
	if (y > n) return (x == m ? 1 : check(x + 1, 1));
	if (a[x].fi > n - y + 1) return false;
	sort(b + 1, b + n + 1, greater < pii > ());
	int p = 1;
	while (b[p].se < y) p ++;
	while (a[x].fi > 0 && p <= n) {
		b[p].fi --; a[x].fi --;
		p ++;
		while (p <= n && (b[p].fi == 0 || b[p].se < y)) p++;
	}
	if (a[x].fi != 0) return false;
	if (x == m) {
		for (int i = 1; i <= n; i++) if (b[i].fi != 0) return false;
		return true;
	}
	return check(x + 1, 1);
}

void solve() {
	int sa = 0, sb = 0;
	for (int i = 1; i <= m; i++) {
		cin >> aa[i];
		sa += aa[i];
	}
	for (int i = 1; i <= n; i++) {
		cin >> bb[i];
		sb += bb[i];
	}
	for (int ii = 1; ii <= m; ii++) a[ii] = {aa[ii], ii};
	for (int ii = 1; ii <= n; ii++) b[ii] = {bb[ii], ii};
	if (!check(1, 1)) {
		cout << -1 << '\n';
		return ;
	}
	for (int i = 1; i <= m; i++) 
	for (int j = 1; j <= n; j++) {
		for (int ii = 1; ii <= m; ii++) a[ii] = {aa[ii], ii};
		for (int ii = 1; ii <= n; ii++) b[ii] = {bb[ii], ii};
		if (check(i, j + 1)) cout << 0;
		else {
			cout << 1;
			aa[i] --; bb[j] --;
		}
	}
	cout << '\n';
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	while (cin >> m >> n && m != 0 && n != 0) solve();
}