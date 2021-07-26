#include <bits/stdc++.h>
#define fi first
#define se second

using namespace std;

int n, it[800005], ans = -1e9;
pair < int, int > a[100005], p[100005];

bool cmp(pair < int, int > x, pair < int, int > y){
	return (x.fi < y.fi) || (x.fi == y.fi && x.se < y.se);
}

void update(int node, int l, int r, int pos, int val){
	if(pos < l || pos > r || l > r) return ;
	it[node] = max(it[node], val);
	if(l == r) return ;
	int mid = (l + r) / 2;
	update(node * 2, l, mid, pos, val);
	update(node * 2 + 1, mid + 1, r, pos, val);
}

int query(int node, int l, int r, int u, int v){
	//cout << node << " " << l << " " << r << " " << it[node] << '\n';
	if(v < l || r < u || l > r) return 0;
	if(u <= l && r <= v) return it[node];
	int mid = (l + r) / 2;
	return max(query(node * 2, l, mid, u, v), query(node * 2 + 1, mid + 1, r, u, v));
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("ROBOTCAM.Inp", "r", stdin);
	freopen("ROBOTCAM.Out", "w", stdout);
	cin >> n;
	for(int i = 1; i <= n; i++){
		cin >> a[i].fi >> a[i].se;
		p[i].fi = a[i].se;
		p[i].se = i;
	}
	sort(p + 1, p + n + 1);
	int dem = 0;
	p[0].fi = 1e9;
	for(int i = 1; i <= n; i++){
		if(p[i].fi != p[i - 1].fi) dem ++;
		a[p[i].se].se = dem;
	}
	sort(a + 1, a + n + 1, cmp);
	for(int i = 1; i <= n; i++){
		//cout << a[i].fi << " " << a[i].se << '\n';
		int tmp = query(1, 1, n, a[i].se + 1, n);
		//cout << tmp << '\n';
		ans = max(ans, tmp + 1);
		update(1, 1, n, a[i].se, tmp + 1);
	}
	cout << ans;
}