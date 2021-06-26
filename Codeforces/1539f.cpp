// segment tree + lazy
#include <bits/stdc++.h>
#define ll long long
#define fi first
#define se second

using namespace std;

const ll INF = 1E18;

struct Node
{
	ll min_val;
	ll max_val;
} it[1600005];
ll n, lazy[1600005], res[200005];
pair < ll, ll > a[200005];

void build_tree(ll node, ll l, ll r){
	if (l > r) return;
	if (l == r){
		it[node].min_val = -l;
		it[node].max_val = -l;
		return;
	}
	ll mid = (l + r) / 2;
	build_tree(node * 2, l, mid);
	build_tree(node * 2 + 1, mid + 1, r);
	it[node].min_val = min(it[2 * node].min_val, it[2 * node + 1].min_val);
	it[node].max_val = max(it[2 * node].max_val, it[2 * node + 1].max_val);

}

void update(ll node, ll l, ll r, ll u, ll v, ll val){
	if(lazy[node] != 0){
		it[node].min_val += lazy[node];
		it[node].max_val += lazy[node];
		if(l < r){
			lazy[node * 2] += lazy[node];
			lazy[node * 2 + 1] += lazy[node];
		}
		lazy[node] = 0;
	}
	if(r < u || v < l || l > r) return ;
	if(u <= l && r <= v){
		it[node].min_val += val;
		it[node].max_val += val;
		if(l < r){
			lazy[node * 2] += val;
			lazy[node * 2 + 1] += val;
		}
		return ;
	}
	ll mid = (l + r) / 2;
	update(node * 2, l, mid, u, v, val);
	update(node * 2 + 1, mid + 1, r, u, v, val);
	it[node].min_val = min(it[2 * node].min_val, it[2 * node + 1].min_val);
	it[node].max_val = max(it[2 * node].max_val, it[2 * node + 1].max_val);
}

ll query_max(ll node, ll l, ll r, ll u, ll v){
	if(r < u || v < l || r < l) return -INF;
	if(lazy[node] != 0){
		it[node].min_val += lazy[node];
		it[node].max_val += lazy[node];
		if(l < r){
			lazy[node * 2] += lazy[node];
			lazy[node * 2 + 1] += lazy[node];
		}
		lazy[node] = 0;
	}
	if(u <= l && r <= v) return it[node].max_val;
	ll mid = (l + r) / 2;
	return max(query_max(node * 2, l, mid, u, v), query_max(node * 2 + 1, mid + 1, r, u, v));
}

ll query_min(ll node, ll l, ll r, ll u, ll v){
	if(r < u || v < l || r < l) return INF;
	if(lazy[node] != 0){
		it[node].min_val += lazy[node];
		it[node].max_val += lazy[node];
		if(l < r){
			lazy[node * 2] += lazy[node];
			lazy[node * 2 + 1] += lazy[node];
		}
		lazy[node] = 0;
	}
	if(u <= l && r <= v) return it[node].min_val;
	ll mid = (l + r) / 2;
	return min(query_min(node * 2, l, mid, u, v), query_min(node * 2 + 1, mid + 1, r, u, v));
}

bool cmp(pair < ll, ll > x, pair < ll, ll >  y){
	return x.fi > y.fi;
}

void solve(pair < ll, ll > a[], int check){
	memset(lazy, 0, sizeof(lazy));
	build_tree(1, 1, n);
	a[0].fi = -1;
	for(int i = 1; i <= n; i++){
		if(a[i].fi != a[i - 1].fi){
			update(1, 1, n, a[i].se, n, 2);
		//	if(a[i].se <= 14 && a[i].fi >= 25) cout << "yes " << a[i].fi << " " << a[i].se << '\n';
			for(int j = i + 1; j <= n; j++){
				if(a[j].fi == a[i].fi){
					update(1, 1, n, a[j].se, n, 2);
					//if(a[j].se <= 14 && a[j].fi >= 25) cout << "yes" << " " << a[j].fi << " " << a[j].se << '\n';
				}
				else break;
			}
		}
		ll maxa = query_max(1, 1, n, a[i].se, n);
		ll mina = min((ll) 0, query_min(1, 1, n, 1, a[i].se - 1));
		res[a[i].se] = max(res[a[i].se], (maxa - mina - check) / 2);
		//if(a[i].se == 14) cout << a[i].fi << " " << a[i].se  << " " << maxa << " " << mina << '\n';
	}
}

int main(){
	cin >> n;
	for(int i = 1; i <= n; i++){
		cin >> a[i].fi;
		a[i].se = i;
	}
	sort(a + 1, a + n + 1);
	solve(a, 1);
	sort(a + 1, a + n + 1, cmp);
	solve(a, 0);
	for(int i = 1; i <= n; i++) cout << res[i] << " ";
}
