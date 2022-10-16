#pragma once

#include <algorithm>
#include <limits.h>
#include <stack>
#include <string>
#include <vector>
using namespace std;

// NC116 把数字翻译成字符串
// https://www.nowcoder.com/practice/046a55e6cd274cffb88fc32dba695668?tpId=295&tags=&title=&difficulty=0&judgeStatus=0&rp=0&sourceUrl=%2Fexam%2Foj

class NumToString {
public:
	/**
	 * 解码
	 * @param nums string字符串 数字串
	 * @return int整型
	 */
	int solve(string nums) {
		// write code here
		if (nums.empty()) {
			return 0;
		}
		vector<int> dp(nums.size() + 1, 1);
		for (size_t i = 1; i < dp.size(); i++) {
			if (i == 1) {
				dp[i] == 1;
				continue;
			}
			int s = getInt(nums[i - 2], nums[i - 1]);
			if ((s > 10 && s < 20) || (s > 20 && s < 27)) {
				dp[i] = dp[i - 1] + dp[i - 2];
			} else if (s % 10 == 0 && s >= 30) {
				return 0;
			} else {
				dp[i] = dp[i - 1];
			}
		}
		return dp[nums.size()];
	}

	int getInt(char l, char r) {
		int i = l - '0';
		int j = r - '0';
		return i * 10 + j;
	}
};