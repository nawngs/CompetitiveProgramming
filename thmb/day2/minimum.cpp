#include <bits/stdc++.h>

#define ll long long
#define ld long double
#define fi first 
#define se second
#define pll pair < ll, ll >
#define pii pair < int, int >
#define all(F) begin(F),end(F)
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

using namespace std;

const string NAME = "minimum";
const string NAME2 = "TEST";
const ll ESP = 1e-9;
const ll INF = 1e18;
const ll nmax = 5e6;
const ll MOD = 1e9 + 7;
const ll base = 2309;

void fre() {
	string finp = NAME + ".inp";
	string fout = NAME + ".out";
	freopen(finp.c_str(), "r", stdin);
	freopen(fout.c_str(), "w", stdout);
}

int n, x, y, a[nmax + 3], it2[4 * nmax + 3], id;

ll s[nmax + 3];

int main() {
	fast;
	//fre();
	cin >> n >> x >> y;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
		s[i] = s[i - 1] + 1ll * a[i];
	}
	s[n + 1] = -INF;
	int pos_use = n + 1, pos_not_use = n + 1;
	int pos = n + 3, farthest = n + 1;
	ll ans = -INF, pos1, pos2;
	for (int i = n; i >= 1; --i) {
		if (s[pos_not_use] < s[i]) pos_not_use = i;
		if (x <= a[i] && a[i] <= y) {
			pos = i;
			pos_use = pos_not_use;
		}
		if (a[i] < x) {
			farthest = i;
			pos_use = pos_not_use = n + 1;
		}
		//cout << i << " " << " " << pos_use << " " << pos_not_use << '\n'
		if (farthest >= pos) {
			if (ans < s[pos_use] - s[i - 1]) {
				ans = s[pos_use] - s[i - 1];
				pos2 = pos_use;
				pos1 = i;
			}
		}
	}
	cout << ans << '\n' << pos1 << " " << pos2 << '\n'; 
}