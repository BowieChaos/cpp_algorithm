#pragma once

#include <algorithm>
#include <limits.h>
#include <string>
#include <vector>
using namespace std;

// BM82 买卖股票的最好时机(三)
// https://www.nowcoder.com/practice/4892d3ff304a4880b7a89ba01f48daf9?tpId=295&tqId=1073471&ru=%2Fexam%2Foj&qru=%2Fta%2Fformat-top101%2Fquestion-ranking&sourceUrl=%2Fexam%2Foj

class Stock3 {
public:
	/**
	 * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
	 * 两次交易所能获得的最大收益
	 * @param prices int整型vector 股票每一天的价格
	 * @return int整型
	 */
	int maxProfit(vector<int>& prices) {
		// write code here
		if (prices.size() <= 1) {
			return 0;
		}

		vector<int> dp1(prices.size(), 0);
		vector<int> dp2(prices.size(), 0);
		int min_price = prices[0];
		for (int i = 1; i < prices.size(); i++) {
			min_price = min(min_price, prices[i]);
			dp1[i] = max(dp1[i - 1], prices[i] - min_price);
		}

		int max_price = prices[prices.size() - 1];
		for (int i = prices.size() - 2; i >= 0; i--) {
			max_price = max(prices[i], max_price);
			dp2[i] = max(dp2[i + 1], max_price - prices[i]);
		}

		int ret = 0;
		for (int i = 0; i < dp1.size(); i++) {
			ret = max(ret, dp1[i] + dp2[i]);
		}
		return ret;
	}
};

class Solution {
public:
	/**
	 * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
	 * 两次交易所能获得的最大收益
	 * @param prices int整型vector 股票每一天的价格
	 * @return int整型
	 */
	int maxProfit(vector<int>& prices) {
		// write code here
		if (prices.empty()) {
			return 0;
		}

		int ret = 0;
		vector<vector<int>> dp(prices.size(), vector<int>(5, -1000000));

		dp[0][0] = 0;
		dp[0][1] = -prices[0];

		for (int i = 1; i < prices.size(); i++) {
			dp[i][0] = dp[i - 1][0];
			dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] - prices[i]);
			dp[i][2] = max(dp[i - 1][2], dp[i - 1][1] + prices[i]);
			dp[i][3] = max(dp[i - 1][3], dp[i - 1][2] - prices[i]);
			dp[i][4] = max(dp[i - 1][4], dp[i - 1][3] + prices[i]);
		}
		return max(0, max(dp[prices.size() - 1][2], dp[prices.size() - 1][4]));
	}
};