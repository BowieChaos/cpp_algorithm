#pragma once

#include <algorithm>
#include <limits.h>
#include <vector>
using namespace std;
// https://www.nowcoder.com/practice/6fe0302a058a4e4a834ee44af88435c7?tpId=295&tags=&title=&difficulty=0&judgeStatus=0&rp=0&sourceUrl=%2Fexam%2Foj

class MinCost {
public:
	/**
	 * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
	 *
	 *
	 * @param cost int整型vector
	 * @return int整型
	 */
	int minCostClimbingStairs(vector<int>& cost) {
		// write code here
		if (cost.size() == 1) {
			return cost[0];
		}
		if (cost.size() == 2) {
			return min(cost[0], cost[1]);
		}
		vector<int> dp(cost.size() + 1, INT_MAX);
		dp[0] = 0;
		dp[1] = 0;
		for (size_t i = 2; i < dp.size(); i++) {
			dp[i] = std::min(dp[i - 1] + cost[i - 1], dp[i - 2] + cost[i - 2]);
		}
		return dp[cost.size()];
	}
};