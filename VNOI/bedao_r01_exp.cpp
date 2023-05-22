#include <bits/stdc++.h>

using namespace std;

int t;

long long mu(long long a, long long b) {
	if (b == 0) return 1;
	long long x = mu(a, b / 2);
	x = x * x;
	if (b % 2 == 1) x = x * a;
	return x;
}

int main() {
	cin >> t;
	while (t --) {
		long long a, b, c, d;
		cin >> a >> b >> c >> d;
		int tam = min(b, d);
		b -= tam;
		d -= tam;
		long long x = a * mu(10, b);
		long long y = c * mu(10, d);
		if (x > y) {
			cout << "X > Y" << '\n';
		}
		else if (x < y) cout << "X < Y" << '\n';
			else cout << "X = Y" << '\n';
	}
}