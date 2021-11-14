#pragma GCC optimize ("O3")
#include <bits/stdc++.h>

#define ll long long
#define ld long double
#define fi first 
#define se second
#define pll pair < ll, ll >
#define pii pair < int, int >
#define slow ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

using namespace std;

const ll ESP = 1e-9;
const ll INF = 1e18;
const ll nmax = 1e7;
const ll MOD = 1e9 + 7;

int n, k, a[100005];

int main() {
	slow;
	cin >> n >> k;
	for (int i = 1; i <= k; i++) cin >> a[i];
 	int pos = -1;
 	for (int i = k; i >= 1; i--) {
 		if (a[i] == n - (k - i)) continue;
 		else {
 			a[i] ++;
 			pos = i;
 			break;
 		} 
 	}
 	if (pos == -1) {
 		cout << -1 << '\n';
 		return 0;
 	}
 	for (int i = 1; i <= k; i++) {
 		if (i > pos) a[i] = a[i - 1] + 1;
 		cout << a[i] << " " ;
 	}
}
