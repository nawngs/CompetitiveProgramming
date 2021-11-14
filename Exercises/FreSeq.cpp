#pragma GCC optimize ("O3")
#include <bits/stdc++.h>

#define ll long long
#define ld long double
#define fi first 
#define se second
#define pll pair < ll, ll >
#define pii pair < int, int >
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

using namespace std;

const string NAME = "FreSeq";
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

int n, a[100005], q, it[800005][15], start[100005], endq[100005], it2[800005];

int x, y;

pll p[100005];

void roi_rac() {
	for (int i = 1; i <= n; i++) p[i] = {a[i], i};
	sort(p + 1, p + n + 1);
	p[0].fi = INF;
	int dem = 0;
	for (int i = 1; i <= n; i++) {
		dem += (p[i].fi != p[i - 1].fi);
		a[p[i].se] = dem;
	}
}

//####################################################################### 

void sol1() {
	while (q --) {
		cin >> x >> y;
		int dem[1005], ans = 0;
		memset(dem, 0, sizeof(dem));
		for (int i = x; i <= y; i++) {
			dem[a[i]] ++;
			ans = max(ans, dem[a[i]]);
		}
		cout << ans << '\n';
	}
}

//#######################################################################

void update(int node, int l, int r, int pos, int lev) {
	if (pos < l || pos > r) return ;
	it[node][lev] ++;
	if (l == r) return ;
	int mid = (l + r) / 2;
	update(node * 2, l, mid, pos, lev);
	update(node * 2 + 1, mid + 1, r, pos, lev);
}

int query(int node, int l, int r, int u, int v, int lev) {
	if (r < u || v < l) return 0;
	if (u <= l && r <= v) return it[node][lev];
	int mid = (l + r) / 2;
	return query(node * 2, l, mid, u, v, lev) + query(node * 2 + 1, mid + 1, r, u, v, lev);
}

void sol2() {
	for (int i = 1; i <= n; i++) update(1, 1, n, i, a[i]);
	while (q --) {
		cin >> x >> y;
		int ans = 0;
		for (int i = 0; i <= 12; i++) ans = max(ans, query(1, 1, n, x, y, i));
		cout << ans << '\n';
	}
}

//#######################################################################

void update2(int node, int l, int r, int pos, int val) {
	if (pos < l || pos > r) return ;
	if (l == r) {
		it2[node] = val;
		return ;
	}
	int mid = (l + r) / 2;
	update2(node * 2, l, mid, pos, val);
	update2(node * 2 + 1, mid + 1, r, pos, val);
	it2[node] = max(it2[node * 2], it2[node * 2 + 1]);
}

int query2(int node, int l, int r, int u, int v) {
	if (r < u || v < l) return 0;
	if (u <= l && r <= v) return it2[node];
	int mid = (l + r) / 2;
	return max(query2(node * 2, l, mid, u, v), query2(node * 2 + 1, mid + 1, r, u, v));
}

void sol3() {
	start[a[1]] = 1;
	a[n + 1] = 0;
	for (int i = 1; i <= n + 1; i++) {
		if (a[i] != a[i - 1]) {
			endq[a[i - 1]] = i - 1;
			update2(1, 1, n, a[i - 1], endq[a[i - 1]] - start[a[i - 1]] + 1); 
			start[a[i]] = i;
		}
	}
	while (q --) {
		cin >> x >> y;
		if (a[x] == a[y]) {
			cout << y - x + 1 << '\n';
			continue;
		}
		int res = max(endq[a[x]] - x + 1, y - start[a[y]] + 1);
		if (a[x] + 1 <= a[y] - 1) res = max(res, query2(1, 1, n, a[x] + 1, a[y] - 1));
		cout << res << '\n';
	}
}

//#######################################################################

void sol() {
	cin >> n >> q;
	for (int i = 1; i <= n; i++) cin >> a[i];
	roi_rac();
	if (n <= 1000 && q <= 1000) {
		sol1();
		return ;
	}
	if (a[n] <= 11) {
		sol2();
		return ;
	}
	sol3();
}

int main() {
	fast;
	fre();
	int t = 1;
	//cin >> t;
	while (t --) sol();
}


