#include <bits/stdc++.h>

using namespace std;

const int NMAX = 1E6;

int n, a[100003];

bool IsPrime[NMAX + 3];

void sangnguyento() {
	for (int i = 2; i <= NMAX; i++) IsPrime[i] = 1; // khởi tạo tất cả các số đều là số nguyên tố
	for (int i = 2; i <= NMAX; i++) if (IsPrime[i] == 1) // kiểm tra i có phải là số nguyên tố hay không
		for (int j = i * 2; j <= NMAX; j+=i) // duyệt qua tất cả các bội của i
			IsPrime[j] = false; // gán tất cả các bội của i không phải là số nguyên tố
}

int main() {
	sangnguyento();
	cin >> n;
	int res = 0;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		if (IsPrime[a[i]]) res ++;
	}
	cout << res;
}