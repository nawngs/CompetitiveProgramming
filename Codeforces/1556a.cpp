#include <bits/stdc++.h>

using namespace std;

int t;

int main() {
	cin >> t;
	while (t --) {
		int c, d;
		cin >> c >> d;
		if (c < d) swap(c, d);
		//int tam = c - d;
		if ((c - d) % 2 == 1) {
			cout << -1 << '\n';
			continue;
		}
		if (c == d && c == 0) {
			cout << 0 << "\n";
			continue;
		}  
		if (c == d) {
			cout << 1 << '\n';
			continue;
		}
		cout << 2 << "\n";
	}
}