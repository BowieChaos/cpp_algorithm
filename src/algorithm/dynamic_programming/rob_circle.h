#pragma once

#include <algorithm>
#include <limits.h>
#include <string>
#include <vector>
using namespace std;
// https://www.nowcoder.com/practice/c5fbf7325fbd4c0ea3d0c3ea6bc6cc79?tpId=295&tags=&title=&difficulty=0&judgeStatus=0&rp=0&sourceUrl=%2Fexam%2Foj

class RobCircle {
public:
	int rob(vector<int>& nums) {
		// dp[i]表示长度为i的数组，最多能偷取多少钱
		vector<int> dp(nums.size() + 1, 0);
		//选择偷了第一家
		dp[1] = nums[0];
		//最后一家不能偷
		for (int i = 2; i < nums.size(); i++)
			//对于每家可以选择偷或者不偷
			dp[i] = max(dp[i - 1], nums[i - 1] + dp[i - 2]);
		int res = dp[nums.size() - 1];
		//清除dp数组，第二次循环
		dp.clear();
		//不偷第一家
		dp[1] = 0;
		//可以偷最后一家
		for (int i = 2; i <= nums.size(); i++)
			//对于每家可以选择偷或者不偷
			dp[i] = max(dp[i - 1], nums[i - 1] + dp[i - 2]);
		//选择最大值
		return max(res, dp[nums.size()]);
	}
};
