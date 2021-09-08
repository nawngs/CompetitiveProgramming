//link: https://www.facebook.com/codingcompetitions/hacker-cup/2021/qualification-round/problems/A1

#include <bits/stdc++.h>

using namespace std;

const char vowel[5] = {'A', 'E', 'I', 'O', 'U'};

int t;

bool check_vowel(char ch) {
	for (int i = 0; i < 5; i++) if (ch == vowel[i]) return true;
	return false;
}

int sol() {
	string s;
	int cnt[33], cnt_vo = 0, cnt_co = 0;
	memset(cnt, 0, sizeof(cnt));
	int ans = 1e9;
	cin >> s;
	for (int i = 0; i < s.size(); i++) {
		cnt[s[i] - 'A'] ++;
		if (check_vowel(s[i])) cnt_vo ++;
		else cnt_co ++;
	}
	for (int i = 0; i <= 30; i++) {
		char ch = i + 'A';
		if (i > 'Z') break;
		if (check_vowel(ch)) {
			int tam = 0;
			tam = cnt_co + (cnt_vo - cnt[i]) * 2;
			ans = min(ans, tam);
		}
		else {
			int tam = 0;
			tam = cnt_vo + (cnt_co - cnt[i]) * 2;
			ans = min(ans, tam);
		}
	}
	return ans;
}

int main() {
	cin >> t;
	for (int test = 1; test <= t; test++) {
		int tam = sol();
		cout << "Case #" << test << ": " << tam << '\n';
	}
}

