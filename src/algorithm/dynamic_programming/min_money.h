#pragma once

#include <algorithm>
#include <limits.h>
#include <vector>
using namespace std;

// NC126 兑换零钱(一)
// https://www.nowcoder.com/practice/3911a20b3f8743058214ceaa099eeb45?tpId=295&tqId=988994&ru=/exam/oj&qru=/ta/format-top101/question-ranking&sourceUrl=%2Fexam%2Foj

class MinMoney {
public:
	/**
	 * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
	 *
	 * 最少货币数
	 * @param arr int整型vector the array
	 * @param aim int整型 the target
	 * @return int整型
	 */
	int minMoney(vector<int>& arr, int aim) {
		// write code here
		if (arr.empty()) {
			if (aim <= 0) {
				return 0;
			} else {
				return -1;
			}
		}

		vector<int> dp(aim + 1, -1);
		dp[0] = 0;
		for (size_t i = 1; i <= aim; i++) {
			for (int coin : arr) {
				int index = i - coin;
				if (index >= 0 && dp[index] != -1) {
					if (dp[i] != -1) {
						dp[i] = min(dp[i], dp[index] + 1);
					} else {
						dp[i] = dp[index] + 1;
					}
				}
			}
		}
		return dp[aim];
	}
};