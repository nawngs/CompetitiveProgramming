#include <bits/stdc++.h>

using namespace std;

const int NTEST = 100000;

int n, a[10005], k, b[10006];

int main(){
	freopen("check_test.inp", "r", stdin);
	for (int i = 1; i <= 500; i++) cin >> a[i];
	for (int i = 1; i <= 500; i++) {
		cin >> b[i];
		if (a[i] != b[i]) cout << a[i] << " " << b[i] << '\n';
	}

	cout << "OK" << '\n';
}