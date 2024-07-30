#include <bits/stdc++.h>
using namespace std;

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

int64_t get(int64_t l, int64_t r) {
   return rng() % (r - l + 1) + l;
}

int a[500][500];

int32_t main() {
  cin.tie(0)->sync_with_stdio(0);
 	int n = get(1, 7);
 	cout << n << '\n';
 	for (int i = 1; i <= n; i++) cout << get(1, 15) << " ";
 	cout << '\n';
 	for (int i = 2; i <= n; i++) cout <<get(1, i - 1) << " " << i << '\n';
 	
}