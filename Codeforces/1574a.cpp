#include <bits/stdc++.h>

using namespace std;

int t, n;

void sol() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		string ans = "";
		for (int j = 1; j <= i; j++) {
			ans = ans + '(';
		}
		for (int j = 1; j <= i; j++) {
			ans = ans + ')';
		}
		for (int j = 1; j <= n - i; j++) ans += "()";
		cout << ans << '\n';
	}
}

int main() {
	cin >> t;
	while (t --) sol();
}