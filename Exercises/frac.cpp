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

const string NAME = "frac";
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

ll a, b;

ll s, t;

vector < ll > res;

vector < int > digit;

unordered_set < ll > st;

void create(ll a, ll b) {
	st.clear();
	digit.clear();
	res.clear();
	while (res.size() <= t) {
		a *= 10;
		res.push_back(a);
		digit.push_back(a / b);
		if (st.count(a)) break;
		st.insert(a);
		a %= b;
	}
}

ll calc(ll x) {
	if (x == 0 || x == -1) return 0;
	ll ans = 0;
	int pos;
	if (res.size() >= x) {
		for (int i = 0; i < res.size(); i++) {
			ans = (ans + 1ll * digit[i]) % b;
			x --;
			if (x == 0) return ans;
		}
	}
	for (int i = 0; i < res.size(); i++) {
		pos = i;
		if (res[i] == res.back()) break;
		ans = (ans + 1ll * digit[i]) % b;
		x --;
		if (x == 0) return ans;
	}
	ll tam = 0;
	for (int i = pos; i < res.size() - 1; i++) tam =(tam + 1ll * digit[i]) % b;
	ans =  (ans + tam * (x / (res.size() - 1 - pos))) % b;
	x %= (res.size() - 1 - pos);
	for (int i = pos; i < pos + x; i++) ans = (ans + 1ll * digit[i]) % b;
	return ans;
}

ll mu(ll a, ll b, ll k) {
	if (b == 0) return 1;
	ll x = mu(a, b / 2, k);
	x = (x * x) % k;
	if (b % 2 == 1) x = (x * a) % k;
	return x;
}

void sub4() {
	a *= mu(10, s - 1, b);
	a %= b;
	a *= 10;
	a/= b;
	cout << a % 10 << '\n';
}

void sol() {
	cin >> a >> b >> s >> t;
	a %= b;
	if (s == t) {
		sub4();
		return ;
	}
	create(a, b);
	cout << (calc(t) - calc(s - 1) + b) % b << '\n';
}

int main() {
	fast;
	fre();
	int t = 1;
	cin >> t;
	while (t --) sol();
}
