#include <bits/stdc++.h>
#define fi first
#define se second

using namespace std;

int n, m, cntp = 0, ans = 0, res[100005];

pair < int, int > a[100005];
pair < int, pair < int, int > > p[200005];

vector < int > start[200005], last[200005], room;

int main(){
	//freopen("room.inp", "r", stdin);
	//freopen("room.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1; i <= n; i++){
		cin >> a[i].fi >> a[i].se;
		p[++ cntp].fi = a[i].fi;
		p[cntp].se.fi = i;
		p[cntp].se.se = 1;
		p[++ cntp].fi = a[i].se;
		p[cntp].se.fi = i;
		p[cntp].se.se = 2;
	}
	sort(p + 1, p + cntp + 1);
	int cnt = 0;
	p[0].fi = 1e9 + 7;
	for(int i = 1; i <= cntp; i++){
		if(p[i].fi != p[i - 1].fi) cnt ++;
		//cout << p[i].fi << " " << cnt << " " << p[i].se.fi << " " << p[i].se.se << '\n';
		if(p[i].se.se == 1) a[p[i].se.fi].fi = cnt;
		if(p[i].se.se == 2) a[p[i].se.fi].se = cnt;
	}
	for(int i = 1; i <= n; i++){
		//cout << a[i].fi << " " << a[i].se << '\n';
		start[a[i].fi].push_back(i);
		last[a[i].se].push_back(i);
	}
	//sort(a + 1, a + n + 1);
	for(int i = 1; i <= cntp; i++){
		for(auto v : last[i]){
			room.push_back(res[v]);
		}
		while(room.size() < start[i].size()){
			room.push_back(++ ans);
		}
		for(auto v : start[i]){
			res[v] = room[room.size() - 1];
			//cout << v << " " << res[v] << '\n'
			room.pop_back();
		}
	}
	if(ans > m) cout << -1;
	else{
		cout << ans << '\n';
		for(int i = 1; i <= n; i++) cout << res[i] << '\n';
	}
}