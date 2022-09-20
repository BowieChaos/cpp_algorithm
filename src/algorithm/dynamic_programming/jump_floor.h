#pragma once

// NC68 跳台阶
// https://www.nowcoder.com/practice/8c82a5b80378478f9484d87d1c5f12a4?tpId=295&tags=&title=&difficulty=0&judgeStatus=0&rp=0&sourceUrl=%2Fexam%2Foj

class JumpFloor {
public:
	int jumpFloor(int number) {
		if (number == 1) {
			return 1;
		}
		if (number == 2) {
			return 2;
		}
		return jumpFloor(number - 1) + jumpFloor(number - 2);
	}
};

class Solution {
public:
	int dp[50]{0};
	int jumpFloor(int number) {
		dp[0] = 1, dp[1] = 1;
		for (int i = 2; i <= number; i++)
			dp[i] = dp[i - 1] + dp[i - 2];
		return dp[number];
	}
};
