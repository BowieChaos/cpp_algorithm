#pragma once

#include <algorithm>
#include <limits.h>
#include <stack>
#include <string>
#include <vector>
using namespace std;

// https://www.nowcoder.com/practice/f33f5adc55f444baa0e0ca87ad8a6aac?tpId=295&tqId=991075&ru=%2Fexam%2Foj&qru=%2Fta%2Fformat-top101%2Fquestion-ranking&sourceUrl=%2Fexam%2Foj

class LCSSubstr {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * longest common substring
     * @param str1 string字符串 the string
     * @param str2 string字符串 the string
     * @return string字符串
     */
	string LCS(string s1, string s2) {
		// write code here
		if (s1.empty() || s2.empty()) {
			return "";
		}
		int rows = s1.size() + 1;
		int cols = s2.size() + 1;
		vector<vector<int>> dp(rows, vector<int>(cols, 0));
        int max_len = 0;
        int max_row = 0;
        int max_col = 0;
		for (size_t row = 1; row < rows; row++) {
			for (size_t col = 1; col < cols; col++) {
				if (s1[row - 1] == s2[col - 1]) {
					dp[row][col] = dp[row - 1][col - 1] + 1;
                    if (dp[row][col] > max_len) {
                        max_len = dp[row][col];
                        max_row = row;
                        max_col = col;
                    }
				}
			}
		}
        if (max_len == 0) {
            return "";
        }


		string ret;
		int i = max_row;
		int j = max_col;
		while (dp[i][j] != 0) {
            if (dp[i][j] == dp[i - 1][j - 1] + 1) {
                ret.push_back(s1[i-1]);
                i--;
                j--;
            }
		}
        if (ret.empty()) {
            return "";
        }
        reverse(ret.begin(), ret.end());
        return ret;
	}
};