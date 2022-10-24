#pragma once
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;
// 518. 零钱兑换 II
// https://leetcode.cn/problems/coin-change-ii/

class Solution {
public:
	int change(int amount, vector<int>& coins) {
		int n = coins.size();

		vector<vector<int>> dp(n + 1, vector<int>(amount + 1, 0));

		dp[0][0] = 1;
		for (int i = 1; i <= n; i++) {
			for (int j = 0; j <= amount; j++) {
				if (j < coins[i - 1]) {
					dp[i][j] = dp[i - 1][j];

				} else {
					dp[i][j] = dp[i - 1][j] + dp[i][j - coins[i - 1]];
				}
			}
		}
		return dp[n][amount];
	}
};

class Solution {
public:
	int change(int amount, vector<int>& coins) {
		vector<int> dp(amount + 1);
		dp[0] = 1;
		for (int& coin : coins) {
			for (int i = coin; i <= amount; i++) {
				dp[i] += dp[i - coin];
			}
		}
		return dp[amount];
	}
};