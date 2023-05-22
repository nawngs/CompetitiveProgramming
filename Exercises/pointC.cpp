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

const string NAME = "pointC";
const string NAME2 = "TEST";
const ld EPS = 1e-9;
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

struct Point {
	ll x, y;
} A, B, C, D;

struct Vec {
	ll x, y;
};

Vec create(Point const &x, Point const &y) {
	Vec ans;
	ans.x = y.x - x.x;
	ans.y = y.y - x.y;
	return ans;
}

ll cross(Vec const &x, Vec const &y) {
	return x.x * y.y - x.y * y.x;
}

ll dot(Vec const &x, Vec const &y) {
	return x.x * y.x + x.y * y.y;
}

bool solve() {
	cin >> A.x >> A.y >> B.x >> B.y >> C.x >> C.y >> D.x >> D.y;
	ll ABxAC = cross(create(A, B), create(A, C));
	ll ABxAD = cross(create(A, B), create(A, D));
	ll CDxCA = cross(create(C, D), create(C, A));
	ll CDxCB = cross(create(C, D), create(C, B));
	if (!ABxAC || !ABxAD || !CDxCA || !CDxCB) {
		if (ABxAC == 0 && dot(create(C, A), create(C, B)) <= 0) return 1;
		if (ABxAD == 0 && dot(create(D, A), create(D, B)) <= 0) return 1;
		if (CDxCA == 0 && dot(create(A, C), create(A, D)) <= 0) return 1;
		if (CDxCB == 0 && dot(create(B, C), create(B, D)) <= 0) return 1;
		return 0;
	}
	return (ABxAC * ABxAD < 0 && CDxCA * CDxCB < 0);
}

int main() {
	fast;
	fre();
	int t;
	cin >> t;
	while (t--) cout << (solve() ? "Yes" : "No") << '\n';
}
