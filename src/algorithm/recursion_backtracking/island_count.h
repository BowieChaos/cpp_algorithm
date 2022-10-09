#pragma once
#include <algorithm>
#include <set>
#include <vector>
using namespace std;

// NC109 岛屿数量
// https://www.nowcoder.com/practice/0c9664d1554e466aa107d899418e814e?tpId=295&tqId=2188893&ru=%2Fexam%2Foj&qru=%2Fta%2Fformat-top101%2Fquestion-ranking&sourceUrl=%2Fexam%2Foj

class Island {
public:
	/**
	 * 判断岛屿数量
	 * @param grid char字符型vector<vector<>>
	 * @return int整型
	 */
	vector<vector<int>> direction{{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
	int solve_1(vector<vector<char>>& grid) {
		// write code here
		int count = 0;
		if (grid.empty() || grid[0].empty()) {
			return count;
		}
		int rows = grid.size();
		int cols = grid[0].size();
		vector<vector<bool>> hasVisited(rows, vector<bool>(cols, false));
		for (size_t row = 0; row < rows; row++) {
			for (size_t col = 0; col < cols; col++) {
				if (!hasVisited[row][col] && grid[row][col] == '1') {
					count++;
					traverse(grid, hasVisited, row, col);
				}
			}
		}
		return count;
	}

	void traverse(vector<vector<char>>& grid, vector<vector<bool>>& hasVisited,
	              int row, int col) {
		if (row < 0 || row >= grid.size() || col < 0 || col >= grid[0].size() ||
		    hasVisited[row][col] || grid[row][col] == '0') {
			return;
		}
		hasVisited[row][col] = true;
		for (auto& v : direction) {
			traverse(grid, hasVisited, row + v[0], col + v[1]);
		}
		return;
	}
};