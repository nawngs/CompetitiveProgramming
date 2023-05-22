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

int cnt[30], dem[30];

string s, t;

int main() {
	fast;
	cin >> s >> t;
	for (auto c : t) cnt[c - 'a'] ++;
	int r = -1;
	ll ans = 0;
	for (int l = 0; l < s.size(); l++) {
		if (r < l) r = l - 1;
		while (r < (int)s.size() - 1 && dem[s[r + 1] - 'a'] < cnt[s[r + 1] - 'a']) {
			r ++;
			dem[s[r] - 'a'] ++;
		}
		ans += 1ll * (r - l + 1);
		if (r >= l) dem[s[l] - 'a'] --;
	}
	cout << ans;
}
