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

const string NAME = "BoundSeq";
const string NAME2 = "TEST";
const ll ESP = 1e-9;
const int INF = 1E9 + 7;
const ll nmax = 1e7;
const ll MOD = 1e9 + 7;

void fre() {
	string finp = NAME + ".inp";
	string fout = NAME + ".out";
	freopen(finp.c_str(), "r", stdin);
	freopen(fout.c_str(), "w", stdout);
}

int n, a[500005], it[4000005], it2[4000005];

pll p[500005];


void roi_rac() {
	//cout << 123 << '\n';
	for (int i = 1; i <= n; i++) p[i] = {a[i], i};
	sort(p + 1, p + n + 1);
	p[0].fi = INF;
	int dem = 0;
	for (int i = 1; i <= n; i++) {
		dem += (p[i].fi != p[i - 1].fi);
		a[p[i].se] = dem;
	}
}

int query(int node, int l, int r, int u, int v) {
	if (v < l || r < u) return 0;
	if (u <= l && r <= v) return it[node];
	int mid = (l + r) / 2;
	return max(query(node * 2, l, mid, u, v), query(node * 2 + 1, mid + 1, r, u, v));
}

int query2(int node, int l, int r, int u, int v) {
	//cout << l << " " << r << " " << it2[node] << '\n';
	if (v < l || r < u) return 0;
	if (u <= l && r <= v) return it2[node];
	int mid = (l + r) / 2;
	int lnode = query2(node * 2, l, mid, u, v);
	int rnode = query2(node * 2 + 1, mid + 1, r, u, v);
	return a[lnode] <= a[rnode] ? lnode : rnode;
}

void update1(int node, int l, int r, int pos, int val) {
	if (pos < l || pos > r) return ;
	it[node] = max(it[node], val);
	if (l == r) return ;
	int mid = (l + r) / 2;
	update1(node * 2, l, mid, pos, val);
	update1(node  * 2 + 1, mid + 1, r, pos, val);
}

void update2(int node, int l, int r, int pos, int val) {
	if (pos < l || pos > r) return ;
	if (l == r) {
		it2[node] = pos;
		return ;
	}
	int mid = (l + r) / 2;
	update2(node * 2, l, mid, pos, val);
	update2(node * 2 + 1, mid + 1, r, pos, val);
	it2[node] = (a[it2[node * 2]] <= a[it2[node * 2 + 1]] ? it2[node * 2] : it2[node * 2 + 1]);
}

void sol() {
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];
	roi_rac();
	//cout << 123 << '\n';
	a[0] = INF;
	int ans = -1;
	for (int i = 1; i <= n; i++) {
		int tam = query(1, 1, n, a[i] + 1, n);
		int temp = query2(1, 1, n, tam, i);
		//cout << i << " " << tam << " " << temp << '\n';
		if (a[i] >= a[temp]) ans = max(ans, i - temp + 1);
		update1(1, 1, n, a[i], i);
		update2(1, 1, n, i, a[i]);

	}
	cout << ans << '\n';
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
#define nmax 500007
void faster()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

int n;
pair < int , int > b[nmax];
int a[nmax];
int p[nmax][20];
vector < int > v[nmax];

stack < int > sk;
int s[nmax];

void pre()
{
    FOD(i, n, 1)
    {
        p[i][0] = a[i];
        for(int j = 1; i + (1 << j) - 1 <= n; ++j)
            p[i][j] = min(p[i][j - 1] , p[i + (1 << (j - 1))][j - 1]);
    }

    FOR(i, 1, n) v[a[i]].eb(i);

    a[0] = 1e9;

    while(sk.size()) sk.pop();
    sk.push(0);

    FOR(i, 1, n)
    {
        while(a[sk.top()] <= a[i]) sk.pop();
        s[i] = sk.top() + 1;
        sk.push(i);
    }
}

void roirac()
{
    sort(b + 1, b + 1 + n);
    int cnt = 0;
    b[0].fi = b[1].fi;
    FOR(i, 1, n)
    {
        if(b[i].fi != b[i - 1].fi) cnt++;
        a[b[i].se] = cnt;
    }
}

int get(int x, int y)
{
    int tp = log2(y - x + 1);
    return min(p[x][tp] , p[y - (1 << tp) + 1][tp]);
}

int bs(int x, int id)
{
    int ans = 1e9;
    int l = 0;
    int r = v[x].size() - 1;
    int m;
    while(l <= r)
    {
        m = (l + r)/2;
        if(v[x][m] >= id)
        {
            ans = min(ans, m);
            r = m - 1;
        }
        else l = m + 1;
    }
    return ans;
}

int main()
{
    faster();
    freopen("BoundSeq.inp","r",stdin);
    freopen("BoundSeq.out","w",stdout);
    cin >> n;
    FOR(i, 1, n)
    {
        cin >> a[i];
        b[i] = {a[i] , i};
    }
    roirac();
    pre();
    int ans = 0;
    FOR(i, 1, n)
    {
        if(s[i] == i) continue;
        int tmp = get(s[i] , i);
        int id = bs(tmp , s[i]);
        ans = max(ans, i - v[tmp][id] + 1);
    }
    if(ans == 0) cout << -1;
    else cout << ans;
    return 0;
    /

}*/
