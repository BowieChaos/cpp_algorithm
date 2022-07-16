#pragma once
#include <algorithm>
#include <unordered_set>
#include <vector>
using namespace std;

// https://www.nowcoder.com/practice/76039109dd0b47e994c08d8319faa352?tpId=295&tags=&title=&difficulty=0&judgeStatus=0&rp=0&sourceUrl=%2Fexam%2Foj

class Candy {
public:
	/**
	 * pick candy
	 * @param arr int整型vector the array
	 * @return int整型
	 */
	int candy(vector<int>& arr) {
		// write code here
		if (arr.empty()) {
			return 0;
		}

		vector<int> dp(arr.size(), 1);
		for (int i = 1; i < dp.size(); i++) {
			if (arr[i] > arr[i - 1]) {
				dp[i] = max(dp[i - 1] + 1, dp[i]);
			}
		}

		for (int i = dp.size() - 2; i >= 0; i--) {
			if (arr[i] > arr[i + 1]) {
				dp[i] = max(dp[i + 1] + 1, dp[i]);
			}
		}
		int ret = 0;
		for (int i : dp) {
			ret += i;
		}
		return ret;
	}
};