#include<bits/stdc++.h>
using namespace std;
long long n , c;
long long x[105] , y[105] , sm[105] , pm[105] , sl[105] , pl[105] , ans;
bool check(long long f,long long v){
	for(long long i = 1 ; i <= n ; i++){
		long long minn=1e9;
		for(long long j = f * x[i] - y[i]; j < (f + 1) * x[i] - y[i] ; j++){
			for(long long t = 0 ; t <= j ; t += sl[i] ){
				long long g = t * pl[i] + ((j - t * pl[i]) / sm[i]) * sm[i] * pm[i];
				minn = min(minn , g);
			}
		}
		v -= minn;
		if( v < 0) return false;
	}
return true;
}
int main(){

	cin >> n >> c;
	for(long long i = 1 ; i <= n ; i++){
		cin >> x[i] >> y[i] >> sm[i] >> pm[i] >> sl[i] >> pl[i];
	}
	long long l = 1 , r = 1e9 , mid;
	while( l <= r ){
		mid = ( l + r ) / 2;
		if( check(mid , c) ){
			ans = mid;
			l = mid + 1;
		}else r = mid - 1;
	}
	cout << ans;
}