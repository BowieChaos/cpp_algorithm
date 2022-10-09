#pragma once

#include <algorithm>
#include <limits.h>
#include <stack>
#include <string>
#include <vector>
using namespace std;

// NC59 矩阵的最小路径和
// https://www.nowcoder.com/practice/7d21b6be4c6b429bb92d219341c4f8bb?tpId=295&tags=&title=&difficulty=0&judgeStatus=0&rp=0&sourceUrl=%2Fexam%2Foj

class MinPathSum {
public:
	/**
	 *
	 * @param matrix int整型vector<vector<>> the matrix
	 * @return int整型
	 */
	int minPathSum(vector<vector<int>>& matrix) {
		// write code here
		if (matrix.empty() || matrix[0].empty()) {
			return 0;
		}
		int rows = matrix.size() + 1;
		int cols = matrix.size() + 1;
		vector<vector<int>> dp(rows, vector<int>(cols, INT_MAX));
		dp[1][1] = matrix[0][0];
		for (size_t row = 1; row < rows; row++) {
			for (size_t col = 1; col < cols; col++) {
				if (row == 1 && col == 1) {
					continue;
				}
				dp[row][col] = min(dp[row - 1][col], dp[row][col - 1]) +
				               matrix[row - 1][col - 1];
			}
		}
		return dp[rows - 1][cols - 1];
	}
};