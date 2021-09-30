#include <bits/stdc++.h>

using namespace std;

int t;

void sol() {
	int n;
	string s;
	cin >> n >> s;
	if (n % 4 != 0) {
		cout << "NO" << '\n';
		return ;
	}
	int dem[5];
	memset(dem, 0, sizeof(dem));
	for (int i = 0; i < n; i++) {
		if (s[i] != '#') {
			dem[s[i] - 'A'] ++;
			if (dem[s[i] - 'A'] > n / 4) {
				cout << "NO" << '\n';
				return ;
			}
		}
	}
	cout << "YES" << '\n';
}

int main() {
	cin >> t;
	while (t --) sol();
}