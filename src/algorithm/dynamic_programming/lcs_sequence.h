#pragma once

#include <algorithm>
#include <limits.h>
#include <stack>
#include <string>
#include <vector>
using namespace std;

// https://www.nowcoder.com/practice/6d29638c85bb4ffd80c020fe244baf11?tpId=295&tqId=991075&ru=/exam/oj&qru=/ta/format-top101/question-ranking&sourceUrl=%2Fexam%2Foj
class LCSSeq {
public:
	/**
	 * longest common subsequence
	 * @param s1 string字符串 the string
	 * @param s2 string字符串 the string
	 * @return string字符串
	 */
	string LCS(string s1, string s2) {
		// write code here
		if (s1.empty() || s2.empty()) {
			return "-1";
		}
		int rows = s1.size() + 1;
		int cols = s2.size() + 1;
		vector<vector<int>> dp(rows, vector<int>(cols, 0));
		for (size_t row = 1; row < rows; row++) {
			for (size_t col = 1; col < cols; col++) {
				if (s1[row - 1] == s2[col - 1]) {
					dp[row][col] = dp[row - 1][col - 1] + 1;
				} else {
					dp[row][col] = max(dp[row - 1][col], dp[row][col - 1]);
				}
			}
		}

		string ret;
		int i = rows - 1;
		int j = cols - 1;
		while (dp[i][j] != 0) {
			if (dp[i][j] == dp[i - 1][j]) {
				i--;
			} else if (dp[i][j] == dp[i][j - 1]) {
				j--;
			} else if (dp[i][j] == dp[i - 1][j - 1] + 1) {
                ret.push_back(s1[i-1]);
                i--;
                j--;
            }
		}
        if (ret.empty()) {
            return "-1";
        }
        reverse(ret.begin(), ret.end());
        return ret;
	}
};