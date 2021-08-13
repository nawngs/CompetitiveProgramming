#include <bits/stdc++.h>

using namespace std;

long long a, b, c, mod;

vector < long long > temp;

long long nhan(long long a,long long b){
    if (b == 0) 
        return 0;
    long long t = nhan(a, b / 2);     	
    t = (t + t) % mod; 
    if (b % 2 == 1) t = (t + a) % mod;
    return t;
} 
int main(){
	cin >> a >> b >> c >> mod;
	temp.push_back(a);
	temp.push_back(b);
	temp.push_back(c);
	//cout << 0 % m << '\n';
	sort(temp.begin(), temp.end());
	if(temp[1] < 0){
		cout << nhan(abs(temp[1]), abs(temp[0]));
	}
	else cout << nhan(temp[1], temp[2]);
}