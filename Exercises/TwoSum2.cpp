#include <bits/stdc++.h>

using namespace std;

string s;

int main() {
	cin >> s;
	cout << s[s.size() - 1] - '0' + s[s.size() - 2] - '0';
}