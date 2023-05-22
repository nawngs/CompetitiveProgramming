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

const string NAME = "RobotGame";
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

ll n, cnt[3][100003], ans = 0;

void calc(ll x, ll y) {
	ll posx, posy;
	if (y < 1) {
		ans += 1 - y;
		posy = 1;
	}
	else if (y > 2) {
			ans += y - 2;
			posy = 2;
		}
		else posy = y;

	if (x < 1) {
		ans += 1 - x;
		posx = 1;
	}
	else if (x > n) {
			ans += x - n;
			posx = n;
		}
		else posx = x;

	cnt[posy][posx] ++;
}

void sol() {
	cin >> n;
	for (int i = 1; i <= 2 * n; i++) {
		ll x, y;
		cin >> x >> y;
		calc(x, y);
	}
	for (int i = 1; i <= n; i++) {
		if (cnt[1][i] < 1 && cnt[2][i] < 1) {
			ll tam1 = cnt[1][i] - 1;
			ll tam2 = cnt[2][i] - 1;
			ans += abs(tam1) + abs(tam2);
			cnt[1][i + 1] += tam1;
			cnt[2][i + 1] += tam2;
			continue;
		}
		if (cnt[1][i] >= 1 && cnt[2][i] >= 1) {
			ll tam1 = cnt[1][i] - 1;
			ll tam2 = cnt[2][i] - 1;
			ans += abs(tam1) + abs(tam2);
			cnt[1][i + 1] += tam1;
			cnt[2][i + 1] += tam2;
			continue;
		}
		if (cnt[1][i] >= 1 && cnt[2][i] < 1) {
			ll tam = min(cnt[1][i] - 1, 1 - cnt[2][i]);
			cnt[1][i] -= tam;
			cnt[2][i] += tam;
			ans += tam;
			ll tam1 = cnt[1][i] - 1;
			ll tam2 = cnt[2][i] - 1;
			ans += abs(tam1) + abs(tam2);
			cnt[1][i + 1] += tam1;
			cnt[2][i + 1] += tam2;
			continue;
		}
		if (cnt[1][i] < 1 && cnt[2][i] >= 1) {
			ll tam = min(cnt[2][i] - 1, 1 - cnt[1][i]);
			cnt[1][i] += tam;
			cnt[2][i] -= tam;
			ans += tam;
			ll tam1 = cnt[1][i] - 1;
			ll tam2 = cnt[2][i] - 1;
			ans += abs(tam1) + abs(tam2);
			cnt[1][i + 1] += tam1;
			cnt[2][i + 1] += tam2;
			continue;
		}
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
