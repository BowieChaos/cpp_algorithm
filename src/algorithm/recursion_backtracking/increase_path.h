#pragma once
#include <algorithm>
#include <set>
#include <vector>
using namespace std;

// https://www.nowcoder.com/practice/7a71a88cdf294ce6bdf54c899be967a2?tpId=295&tqId=1008753&ru=%2Fexam%2Foj&qru=%2Fta%2Fformat-top101%2Fquestion-ranking&sourceUrl=%2Fexam%2Foj

class IncreasePath {
public:
	/**
	 * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
	 * 递增路径的最大长度
	 * @param matrix int整型vector<vector<>> 描述矩阵的每个数
	 * @return int整型
	 */
	vector<vector<int>> direction{{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

	int solve(vector<vector<int>>& matrix) {
		// write code here
		if (matrix.empty() || matrix[0].empty()) {
			return 0;
		}
		int ret = 0;
		int pre = -1;
		int count = 0;
		int rows = matrix.size();
		int cols = matrix[0].size();
		for (size_t row = 0; row < rows; row++) {
			for (size_t col = 0; col < cols; col++) {
				dfs(matrix, row, col, 0, -1, ret);
			}
		}
		return ret;
	}

	void dfs(vector<vector<int>>& matrix, int row, int col, int count, int pre,
	         int& ret) {
		if (row < 0 || row >= matrix.size() || col < 0 ||
		    col >= matrix[0].size() || matrix[row][col] <= pre) {
			return;
		}
		count++;
		ret = max(ret, count);
		for (auto& v : direction) {
			int tmp_row = v[0] + row;
			int tmp_col = v[1] + col;
			dfs(matrix, tmp_row, tmp_col, count, matrix[row][col], ret);
		}
		return;
	}
};