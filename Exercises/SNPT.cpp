#pragma GCC optimize ("O3")
#include <bits/stdc++.h>

#define ll long long
#define ld long double
#define fi first 
#define se second
#define pll pair < ll, ll >
#define pii pair < int, int >
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

using namespace std;

const string NAME = "ExpSum";
const string NAME2 = "TEST";
const ll ESP = 1e-9;
const ll INF = 1e18;
const ll nmax = 1e7;
const ll MOD = 1e9 + 7;

void fre() {
	string finp = NAME + ".inp";
	string fout = NAME + ".out";
	freopen(finp.c_str(), "r", stdin);
	freopen(fout.c_str(), "w", stdout);
}

int n, s, a[25], sum = 0;

bool th;

void back_track(int pos) {
	if (th) return ;
	if (pos == n) {
		if ((s - sum) % a[n] == 0) th = true;
		return ;
	}
	for (int i = 0; i <= 50; i ++) {
		if (sum + i * a[pos] > s) return ;
		sum += i * a[pos];
		back_track(pos + 1);
		if (th) return ;
		sum -= i * a[pos];
	}
}

void sol() {
	cin >> n >> s;
	for (int i = 1; i <= n; i++) cin >> a[i];
	sum = 0;
	th = false;
	back_track(1);
	cout << th << '\n';
}

int main() {
	fast;
	fre();
	int t = 1;
	cin >> t;
	while (t --) sol();
}
