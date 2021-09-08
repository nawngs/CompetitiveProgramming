#include <bits/stdc++.h>

using namespace std;

int t, n, a[10005];

int main() {
	cin >> t;
	while (t--) {
		cin >> n;
		for (int i = 1; i <= n; i++) cin >> a[i];
		a[0] = 0;
		bool th = false;
		if (a[n] == 0) {
			for (int i = 1; i <= n + 1; i++) cout << i << ' ';
			cout << '\n';
			continue;
		}
		for (int i = 0; i <= n; i++) {
			if (a[i] == 0 && a[i + 1] == 1) {
				for (int j = 1; j <= i; j++) cout << j << ' ';
				cout << n + 1 << ' ';
				for (int j = i + 1; j <= n; j++) cout << j << ' ';
				th = true;
				break;
			}
		}
		if (th) cout << '\n';
		else cout << -1 << '\n';
	}
}