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

const string NAME = "robot";
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

int n;

ll ans = INF, s[100003];

pii a[100003];

int bs1(int x) {
	int l = 1, r = n, mid, ans = 0;
	while (l <= r) {
		mid = (l + r) / 2;
		if (a[mid].se <= x) {
			ans = mid;
			l = mid + 1;
		}
		else r = mid - 1;
	}
	return ans;
}

void th1() {
	sort(a + 1, a + n + 1);
	ll j = 1, res = 0;
	stack < int > space, robot;
	for (int i = 1; i <= n; i++) {
		space.push(i);
		while (a[j].fi == i) {
			robot.push(i);
			j ++;
		}
		while (space.size() && robot.size()) {
			res += abs(space.top() - robot.top());
			space.pop();
			robot.pop();
		}
	}
	sort(a + 1, a + n + 1, [](pii &x, pii &y){
		return x.se < y.se;
	});
	for (int i = 1; i <= n; i++) s[i] = s[i - 1] + 1ll * a[i].se;
	for (int i = 1; i <= n; i++) {
		ll tam = bs1(i);
		ans = min(ans, res + tam * i - s[tam] + (s[n] - s[tam]) - i * (n - tam));
	}
}

ll bs2(ll x) {
	ll l = 1, r = n, mid, ans = 0;
	while (l <= r) {
		mid = (l + r) / 2;
		if (a[mid].fi <= x) {
			ans = mid;
			l = mid + 1;
		}
		else r = mid - 1;
	}
	return ans;
}

void th2() {
	ll j = 1, res = 0;
	stack < int > space, robot;
	for (int i = 1; i <= n; i++) {
		space.push(i);
		while (a[j].se == i) {
			robot.push(i);
			j ++;
		}
		while (space.size() && robot.size()) {
			res += abs(space.top() - robot.top());
			space.pop();
			robot.pop();
		}
	}
	sort(a + 1, a + n + 1);
	for (int i = 1; i <= n; i++) s[i] = s[i - 1] + a[i].fi;
	for (int i = 1; i <= n; i++) {
		ll tam = bs2(i);
		ans = min(ans, res + tam * i - s[tam] + (s[n] - s[tam]) - i * (n - tam));
	}
}

void sol() {
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i].fi >> a[i].se;
	th1();
	th2();
	cout << ans;
}

int main() {
	fast;
	fre();
	int t = 1;
	//cin >> t;
	while (t --) sol();
}
