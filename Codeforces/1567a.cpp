#include <bits/stdc++.h>

using namespace std;

int t;

int main() {
	cin >> t;
	while (t --) {
		int n;
		string s, ans = "";
		cin >> n >> s;
		for (int i = 0; i < s.size(); i++) {
			if (s[i] == 'U') {
				ans += 'D';
				continue;
			}
			if (s[i] == 'D') {
				ans += 'U';
				continue;
			}
			ans += s[i];
		}
		cout << ans << '\n';
	}
}