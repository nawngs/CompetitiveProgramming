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

const string NAME = "ArrDK";
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

ll n, k;

vector < ll > a;

void sol() {
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		ll x;
		cin >> x;
		x = (k - (x % k)) % k;
		if (x) a.push_back(x);
	}
	if (!a.size()) {
		cout << 0 << '\n';
		return ;
	}
	sort(a.begin(), a.end());
	int dem = 1;
	ll ans = 0;
	for (int i = 1; i < a.size(); i++) {
		if (a[i] == a[i - 1]) dem ++;
		else {
			if (dem == 1) ans = max(ans, a[a.size() - 1]);
			else {
				ans = max(ans, (dem - 1) * k + a[i - 1]);
				dem = 1;
			}
		}
	}
	if (dem == 1) ans = max(ans, a[a.size() - 1]);
	else {
		ans = max(ans, (dem - 1) * k + a[a.size() - 1]);
		dem = 1;
	}
	cout << ans + 1 << '\n';

}

int main() {
	fast;
	fre();
	int t = 1;
	//cin >> t;
	while (t --) sol();
}
