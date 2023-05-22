#pragma GCC optimize ("O2")
#include <bits/stdc++.h>

#define ll long long
#define ld long double
#define fi first 
#define se second
#define pll pair < ll, ll >
#define pii pair < int, int >
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

using namespace std;

const string NAME = "";
const string NAME2 = "TEST";
const ld ESP = 1e-9;
const ll INF = 1e9 + 7;
const ll LINF = 1E18;
const ll nmax = 2e5;
const ll MOD = 1e9 + 7;
const ll base = 2309;

void fre() {
	string finp = NAME + ".inp";
	string fout = NAME + ".out";
	freopen(finp.c_str(), "r", stdin);
	freopen(fout.c_str(), "w", stdout);
}

ll n, cnt0 = 0;

int main() {
	fast;
	cin >> n;
	ll res = 1;
	vector < ll > negative;
	for (int i = 1; i <= n; i++) {
		ll x;
		cin >> x;
		if (x > 0) res = (res * x) % MOD;
		else if (x < 0) negative.push_back(x);
		else cnt0 ++;
	}
	if (cnt0 > 1) {
		cout << 0 << '\n';
		return 0;
	}
	if (cnt0 && negative.size() % 2 == 1) {
		cout << 0 << '\n';
		return 0;
 	}
 	sort(negative.begin(), negative.end());
 	if (negative.size() % 2)
 		for (int i = 0; i < negative.size() - 1; i++) res = (res * negative[i]) % MOD;
 	else 
 		for (auto x : negative) res = (res * x) % MOD;
 	cout << res;
}	
