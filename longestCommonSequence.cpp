#include<bits/stdc++.h>
using namespace std;

#define endl "\n"

int longestCommonSubsequence(string s1, string s2) {
	if(s1.length() == 0 || s2.length() == 0)
		return 0;
	if(s1 == s2)
		return s1.length();
	int m = s1.length();
	int n = s2.length();
	int LCS[m + 1][n + 1];
	for(int i = 0; i < m + 2; i++) {
		LCS[i][n + 1] = 0;
	}
	for(int i = 0; i < n + 2; i++) {
		LCS[m + 1][i] = 0;
	}
	for(int c = n; c >= 0; c--) {
		for(int r = m; r >= 0; r--) {
			if(s1[r] == s2[c])
				LCS[r][c] = 1 + LCS[r + 1][c + 1];
			else
				LCS[r][c] = max(LCS[r + 1][c], LCS[r][c + 1]);
			// cout << LCS[r][c] << " ";
		}
		// cout << endl;
	}
	for(int i = 0; i < n + 1; i++) {
		for(int j = 0; j < m + 1; j++) {
			cout << LCS[i][j] << " ";
		}
		cout << endl;
	}
	return LCS[0][0] - 1;
}


int main() {
	string s1, s2;
	cin >> s1 >> s2;
	cout << longestCommonSubsequence(s1, s2);
	return 0;
}
