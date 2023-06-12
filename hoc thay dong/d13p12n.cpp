#include <bits/stdc++.h>

#define ld long double

using namespace std;

int n;

string ss;

const double INF = 1E9 + 7;
const ld EPS = 1E-130;

map < string, ld > f[123];

ld dp(string s, int cur) {
	if (f[cur].find(s) != f[cur].end()) return f[cur][s];
	if (cur > 120) return 0;
	string old = s;
	bool ok = 1;
	for (int i = 1; i < s.size(); i++) {
		if (s[i] < s[i - 1]) {
			ok = false;
			break;
		}
	}
	if (ok) return cur;
	if (cur % 2 == 0) {
		ld res = INF;
		for (int i = 1; i < s.size(); i++) if (s[i] < s[i - 1]) {
			swap(s[i], s[i - 1]);
			res = min(res, dp(s, cur + 1));
			swap(s[i], s[i - 1]);
		}
		return f[cur][old] = res;
	}
	ld res = 0;
	for (int i = 1; i < s.size(); i++) {
		swap(s[i], s[i - 1]);
		res += dp(s, cur + 1);
		swap(s[i], s[i - 1]);
	}
	res /= (1.0 * (n - 1));
	return f[cur][old] = res;
}

int main() {
	cin >> n;
	ss = "";
	for (int i = 1; i <= n; i++) {
		char c; cin >> c;
		ss += c;
	}
	cout << fixed << setprecision(5) << dp(ss, 0);
}