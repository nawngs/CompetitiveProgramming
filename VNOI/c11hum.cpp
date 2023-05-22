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

 ll n, k, val[1003], cnt[1003];

void sol() {
	cin >> k >> n;
	memset(cnt, 255, sizeof(cnt));
	fill(val + 1, val + 1001, INF);
	for (int i = 1; i <= k; i++) {
		ll x;
		cin >> x;
		val[x] = x;
	}
	vector < ll > res;
	res.clear();
	while (n --) {
		ll tam, gt = INF;
		for (int i = 2; i <= 1000; i++) {
			if (val[i] < gt) {
				gt = val[i];
				tam = i;
			}
		}
		res.push_back(gt);
		for (int i = 2; i <= 1000; i++) {
			if (val[i] == gt) val[i] = i * res[++ cnt[i]];
		}
	}
	cout << res.back();
}

int main() {
	//fast;
	//fre();
	int t = 1;
	//cin >> t;
	while (t --) sol();
}
