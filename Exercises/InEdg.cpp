#include <bits/stdc++.h>
#define fi first
#define se second

using namespace std;

int n, p;
pair < int, int > a[300005];

map < int, vector < int > > map_x;
map < int, vector < int > > map_y;

bool cmp(pair < int, int > x, pair < int, int > y){
	return (x.fi < y.fi) || (x.fi == y.fi && x.se < y.se);
}

bs1(int val, vector < int > f){
	int l = 0, r = f.size() - 1, mid, ans = -1;
	while(l <= r){
		mid = (l + r) / 2;
		if(f[mid] >= val){
			ans = mid;
			r = mid - 1;
		}
		else l = mid + 1;
	}
	return ans;
}

bs2(int val, vector < int > f){
	int l = 0, r = f.size() - 1, mid, ans = -1;
	while(l <= r){
		mid = (l + r) / 2;
		if(f[mid] <= val){
			ans = mid;
			l = mid + 1;
		}
		else r = mid - 1;
	}
	return ans;
}

int main(){	
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("InEdg.inp", "r", stdin);
	freopen("InEdg.out", "w", stdout);
	cin >> n;
	for(int i = 1; i <= n; i++) cin >> a[i].fi >> a[i].se;
	sort(a + 1, a + n + 1, cmp);
	for(int i = 1; i <= n; i++){
		map_x[a[i].fi].push_back(a[i].se);
		map_y[a[i].se].push_back(a[i].fi);
	}
	cin >> p;
	//for(auto v : map_x[4]) cout << v << '\n';
	while( p --){
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		int temp1, temp2, ans = 0;
		temp1 = bs1(y1, map_x[x1]);
		temp2 = bs2(y2, map_x[x1]);
		//cout << temp1 << " " << temp2 << '\n';
		if(temp1 != -1 && temp2 != -1 && temp2 >= temp1) ans += temp2 - temp1 + 1;
		//cout << ans << '\n';
		temp1 = bs1(y1, map_x[x2]);
		temp2 = bs2(y2, map_x[x2]);
		if(temp1 != -1 && temp2 != -1 && temp2 >= temp1) ans += temp2 - temp1 + 1;
		//cout << temp1 << " " << temp2 << '\n';
		
		temp1 = bs1(x1 + 1, map_y[y1]);
		temp2 = bs2(x2 - 1, map_y[y1]);
		if(temp1 != -1 && temp2 != -1 && temp2 >= temp1) ans += temp2 - temp1 + 1;
		//cout << temp1 << " " << temp2 << '\n';

		temp1 = bs1(x1 + 1, map_y[y2]);
		temp2 = bs2(x2 - 1, map_y[y2]);
		if(temp1 != -1 && temp2 != -1 && temp2 >= temp1) ans += temp2 - temp1 + 1;
		//cout << temp1 << " " << temp2 << '\n';

		cout << ans << '\n';
	}
}