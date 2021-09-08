#include <bits/stdc++.h>

using namespace std;

int t, n, a[1002];

bool check(int n) {
	for (int i = 2; i <= n; i++) if (a[i] < a[i - 1]) return false;
	return true;
}

int main() {
	cin >> t;
	while (t --) {
		cin >> n;
		for (int i = 1; i <= n; i++) cin >> a[i];
		if (check(n)) {
			cout << 0 << '\n';
			continue;
		}
		int k = 1;
		while(1) {
			//cout << k << '\n';
			if (k % 2 == 1) for (int i = 1; i <= n - 2; i += 2) {if (a[i] > a[i + 1]) swap(a[i], a[i + 1]);}
			if (k % 2 == 0) for (int i = 2; i < n; i += 2) {if (a[i] > a[i + 1]) swap(a[i], a[i + 1]);}
			//cout << k  << '\n';
			//for (int i = 1; i <= n; i++) cout << a[i] << ' ';
			//cout << '\n';
			if (check(n)) break;
			k ++;
		}
		cout << k << '\n';
	}
}