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

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

ll get_random(int l, int r) {
	return l + (rng() % (r - l + 1));
}

int used[1000003];

int main() {
	fast;
	int n = get_random(15, 30), k = get_random(1, n);
	cout << n << " " << k << '\n';
	for (int i = 1; i <= n; i++) {
		while (1) {
			 int x = get_random(1, 100000);
			 if (used[x]) continue;
			 cout << x << ' ';
			 break;
		}
	}
}
