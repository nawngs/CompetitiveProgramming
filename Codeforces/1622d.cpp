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

const string NAME = "";
const string NAME2 = "TEST";
const ll ESP = 1e-9;
const ll INF = 1e18;
const ll nmax = 1e7;
const ll MOD = 998244353;

void fre() {
	string finp = NAME2 + ".inp";
	string fout = NAME2 + ".out";
	freopen(finp.c_str(), "r", stdin);
	freopen(fout.c_str(), "w", stdout);
}

ll n, k, giaithua[5005];

string s;

vector < int > pos;

void create() {
	giaithua[0] = 1;
	for (int i = 1; i <= 5000; i++) giaithua[i] = (giaithua[i - 1] * i) % MOD;
}

ll mu(ll a, ll b) {
	if (b == 0) return 1;
	ll x = mu(a, b / 2);
	x = (x * x) % MOD;
	if (b % 2 == 1) x = (x * a) % MOD;
	return x;
}

ll calc(ll k, ll n) {
	ll tam = (giaithua[n - k] * giaithua[k]) % MOD;
	return ((giaithua[n] % MOD) * mu(tam, MOD - 2) + MOD * MOD) % MOD;
}

void sol() {
	create();
	cin >> n >> k;
	cin >> s;
	s = ' ' + s;
	pos.push_back(0);
	for (int i = 1; i <= n; i++) {
		if (s[i] == '1') {
			pos.push_back(i);
		}
	}
	pos.push_back(n + 1);
	if (pos.size() - 2 < k || k == 0) {
		cout << 1 << '\n';
		return ;
	}
	ll ans = 0;
	for (int i = k + 1; i < pos.size(); i++) {
		if (i == k + 1) ans = (ans + calc(k, pos[i] - pos[i - k - 1] - 1)) % MOD;
		else {
			ans = ((ans - calc(k - 1, pos[i - 1] - 1 - pos[i - k - 1])) % MOD + MOD) % MOD;
			ans = (ans + calc(k, pos[i] - pos[i - k - 1] - 1)) % MOD;  
		}
		//cout << ans << '\n';
	}
	cout << ans;
}

int main() {
	fast;
	fre();
	int t = 1;
	//cin >> t;
	while (t --) sol();
}
