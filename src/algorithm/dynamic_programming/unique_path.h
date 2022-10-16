#pragma once

#include <algorithm>
#include <limits.h>
#include <stack>
#include <string>
#include <vector>
using namespace std;

// NC34 不同路径的数目(一)
// https://www.nowcoder.com/practice/166eaff8439d4cd898e3ba933fbc6358?tpId=295&tqId=991075&ru=%2Fexam%2Foj&qru=%2Fta%2Fformat-top101%2Fquestion-ranking&sourceUrl=%2Fexam%2Foj

class UniquePath {
public:
	/**
	 *
	 * @param m int整型
	 * @param n int整型
	 * @return int整型
	 */
	int uniquePaths(int m, int n) {
		// write code here
		if (m <= 1 || n <= 1) {
			return 0;
		}
		vector<vector<int>> dp(m, vector<int>(n, 1));

		for (size_t row = 0; row < m; row++) {
			for (size_t col = 0; col < n; col++) {
				if (row == 0 || col == 0) {
					continue;
				}
				dp[row][col] = dp[row - 1][col] + dp[row][col - 1];
			}
		}
		return dp[m - 1][n - 1];
	}

	int uniquePaths_recurse(int m, int n) {
		// write code here
		if (m == 1 || n == 1) {
			return 1;
		}
		return uniquePaths_recurse(m - 1, n) + uniquePaths_recurse(m, n - 1);
	}
};