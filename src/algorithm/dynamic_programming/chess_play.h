#pragma once

#include <algorithm>
#include <limits.h>
#include <stack>
#include <string>
#include <vector>
using namespace std;

// 丢棋子问题 https://www.cnblogs.com/willwuss/p/12256475.html
// https://www.nowcoder.com/practice/d1418aaa147a4cb394c3c3efc4302266?tpId=117&tqId=37844&rp=1&ru=/exam/oj&qru=/exam/oj&sourceUrl=%2Fexam%2Foj%3FjudgeStatus%3D3%26page%3D1%26pageSize%3D50%26search%3D%26tab%3D%25E7%25AE%2597%25E6%25B3%2595%25E7%25AF%2587%26topicId%3D117&difficulty=undefined&judgeStatus=3&tags=&title=

class ChessFlip {
public:
	/**
	 * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
	 * 返回最差情况下扔棋子的最小次数
	 * @param n int整型 楼层数
	 * @param k int整型 棋子数
	 * @return int整型
	 */
	int solve(int n, int k) {
		// write code here
		if (n < 1 || k < 1)
			return 0;
		vector<int> dp(k);
		int res = 0;
		while (true) {
			++res;
			int previous = 0;
			for (int i = 0; i < dp.size(); ++i) {
				int tmp = dp[i];
				dp[i] = dp[i] + previous + 1;
				previous = tmp;
				if (dp[i] >= n) {
					return res;
				}
			}
		}
	}
};