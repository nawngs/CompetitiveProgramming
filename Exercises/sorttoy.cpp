#include <bits/stdc++.h>
#define ll long long
#define fi first
#define se second

using namespace std;

struct Data
{
	ll a;
	ll b;
	ll c;
} a[100005];

 ll n, demp = 0, it[800005];

bool cmp(Data x, Data y){
	return (x.a < y.a);
}

pair <ll, pair <ll, ll >> p[200005];

void update(ll node,ll l, ll r, ll pos, ll val){
	if(pos < l || pos > r || l > r) return ;
	it[node] = max(it[node], val);
	if(l == r) return ;
	ll mid = (l + r) / 2;
	update(node * 2, l, mid, pos, val);
	update(node  * 2 + 1, mid + 1, r, pos, val);
}

ll query(ll node, ll l, ll r, ll u, ll v){
	if(u > r || l > v || l > r) return -1e18;
	if(u <= l && r <= v) return it[node];
	ll mid = (l + r) / 2;
	return max(query(node * 2, l, mid, u, v), query(node * 2 + 1, mid + 1, r, u, v));
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("SORTTOY.inp", "r", stdin);
	freopen("SORTTOY.out", "w", stdout);
	cin >> n;
	for(int i = 1; i <= n; i++){
		cin >> a[i].a >> a[i].b >> a[i].c;
		p[++ demp].fi = a[i].a;
		p[demp].se.fi = 1;
		p[demp].se.se = i;
		p[++ demp].fi = a[i].b;
		p[demp].se.fi = 2;
		p[demp].se.se = i;
	}
	sort(p + 1, p + demp + 1);
	ll dem = 0;
	for(int i = 1; i <= demp; i++){
		if(p[i].fi != p[i - 1].fi) dem ++;
		if(p[i].se.fi == 1) a[p[i].se.se].a = dem;
		else a[p[i].se.se].b = dem;
	}
	sort(a + 1, a + n + 1, cmp);
	update(1, 1, 2 * n + 3, a[1].b, a[1].c);
	ll ans = a[1].c;
	for(int i = 2; i <= n; i++){
		ll tmp = query(1, 1, 2 * n + 3, 1, a[i].a);
		ans = max(ans, tmp + a[i].c);
		update(1, 1, 2 * n + 3, a[i].b, tmp + a[i].c);
	}
	cout << ans;
}