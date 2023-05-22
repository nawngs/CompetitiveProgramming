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

ll z[200003], cnt[200003];

string s;

int main() {
	fast;
	cin >> s;
	int n = s.size();
	s = ' ' + s;
	z[1] = 0;
	ll l = 0, r = 0;
	for (int i = 2; i <= n; i++) {
		ll &x = z[i];
		if (i <= r) x = min(r - i + 1, z[i - l + 1]);
		while (i + x < s.size() && s[i + x] == s[x + 1]) {
			x++;
			l = i;
			r = i + x - 1;
		}
		cnt[z[i]] ++;
	}
	for (int i = n; i >= 1; i--) 
		cnt[i] += cnt[i + 1];
	int q; cin >> q;
	while (q--) {
		ll x;
		cin >> x;
		if (z[n - x + 1] == x && cnt[x] >= 2) 
			cout << "YES" << " " << cnt[x] + 1 << '\n';
		else cout << "NO" << '\n';
	}

}