/*
#include <bits/stdc++.h>
#include <algorithm>
using namespace std;
#define FOR(i, a, b) for(int i = a; i <= b; ++i)
#define FOD(i, a, b) for(int i = a; i >= b; --i)
#define fi first
#define se second
#define pb push_back
#define eb emplace_back
#define ll long long
#define ld long double
#define nmax 100007
void faster()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

int n, q;
int a[nmax];
pair < int , int > b[nmax];

void pre1()
{
    FOR(i, 1, n) b[i] = {a[i] , i};
    sort(b + 1, b + 1 + n);
}

void solve1()
{
    while(q--)
    {
        int x, y;
        cin >> x >> y;
        int ans = 0;
        FOR(i, 1, n)
        {
            int jp = i;
            int dem = (b[i].se >= x) * (b[i].se <= y);
            FOR(j, i + 1, n)
            {
                if(b[j].fi != b[i].fi) break;
                jp = j;
                dem += (b[j].se >= x) * (b[j].se <= y);
            }
            ans = max(ans, dem);
            i = jp;
        }
        cout << ans << '\n';
    }
}

int seg[11][nmax * 4 + 40];

void update(int l, int r, int node, int pos, int type)
{
    if(r < pos || pos < l) return;
    if(l == r)
    {
        seg[type][node]++;
        return;
    }
    int mid = (l + r)/2;
    update(l, mid, node * 2, pos, type);
    update(mid + 1, r, node * 2 + 1, pos, type);
    seg[type][node] = seg[type][node * 2] + seg[type][node * 2 + 1];
}

int get(int u, int v, int l, int r, int node, int type)
{
    if(v < l || r < u) return 0;
    if(u <= l && r <= v) return seg[type][node];
    int mid = (l + r)/2;
    return get(u, v, l, mid, node * 2, type) + get(u, v, mid + 1, r, node * 2 + 1, type);
}

void pre2()
{
    FOR(i, 1, n)
        update(1, n, 1, i, a[i]);
}

void solve2()
{
    while(q--)
    {
        int x, y;
        cin >> x >> y;
        int ans = 0;
        FOR(i, 0, 10) ans = max(ans, get(x, y, 1, n, 1, i));
        cout << ans << '\n';
    }
}

int p[nmax][20];

int id = 0;

void pre3()
{
    FOR(i, 1, n)
    {
        int jp = i;
        FOR(j, i + 1, n)
        {
            if(a[j] != a[i]) break;
            jp = j;
        }
        b[++id] = {i, jp};
        i = jp;
    }

    FOD(i, id, 1)
    {
        p[i][0] = b[i].se - b[i].fi + 1;
        for(int j = 1; i + (1 << j) - 1 <= id; ++j)
            p[i][j] = max(p[i][j - 1] , p[i + (1 << (j - 1))][j - 1]);
    }
}

int pro(int x, int y)
{
    int tp = log2(y - x + 1);
    return max(p[x][tp] , p[y - (1 << tp) + 1][tp]);
}

void solve3()
{
    while(q--)
    {
        int x, y;
        cin >> x >> y;

        int l, r, m, e, f;

        l = 1;
        r = id;
        e = -1;
        f = 1e9;

        while(l <= r)
        {
            m = (l + r)/2;
            if(b[m].fi <= x)
            {
                e = max(e, m);
                l = m + 1;
            }
            else r = m - 1;
        }

        l = 1;
        r = id;

        while(l <= r)
        {
            m = (l + r) / 2;
            if(y <= b[m].se)
            {
                f = min(f, m);
                r = m - 1;
            }
            else l = m + 1;
        }

        if(e == f)
        {
            cout << y - x + 1 << '\n';
            continue;
        }

        if(e + 1 == f)
        {
            cout << max(b[e].se - x + 1, y - b[f].fi + 1) << '\n';
            continue;
        }

        cout << max(b[e].se - x + 1 , max(y - b[f].fi + 1 , pro(e + 1, f - 1))) << '\n';
    }
}

int main()
{
    faster();
    freopen("FreSeq.inp","r",stdin);
    freopen("FreSeq.out","w",stdout);
    cin >> n >> q;
    bool ch = true;
    FOR(i, 1, n)
    {
        cin >> a[i];
        if(a[i] < 0 || a[i] > 10) ch = false;
    }

    if(n <= 1000 && q <= 1000)
    {
        pre1();
        solve1();
        return 0;
    }

    if(ch)
    {
        pre2();
        solve2();
        return 0;
    }

    pre3();
    //FOR(i, 1, id) cout << b[i].fi << " " << b[i].se << " " << b[i].se - b[i].fi + 1 << endl;
    //cout << "-------------------------------------------------" << endl;
    // 30 --> 47
    solve3();
    return 0;
}
*/	