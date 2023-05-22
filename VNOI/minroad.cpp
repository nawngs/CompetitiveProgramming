//link: https://oj.vnoi.info/problem/minroad
#include <bits/stdc++.h>
#define ll long long
#define int ll
#define fi first
#define se second

using namespace std;

const string NAME = "minroad";

void fre() {
	string finp = NAME + ".inp";
	string fout = NAME + ".out";
	freopen(finp.c_str(), "r", stdin);
	freopen(fout.c_str(), "w", stdout);
}

int n, pos[300005], b[300005], x, y, ans = 1e12;
pair < int, int > a[300005], p[300005], f[300005];

int bs(int l, int r, int pos){
	int mid, ans = 1e12;
	while(l <= r){
		mid = (l + r) / 2;
		//cout << pos << " " << mid << '\n';
		if(f[pos].fi - f[mid].fi >= x && f[pos].se - f[mid].se >= y){
			ans = mid;
			l = mid + 1;
		}
		else r = mid - 1;
	}
	return ans;
}

main(){
	fre();
	cin >> n >> x >> y;
	for(int i = 1; i <= n; i++){
		cin >> a[i].fi >> a[i].se;
		p[i].fi = a[i].fi;
		p[i].se = i;
	}
	sort(p + 1, p + n + 1);
	p[0].fi = 1e9;
	int dem = 0;
	for(int i = 1; i <= n; i++){
		if(p[i].fi != p[i - 1].fi) dem ++;
		pos[dem] = a[p[i].se].fi; 
		b[dem] = a[p[i].se].se;
	}
	for(int i = 1; i <= dem; i++){
		f[i].fi = f[i - 1].fi + (b[i] == 1);
		f[i].se = f[i - 1].se + (b[i] == 2);
		//cout << pos[i] << " " << f[i].fi << " " << f[i].se << '\n';
	}
	for(int i = 2; i <= n; i++){
		int tam = bs(0, i - 1, i);
		if(tam != 1e12) ans = min(ans, pos[i] - pos[tam + 1]);
	}
	if(ans == 1e12) cout << -1;
	else cout << ans;
}
