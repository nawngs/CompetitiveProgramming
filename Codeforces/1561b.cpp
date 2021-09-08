#pragma GCC optimize ("O3")
#include <bits/stdc++.h>

using namespace std;

int t, a, b;

vector < int > f;

void sol() {
	cin >> a >> b;
	f.clear();
	if (b > a) swap(a, b);
	int tam = a - b;
	f.push_back(tam / 2);
	if (tam % 2 == 1) f.push_back(tam / 2 + 1);
	for (int i = 1; i <= b; i++) {
		f.push_back(tam / 2 + 2 * i);
		if (tam % 2 == 1) f.push_back(tam / 2 + 1 + 2 * i);
	}
	sort(f.begin(), f.end());
	cout << f.size() << '\n';
	cout << f[0] << " ";
	for (int i = 1; i < f.size(); i++) if (f[i] != f[i - 1]) cout << f[i] << ' ';
	cout << "\n";
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin >> t;
	while (t --) {
		sol();
	}
}