#include <bits/stdc++.h>

#define name "race"
#define test "test"
#define ll long long
#define ld long double
#define fi first 
#define se second
#define pll pair < ll, ll >
#define pii pair < int, int >
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define sz(x) ((int)(x).size())
#define pb push_back
#define mp make_pair

using namespace std;

const ld EPS = 1e-9;
const int INF = 1e9 + 7;
const ll LINF = 1E18;
const int NMAX = 2e5;
const ll MOD = 1e9 + 7;
const ll BASE = 2309;

ll n, x;

ll calc(ll l, ll r) {
	return (l + r) * (r - l + 1) / 2;
}

bool check(ll cur, ll target, ll len) { // from cur speed slow down to target speed in len
	if (cur <= target) return true;
	ll need = calc(target, cur - 1);
	return (need <= len);
}

void sol() {
	cin >> x;
	ll res = 0, rem = n, speed = 0;
	while (rem > 0) {
		if (check(speed + 1, x, rem - speed - 1)) speed ++;
		else if (!check(speed, x, rem - speed)) speed --;
		rem -= speed; res ++;
	}
	cout << res << '\n';
}

int main() {
	fast;
	if(fopen(name".in", "r")) {
		freopen(name".in", "r", stdin);
		freopen(name".out", "w", stdout);
	}
	cin >> n;
	int t; cin >> t; while (t --) sol();
}