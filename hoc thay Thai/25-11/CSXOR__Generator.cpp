#include <bits/stdc++.h>

using namespace std;

const int NTEST = 10; //so luong test
const string TESTNAME = "TASK"; // ten bai

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

long long get_random(long long l, long long h) {
    return l + rng() % (h - l + 1);
}

// get random(l , r) lay 1 so bat ki tu l den r

void make_test(){
	/*
	nhap input
	vd tao inp co n va day a[n]
	code:
	int n = get_random(l, r);
	for(int i = 1; i <= n; i++){
		int x;
		x = get_random(l, r);
		cout << x;
	}
	*/
}

int main(){
	srand(time(NULL));;
	int n = get_random(1, 500);
	cout << n << '\n';
	while (n -- ) cout << get_random(1, 100) << ' ';
}

