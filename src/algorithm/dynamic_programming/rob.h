#pragma once

#include <algorithm>
#include <limits.h>
#include <string>
#include <vector>
using namespace std;
// BM78 打家劫舍(一)
// https://www.nowcoder.com/practice/c5fbf7325fbd4c0ea3d0c3ea6bc6cc79?tpId=295&tags=&title=&difficulty=0&judgeStatus=0&rp=0&sourceUrl=%2Fexam%2Foj

class Rob {
public:
	/**
	 * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
	 *
	 *
	 * @param nums int整型vector
	 * @return int整型
	 */
	int rob(vector<int>& nums) {
		// write code here
		if (nums.empty()) {
			return 0;
		}
		vector<int> dp(nums.size() + 1, 0);
		for (size_t i = 1; i < dp.size(); i++) {
			if (i == 1) {
				dp[i] = nums[i - 1];
				continue;
			}
            dp[i] = max(dp[i-1], dp[i-2]+nums[i-1]);
		}
        return dp[nums.size()];
	}
};