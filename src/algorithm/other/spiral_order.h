#pragma once
#include <algorithm>
#include <unordered_set>
#include <vector>
using namespace std;

// https://www.nowcoder.com/practice/7edf70f2d29c4b599693dc3aaeea1d31?tpId=295&tqId=693&ru=/exam/oj&qru=/ta/format-top101/question-ranking&sourceUrl=%2Fexam%2Foj
class Spiral {
public:
	vector<vector<int>> directions{{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

	vector<int> spiralOrder(vector<vector<int>>& matrix) {
		vector<int> ret;
		if (matrix.empty() || matrix[0].empty()) {
			return ret;
		}
		int top = 0;
		int bottom = matrix.size() - 1;
		int left = 0;
		int right = matrix[0].size() - 1;
		while (top < (matrix.size() + 1) / 2 &&
		       left < (matrix[0].size() + 1) / 2) {
			for (int i = left; i <= right; i++) {
				ret.emplace_back(matrix[top][i]);
			}

			for (int i = top + 1; i <= bottom; i++) {
				ret.emplace_back(matrix[i][right]);
			}

			for (int i = right - 1; bottom != top && i >= left; i--) {
				ret.emplace_back(matrix[bottom][i]);
			}

			for (int i = bottom - 1; left != right && i >= top + 1; i--) {
				ret.emplace_back(matrix[i][left]);
			}
			++top;
			--bottom;
			++left;
			--right;
		}

		return ret;
	}
};