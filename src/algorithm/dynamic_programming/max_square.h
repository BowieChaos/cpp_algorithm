#pragma once

#include <algorithm>
#include <limits.h>
#include <stack>
#include <string>
#include <vector>
using namespace std;

// NC108 最大正方形
// https://www.nowcoder.com/practice/0058c4092cec44c2975e38223f10470e?tpId=117&tqId=37832&rp=1&ru=/exam/oj&qru=/exam/oj&sourceUrl=%2Fexam%2Foj%3FjudgeStatus%3D3%26page%3D1%26pageSize%3D50%26search%3D%26tab%3D%25E7%25AE%2597%25E6%25B3%2595%25E7%25AF%2587%26topicId%3D117&difficulty=undefined&judgeStatus=3&tags=&title=

class Solution {
public:
	/**
	 * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
	 *
	 * 最大正方形
	 * @param matrix char字符型vector<vector<>>
	 * @return int整型
	 */
	int solve(vector<vector<char>>& matrix) {
		// write code here
		if (matrix.empty() || matrix[0].empty()) {
			return 0;
		}
		int rows = matrix.size();
		int cols = matrix[0].size();
		vector<vector<int>> dp(rows + 1, vector<int>(cols + 1, 0));
		int ret = 0;

		for (int i = 1; i < rows + 1; i++) {
			for (int j = 1; j < cols + 1; j++) {
				if (matrix[i - 1][j - 1] == '1') {
					int tmp = std::min(std::min(dp[i - 1][j - 1], dp[i - 1][j]), dp[i][j - 1]);
					dp[i][j] = tmp + 1;
					if (dp[i][j] > ret) {
						ret = dp[i][j];
					}
				}
			}
		}
		return ret * ret;
	}
};