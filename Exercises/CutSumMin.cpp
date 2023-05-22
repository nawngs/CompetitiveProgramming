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

const string NAME = "CutSumMin";
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

ll n, a[500003], s[500003], ans = INF;

int bs1(int pos, int rr) {
	int l = pos + 1, r = rr, mid, ans = -1;
	ll val = (s[rr] - s[pos]) / 2;
	while (l <= r) {
		mid = (l + r) / 2;
		//if (rr == 114) cout << mid << '\n';
		if (s[mid] - s[pos] <= val) {
			ans = mid;
			l = mid + 1;
		}
		else r = mid - 1;
	}
	return ans;
}

int bs2(int pos, int rr) {
	int l = pos + 1, r = rr, mid, ans = -1;
	ll val = (s[rr] - s[pos]) / 2;
	while (l <= r) {
		mid = (l + r) / 2;
		if (s[mid] - s[pos] >= val) {
			ans = mid;
			r = mid - 1;
		}
		else l = mid + 1;
	}
	return ans;
}

void getans(int r1, int r2, int r3) {
	if (r1 == -1 || r3 == -1) return ;
	ll sum1 = s[r1];
	ll sum2 = s[r2] - s[r1];
	ll sum3 = s[r3] - s[r2];
	ll sum4 = s[n] - s[r3];
	ans = min(ans, max(sum1, max(sum2, max(sum3, sum4))) - min(sum1, min(sum2, min(sum3, sum4))));
	return ;
 
}


void sol() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		s[i] = s[i - 1] + a[i];
	}
	for (int i = 1; i <= n; i++) {
		int r1 = bs1(0, i);
		int r2 = bs1(i, n);
		getans(r1, i, r2);
		r2 = bs2(i, n);
		getans(r1, i, r2);
		r1 = bs2(0, i);
		getans(r1, i, r2);
		r2 = bs1(i, n);
		getans(r1, i, r2);
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
