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

const string NAME = "";
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

int n, m, a[200003], ans = 1, pos[200003];

void sol() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		pos[a[i]] = i;
	}
	for (int i = 2; i <= n; i++) if (pos[i] < pos[i - 1]) ans ++;
	while (m --) {
		int l, r;
		cin >> l >> r;
		if (a[r] != a[l] - 1) {
			if (pos[a[l]] < pos[a[l] - 1]) ans --;
			if (r < pos[a[l] - 1]) ans ++;
		}
		else {
			if (pos[a[l]] < pos[a[l] - 1]) ans --;
			if (r < l) ans ++;
		}
		if (a[r] != a[l] + 1) {
			if (pos[a[l] + 1] < pos[a[l]]) ans --;
			if (pos[a[l] + 1] < r) ans ++;
		}
		else {
			if (pos[a[l] + 1] < pos[a[l]]) ans --;
			if (l < r) ans ++;
		}
		if (a[r] - 1 != a[l]) {
			if (pos[a[r]] < pos[a[r] - 1]) ans --;
			if (l < pos[a[r] - 1]) ans ++;
		}
		if (a[r] + 1 != a[l]) {
			if (pos[a[r] + 1] < pos[a[r]]) ans --;
			if (pos[a[r] + 1] < l) ans ++;
		}
		cout << ans << '\n';
		swap(pos[a[l]], pos[a[r]]);
		swap(a[l], a[r]);
	}
}

int main() {
	fast;
	//fre();
	int t = 1;
	//cin >> t;
	while (t --) sol();
}
