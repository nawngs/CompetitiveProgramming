#include <bits/stdc++.h>
using namespace std;

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

int64_t rnd(int64_t l, int64_t r) {
   return rng() % (r - l + 1) + l;
}

int a[500][500];

int32_t main() {
  cin.tie(0)->sync_with_stdio(0);
 	int n = rnd(3, 15), m = rnd(1, n), q = rnd(1, 20);
 	cout << n << " " << m << " " << q << '\n';
 	for (int i = 1; i <= m; i++) 
 		cout << rnd(1, n) << ' ';
 	cout << '\n';
 	for (int i = 2; i <= n; i++)
 		cout << rnd(1, i - 1) << " " << i << '\n';
 	while (q--) {
 		int t = rnd(1, 3);
 		if (t == 1) cout << "q" << " " << rnd(1, m) << '\n';
 		else if (t == 2) {
 			cout << "t ";
 			int l = rnd(1, m), r = rnd(l, m);
 			cout << l << " " << r << " " << rnd(1, n) << '\n';
 		}
 		else {
 			cout << "e" << " " << rnd(1, n) << " " << rnd(1, 20) << '\n';
 		}
 	}
}