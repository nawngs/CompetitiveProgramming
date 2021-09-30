#include <bits/stdc++.h>

using namespace std;

int t;
int n;
string s;

int calc(int tmp, string s) {
	int n = s.size();
	int ans = 0;
	for (int i = 0; i < n; i++) {
		if (s[i] == 'O' && tmp == 1) {
			ans ++;
			tmp = 2;
		}
		if (s[i] == 'X' && tmp == 2) {
			ans ++;
			tmp = 1;
		}
	}
	return ans;
}

int sol(string s) {
	return min(calc(1, s), calc(2, s));
}

int main() {
	freopen("weak_typing.inp", "r", stdin);
	freopen("weak_typing.out", "w", stdout);
	cin >> t;
	for (int i = 1; i <= t; i++) {
		cin >> n >> s;
		cout << "Case #" << i << ": " << sol(s) << '\n';
	}
}