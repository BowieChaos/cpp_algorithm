#pragma once

#include <algorithm>
#include <limits.h>
#include <string>
#include <vector>
using namespace std;

// NC7 买卖股票的最好时机(一)
// https://www.nowcoder.com/practice/c5fbf7325fbd4c0ea3d0c3ea6bc6cc79?tpId=295&tags=&title=&difficulty=0&judgeStatus=0&rp=0&sourceUrl=%2Fexam%2Foj

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
		vector<vector<int> > dp(n, vector<int>(2,
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