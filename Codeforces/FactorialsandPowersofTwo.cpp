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
const ll nmax = 1e12;
const ll MOD = 1e9 + 7;
const ll base = 2309;

void fre() {
	string finp = NAME + ".inp";
	string fout = NAME + ".out";
	freopen(finp.c_str(), "r", stdin);
	freopen(fout.c_str(), "w", stdout);
}

ll n, sum = 0, dem = 0;

vector < ll > mu, factor;

vector < pll > val;

void back_track(int pos) {
	if (pos == factor.size()) {
		val.push_back({sum, dem});
		return ;
	}
	for (int i = 0; i < 2; i++) {
		if (i == 1) sum += factor[pos];
		dem += i;
		back_track(pos + 1);
		if (i == 1) sum -= factor[pos];
		dem -= i;
	}
}

void create() {
	mu.push_back(1);
	factor.push_back(1);
	while (mu.back() < nmax) mu.push_back(mu.back() * 2);
	ll i = 1;
	while (factor.back() < nmax) factor.push_back(factor.back() * (++ i));
	back_track(0);
}

ll calc(ll x) {
	ll dem = 0;
	for (int i = mu.size() - 1; i >= 0; i--) {
		if (x >= mu[i]) {
			x -= mu[i];
			dem ++;
		}
	}
	return dem;
}

void sol() {
	cin >> n;
	ll ans = INF;
	for (auto x : val) if (n >= x.fi) ans = min(ans, x.se + calc(n - x.fi));
	cout << ans << '\n';
}

int main() {
	fast;
	//fre();
	create();
	int t = 1;
	cin >> t;
	while (t --) sol();
}
