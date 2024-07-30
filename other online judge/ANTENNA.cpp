#include <bits/stdc++.h>

#define name ""
#define ll long long
#define ld long double
#define fi first 
#define se second
#define pll pair < ll, ll >
#define pii pair < int, int >
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define SZE(x) ((int)(x).size())
#define pb push_back
#define mp make_pair
#define lnode node * 2, l, (l + r) / 2
#define rnode node * 2 + 1, (l + r) / 2 + 1, r

using namespace std;

const ld EPS = 1e-9;
const int INF = 1e9 + 7;
const ll LINF = 1E18;
const int N = 500;
const ll MOD = 1e9 + 7;
const ll BASE = 50;
const ld pi = acos(-1);

int n, k;

struct Pt {
	ld x, y;
	Pt(ld x = 0, ld y = 0) : x(x), y(y) {}
	Pt& operator -= (const Pt &oth) {
		x -= oth.x, y -= oth.y;
		return (*this);
	}
	Pt operator - (const Pt &oth) const {
		return Pt(*this) -= oth;
	}
} a[N + 3], res;

vector < pair < ld, int > > events;

ld abs(const Pt &x) {
	return sqrtl(x.x * x.x + x.y * x.y);
}

bool check(ld R) {
	for (int i = 1; i <= n; i++) {
		events.clear();
		for (int j = 1; j <= n; j++) if (j != i) {
			Pt ij = a[j] - a[i];
			if (abs(ij) > 2 * R) continue;
			ld A = atan2(ij.y, ij.x);
			ld B = acos(abs(ij) / (2 * R));
			// cout << i << " " << j << " " << A << " " << B << '\n';
			events.pb({A - B, 1});
			events.pb({A + B, -1});
			// events.pb({A - B + 2 * pi, 1});
			// events.pb({A + B + 2 * pi, -1});
		}
		sort(events.begin(), events.end());
		int cnt = 1;
		for (auto x : events) {
			cnt += x.se;
			if (cnt >= k) return true;
		}
	}
	return false;
}

void find(ld R) {
	for (int i = 1; i <= n; i++) {
		events.clear();
		for (int j = 1; j <= n; j++) if (j != i) {
			Pt ij = a[j] - a[i];
			if (abs(ij) > 2 * R) continue;
			ld A = atan2(ij.y, ij.x);
			ld B = acos(abs(ij) / (2 * R));
			events.pb({A - B, 1});
			events.pb({A + B, -1});
		}
		sort(events.begin(), events.end());
		int cnt = 1;
		for (auto x : events) {
			cnt += x.se;
			if (cnt >= k) {
				res = {a[i].x + cos(x.fi) * R, a[i].y + sin(x.fi) * R};
				return ;
			}
		}
	}
}

bool ktra(ld R) {
	int cnt = 0;
	for (int i = 1; i <= n; i++) 
		if (abs(a[i] - res) - R <= EPS) cnt ++;
	return cnt >= k;
}

int main() {
	fast;
	if(fopen(name".inp", "r")) {
		freopen(name".inp", "r", stdin);
		freopen(name".out", "w", stdout);
	}
	//int t; cin >> t; while (t --) sol();
	cin >> n >> k;
	cout << fixed << setprecision(9);
	for (int i = 1; i <= n; i++) 
		cin >> a[i].x >> a[i].y;
	ld l = 0, r = INF, mid, ans;
	for (int i = 0; i <= BASE; i++) {
		mid = (l + r) / 2;
		if (check(mid)) {
			ans = mid;
			r = mid - EPS;
		}
		else l = mid + EPS;
	}
	cout << ans << '\n';
	find(ans);
	assert(ktra(ans));
	cout << res.x << " " << res.y << '\n';
	
}