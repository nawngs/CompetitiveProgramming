#include <bits/stdc++.h>

#define name ""
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
const int NMAX = 2e3;
const ll MOD = 1e9 + 7;
const ll BASE = 2309;

int l, w, n, m, a[NMAX + 3], b[NMAX + 3], it[2 * NMAX + 3][2 * NMAX + 3];

vector < pair < double, pii > > val1, val2;

void update_y(int x, int y, int val) {
    for(y += m, it[x][y] = max(it[x][y], val); y > 1; y >>= 1) 
        it[x][y >> 1] = max(it[x][y], it[x][y ^ 1]);   
}
void update_x(int x, int y, int val) {
    for(x += n; x > 1; x >>= 1)
        update_y(x, y, val);
}
int query_y(int x, int ly, int ry) {
    int ans = -INF;
    for(ly += m, ry += m; ly < ry; ly >>= 1, ry >>= 1) {
        if(ly & 1) ans = max(ans, it[x][ly++]);
        if(ry & 1) ans = max(ans, it[x][--ry]);
    }
    return ans;
}	
int query_x(int lx, int rx, int ly, int ry) {
    int ans = -INF;
    for(lx += n, rx += n; lx < rx; lx >>= 1, rx >>= 1) {
        if(lx & 1) ans = max(ans, query_y(lx++, ly, ry));
        if(rx & 1) ans = max(ans, query_y(--rx, ly, ry));
    }
    return ans;
}

double dis(int x, int y) {
    return hypot(w, x - y);
}

void solve1() {
    int ans = 0;
    swap(m, n);
    for (int i = 1; i <= m; i++) for (int j = i; j <= m; j++) {
        for (int i2 = 1; i2 <= n; i2++) for (int j2 = i2; j2 <= n; j2++) {
            if (a[j] - a[i] + b[j2] - b[i2] + dis(a[i], b[i2]) + dis(a[j], b[j2]) <= l) {
                ans = max(ans, j - i + 1 + j2 - i2 + 1);
            }
        }
    }
    cout << ans << '\n';
}

void sol() {
	cin >> l >> w;
	cin >> n; for (int i = 1; i <= n; i++) cin >> a[i];
	cin >> m; for (int i = 1; i <= m; i++) cin >> b[i];
	if (n + m <= 50) {
		solve1();
		return ;
	}
	for (int i = 0; i <= 2 * n; i++)
		for (int j = 0; j <= 2 * m; j++) 
			it[i][j] = -INF;
	val1.clear(); val2.clear();
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++) {
			double dis = sqrtl(1ll * (a[i] - b[j]) * 1ll * (a[i] - b[j]) + 1ll * w * w);
			val1.pb({dis + a[i] + b[j], {i, j}});
			val2.pb({dis - a[i] - b[j], {i, j}});
		}
	sort(val1.begin(), val1.end(), greater < pair < double, pii > >());
	sort(val2.begin(), val2.end());
	int cur = 0, res = 0;
	for (auto x : val1) {
		while (cur < sz(val2) && x.fi + val2[cur].fi <= l) {
			update_x(val2[cur].se.fi, val2[cur].se.se, 2 - val2[cur].se.fi - val2[cur].se.se);
			cur ++;
		}
		res = max(res, query_x(1, x.se.fi, 1, x.se.se) + x.se.fi + x.se.se);
	}
	cout << res << '\n';
}

int main() {
	fast;
	if(fopen(name".inp", "r")) {
		freopen(name".inp", "r", stdin);
		freopen(name".out", "w", stdout);
	}
	int t; cin >> t; while (t --) sol();
}
