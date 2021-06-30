#include <bits/stdc++.h>
#define fi first
#define se second
#define ll long long

using namespace std;

ll n, ans = -1e18, it[32000005];
pair < ll, ll > a[200005];
pair < ll , pair < ll, ll > > p[400005];

void update(ll node, ll l, ll r, ll pos, ll val){
	if(pos < l || pos > r || l > r) return ;
	it[node] = max(it[node], val);
	if(l == r) return;
	ll mid = (l + r) / 2;
	update(node * 2, l, mid, pos, val);
	update(node * 2 + 1, mid + 1, r, pos, val);
}

ll query(ll node, ll l, ll r, ll u, ll v){
	if(v < l || r < u || l > r) return 0;
	if(u <= l && r <= v) return it[node];
	ll mid = (l + r) / 2;
	return max(query(node * 2, l, mid, u, v), query(node * 2 + 1, mid + 1, r, u, v));
}

bool cmp(pair < ll, ll > x, pair < ll, ll > y){
	return (x.fi < y.fi) || (x.fi == y.fi && x.se < y.se);
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("Exhibition1.INP", "r", stdin);
	freopen("Exhibition1.OUT", "w", stdout);
	cin >> n;
	for(int i = 1; i <= n; i++){
		cin >> a[i].fi;
		p[i].fi = a[i].fi;
		p[i].se.fi = 1;
		p[i].se.se = i;
	}
	for(int i = 1; i <= n; i++){
		cin >> a[i].se;
		p[n + i].fi = a[i].se;
		p[n + i].se.fi = 2;
		p[n + i].se.se = i;
	}
	sort(p + 1, p +  2 * n + 1);
	ll cnt = 0;
	p[0].fi = 1e18;
	for(int i = 1; i <= 2 * n; i++){
		if(p[i].fi != p[i - 1].fi) cnt ++;
		if(p[i].se.fi == 1) a[p[i].se.se].fi = cnt;

		else a[p[i].se.se].se = cnt;
	}
//	for(int i = 1; i <= n; i++) cout << a[i].fi << " " << a[i].se << '\n';
	sort(a + 1, a + n + 1, cmp);
	for(int i = 1; i <= n; i++){
		ll tmp =  query(1, 1, cnt, 1, a[i].se) + 1;
		//cout << tmp <<
		ans = max(ans, tmp);
		update(1, 1, cnt, a[i].se, tmp);
	}
	cout << ans;
}