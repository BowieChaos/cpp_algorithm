#pragma once

#include <algorithm>
#include <limits.h>
#include <string>
#include <vector>
using namespace std;

// https://www.nowcoder.com/practice/28970c15befb4ff3a264189087b99ad4?tpId=295&tqId=2294660&ru=%2Fexam%2Foj&qru=%2Fta%2Fformat-top101%2Fquestion-ranking&sourceUrl=%2Fexam%2Foj

class RegexMatch {
public:
	/**
	 * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
	 *
	 *
	 * @param str string字符串
	 * @param pattern string字符串
	 * @return bool布尔型
	 */
	bool match(string str, string pattern) {
		int rows = str.size() + 1;
		int cols = pattern.size() + 1;
		vector<vector<bool>> dp(rows, vector<bool>(cols, false));
		dp[0][0] = true;
		for (size_t row = 0; row < rows; row++) {
			for (size_t col = 0; col < cols; col++) {
				if (col == 0) {
					continue;
				}
				if (pattern[col - 1] != '*') {
					if (row > 0 && (str[row - 1] == pattern[col - 1] ||
					                pattern[col - 1] == '.')) {
						dp[row][col] = dp[row - 1][col - 1];
					}
				} else {
					if (col >= 2) {
						dp[row][col] = (dp[row][col - 2] || dp[row][col]);
					}

					if (row >= 1 && col >= 2 &&
					    (str[row - 1] == pattern[col - 2] ||
					     pattern[col - 2] == '.')) {
						dp[row][col] = dp[row - 1][col] || dp[row][col];
					}
				}
			}
		}
		return dp[rows - 1][cols - 1];
	}

	bool match_recurse(string str, string pattern) {
		// write code here
		return matchCore(str, 0, pattern, 0);
	}
	bool matchCore(const string& str, int index1, const string& pattern,
	               int pIndex) {
		if (index1 == str.size()) {
			if (pIndex == pattern.size() || judgeP(pattern.substr(pIndex)))
				return true;
			else
				return false;
		}
		if (pIndex == pattern.size() && index1 != str.size())
			return false;
		if (pIndex < pattern.size() - 1) {
			if (pattern[pIndex + 1] != '*') {
				if (pattern[pIndex] != '.' && pattern[pIndex] != str[index1])
					return false;
				else
					return matchCore(str, index1 + 1, pattern, pIndex + 1);
			} else {
				if (pattern[pIndex] == '.') {
					return matchCore(str, index1 + 1, pattern, pIndex) ||
					       matchCore(str, index1, pattern, pIndex + 2);
				} else {
					if (pattern[pIndex] != str[index1])
						return matchCore(str, index1, pattern, pIndex + 2);
					else
						return matchCore(str, index1 + 1, pattern, pIndex) ||
						       matchCore(str, index1, pattern, pIndex + 2);
				}
			}
		} else {
			if (pattern[pIndex] == '.') {
				return matchCore(str, index1 + 1, pattern, pIndex + 1);
			} else {
				if (pattern[pIndex] != str[index1])
					return false;
				else
					return matchCore(str, index1 + 1, pattern, pIndex + 1);
			}
		}
	}
	bool judgeP(const string& pattern) {
		for (int i = 0; i < pattern.size(); i++) {
			if (pattern[i] != '*') {
				if (i < pattern.size() - 1 && pattern[i + 1] != '*') {
					return false;
				}
				if (i == pattern.size() - 1)
					return false;
			}
		}
		return true;
	}
};