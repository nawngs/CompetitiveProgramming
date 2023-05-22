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
const ll MOD = 50000003;
const ll base = 2309;

void fre() {
	string finp = NAME + ".inp";
	string fout = NAME + ".out";
	freopen(finp.c_str(), "r", stdin);
	freopen(fout.c_str(), "w", stdout);
}

ll n, dem[30], giaithua[17];

void create() {
	giaithua[0] = 1;
	for (int i = 1; i <= 15; i++) giaithua[i] = giaithua[i - 1] * i;
}

ll mu(ll a, ll b, ll mod) {
	if (b == 0) return 1;
	ll x = mu(a, b / 2, mod);
	x = (x * x) % mod;
	if (b % 2 == 1) x = (x * a) % mod;
	return x;
}

void sol() {
	cin >> n;
	create();
	ll ans = 0;
	for (int i = 1; i <= n; i++) {
		memset(dem, 0, sizeof(dem));
		string s;
		ll y;
		cin >> s >> y;
		for (int j = 0; j < s.size(); j++) dem[s[j] - 'A'] ++;
		ll tam = giaithua[s.size()];
		for (int j = 0; j <= (int) 'z' - 'a'; j++) tam /= giaithua[dem[j]];
		//cout << tam << '\n';
		ans += mu(y, tam, 2000019);
		ans %= MOD;
	}
	cout << ans;
}

int main() {
	//fast;
	//fre();
	int t = 1;
	//cin >> t;
	while (t --) sol();
}
