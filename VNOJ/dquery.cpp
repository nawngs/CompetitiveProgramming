#include <bits/stdc++.h>
#define ll long long
#define fi first
#define se second

using namespace std;

struct Query{
	ll l;
	ll r;
	ll index;
} d[200005];

ll n, a[30005], it[240005], last[1000005], q, res[200005];

bool cmp(Query x, Query y){
	return x.r < y.r;
}

void update(ll node, ll l, ll r, ll pos, ll val){
	if(l > r || pos < l || pos > r) return ;
	if(l == r){
		it[node] += val;
		//cout << l << " " << r << " " << it[node] << '\n';
		return ;
	}
	ll mid = (l + r) / 2;
	update(node * 2, l, mid, pos, val);
	update(node * 2 + 1, mid + 1, r, pos, val);
	it[node] = it[node * 2] + it[node * 2 + 1];
	//cout << l << " " << r << " " << it[node] << '\n';
}

ll query(ll node, ll l, ll r, ll u, ll v){
	//cout << l << " " << r << " " << it[node] << '\n';
	if(v < l || r < u || r < l) return 0;
	if(u <= l && r <= v) return it[node];
	ll mid = (l + r) / 2;
	return query(node * 2, l, mid, u, v) + query(node * 2 + 1 , mid + 1, r, u, v);
}

int main(){
	memset(last, 255, sizeof(last));
	cin >> n;
	for(int i = 1; i <= n; i++) cin >> a[i];
	cin >> q;
	for(int i = 1; i <= q; i++){
		cin >> d[i].l >> d[i].r;
		d[i].index = i;
	}
	sort(d + 1, d + q + 1, cmp);
	d[0].r = 0;
	for(int i = 1; i <= q; i++){
		for(int j = d[i - 1].r + 1; j <= d[i].r; j++){
			if(last[a[j]] != -1) update(1, 1, n, last[a[j]], -1);
			last[a[j]] = j;
			update(1, 1, n, j, 1);
		}
		res[d[i].index] = query(1, 1, n, d[i].l, d[i].r);
	}
	for(int i = 1; i <= q; i++) cout << res[i] << '\n';
}