#pragma GCC optimize ("O3")
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
const ll nmax = 1e7;
const ll MOD = 1e9 + 7;

void fre() {
	string finp = NAME + ".inp";
	string fout = NAME + ".out";
	freopen(finp.c_str(), "r", stdin);
	freopen(fout.c_str(), "w", stdout);
}

int n, dem = 0;

ll x, a[40], sum = 0, ans = 0;d

vector < ll > cnt[19];

vector < pll > tmp;

void backtrack(int pos, int r) {
	if (pos == r + 1) {
		if (r == n) tmp.push_back({sum, dem});
		else cnt[dem].push_back(sum);
		return ;
	}
	for (int i = 0; i <= 1; i++) {
		if (i == 1) {
			sum += a[pos];
			dem ++;
		}
		backtrack(pos + 1, r);
		if (i == 1) {
			sum -= a[pos];
			dem --;
		}
	}
}

int bs1(ll val, vector < ll > a) {
	ll l = 0, r = a.size() - 1, mid, ans = -1;
	while (l <= r) {
		mid = (l + r) / 2;
		if (a[mid] <= val) {
			ans = mid;
			l = mid + 1;
		}
		else r = mid - 1;
	}
	return ans;
} //tim gtln be hon

int bs2(ll val, vector < ll > a) {
	ll l = 0, r = a.size() - 1, mid, ans = -1;
	while (l <= r) {
		mid = (l + r) / 2;
		if (a[mid] >= val) {
			ans = mid;
			r = mid - 1;
		}
		else l = mid + 1;
	}
	return ans;
} //tim gtnn lon hon


void sol() {
	cin >> n >> x;
	for (int i = 1; i <= n; i++) cin >> a[i];
	backtrack(1, n / 2);
	backtrack(n / 2 + 1, n);
	for (int i = 0; i <= 18; i++) sort(cnt[i].begin(), cnt[i].end());
	for (auto p : tmp) {
		ll tam = x * p.se - p.fi;
		for (int i = 0; i <= 18; i++) {
			int r = bs1(tam, cnt[i]);
			int l = bs2(tam, cnt[i]);
			if (l <= r && l != -1 && cnt[i][l] == tam && r != -1 && cnt[i][r] == tam) ans += r - l + 1;
			tam += x;
		} 
	}
	cout << ans - 1 << '\n';
}

int main() {
	fast;
	//fre();
	int t = 1;
	//cin >> t;
	while (t --) sol();
}
