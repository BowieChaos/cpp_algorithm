#pragma once

#include <algorithm>
#include <limits.h>
#include <string>
#include <vector>
using namespace std;

// https://www.nowcoder.com/practice/c5fbf7325fbd4c0ea3d0c3ea6bc6cc79?tpId=295&tags=&title=&difficulty=0&judgeStatus=0&rp=0&sourceUrl=%2Fexam%2Foj

class Stock1 {
public:
	/**
	 *
	 * @param prices int整型vector
	 * @return int整型
	 */
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