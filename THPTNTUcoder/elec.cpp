// link: http://thptchuyen.ntucoder.net/Problem/Details/4658

#include <bits/stdc++.h>

using namespace std;

int n, m, a[55];

int main(){
	cin >> n >> m;
	for(int i = 1; i <= n; i++) cin >> a[i];
	sort(a + 1, a + n + 1, greater < int >() );
	int sum = 0;
	for(int i = 1; i <= n; i++){
		sum += a[i];
		if(sum >= m){
			cout << i ;
			return  0;
		}
		else sum --;
	}
	cout << -1;
}