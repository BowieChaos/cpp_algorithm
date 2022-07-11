#pragma once

#include <algorithm>
#include <limits.h>
#include <string>
#include <vector>
using namespace std;

// https://www.nowcoder.com/practice/28970c15befb4ff3a264189087b99ad4?tpId=295&tqId=2294660&ru=%2Fexam%2Foj&qru=%2Fta%2Fformat-top101%2Fquestion-ranking&sourceUrl=%2Fexam%2Foj

class EditDistance {
public:
	/**
	 * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
	 *
	 *
	 * @param str1 string字符串
	 * @param str2 string字符串
	 * @return int整型
	 */
	int editDistance(string str1, string str2) {
		if (str1.empty()) {
			return str2.size();
		}
		if (str2.empty()) {
			return str1.size();
		}

		int rows = str1.size() + 1;
		int cols = str2.size() + 1;
		vector<vector<int>> dp(rows, vector<int>(cols, 1002));

		for (size_t row = 0; row < rows; row++) {
			for (size_t col = 0; col < cols; col++) {
				if (row == 0 || col == 0) {
					dp[row][col] = max(row, col);
					continue;
				}

				if (str1[row - 1] == str2[col - 1]) {
					dp[row][col] = dp[row - 1][col - 1];
				} else {
					dp[row][col] =
					    1 + min(dp[row - 1][col - 1],
					            min(dp[row - 1][col], dp[row][col - 1]));
				}
			}
		}
		return dp[rows - 1][cols - 1];
	}
};