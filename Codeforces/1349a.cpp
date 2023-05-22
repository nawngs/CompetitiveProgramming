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

int n, f[nmax + 3];

vector < int > cnt[nmax + 3], prime;

void sang() {
	for (int i = 1; i <= nmax; i++) f[i] = i;
	for (int i = 2; i * i <= nmax; i++) {
		if (f[i] == i) for (int j = i * 2; j <= nmax; j+= i) f[j] = i;
		
	}
}

ll mu(ll a, ll b) {
	if (b == 0) return 1;
	ll x = mu(a, b / 2);
	x *= x;
	if (b % 2 == 1) x *= a;
	return x;
}

void sol() {
	sang();
	cin >> n;
	for (int i = 1; i <= n; i++) {
		int x;
		cin >> x;
		int dem = 0, pre = 0;
		while (x > 1) {
			if (f[x] == pre) dem ++;
			else {
				cnt[pre].push_back(dem);
				dem = 1;
			}
			pre = f[x];
			x /= f[x];
		}
		cnt[pre].push_back(dem);
	}
	ll ans = 1;
	for (int x = 2; x <= nmax; x++) {
		if (cnt[x].size() <= n - 2) continue;
		sort(cnt[x].begin(), cnt[x].end());
		if (cnt[x].size() == n - 1) ans *= mu(x, cnt[x][0]);
		else ans *= mu(x, cnt[x][1]);
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
