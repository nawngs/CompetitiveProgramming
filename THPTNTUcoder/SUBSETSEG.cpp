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
const ll INF = 1e9 + 7;
const ll nmax = 1e7;
const ll MOD = 1e9 + 7;

void fre() {
	string finp = NAME + ".inp";
	string fout = NAME + ".out";
	freopen(finp.c_str(), "r", stdin);
	freopen(fout.c_str(), "w", stdout);
}

int n, a[100005], cnt[1005], s;

void sol() {
	cin >> n >> s;
	for (int i = 1; i <= n; i++) cin >> a[i];
	cnt[0] = 1;
	int l = 1, r = 0, ans = INF;
	while (r <= n) {
		if (r < l) r = l - 1;
		r ++;
		for (int i = s; i >= a[r]; i --) cnt[i] += cnt[i - a[r]];
		if (cnt[s] != 0) {
			ans = min(ans, r - l + 1);
			for (int i = a[r]; i <= s; i++) cnt[i] -= cnt[i - a[r]];
			for (int i = a[l]; i <= s; i++) cnt[i] -= cnt[i - a[l]];
			l ++;
			r --;
		}
	}
	cout << (ans == INF ? -1 : ans); 
}

int main() {
	fast;
	//fre();
	int t = 1;
	//cin >> t;
	while (t --) sol();
}
