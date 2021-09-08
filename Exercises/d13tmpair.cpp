//link:https://lqdoj.edu.vn/problem/d13tmpair
#include <bits/stdc++.h>

using namespace std;

long long n;

int main() {
	long long ans = 2;
	cin >> n;
	for (int i = 2; i * i <= n; i++) {
		if (n % i == 0) {
			//cout << i << '\n';
			ans += 4;
			if(i == n / i) ans -= 2;
		}
	}
	cout << ans - (n % 2 == 0);
}