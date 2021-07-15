#include <bits/stdc++.h>
#define ll long long
#define fi first
#define se second

using namespace std;

ll n, res[300005];
pair < ll, ll > s[300005];

bool cmp(pair < ll, ll > x, pair < ll, ll > y){
	return (x.fi < y.fi) || (x.fi == y.fi && x.se < y.se);
}

int main(){
	cin >> n;
	s[0].fi = 0;
	s[0].se = 0;
	for(int i = 1; i <= n; i++){
		ll x;
		cin >> x;
		s[i].fi = s[i - 1].fi + x;
		s[i].se = i;
	}
	sort(s, s + n + 1, cmp);
	ll pos = 0;
	s[n + 1].fi = -1e18;
	for(int i = 1; i <= n + 1; i++){
		if(s[i].fi != s[i - 1].fi){
			for(int j = pos + 1; j < i; j++){
				res[s[j - 1].se + 1] += (j - pos) * (i - j);
				res[s[j].se + 1] -= (j - pos) * (i - j);
			}
			pos = i;
		}
	}
	for(int i = 1; i <= n; i++){
		res[i] += res[i - 1];
		cout << res[i] << ' ';
	}
}