#include <bits/stdc++.h>

using namespace std;

int t;

int main() {
	cin >> t;
	while (t --) {
		long long l, r;
		cin >> l >> r;
		if (l <= r / 2) {
			r += r % 2;
			cout << r / 2 - 1 << '\n';
			continue;
		}
		else cout << r % l << '\n';
	}
}