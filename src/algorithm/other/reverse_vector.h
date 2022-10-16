#pragma once
#include <algorithm>
#include <unordered_set>
#include <vector>
using namespace std;

// NC110 旋转数组
// https://www.nowcoder.com/practice/e19927a8fd5d477794dac67096862042?tpId=295&tags=&title=&difficulty=0&judgeStatus=0&rp=0&sourceUrl=%2Fexam%2Foj

class ReverseVec {
public:
	/**
	 * 旋转数组
	 * @param n int整型 数组长度
	 * @param m int整型 右移距离
	 * @param a int整型vector 给定数组
	 * @return int整型vector
	 */
	vector<int> solve(int n, int m, vector<int>& a) {
		// write code here
		m = m % n;
		std::reverse(a.begin(), a.end());
		std::reverse(a.begin(), a.begin() + m);
		std::reverse(a.begin() + m, a.end());
		return a;
	}
};