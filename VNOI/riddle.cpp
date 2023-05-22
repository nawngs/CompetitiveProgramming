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

int n, k, a[100003];

vector < int > tam;

bool check(int pos) {
	tam.clear();
	ll s = 0;
	for (int i = 1; i <= pos; i++) {
		tam.push_back(a[i]);
		s += 1ll * a[i];
	}
	if (s < k) return false;
	s = 0;
	sort(tam.begin(), tam.end());
	for (auto x : tam) {
		if (x > s + 1) return false;
		s += x;
	}
	return true;
}

void sol() {
	cin >> n >> k;
	for (int i = 1; i <= n; i++) cin >> a[i];
	int l = 1, r = n, mid, ans = -1;
	while (l <= r) {
		mid = (l + r) / 2;
		if (check(mid)) {
			ans = mid;
			r = mid - 1;
		}
		else l = mid + 1;
	} 
	cout << ans << '\n';
}

int main() {
	fast;
	//fre();
	int t = 1;
	cin >> t;
	while (t --) sol();
}
