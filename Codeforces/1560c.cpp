#include <bits/stdc++.h>

using namespace std;

int t;

int main() {
	cin >> t;
	while (t --) {
		int n;
		cin >> n;
		if (n == 1) {
			cout << 1 << " " << 1 << '\n';
			continue;
		}
		long long i = 1;
		while (i * i < n) i ++;
		i --;
		long tam = i * i;
		//cout << i << "\n";
		if (n - tam <= i + 1) {
			cout << n - tam << " " << i + 1 << '\n';
			continue;
		}
		else  cout << i + 1 << " " << (i + 1) * (i + 1) - n + 1 << '\n';
	}
}