#pragma once
#include <algorithm>
#include <iostream>
#include <stack>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
	vector<vector<char>> reverseMatrix(vector<vector<char>>& matrix) {
		int rows = matrix.size();
		int cols = matrix[0].size();
		vector<vector<char>> ret_vec(cols, vector<char>(rows));
		for (int i = 0; i < rows; i++) {
			for (int j = 0; j < cols; j++) {
				ret_vec[cols - j - 1][i] = matrix[i][j];
			}
		}
		return ret_vec;
	}

	int maximalRectangle(vector<vector<char>>& matrix) {
		if (matrix.empty() || matrix[0].empty()) {
			return 0;
		}
		int rows = matrix.size();
		int cols = matrix[0].size();
		vector<vector<pair<int, int>>> dp(rows + 1, vector<pair<int, int>>(cols + 1, {0, 0}));
		int ret = 0;
		for (int i = 1; i < dp.size(); i++) {
			for (int j = 1; j < dp[0].size(); j++) {
				if (matrix[i - 1][j - 1] == '0') {
					continue;
				}
				/* 				int width = 0;
				                if (i >= 2 && j >= 2 && matrix[i - 2][j - 2] == '0') {
				                    width = 1;
				                } else {
				                    width = dp[i][j - 1].first + 1;
				                } */

				int width = std::min(dp[i][j - 1].first, dp[i - 1][j - 1].first) + 1;

				int height = dp[i - 1][j].second + 1;

				auto pair = std::make_pair(width, height);
				dp[i][j] = pair;
				if (width * height > ret) {
					ret = width * height;
				}
			}
		}

		for (int count = 0; count < 3; count++) {

			auto reverse_matrix = reverseMatrix(matrix);

			vector<vector<pair<int, int>>> dp1(reverse_matrix.size() + 1,
			                                   vector<pair<int, int>>(reverse_matrix[0].size() + 1, {0, 0}));

			for (int i = 1; i < dp1.size(); i++) {
				for (int j = 1; j < dp1[0].size(); j++) {
					if (reverse_matrix[i - 1][j - 1] == '0') {
						continue;
					}
					int width = 0;
					if (i >= 2 && j >= 2 && matrix[i - 2][j - 2] == '0') {
						width = 1;
					} else {
						width = dp1[i][j - 1].first + 1;
					}

					// int width = std::min(dp1[i][j - 1].first, dp1[i - 1][j - 1].first) + 1;

					int height = dp1[i - 1][j].second + 1;

					auto pair = std::make_pair(width, height);
					dp1[i][j] = pair;
					if (width * height > ret) {
						ret = width * height;
					}
				}
			}
		}

		return ret;
	}
};

vector<vector<char>> reverseMatrix(vector<vector<char>>& matrix) {
	int rows = matrix.size();
	int cols = matrix[0].size();
	vector<vector<char>> ret_vec(cols, vector<char>(rows));
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			ret_vec[cols - j - 1][i] = matrix[i][j];
		}
	}
	return ret_vec;
}

int main() {

	vector<vector<char>> matrix = {{'0', '0', '1', '0'}, {'0', '0', '1', '0'}, {'0', '0', '1', '0'},
	                               {'0', '0', '1', '1'}, {'0', '1', '1', '1'}, {'0', '1', '1', '1'},
	                               {'1', '1', '1', '1'}};
	Solution solution;
	auto rever_mat = reverseMatrix(matrix);

	auto ret = solution.maximalRectangle(matrix);

	cout << ret << endl;
	return 0;
}