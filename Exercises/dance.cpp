#include <bits/stdc++.h>

using namespace std;

long long n, m, a[100005], b[100005];

bool check(long long x, long long y, long long f[], long long g[], long long temp){
	long long dau = 1;
	for(int i = 1; i <= x; i++){
		bool th = false;
		for(int j = dau; j <= y - x + i; j++){
			if(abs(g[j] - f[i]) <= temp){
				//cout << i << " " << j << '\n';
				dau = j + 1;
				th = true;
				break;
			}
		}
		if(!th) return false;
	}
	return true;
}

void solve(long long x, long long y, long long f[], long long g[]){
	long long l = 0, r = 1e18, mid, ans;
	while(l <= r){
		//cout << ans << '\n';
		mid = (l + r) / 2;
		//cout << mid << '\n';
		if(check(x, y, f, g, mid)){
			ans = mid;
			r = mid - 1;
		}
		else l = mid + 1;
	}
	cout << ans << '\n';
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("dance.inp", "r", stdin);
	freopen("dance.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1; i <= n; i++) cin >> a[i];
	for(int i = 1; i <= m; i++) cin >> b[i];
	sort(a + 1, a + n + 1);
	sort(b + 1, b + m + 1);
	if(n > m) solve(m, n, b, a);
	else solve(n, m, a, b);
}