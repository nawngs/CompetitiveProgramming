#include <bits/stdc++.h>

using namespace std;

string s;

int main() {
	cin >> s;
	s = '0' + s;
	//cout << s << '\n';
	int r = s.size() - 1;
	while (s[r] == '1') {
		//cout << s[r] << '\n';
		r --;
	}
	//cout << r << '\n';
	for (int i = 1; i < r; i++) cout << s[i];
	s[r] = '1';
	cout << s[r];
	for (int i = r + 1; i < s.size(); i++) cout << 0;
}