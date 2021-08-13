#include <bits/stdc++.h>
#define ll long long

using namespace std;

int ntest, n;
vector < ll > a;
vector < ll > it;

void build(int node, int l, int r){
	if(l == r){
		it[node] = a[l];
		return ;
	}
	int mid = (l + r) / 2;
	build(node * 2, l, mid);
	build(node * 2 + 1, mid + 1, r);
	it[node] = __gcd(it[node * 2], it[node * 2 + 1]);
}

ll query(int node, int l, int r, int u, int v){
    if(v < l || r < u || l > r) return -1;
    if(u <= l && r <= v) return it[node];
    int mid = (l + r) / 2;
    ll lnode = query(node * 2, l, mid, u, v);
    ll rnode = query(node * 2 + 1, mid + 1, r, u, v);
    if(lnode == -1) return rnode;
    if(rnode == -1) return lnode;
    return __gcd(lnode, rnode);
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin >> ntest;
	while(ntest --){
		cin >> n;
		ll prex, x;
		if(n == 1){
			cin >> x;
			cout << 1 << '\n';
			continue;
		}
		if(n == 2){
			cin >> prex >> x;
			cout << (abs(x - prex) == 1 ? 1 : 2) << '\n';
			continue;
		}
		it.clear();
		vector < ll > (6 * n, 0).swap(it);
		a.clear();
		cin >> prex;
		//vector < ll > (6 * n, 0).swap(it);	
		for(int i = 1; i < n; i++){
			cin >> x;
			a.push_back((x - prex != 0 ? abs(x - prex) : x));
			//cout << a[i] << ' ';
			prex = x;
		}
		//cout << endl;
		n -= 2;
		//for(int i = 0; i <= n - 2; i++) cout << a[i] << ' ';
		//cout << '\n';
		build(1, 0, n);
		int l = 0;
		int r = 0;
		int ans = 0;
		ll temp;
		while(r < n){
			r ++;
			while(r < l) r++;
			//cout << l << " " << r << '\n';
			temp = query(1, 0, n, l, r);
			//cout << l << " " << r << " " << temp << '\n';
			if(temp > 1){
				ans = max(ans, r - l + 1);
			}
			else{
				r --;
				l ++;
			}
		}
		cout << ans + 1 << '\n';
	}
}