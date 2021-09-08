#include <bits/stdc++.h>

using namespace std;

int t, ans, n;

string s;

int calc(string s) {
	int sum = 0;
	for (int i = 1; i < n; i++) if(s[i] == s[i - 1]) sum ++;
	return sum;
}

string solve() {
	string tams = s;
	for (int i = 1; i < n; i++) {
		if (tams[i] == '?') {
			tams[i] = (tams[i - 1] == 'B' ? 'R' : 'B');
		}
	}
	return tams;
}

int main() {
	cin >> t;
	while (t --) {
		cin >> n >> s;
		ans = 1e9;
		if (s[0] == '?') {
			s[0] = 'R';
			string tam = solve();
			s[0] = 'B';
			string temp = solve();
			calc(tam) < calc(temp) ? cout << tam << '\n' : cout << temp << '\n';
		}
		else cout << solve() << '\n';
	}
}