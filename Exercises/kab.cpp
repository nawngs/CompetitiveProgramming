#pragma GCC optimize ("O3")
#include <bits/stdc++.h>

using namespace std;

string s;

int main() {
	cin >> s;
	int n = s.size();
	s = ' ' + s;
	long long ans = 0;
	long long cnt = 0;
	for (int i = 1; i <= n; i++) {
		if (s[i] == 'A') cnt ++;
		else ans += cnt;
	}
	cout << ans;
}
