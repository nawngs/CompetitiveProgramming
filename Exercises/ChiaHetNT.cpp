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

const string NAME = "ChiaHetNT";
const string NAME2 = "TEST";
const ll ESP = 1e-9;
const ll INF = 1e18;
const ll nmax = 1e5;
const ll MOD = 1e9 + 7;

void fre() {
	string finp = NAME + ".inp";
	string fout = NAME + ".out";
	freopen(finp.c_str(), "r", stdin);
	freopen(fout.c_str(), "w", stdout);
}

ll n, k, a[23], tich = 1, dem = 0, ans = 0;

void back_track(ll pos) {
	if (pos == k + 1) {
		if (dem == 0) return ;
		if (dem % 2 == 1) ans += n / tich;
		else ans -= n / tich;
		return ;
	}
	for (int i = 0; i <= 1; i++) {
		if (i == 1) {
			if (n / a[pos] >= tich) tich *= a[pos];
			else break;
		}
		dem += i;
		back_track(pos + 1);
		if (i == 1) tich /= a[pos];
		dem -= i;
	}
}

void sol() {
	cin >> n >> k;
	for (int i = 1; i <= k; i++) cin >> a[i];
	back_track(1);
	cout << ans;
}

int main() {
	fast;
	fre();
	int t = 1;
	//cin >> t;
	while (t --) sol();
}
