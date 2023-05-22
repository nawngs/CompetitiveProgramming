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

const string NAME = "past_story";
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

int n, a[300003];

int main() {
	fast;
	//fre();
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];
	a[0] = a[n + 1] = INF;
	int l = 2, r = n - 1;
	while (a[l] <= a[l - 1]) l++;
	while (a[r] <= a[r + 1]) r--;
	l --;
	r ++;
	if (l >= r) {
		cout << "yea bro" << '\n';
		return 0;
	}
	if (r - l == 2) {
		if (a[l] + a[r] >= a[l + 1]) 
			cout << "yea bro" << '\n';
		else cout << "nah bruh" << '\n';
		return 0;
	}
	cout << "nah bruh" << '\n';
}
