#include <bits/stdc++.h>

using namespace std;

int t, n;
string s;

int main() {
	cin >> t;
	while (t --) {
		cin >> n >> s;
		long long res = 0;
		for (int i = 0; i < n; i++) {
			if (s[i] == '0') continue;
			res += (s[i] - '0') + (i != n - 1);
		}
		cout << res << '\n';
	}
}