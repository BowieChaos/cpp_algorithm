#pragma once

#include <algorithm>
#include <limits.h>
#include <string>
#include <vector>
using namespace std;

// NC7 买卖股票的最好时机(一)
// https://www.nowcoder.com/practice/64b4262d4e6d4f6181cd45446a5821ec?tpId=295&tqId=625

class Stock1 {
public:
	/**
	 *
	 * @param prices int整型vector
	 * @return int整型
	 */

	int maxProfit_A(vector<int>& prices) {
		if (prices.empty()) {
			return 0;
		}
		int ret = 0;
		int min_price = INT_MAX;
		for (int i = 0; i < prices.size(); i++) {
			ret = max(ret, prices[i] - min_price);
			min_price = min(min_price, prices[i]);
		}
		return ret;
	}

	int maxProfit_D(vector<int>& prices) {
		int n = prices.size();
		vector<vector<int>> dp(n, vector<int>(2,
		                                      0)); // dp[i][0]表示某⼀天不持股到该天为⽌的最⼤收益，dp[i][1]
		                                           // 表示某天持股，到该天为⽌的最⼤收益
		                                           // dp[0][0] =0; //第⼀天不持股，总收益为0
		dp[0][1] = -prices[0];        //第⼀天持股，总收益为减去该天的股价
		for (int i = 1; i < n; i++) { //遍历后续每天，状态转移
			dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] + prices[i]);
			dp[i][1] = max(dp[i - 1][1], -prices[i]);
		}
		return dp[n - 1][0]; //最后⼀天不持股，到该天为⽌的最⼤收益
	}
	int maxProfit(vector<int>& prices) {
		// write code here
		if (prices.size() <= 1) {
			return 0;
		}
		vector<int> diff(prices.size() - 1);
		for (int i = 1; i < prices.size(); i++) {
			diff[i - 1] = prices[i] - prices[i - 1];
		}

		int ret = diff[0];
		vector<int> dp(diff.size());
		for (int i = 1; i < diff.size(); i++) {
			if (dp[i - 1] >= 0) {
				dp[i] = dp[i - 1] + diff[i];
			} else {
				dp[i] = diff[i];
			}
			ret = max(ret, dp[i]);
		}
		return ret >= 0 ? ret : 0;
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
		}
		return max(0, dp[prices.size() - 1][2]);
	}
};