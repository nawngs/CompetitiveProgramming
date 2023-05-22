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

int n, a[100003];

void sol() {
	cin >> n;
	bool odd = false, even = false;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		if (a[i] % 2 == 1) odd = 1;
		else even = 1;
	}
	if (odd && even) {
		int pos = 1;
		for (int i = 1; i <= n; i++) if ((a[i] % 2) == (a[1] % 2)) pos = i;
		cout << n - 1 << '\n';
		for (int i = 1; i <= n; i++) {
			if (i == pos) continue;
			if ((a[i] % 2) == (a[pos] % 2)) cout << i << " " << pos << '\n';
			else cout << 1 << " " << i << '\n';
		} 
	}
	else {
		cout << n - 1 << '\n';
		for (int i = 1; i < n; i++) cout << i << " " << n << '\n';
		return ;
	}
}

int main() {
	fast;
	//fre();
	int t = 1;
	cin >> t;
	while (t --) sol();
}
