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

const string NAME = "xgcd";
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

int n, a[100003], st[100003][20];

map < int, ll > f;

int getgcd(int l, int r) {
	int t = log2(r - l + 1);
	return  __gcd(st[l][t], st[r - (1 << t) + 1][t]);
}

int bs(int posl, int val) {
	int l = posl, r = n, mid, ans = n + 1;
	while (l <= r) {
		mid = (l + r) / 2;
		if (getgcd(posl, mid) < val) {
			ans = mid;
			r = mid - 1;
		}
		else l = mid + 1;
	}
	return ans;
}

void sol() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		st[i][0] = a[i];
	}
	for (int t = 1; t <= 17; t++) {
		for (int i = 1; i <= n; i++) {
			if (i + (1 << t) - 1 > n) break;
			st[i][t] = __gcd(st[i][t - 1], st[i + (1 << (t - 1))][t - 1]);
		}
	}
	for (int i = 1; i <= n; i++) {
		int r = i;
		int gcd_i = a[i];
		while (r <= n) {
			int tam = bs(i, gcd_i);
			//cout << i << " " << gcd_i << " " << tam << " " << r << '\n';
			f[gcd_i] += 1ll * (tam - r);
			r = tam;
			gcd_i = getgcd(i, r);
		}
	}
	int q;
	cin >> q;
	while (q --) {
		int x;
		cin >> x;
		cout << f[x] << '\n';
	}
}

int main() {
	fast;
	fre();
	int t = 1;
	//cin >> t;
	while (t --) sol();
}
