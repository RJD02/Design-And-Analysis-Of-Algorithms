#include<bits/stdc++.h>
using namespace std;

#define endl "\n"

int dpCommonSubwordLengh(string s1, string s2) {
	if(s1.length() == 0 || s2.length() == 0)
		return 0;
	if(s1 == s2)
		return s1.length();
	int m = s1.length();
	int n = s2.length();
	int LCW[m + 1][n + 1];
	int max_LCW = 0;
	/* for(int i = 0; i < m + 1; i++) {
	 *   LCW[i][n + 1] = 0;
	 * }
	 * for(int i = 0; i < n + 1; i++) {
	 *   LCW[m + 1][i] = 0;
	 * } */
	for(int c = 0; c < n + 1; ++c) {
		for(int r = 0; r < m + 1; ++r) {
			if(r == 0 || c == 0)
				LCW[r][c] = 0;
			else if(s1[r - 1] == s2[c - 1])
				LCW[r][c] = 1 + LCW[r - 1][c - 1];
			else
				LCW[r][c] = 0;
			// max_LCW = max(max_LCW, LCW[r][c]);
			if(max_LCW < LCW[r][c])
				max_LCW = LCW[r][c];
			cout << LCW[r][c] << " ";
		}
		cout << endl;
	}
	return max_LCW;
}

int main() {
	string s1, s2;
	cin >> s1 >> s2;
	cout << dpCommonSubwordLengh(s1, s2);
	return 0;
}
