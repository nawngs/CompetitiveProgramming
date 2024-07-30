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

const string NAME = "winterfashion";
const string NAME2 = "TEST";
const ll ESP = 1e-9;
const ll INF = 1e18;
const ll nmax = 2e5;
const ll MOD = 1e9 + 7;
const ll base = 2309;

void fre() {
	string finp = NAME + ".inp";
	string fout = NAME + ".out";
	freopen(finp.c_str(), "r", stdin);
	freopen(fout.c_str(), "w", stdout);
}

int n, k, a[200003];

int main() {
	fast;
	//fre();
	cin >> n >> k;
	int dem = 0;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		a[i] = (a[i] < 20);
		dem += a[i];
	}
	if (dem > k) {
		cout << -1 << '\n';
		return 0;
	}
	k -= dem;
	int res = 0;
	dem = 0;
	vector < pii > temp;
	temp.clear();
	for (int i = 1; i <= n; i++) {
		if (a[i] == a[i - 1]) dem += (a[i] == 0);
		else {
			res ++;
			if (dem == i - 1) {
				dem = 0;
				continue;
			}
			if (dem != 0) temp.push_back({dem, 2});
			dem = (a[i] == 0); 
		}
	}
	if (dem != 0) temp.push_back({dem, 1 - (dem == n)});
	sort(temp.begin(), temp.end(), [&](pii &x, pii &y) {
		return (x.se > y.se) || (x.se == y.se && x.fi < y.fi);
	});
	for (auto x : temp) {
		if (k >= x.fi) {
			res -= x.se;
			k -= x.fi;
		}
	}
	cout << res;
}
