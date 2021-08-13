#include <bits/stdc++.h>
#define ll long long

using namespace std;

const ll MOD = 1e9 + 7;
const ll nmax = 1e5;

ll cnt_0[100005], cnt_1[100005], cnt_l_0[100005], cnt_l_1[100005], cnt_r_1[100005];

void build_cnt_0(){
	cnt_0[1] = 0;
	cnt_1[1] = 0;
	cnt_r_1[1] = 1;
	cnt_l_0[1] = 1;
	cnt_l_1[1] = 0;
	for(int i = 2; i <= nmax; i++){
		cnt_0[i] = (cnt_0[i - 1] + cnt_1[i - 1]) % MOD;
		cnt_1[i] = cnt_0[i];
		cnt_0[i] = (cnt_0[i] + cnt_r_1[i - 1] + cnt_l_0[i - 1] - 1) % MOD;
		cnt_l_0[i] = cnt_l_1[i - 1];
		cnt_l_1[i] = cnt_l_0[i - 1];
		cnt_r_1[i] = cnt_r_1[i - 1];

	}
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("PAIRZERO.inp", "r", stdin);
	freopen("PAIRZERO.out", "w", stdout);
	build_cnt_0();
	int n;
	while(cin >> n){
		cout << cnt_0[n] << '\n';
	}
}