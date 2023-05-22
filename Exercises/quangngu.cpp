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
const ll nmax = 1e6;
const ll MOD = 1e9 + 7;
const ll base = 2309;

void fre() {
	string finp = NAME + ".inp";
	string fout = NAME + ".out";
	freopen(finp.c_str(), "r", stdin);
	freopen(fout.c_str(), "w", stdout);
}

int n, cnt[nmax + 3];

int main() {
	fast;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		int x;
		cin >> x;
		cnt[x] ++;
	}
	for (int i = nmax; i >= 2; i--) {
		int dem = 0;
		for (int j = i; j <= nmax; j += i) dem += cnt[j];
		if (dem >= 2) {
			cout << i << '\n';
			return 0;
		}
	}
	cout << 1;
}
