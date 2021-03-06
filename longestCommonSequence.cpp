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
	for(int c = 0; c < n + 1; c++) {
		for(int r = 0; r < m + 1; r++) {
			if(r == 0 || c == 0)
				LCS[r][c] = 0;
			else if(s1[r - 1] == s2[c - 1])
				LCS[r][c] = LCS[r - 1][c] + 1;
			else
				LCS[r][c] = max(LCS[r - 1][c], LCS[r][c - 1]);
		}
	}
	return LCS[m][n];
}


int main() {
	string s1, s2;
	cin >> s1 >> s2;
	cout << longestCommonSubsequence(s1, s2);
	return 0;
}
