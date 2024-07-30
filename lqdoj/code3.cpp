#include <bits/stdc++.h>

using namespace std;

int X;

int main() {
	cin >> X;
	for (int i = 2; i * i <= X; i++) {
		while (X % i == 0) { // kiểm tra X có chia hết cho i hay không
			cout << i << ' '; 
			X /= i; // cập nhật lại X
		}
	}
	if (X != 1) cout << X << ' ';
}