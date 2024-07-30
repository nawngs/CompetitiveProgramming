#include <bits/stdc++.h>

using namespace std;

const int NMAX = 1E6;

int X, MinPrime[NMAX + 3];

void sanguoc() {
	for (int i = 1; i <= NMAX; i++) MinPrime[i] = i; 
	for (int i = 2; i <= NMAX; i++) if (MinPrime[i] == i) // kiểm tra i có phải số nguyên tố hay không
		for (int j = 2 * i; j <= NMAX; j+=i) // duyệt qua tất cả các bội j của i
			if (MinPrime[j] == j) // kiểm tra xem chúng ta đã tìm được MinPrime[j] hay chưa
				MinPrime[j] = i; // gán MinPrime[j] = i
}	

int main() {
	sanguoc();
	cin >> X;
	while (X > 1) {
		cout << MinPrime[X] << " ";
		X /= MinPrime[X];
	}
}