#include <bits/stdc++.h>
#define fi first
#define se second
#define ll long long

using namespace std;

ll n, demb = 0, it[2400005];
pair < ll, ll > a[200005];
struct Data
{
	ll x;
	ll y;
};

pair < ll , Data > b[400005];

bool cmp_b(pair < ll , Data > x, pair < ll , Data >  y){
	return x.fi < y.fi;
}

bool cmp_a(pair < ll, ll > x, pair < ll, ll > y){
	return (x.fi < y.fi) || (x.fi == y.fi && x.se > y.se);
}

void update(ll node, ll l, ll r, ll pos, ll val){
//	cout << pos << " " << l << " " << r << '\n';
	if(pos < l || pos > r) return ;
	it[node] = max(it[node], val);
	if(l == r) return ;
	ll mid = (l + r) / 2;
	update(node * 2, l, mid, pos, val);
	update(node * 2 + 1, mid + 1, r, pos, val);
}

ll query(ll node, ll l, ll r, ll u, ll v){
	//cout << l << " " << r << " " << u << " " << v << " " << it[node] << '\n';
	if(v < l || r < u || l > r) return -1e18;
	if(u <= l && r <= v) return it[node];
	ll mid = (l + r) / 2;
	return max(query(node * 2, l, mid, u, v), query(node * 2 + 1, mid + 1, r, u, v));
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("NestSeg.inp", "r", stdin);
	freopen("NestSeg.out", "w", stdout);
	cin >> n;
	memset(it, 0, sizeof(it));
	for(int i = 1; i <= n; i++){
		cin >> a[i].fi >> a[i].se;
		b[++ demb].fi = a[i].fi;
		b[demb].se.x = 1;
		b[demb].se.y = i;
		b[++ demb].fi = a[i].se;
		b[demb].se.x = 2;
		b[demb].se.y = i;
	}
	sort(b + 1, b + demb + 1, cmp_b);
	int dem = 0;
	b[0].fi = 1e18;
	for(int i = 1; i <= demb; i++){
		if(b[i].fi != b[i - 1].fi) dem ++;
		if(b[i].se.x == 1) a[b[i].se.y].fi = dem;
		else a[b[i].se.y].se = dem;
	}
	//for(int i = 1; i <= n; i++) cout << a[i].fi << " " << a[i].se << '\n';
	sort(a + 1, a + n + 1, cmp_a);
	update(1, 1, 2 * n, a[1].se, 1);
	ll ans = 1;
	for(int i = 2; i <= n; i++){
		//cout << a[i].fi << " " << a[i].se << '\n';
		ll tmp = query(1, 1, 2 * n, a[i].se + 1, 2 * n);
		ans = max(ans, tmp + 1);
		//cout << tmp << '\n';
		update(1, 1, 2 * n, a[i].se, tmp + 1);
	}
	cout << ans;
}