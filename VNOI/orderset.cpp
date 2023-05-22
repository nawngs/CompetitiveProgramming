#include <bits/stdc++.h>
#define ll long long
#define fi first
#define se second 

using namespace std;

ll n, it[1600005], ans = -1, f[2000005], cnt = 0;

pair <char, ll> a[200005];
pair < ll, ll > p[200005];

void update(ll node, ll l, ll r, ll pos, ll val){
	if(pos < l || r < pos) return ;
	if(l == r){
		it[node] = val;
		return;
	}
	ll mid = (l + r) / 2;
	update(node * 2, l, mid, pos, val);
	update(node * 2 + 1, mid + 1, r, pos, val);
	it[node] = it[node * 2] + it[node * 2 + 1];
}

void queryk(ll node, ll l, ll r, ll k){
	//cout << it[node] << " " << l << " " << r << " " << cnt << " " << k << '\n';
	if(cnt >= k) return ;
	if(cnt + it[node] < k){
		cnt += it[node];
		return ;
	}
	if(l == r){
		cnt += it[node];
		if(cnt == k) ans = l;
		return ;
	}
	ll mid = (l + r) / 2;
	queryk(node * 2, l, mid, k);
	queryk(node * 2 + 1, mid + 1, r , k);

}

ll query(ll node, ll l, ll r, ll u, ll v){
	if(v < l || r < u || l > r) return 0;
	if(u <= l && r <= v) return it[node];
	ll mid = (l + r) / 2;
	return query(node * 2, l, mid, u, v) + query(node * 2 + 1, mid + 1, r, u, v);
}

int main(){
	cin >> n;
	for(int i = 1; i <= n; i++){
		cin >> a[i].fi >> a[i].se;
		if(a[i].fi == 'I' || a[i].fi == 'D' || a[i].fi == 'C'){
			p[i].fi = a[i].se;
			p[i].se = i;
		}
	}
	ll dem = 0;
	sort(p + 1, p + n + 1);
	p[0].fi = 1e18;
	for(int i = 1; i <= n; i++){
		if(p[i].fi != p[i - 1].fi) dem ++;
		f[dem] = a[p[i].se].se;
		a[p[i].se].se = dem;
	}
	for(int i = 1; i <= n; i++){
		//cout << a[i].fi << " " << a[i].se << '\n';
		if(a[i].fi == 'I' || a[i].fi == 'D') update(1, 1, n, a[i].se, (a[i].fi == 'I'));
		if(a[i].fi == 'K'){
			ans = -1;
			cnt = 0;
			queryk(1, 1, n, a[i].se);
			ans == -1 ? cout << "invalid" << '\n' : cout << f[ans] << '\n';
		}
		if(a[i].fi == 'C'){
			cout << query(1, 1, n, 1, a[i].se - 1) << '\n';
		}

	}
}

