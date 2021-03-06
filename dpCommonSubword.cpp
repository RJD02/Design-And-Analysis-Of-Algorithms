#include<bits/stdc++.h>
using namespace std;

#define endl "\n"

int dpCommonSubwordLength(string s1, string s2) {
	if(s1.length() == 0 || s2.length() == 0)
		return 0;
	if(s1 == s2)
		return s1.length();
	int m = s1.length();
	int n = s2.length();
	int LCW[m + 1][n + 1];
	int max_LCW = 0;
	for(int r = 0; r <= m + 1; r++) {
		LCW[r][n + 1] = 0;
	}
	for(int c = 0; c <= n + 1; c++) {
		LCW[m + 1][c] = 0;
	}
	for(int c = n; c >= 0; --c) {
		for(int r = m; r >= 0; --r) {
			if(s1[r] == s2[c])
				LCW[r][c] = 1 + LCW[r + 1][c + 1];
			else
				LCW[r][c] = 0;
			max_LCW = max(LCW[r][c], max_LCW);
			cout << LCW[r][c] << " ";
		}
		cout << endl;
	}
	return max_LCW;
}

int main() {
	string s1, s2;
	cin >> s1 >> s2;
	cout << dpCommonSubwordLength(s1, s2);
	return 0;
}
