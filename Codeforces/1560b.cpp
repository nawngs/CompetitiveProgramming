#include <bits/stdc++.h>

using namespace std;

int t;

int main() {
	cin >> t;
	while (t --) {
		int a, b, c;
		cin >> a >> b >> c;
		if (a > b) swap(a, b);
		int last = (b - a) * 2;
		if (last < b || last < c || last < a) {
			cout << -1 << '\n'; 
			continue;
		}
		if (c + last / 2 <= last) {
			cout << c + last / 2 << '\n';
			continue;
		}
		if (c - last / 2 <= last && c - last / 2 >= 1 && c - last / 2 != a && c - last / 2 != b) {
			cout << c - last / 2 << '\n';
			continue;
		}	
		cout << -1 << '\n';
	}
}