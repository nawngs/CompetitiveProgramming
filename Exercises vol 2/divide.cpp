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

const string NAME = "divide";
const string NAME2 = "TEST";
const ll ESP = 1e-9;
const ll INF = 1e18;
const ll nmax = 1e7;
const ll MOD = 1e9 + 7;

void fre() {
	string finp = NAME + ".inp";
	string fout = NAME + ".out";
	freopen(finp.c_str(), "r", stdin);
	freopen(fout.c_str(), "w", stdout);
}

ll n, s[100005];

vector < ll > prime;

ll bs(ll val) {
	ll l = 0, r = n, mid;
	while (l <= r) {
		mid = (l + r) / 2;
		if (s[mid] == val) return mid;
		if (s[mid] > val) r = mid - 1;
		else l = mid + 1;
	}
	return -1;
}

void sol() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		ll x;
		cin >> x;
		s[i] = s[i - 1] + x;
	}
	for (int i = n; i >= 1; i--) if (s[n] % i == 0) prime.push_back(i);
	ll ans = 1;	
	for (auto x : prime) {
		ll tam = s[n] / x;
		ll temp = tam;
		bool th = 1;
		while (tam <= s[n]) {
			if (bs(tam) == -1) {
				th = false;
				break;
			}
			tam += temp;
		}
		if (th) {
			ans = x;
			break;
		}
	}
	cout << ans << '\n';
	cout << 1 << ' ';
	ll tam = s[n] / ans;
	ll temp = tam;
	while (tam < s[n]) {
		cout << bs(tam) + 1 << ' ';
		tam += temp;
	}
}

int main() {
	fast;
	//fre();
	int t = 1;
	//cin >> t;
	while (t --) sol();
}
