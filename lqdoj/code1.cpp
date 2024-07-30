#include <bits/stdc++.h>

using namespace std;

bool check(int x) {
	if (x == 1) return false; //nếu x = 1 thì x không phải là số nguyên tố
	for (int p = 2; p * p <= x; p++) 
		if (x % p == 0) return false; // nếu x chia hết cho p thì x sẽ không phải là số nguyên tố
	return true;
}

int n, a[100003];

int main() {
	cin >> n;
	int res = 0;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		if (check(a[i])) res ++;
	}
	cout << res;
}