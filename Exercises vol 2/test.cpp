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

const string NAME = "taoso";
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

ll n, k, a[15], val[15], cnt[15];

vector < ll > res;

void change (int pos) {
	ll new_val = pos;
	ll tam = res[++cnt[pos]];
	while (tam > 0) {
		new_val *= 10;
		tam /= 10;
	}
	new_val += res[cnt[pos]];
	val[pos] = new_val;
}

void sol() {
	cin >> k >> n;
	memset(cnt, 255, sizeof(cnt));
	fill(val + 1, val + 11, INF);
	for (int i = 1; i <= k; i++) {
		cin >> a[i];
		val[a[i]] = a[i];
	}
	while (n --) {
		ll tam, gt = INF;
		for (int i = 1; i <= 9; i++) 
			if (gt > val[i]) {
				tam = i;
				gt = val[i];
			}
		//cout << gt << '\n';
		res.push_back(gt);
		change(tam);
	}
	cout << res.back();
}

int main() {
	fast;
	fre();
	int t = 1;
	//cin >> t;
	while (t --) sol();
}
