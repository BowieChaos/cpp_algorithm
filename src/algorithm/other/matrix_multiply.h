#pragma once
#include <deque>
#include <unordered_map>
#include <vector>
using namespace std;

// NC143 矩阵乘法
// https://www.nowcoder.com/practice/bf358c3ac73e491585943bac94e309b0?tpId=117&tqId=37854&rp=1&ru=/exam/oj&qru=/exam/oj&sourceUrl=%2Fexam%2Foj%3Fpage%3D3%26tab%3D%25E7%25AE%2597%25E6%25B3%2595%25E7%25AF%2587%26topicId%3D117&difficulty=undefined&judgeStatus=undefined&tags=&title=

class Solution {
public:
	/**
	 * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
	 *
	 * @param a int整型vector<vector<>> 第一个矩阵
	 * @param b int整型vector<vector<>> 第二个矩阵
	 * @return int整型vector<vector<>>
	 */
	vector<vector<int>> solve(vector<vector<int>>& a, vector<vector<int>>& b) {
		// write code here
		vector<vector<int>> ret;
		if (a.empty() || a[0].empty() || b.empty() || b[0].empty()) {
			return ret;
		}
		int n = a.size();
		ret = vector<vector<int>>(n, vector<int>(n, 0));
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				int tmp = 0;
				for (int k = 0; k < n; k++) {
					tmp += a[i][k] * b[k][j];
				}
				ret[i][j] = tmp;
				tmp = 0;
			}
		}
		return ret;
	}
};