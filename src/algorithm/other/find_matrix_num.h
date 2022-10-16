#pragma once

#include <algorithm>
#include <vector>
using namespace std;

// NC86 矩阵元素查找
// https://www.nowcoder.com/practice/3afe6fabdb2c46ed98f06cfd9a20f2ce?tpId=117&tags=&title=&difficulty=0&judgeStatus=0&rp=1&sourceUrl=%2Fexam%2Foj%3Fpage%3D2%26tab%3D%25E7%25AE%2597%25E6%25B3%2595%25E7%25AF%2587%26topicId%3D117

class Solution {
public:
	vector<int> findElement(vector<vector<int> > mat, int n, int m, int x) {
		// write code here
		int row = n - 1;
		int col = 0;
		vector<int> ret;
		while (row >= 0 && col < m) {
			if (mat[row][col] == x) {
				ret.push_back(row);
				ret.push_back(col);
				break;
			} else if (mat[row][col] > x) {
				row--;
			} else {
				col++;
			}
		}
		return ret;
	}
};