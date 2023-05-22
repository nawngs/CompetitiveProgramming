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

const string NAME = "banhda";
const string NAME2 = "TEST";
const ld ESP = 1e-9;
const ll INF = 1e9 + 7;
const ll LINF = 1E18;
const ll nmax = 2e5;
const ll MOD = 1e9 + 7;
const ll base = 2309;

void fre() {
	string finp = NAME + ".inp";
	string fout = NAME + ".out";
	freopen(finp.c_str(), "r", stdin);
	freopen(fout.c_str(), "w", stdout);
}

ll L, R;

bool th;

ll get(ll l, ll r) {
	return (r + l) * (r - l + 1) / 2;
}

void printans(ll const &x, ll const &y, ll const &z) {
	cout << x << " ";
	if (!th) cout << y << " " << z << '\n';
	else cout << z << " " << y << '\n';
}

ll get_right(ll l, ll r) {
	if (r < l) return 0;
	r -= ((r - l) % 2);
	//cout << l << " " << r << ' ' << ((r + l) * ((r - l) / 2 + 1)) / 2 << '\n';
	return ((r + l) * ((r - l) / 2 + 1)) / 2;
}

void sol() {
	cin >> L >> R;
	th = false;
	if (R > L) {
		swap(L, R);
		th = !th;
	}
	ll l = 0, r = 1e9 + 7, mid, ans;
	while (l <= r) {
		mid = (l + r) / 2;
		if (L - get(0, mid) <= R) {
			ans = mid;
			r = mid - 1;
		}
		else l = mid + 1;
	}
	if (L - get(0, ans) < 0) {
		printans(ans - 1, L - get(0, ans - 1), R);
		return ;
	}
	if (L - get(0, ans) == 0) {
		printans(ans, L - get(0, ans), R);
		return ;
	}
	L -= get(0, ans);
	if (L == R) th = 0;
	if (R > L) {
		swap(L, R);
		th = !th;
	}
	int tam = ans + 2;
	l = tam; r = 2e9;
	ans = tam - 1;
	while (l <= r) {
		mid = (l + r) / 2;
		if (R - get_right(tam, mid) >= 0) {
			ans = mid;
			l = mid + 1;
		}
		else r = mid - 1;
	}
	if (ans == tam - 1) {
		l = ans;
		while (L >= l) {
			L -= l;
			l++;
		}
		printans(l - 1, L, R);
	}
	else {
		ans --;
		//cout << R << " " << tam << " " << ans << " " << R - get_right(tam, ans) << '\n';
		R -= get_right(tam, ans);
		L -= get_right(tam - 1, ans - 1);
		//cout << L << " " << R << '\n';
		l = ans + 1;
		while (L >= l) {
			L -= l;
			l++;
		}
		printans(l - 1, L, R);
	}
}	

int main() {
	fast;
	fre();
	int t = 1;
	cin >> t;
	while (t --) sol();
}