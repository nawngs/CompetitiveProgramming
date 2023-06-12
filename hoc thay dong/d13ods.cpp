#include <bits/stdc++.h>

#define ll long long

using namespace std;

ll t, a, b;

ll solve(ll x) {
	if (x == 0) return 0;
	return ((x + 1) / 2) * ((x + 1) / 2) + solve(x / 2);
}

int main() {
	cin >> t;
	while (t--) {
		cin >> a >> b;
		cout << solve(b) - solve(a - 1) << '\n';
	}
}