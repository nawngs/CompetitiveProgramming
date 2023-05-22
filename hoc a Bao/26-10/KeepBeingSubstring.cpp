#pragma GCC optimize ("O2")
#include <bits/stdc++.h>

#define int ll
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
const ll MOD2 = 1e9 + 9;
const ll base = 1e6 + 19;

void fre() {
	string finp = NAME2 + ".inp";
	string fout = NAME + ".out";
	freopen(finp.c_str(), "r", stdin);
	//freopen(fout.c_str(), "w", stdout);
}

ll n, a[200003], p, x[200003], y[200003], q, dem[200003], dis_x[200003], dis_y[200003];

pll hash_x[200003], hash_y[200003], pow_base[200003], hash_a[200003];

map < pii, bool > f;

pii get_hash(long long l, long long r, pll hasha[]) {
	pll res;
	res.fi = (hasha[r].fi - hasha[l - 1].fi * pow_base[r - l + 1].fi + MOD * MOD) % MOD;
	res.se = (hasha[r].se - hasha[l - 1].se * pow_base[r - l + 1].se + MOD2 * MOD2) % MOD2;
	return res;
}

bool check(int len) {
	f.clear();
	for (int i = 1; i <= p - len + 1; i++) 
		f[get_hash(i, i + len - 1, hash_x)] = 1;
	for (int i = 1; i <= q - len + 1; i++)
		if (f[get_hash(i, i + len - 1, hash_y)]) 
			return true;
	return false;
	
}

main() {
	fast;
	fre();
	cin >> n;
	pow_base[0] = {1, 1};
	for(int i = 1; i <= n; i++) {
		pow_base[i].fi = (pow_base[i - 1].fi * base) % MOD;
		pow_base[i].se = (pow_base[i - 1].se * base) % MOD2;
	}
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	cin >> p;
	for (int i = 1; i <= p; i++) {
		cin >> x[i];
		hash_x[i].fi = (hash_x[i - 1].fi * base + x[i]) % MOD;
		hash_x[i].se = (hash_x[i - 1].se * base + x[i]) % MOD2;
	}
	cin >> q;
	for (int i = 1; i <= q; i++) {
		cin >> y[i];
		hash_y[i].fi = (hash_y[i - 1].fi * base + y[i]) % MOD;
		hash_y[i].se = (hash_y[i - 1].se * base + y[i]) % MOD2;
	}
	int l = 1, r = min(p, q), mid, ans = 0;
	while (l <= r) {
		mid = (l + r) / 2;
		if (check(mid)) {
			ans = mid;
			l = mid + 1;
		}
		else r = mid - 1;
	}
	if (ans == 0) {
		
	}
	cout << p + q - 2 * ans;
}
