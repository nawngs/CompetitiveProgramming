#include <bits/stdc++.h>

using namespace std;

const int NTEST = 10; //so luong test
const string TESTNAME = "TASK"; // ten bai

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int get_random(const int& mi, const int& ma){
    return rng() % (ma - mi + 1) + mi;
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
	srand(time(NULL)); // tranh lap test
	int maxx = get_random(10, 20);
	int maxy = get_random(10, 20);
	int k = get_random(10, (maxx * maxy / 5));
	cout << maxx << " " << maxy << " " << k << '\n';
}
