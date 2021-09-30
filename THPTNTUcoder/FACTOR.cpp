#include <bits/stdc++.h>
#define ll long long

using namespace std;

const ll MOD = 100000;

ll dem = 0;
string s;

bool check(ll x) {
	ll sum = 0;
	for (int i = 5; i <= x; i *= 5) sum += x / i;
	return sum == dem;
}

int main() {
	cin >> s;
	ll n = s.size();
	for (int i = n - 1; i >= 0; i--) {
		if (s[i] == '0') dem ++;
		else break;
	}
	ll ans = 0;
	for (ll i = 4; i >= 0; i--) {
		if (n - 1 - dem - i < 0) continue;
		ans = ans * 10 + (s[n - 1 - dem - i] - '0');
	}
	ll resl = -1, resr = -1;
	for (int i = 1; i <= 1000; i++) {
		if (check(i) && resl == -1) resl = i;
		if (check(i)) resr = i;
 	}
 	ll sum = 1;
 	for (int i = 1; i < resl; i++) {
 		ll tam = i;
 		while (tam % 2 == 0 && dem > 0) {
 			tam /= 2;
 			dem --;
 		}
 		while (tam % 5 == 0) tam /= 5;
 		sum = (sum * tam) % MOD;
 	}
 	for (int i = resl; i <= resr; i++) {
 		ll tam = i;
 		while (tam % 2 == 0 && dem > 0) {
 			tam /= 2;
 			dem --;
 		}
 		while (tam % 5 == 0) tam /= 5;
 		sum = (sum * tam) % MOD;
 		if (sum == ans) {
 			cout << i << '\n';
 			return 0;
 		}
 	}
}