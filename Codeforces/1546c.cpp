#include <bits/stdc++.h>
#define ll long long
#define fi first
#define se second

using namespace std;

ll ntest, n, a[100005];
pair < ll, ll > f[100005];

int main(){
	cin >> ntest;
	while(ntest --){
		cin >> n;
		memset(f, 0, sizeof(f));
		for(int i = 1; i <= n; i++){
			cin >> a[i];
			if(i % 2 == 0) f[a[i]].se ++;
			else f[a[i]].fi ++;
		}
		sort(a + 1, a + n + 1);
		for(int i = 1; i <= n; i++){
			if(i % 2 == 0) f[a[i]].se --;
			else f[a[i]].fi --;
		}
		bool th = true;
		for(int i = 1; i <= 1e5; i++){
			if(f[i].fi != 0 || f[i].se != 0){
				th = false;
				break;
			}
		}
		if(th) cout << "YES" << '\n';
		else cout << "NO" << '\n';
	}
}
