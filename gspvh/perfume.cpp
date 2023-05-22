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

const string NAME = "perfume";
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

int w, h, b, dp[1003];

struct House {
	int x1, y1, x2, y2;
} a[1003];

bool minimize(int &x, int y) {
	if (x > y) {
		x = y;
		return true;
	}
	return false;
}

bool intersect(int l1, int r1, int l2, int r2) {
    if (l1 > l2) swap(l1, l2), swap(r1, r2);
    return l2 <= r1;
}

int calc(House x, House y) {
    //inter cot
    if (intersect(x.x1, x.x2, y.x1, y.x2)) {
        if (x.y1 > y.y1) swap(x, y);
        return (y.y1 - x.y2 - 1);
    }
    if (intersect(x.y1, x.y2, y.y1, y.y2)) {
        if (x.x1 > y.x1) swap(x, y);
        return (y.x1 - x.x2 - 1);
    }
    if (x.x1 > y.x1) swap(x, y);
    if (x.y1 > y.y1) {
        return max(x.y1 - y.y2 - 1, y.x1 - x.x2 - 1);
    } else {
        return max(y.y1 - x.y2 - 1, y.x1 - x.x2 - 1);
    }
}

void dijkstra() {
	priority_queue < pii, vector < pii >, greater < pii > > heap;
	for (int i = 1; i <= b; i++) {
		dp[i] = a[i].x1;
		heap.push({dp[i], i});
	}
	while (heap.size()) {
		auto u = heap.top(); heap.pop();
		if (u.fi != dp[u.se]) continue;
		for (int i = 1; i <= b; i++) {
			if (i == u.se) continue;
			int temp = calc(a[u.se], a[i]);
			if (minimize(dp[i], u.fi + temp))
				heap.push({dp[i], i});
		}
	}
	int res = w;
	for (int i = 1; i <= b; i++) {
		res = min(res, dp[i] + w - 1 - a[i].x2);
	}
	cout << res << '\n';
}

int main() {
	fast;
	//fre();
	cin >> w >> h >> b;
	for (int i = 1; i <= b; i++) 
		cin >> a[i].x1 >> a[i].y1 >> a[i].x2 >> a[i].y2;
	dijkstra();
	for (int i = 1; i)
}
	