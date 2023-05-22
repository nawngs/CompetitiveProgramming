#pragma GCC optimize ("O2")
#pragma GCC optimize ("O1")

#include <bits/stdc++.h>

using namespace std;

int n, q, dem = 0, cur;

bitset < 100000 > pos[26], tam;

string t;

int main() {
	cin >> n >> q >> t;
	for (int i = 0; i < n; ++i) pos[t[i] - 'a'][i] = 1;
	while (q--) {
		cin >> t;
		n = t.size();
		tam = pos[t[0] - 'a'];
		for (int i = 1; i < n; ++i) tam = (tam & (pos[t[i] - 'a'] >> i));
		cur = tam._Find_first();
		dem = 1;
		if (cur == 1e5) {
			cout << 0 << '\n';
			continue;
		}
		while (1) {
			cur = tam._Find_next(cur + n - 1);
			if (cur == 1e5) break;
			dem ++;
		}
		cout << dem << '\n';
	}
}
