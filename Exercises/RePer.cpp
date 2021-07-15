#include <bits/stdc++.h>
#define ll long long

using namespace std;

ll n, a[200005], p[200005];
bool check[200005];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("RePer.Inp", "r", stdin);
	freopen("RePer.Out", "w", stdout);
	cin >> n;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
	}
	a[0] = -1;
	ll pos = 1;
	for(int i = 1; i <= n; i++){
		if(a[i] != a[i - 1]){
			cout << a[i] << " ";
			check[a[i]] = true;
		}
		else{
			while(check[pos]){
				pos ++;
			}
			check[pos] = true;
			cout << pos << " ";
		}
	}

}


