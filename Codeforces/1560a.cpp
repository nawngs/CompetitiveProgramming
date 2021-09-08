#include <bits/stdc++.h>

using namespace std;

int t;

vector < int > f;

int main() {
	for (int i = 1; i <= 1700; i++) if (i % 3 != 0 && i % 10 != 3) f.push_back(i);
	cin >> t;
	while (t --) {
		int n;
		cin >> n;
		cout << f[n - 1] << '\n';
	}
}