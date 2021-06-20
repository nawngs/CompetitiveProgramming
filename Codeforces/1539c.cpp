#include <bits/stdc++.h>

using namespace std;

long long n, k, x, a[200005];
vector < long long > dis;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin >> n >> k >> x;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
	}
	sort(a + 1, a + n + 1);
	long long ans = 1;
	for(int i = 2; i <= n; i++){
		if(a[i] - a[i - 1] > x){
			ans ++;
			dis.push_back(a[i] - a[i - 1]);
		}
	}
	//cout << ans << '\n';
	sort(dis.begin(), dis.end());
//	long long sum = 0;
	for(int i = 0; i < dis.size(); i++){
		long long sum = dis[i] / x - (dis[i] % x == 0);
		//cout << sum << '\n';
		if(k - sum < 0){
			break;
		}
		else ans --;
		k -= sum;
	}
	cout << ans;
}