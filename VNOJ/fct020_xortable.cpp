#include <bits/stdc++.h>

using namespace std;

int n, a[105];

int main() {
	//cout << (5 ^ 0) << '\n';
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cout << (a[i] ^ a[j]) << ' ';
		}
		cout << '\n';
	}
}