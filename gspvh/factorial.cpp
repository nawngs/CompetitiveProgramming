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

const string NAME = "factorial";
const string NAME2 = "TEST";
const ll ESP = 1e-9;
const ll INF = 1e18;
const ll nmax = 1e7;
const ll MOD = 1e9 + 7;
const ll base = 2309;

void fre() {
	string finp = NAME + ".inp";
	string fout = NAME + ".out";
	freopen(finp.c_str(), "r", stdin);
	freopen(fout.c_str(), "w", stdout);
}

int f[nmax + 5], n, a[1000003], prime[664585], num, x, dem;

ll cnt1[nmax + 5], cnt2[nmax + 3], tam;
 
void sang() {
	for (int i = 1; i <= nmax; i++) f[i] = i;
	for (int i = 2; i * i <= nmax; i++)
		if (f[i] == i) for (int j = i * i; j <= nmax; j += i) f[j] = i;
	for (int i = 2; i <= nmax; i++) {
		if (f[i] == i) prime[num ++] = i;
	}
}

bool check(ll r) {
	//for (int i = 0; i <= 5; i++) cout << prime[i] << " " << cnt1[i] << '\n';
	for (int i = 0; i < num; i++) {
		x = prime[i];
		tam = (1ll * x), dem = 1;
		cnt2[i] = cnt1[x];
		while (1) {
			cnt2[i] -= r / tam;
			if (r / tam < x) break; 
			tam = tam * (1ll * x);
			dem ++;
		}
		if (cnt2[i] > 0) return false;
	}
	//for (int i = 0; i < 5; i++) cout << prime[i] << " " << num[prime[i]] << " " << cnt2[i] << '\n';
	return true;
}

void sol() {
	sang();
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		cnt1[a[i]] ++;
	}
	for (int i = 1e7 - 1; i >= 1; i--) cnt1[i] += cnt1[i + 1];
	for (int i = nmax; i >= 2; i--) {
		if (cnt1[i] == 0) continue;
		//cout << i << " " << cnt1[i] << '\n';
		if (f[i] != i) {
			int x = i;
			while (x > 1) {
				cnt1[f[x]] += cnt1[i];
				x /= f[x];
			}
		}
	}
	//for (auto x : prime) cout << cnt1[num[x]]  << '\n';
	//cout << check(8) << '\n';
	ll l = 0, r = 1e13, mid, ans = -1;
	while (l <= r) {
		mid = (l + r) / 2;
		if (check(mid)) {
			ans = mid;
			r = mid - 1;
		}
		else l = mid + 1;
	}
	cout << ans;
 }

int main() {
	fast;
	//fre();
	int t = 1;
	//cin >> t;
	while (t --) sol();
}
