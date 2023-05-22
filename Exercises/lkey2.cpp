#include <bits/stdc++.h>

using namespace std;

string str, s;

int ans = 0, a[105];

int main() {
	cin >> str;
	cin >> s;
	for (int i = 0; i < s.size(); i++) {
		int pos = 0;
		for (int j = 0; j < str.size(); j++) {
			if (s[i] == str[j]) {
				pos = j;
				break;
			}
		}
		a[i] = pos;
	}
	for (int i = 1; i < s.size(); i++) ans += abs(a[i] - a[i - 1]);
	cout << ans;
}