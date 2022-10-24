#pragma once

#include <algorithm>
#include <limits.h>
#include <stack>
#include <string>
#include <vector>
using namespace std;

// NC145 01背包
// https://www.nowcoder.com/practice/2820ea076d144b30806e72de5e5d4bbf?tpId=117&tqId=37856&rp=1&ru=/exam/oj&qru=/exam/oj&sourceUrl=%2Fexam%2Foj%3Fpage%3D3%26tab%3D%25E7%25AE%2597%25E6%25B3%2595%25E7%25AF%2587%26topicId%3D117&difficulty=undefined&judgeStatus=undefined&tags=&title=

class Solution {
public:
	/**
	 * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
	 * 计算01背包问题的结果
	 * @param V int整型 背包的体积
	 * @param n int整型 物品的个数
	 * @param vw int整型vector<vector<>> 第一维度为n,第二维度为2的二维数组,vw[i][0],vw[i][1]分别描述i+1个物品的vi,wi
	 * @return int整型
	 */
	int knapsack(int V, int n, vector<vector<int>>& vw) {
		// write code here
		if (V <= 0 || vw.empty() || vw[0].empty()) {
			return 0;
		}
		vector<vector<int>> dp(n + 1, vector<int>(V + 1, 0));

		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= V; j++) {
				if (j < vw[i - 1][0]) {
					dp[i][j] = dp[i - 1][j];
				} else {
					dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - vw[i - 1][0]] + vw[i - 1][1]);
				}
			}
		}
		return dp[n][V];
	}
};