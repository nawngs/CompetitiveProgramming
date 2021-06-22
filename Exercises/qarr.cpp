#include <bits/stdc++.h>
#define ll long long

using namespace std;

ll n, it[8000005], lazy[8000005];

void update(ll node, ll l, ll r, ll i, ll j){
	if(lazy[node] != 0){
		it[node] += lazy[node] * (r - l + 1);
		if(l < r){
			lazy[node * 2] += lazy[node];
			lazy[node * 2 + 1] += lazy[node];
		}
		lazy[node] = 0;
	}
	if(r < i || j < l || l > r) return ;
	if(i <= l && r <= j){
		it[node] += (r - l + 1);
		if(l < r){
			lazy[node * 2] ++;
			lazy[node * 2 + 1] ++;
		}
		return ;
	}
	ll mid = (l + r) / 2;
	update(node * 2, l, mid, i, j);
	update(node * 2 + 1, mid + 1, r, i, j);
	it[node] = it[node * 2] + it[node * 2 + 1];
}

ll query(ll node, ll l, ll r, ll i, ll j){
	if(r < i || j < l || l > r) return 0;
	if(lazy[node] != 0){
		it[node] += lazy[node] * (r - l + 1);
		if(l < r){
			lazy[node * 2] += lazy[node];
			lazy[node * 2 + 1] += lazy[node];
		}
		lazy[node] = 0;
	}
	if(i <= l && r <= j) return it[node];
	ll mid = (l + r) / 2;
	return query(node * 2, l, mid, i, j) + query(node * 2 + 1, mid + 1, r, i, j);

}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("qarr.inp", "r", stdin);
	freopen("qarr.out", "w", stdout);
	ll q;
	cin >> n >> q;
	for(int i = 1; i <= q; i++){
		ll x, y;
		cin >> x >> y;
		update(1, 1, n, x, y);
	}
	for(int i = 1; i <= n; i++) cout << query(1, 1, n, i, i) << "\n";
}