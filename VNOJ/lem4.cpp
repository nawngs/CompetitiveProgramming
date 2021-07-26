#include <bits/stdc++.h>

using namespace std;

int n, lazy[80005], m;

struct Data{
	int sub;
	int cnt_l;
	int cnt_r;
	int len;
} it[80005];

void update(int node, int l, int r, int u, int v, int val){
	//cout << l << " " << r << " " << u << " " << v << " " << val << '\n';
	if(lazy[node] == 1){
		it[node].sub = it[node].cnt_l = it[node].cnt_r = r - l + 1;
		if(l < r){
			lazy[node * 2] = lazy[node];
			lazy[node * 2 + 1] = lazy[node];
		}
		lazy[node] = 0;
	}
	if(lazy[node] == 2){
		it[node].sub = it[node].cnt_l = it[node].cnt_r = 0;
		if(l < r){
			lazy[node * 2] = lazy[node];
			lazy[node * 2 + 1] = lazy[node];
		}
		lazy[node] = 0;	
	}
	if(r < u || v < l || l > r) return ;
	if(u <= l && r <= v){
		if(val == 1) it[node].sub = it[node].cnt_l = it[node].cnt_r = r - l + 1;
		else it[node].sub = it[node].cnt_l = it[node].cnt_r = 0;
		if(l < r){
				lazy[node * 2] = val;
				lazy[node * 2 + 1] = val;
			}
		//cout << l << " " << r << " " << it[node].cnt_l << " " << it[node].cnt_r << '\n';
		return ;
	}
	int mid = (l + r) / 2;
	update(node * 2, l, mid, u, v, val);
	update(node * 2 + 1, mid + 1, r, u, v, val);
	it[node].sub = max(it[node * 2].sub, max(it[node * 2 + 1].sub, it[node * 2].cnt_r + it[node * 2 + 1].cnt_l));
	it[node].cnt_l = it[node * 2].cnt_l;
	if(it[node * 2].cnt_l == it[node * 2].len) it[node].cnt_l += it[node * 2 + 1].cnt_l;
	it[node].cnt_r = it[node * 2 + 1].cnt_r;
	if(it[node * 2 + 1].cnt_r == it[node * 2 + 1].len) it[node].cnt_r += it[node * 2].cnt_r;
	//cout << l << " " << r << " " << it[node].cnt_l << " " << it[node].cnt_r << '\n';
}

void build_tree(int node, int l, int r){
	if(l > r) return ;
	if(l == r){
		it[node].len = it[node].sub = it[node].cnt_l = it[node].cnt_r = 1;
		return ;
	}
	int mid = (l + r) / 2;
	build_tree(node * 2, l, mid);
	build_tree(node * 2 + 1, mid + 1, r);
	it[node].sub = max(it[node * 2].sub, max(it[node * 2 + 1].sub, it[node * 2].cnt_r + it[node * 2 + 1].cnt_l));
	it[node].cnt_l = it[node * 2].cnt_l;
	if(it[node * 2].cnt_l == it[node * 2].len) it[node].cnt_l += it[node * 2 + 1].cnt_l;
	it[node].cnt_r = it[node * 2 + 1].cnt_r;
	if(it[node * 2 + 1].cnt_r == it[node * 2 + 1].len) it[node].cnt_r += it[node * 2].cnt_r;
	it[node].len = it[node * 2].len + it[node * 2 + 1].len;
	//cout << l << " " << r << " " << it[node].cnt_l << " " << it[node].cnt_r << " " << it[node].len << '\n';
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin >> n >> m;
	build_tree(1, 1, n);
	//cout << it[1].sub << '\n';
	while(m --){
		int x;
		cin >> x;
		if(x == 1 || x == 2){
			int y, z;
			cin >> y >> z;
			update(1, 1, n, y, z, x);
		}
		else{
			cout << it[1].sub << '\n';
		}
	}
}

