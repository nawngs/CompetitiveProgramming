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
const int N = 1e6;
const ll MOD = 1e9 + 7;
const ll BASE = 2309;

struct Data {
	ll x, y, a;
	bool operator < (const Data &oth) {
		return x < oth.x;
	}	
} a[N + 3];

int n;

ll dp[N + 3];

struct Pt {
	ll x, y;
	Pt(ll x = 0, ll y = 0) : x(x), y(y) {}
	Pt& operator -= (const Pt &oth) {
		x -= oth.x; y -= oth.y;
		return *this;
	}
	Pt operator - (const Pt &oth) const {
		return Pt(*this) -= oth;
	}
};

ll cross(const Pt &a, const Pt &b) {
	return a.x * b.y - a.y * b.x;
}

ll orient(const Pt &a, const Pt &b, const Pt &c) {
	return cross(b - a, c - a);
}

double slope(int i, int j) {
	return (double)(dp[i] - dp[j]) / (a[i].x - a[j].x);
}

int main() {
	fast;
	if(fopen(name".inp", "r")) {
		freopen(name".inp", "r", stdin);
		freopen(name".out", "w", stdout);
	}
	//int t; cin >> t; while (t --) sol();
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i].x >> a[i].y >> a[i].a;
	sort(a + 1, a + n + 1);
	deque < ll > dq;
	dq.push_front(0);
	for (int i = 1; i <= n; i++) {
		while (dq.size() > 1 && slope(dq[dq.size() - 2], dq.back()) >= a[i].y) dq.pop_back();
		ll j = dq.back();
		dp[i] = max(dp[i - 1], a[i].x * a[i].y - a[i].a + dp[j] - a[j].x * a[i].y);
		while (dq.size() > 1 && slope(dq[0], i) >= slope(dq[0], dq[1])) dq.pop_front();
		dq.push_front(i);
	}
	cout << dp[n];
}