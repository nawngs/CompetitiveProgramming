#include <bits/stdc++.h>

using namespace std;

int n;

string s;

namespace sub1 {
	int res = 0;
	bool check() { // ham kiem tra co thoa man sub 1
		if (n <= 100) return true;
		else return false;
	}
	void solve() { // ham xu li sub 1
		for (int l = 0; l < n; l++)
		for (int r = l; r < n; r++) {
			bool ok = 1;
			for (int i = l; i <= r; i++) if (s[i] != s[r - (i - l)]) ok = false;
			if (ok) res ++;
		}
		cout << res << '\n';
	}
}

int main() {
    freopen("PALIN.inp", "r", stdin);
	freopen("PALIN.ans", "w", stdout);
	cin >> n >> s;
	if (sub1::check()) {
		sub1::solve();
		return 0;
	}
}

