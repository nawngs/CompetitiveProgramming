//link: https://oj.vnoi.info/problem/avlbit
#include <bits/stdc++.h>
#define fi first
#define se second
#define pii pair < int, int >

using namespace std;

const int INF = 1E9 + 7;

struct Data
{
	int l;
	int r;
	int index;
} d[1000005];

int n, q, a[100005], s[100005], res[1000005], it_last[1600005], it_gcd[1600005], last[100005];

pii it_max_min[1600005], p[100005];

// fi la max
//se la min

bool cmp(Data x, Data y){
	return x.r < y.r;
}


//###########################################################################################################

void update_last(int node, int l, int r, int pos, int val){
	if(l > r || pos < l || pos > r) return ;
	if(l == r){
		it_last[node] += val;
		//cout << l << " " << r << " " << it_last[node] << '\n';
		return ;
	}
	int mid = (l + r) / 2;
	update_last(node * 2, l, mid, pos, val);
	update_last(node * 2 + 1, mid + 1, r, pos, val);
	it_last[node] = it_last[node * 2] + it_last[node * 2 + 1];
	//cout << l << " " << r << " " << it_last[node] << '\n';
}

int query_last(int node, int l, int r, int u, int v){
	//cout << l << " " << r << " " << it_last[node] << '\n';
	if(v < l || r < u || r < l) return 0;
	if(u <= l && r <= v) return it_last[node];
	int mid = (l + r) / 2;
	return query_last(node * 2, l, mid, u, v) + query_last(node * 2 + 1 , mid + 1, r, u, v);
}

//################################################################################################################

void build_tree_gcd(int node, int l, int r){
	if(l == r){
		it_gcd[node] = s[l];
		return ;
	}
	int mid = (l + r) / 2;
	build_tree_gcd(node * 2, l, mid);
	build_tree_gcd(node * 2 + 1, mid + 1, r);
	it_gcd[node] = __gcd(it_gcd[node * 2], it_gcd[node * 2 + 1]);
	return ;

}

int query_gcd(int node, int l, int r, int u, int v){
	if(v < l || r < u || r < l) return -1;
	if(u <= l && r <= v) return it_gcd[node];
	int mid = (l + r) / 2;
	int lnode = query_gcd(node * 2, l, mid, u, v);
	int rnode = query_gcd(node * 2 + 1, mid + 1, r, u, v);
	if(lnode == -1) return rnode;
	if(rnode == -1) return lnode;
	return __gcd(lnode, rnode);
}

//#################################################################################################################

void build_tree_max_min(int node, int l, int r){
	if(l == r){
		it_max_min[node].fi = it_max_min[node].se = a[l];
		//cout << l << " " << r << " " << it_max_min[node].se << " " << it_max_min[node].fi << '\n';
		return ;
	}
	int mid = (l + r) / 2;
	build_tree_max_min(node * 2, l, mid);
	build_tree_max_min(node * 2 + 1, mid + 1, r);
	it_max_min[node].fi = max(it_max_min[node * 2].fi, it_max_min[node * 2 + 1].fi);
	it_max_min[node].se = min(it_max_min[node * 2].se, it_max_min[node * 2 + 1].se);
	//cout << l << " " << r << " " << it_max_min[node].se << " " << it_max_min[node].fi << '\n';
	return ;
}

pii query_max_min(int node, int l, int r, int u, int v){
	//cout << l << " " << r << " " << it_max_min[node].se << " " << it_max_min[node].fi << '\n';
	if(v < l || r < u || r < l) return {-INF, INF};
	if(u <= l && r <= v) return it_max_min[node];
	int mid = (l + r) / 2;
	pii lnode = query_max_min(node * 2, l, mid, u, v);
	pii rnode = query_max_min(node * 2 + 1, mid + 1, r, u, v);
	pii ans;
	ans.fi = max(lnode.fi, rnode.fi);
	ans.se = min(lnode.se, rnode.se);
	return ans; 
}

//#################################################################################################################

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin >> n >> q;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
		s[i] = abs(a[i] - a[i - 1]);
		//cout << s[i] << '\n';
		p[i].fi = a[i];
		p[i].se = i;
	}
	build_tree_gcd(1, 2, n);
	build_tree_max_min(1, 1, n);
	sort(p + 1, p + n + 1);
	int dem = 0;
	p[0].fi = INF;
	for(int i = 1; i <= n; i++){
		if(p[i].fi != p[i - 1].fi) dem ++;
		a[p[i].se] = dem;
	}
	for(int i = 1; i <= q; i++){
		cin >> d[i].l >> d[i].r;
		d[i].index = i;
	}
	sort(d + 1, d + q + 1, cmp);
	d[0].r = 0;
	for(int i = 1; i <= q; i++){
		for(int j = d[i - 1].r + 1; j <= d[i].r; j++){
			//cout << a[j] << " ";
			if(last[a[j]] != -1) update_last(1, 1, n, last[a[j]], -1);
			last[a[j]] = j;
			update_last(1, 1, n, j, 1);
		}
		int temp = query_last(1, 1, n, d[i].l, d[i].r);
		//cout << temp << '\n';
		if(temp != d[i].r - d[i].l + 1){
			res[d[i].index] = 0;
			continue;
		}
		pii u = query_max_min(1, 1, n, d[i].l, d[i].r);
		//cout << u.se << " " << u.fi << '\n';
		int gcd = query_gcd(1, 2, n, d[i].l + 1, d[i].r);
		//cout << gcd << '\n';
		if(u.se + gcd * (d[i].r - d[i].l) == u.fi) res[d[i].index] = 1;
		else res[d[i].index] = 0;
	}
	for(int i = 1; i <= q; i++) res[i] == 1 ? cout << "YES" << '\n' : cout << "NO" << '\n';
}