#include <bits/stdc++.h>
#define ll long long
#define fi first
#define se second

using namespace std;

const ll INF = 1e18;

ll n, t, a[100005];

pair < ll, ll > it[800005];

void build_tree(ll node, ll l, ll r){
	if(l == r){
		it[node].fi = a[l];
		it[node].se = a[r];
		return ;
	}
	ll mid = (l + r) / 2;
	build_tree(node * 2, l, mid);
	build_tree(node * 2 + 1, mid + 1, r);
	it[node].fi = min(it[node * 2].fi, it[node * 2 + 1].fi);
	it[node].se = max(it[node * 2].se, it[node * 2 + 1].se);
}

pair < ll, ll > query(ll node, ll l, ll r, ll u, ll v){
	if(v < l || r < u || l > r){
		return {INF, -INF};
	}
	if(u <= l && r <= v) return it[node];
	ll mid = (l + r) / 2;
	pair < ll, ll > lnode = query(node * 2, l, mid, u, v);
	pair < ll, ll > rnode = query(node * 2 + 1, mid + 1, r, u, v);
	return {min(lnode.fi, rnode.fi), max(lnode.se, rnode.se)};
}

ll build(ll x){
	ll temp = 1;
	for(int i = 2; i * i <= x; i++){
		if(x % i == 0){
			temp += i;
			break;
		}
	}
	if(temp == 1) temp += x;
	return temp * temp;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("DEVI.Inp", "r", stdin);
	freopen("DEVI.Out", "w", stdout);
	cin >> n >> t;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
		a[i] = build(a[i]);
	}
	build_tree(1, 1, n);
	while(t --){
		ll q;
		cin >> q;
		ll ans = 0;
		ll dau = 1;
		ll cuoi = 1;
		while(cuoi <= n){
			while(dau <= cuoi){
				pair < ll , ll > u = query(1, 1, n, dau, cuoi);
				if(u.se - u.fi > q) dau ++;
				else break;
			}
			ans = max(ans, cuoi - dau + 1);
			cuoi ++;
		}
		cout << ans << "\n";
	}
}