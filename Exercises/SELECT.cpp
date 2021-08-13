#include <bits/stdc++.h>
#define fi first
#define se second

using namespace std;

int n, demp = 0, dp[200005], ans = 1, it[1600005];

pair < int, int > a[100005];

pair < int, pair < int, int > > p[200005];

int query(int node, int l, int r, int u, int v){
	//cout << l << " " << r << " " << it[node] << '\n';
	if(v < l || r < u || l > r) return 0;
	if(u <= l && r <= v) return it[node];
	int mid = (l + r) / 2;
	return max(query(node * 2, l, mid, u, v), query(node * 2 + 1, mid + 1, r, u, v));
}

void update(int node, int l, int r, int pos, int val){
	//cout << pos << " " << val << '\n';
	if(pos < l || pos > r || l > r) return ;
	it[node] = max(it[node], val);
	if(l == r) return ;
	int mid = (l + r) / 2;
	update(node * 2, l, mid, pos, val);
	update(node * 2 + 1, mid + 1, r, pos, val);
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("SELECT.inp", "r", stdin);
	freopen("SELECT.out", "w", stdout);
	cin >> n;
	for(int i = 1; i <= n; i++){
		cin >> a[i].fi >> a[i].se;
		p[++ demp].fi = a[i].fi;
		p[demp].se.fi = i;
		p[demp].se.se = 1;
		p[++ demp].fi = a[i].se;
		p[demp].se.fi = i;
		p[demp].se.se = 2;
	}
	sort(p + 1, p + demp + 1);
	p[0].fi = 1e9 + 7;
	int cnt = 0;
	for(int i = 1; i <= demp; i++){
		if(p[i].fi != p[i - 1].fi) cnt ++;
		if(p[i].se.se == 1) a[p[i].se.fi].fi = cnt;
		if(p[i].se.se == 2) a[p[i].se.fi].se = cnt;
	}
	sort(a + 1, a + n + 1);
	for(int i = 1; i <= n; i++){
		dp[a[i].se] = max(dp[a[i].se], query(1, 1, cnt, 1, a[i].fi) + 1);
		ans = max(ans, dp[a[i].se]);
		update(1, 1, cnt, a[i].se, dp[a[i].se]);
	}
	cout << ans;
}

