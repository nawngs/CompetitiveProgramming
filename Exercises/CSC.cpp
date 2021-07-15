#include <bits/stdc++.h>
#define ll long long

using namespace std;

ll ntest, n, a[20005];

bool solve(ll n, ll a[]){
	bool ans = true;
	ll temp = a[2] - a[1];
	for(int i = 2; i <= n; i ++){
		if(a[i] - a[i - 1] != temp){
			ans = false;
			break;
		}
	}
	if(ans) return true;
	//#######################################
	ans = true;
	temp = a[3] - a[2];
	for(int i = 4; i <= n; i ++){
		if(a[i] - a[i - 1] != temp){
			ans = false;
			break;
		}
	}
	if(ans) return true;
	//###################################
	ans = true;
	temp = a[3] - a[1];
	for(int i = 4; i <= n; i ++){
		if(a[i] - a[i - 1] != temp){
			ans = false;
			break;
		}
	}
	if(ans) return true;
	//###################################
	ans = true;
	temp = a[2] - a[1];
	for(int i = 2; i < n; i ++){
		if(a[i] - a[i - 1] != temp){
			ans = false;
			break;
		}
	}
	if(ans) return true;
	//###################################
	temp = a[2] - a[1];
	ll i = 3;
	bool check = false;
	while(i <= n){
		if(a[i] - a[i - 1] != temp && check == true) return false;
		else{
			if(a[i] - a[i - 1] != temp && check == false){
				if(a[i + 1] - a[i - 1] != temp) return false;
				else{
					check = true;
					i ++;
				}
			}
		}
		i ++;
	}
	return true;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("CSC.Inp", "r", stdin);
	freopen("CSC.Out", "w", stdout);
	cin >> ntest;
	while(ntest --){
		memset(a, 0, sizeof(a));
		cin >> n;
		for(int i = 1; i <= n; i++) cin >> a[i];
		sort(a + 1, a + n + 1);
		bool check = solve(n, a);
		if(check) cout << 1 << '\n';
		else cout << -1 << '\n';
	}
}