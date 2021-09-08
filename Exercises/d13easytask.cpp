//link: https://lqdoj.edu.vn/problem/d13easytask

#include <bits/stdc++.h>
#define ll long long

using namespace std;

const int nmax = 1e6;

ll n, x, s = 0;

bool prime[nmax];

void sang() {
	for (int i = 1; i <= nmax; i++) prime[i] = true;
	prime[1] = prime[0] = false;
	for (int i = 2; i * i <= nmax; i++) {
		if (prime[i]) {
			for (int j = i * i; j <= nmax; j += i) prime[j] = false;
		}
	}
}

int main() {
	cin >> n;
	sang();
	ll mina = 1e18, ans = -1e18;
	for (int i = 1; i <= n; i++) {
		cin >> x;
		s += x;
		if (prime[i]) {
			//cout << i << " " << s << " " << mina << '\n';
			mina = min(mina, s - x);
			ans = max(ans, s - mina);
		}
	}
	cout << ans;
}
