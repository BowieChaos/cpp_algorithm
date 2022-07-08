#pragma once

#include <algorithm>
#include <limits.h>
#include <unordered_map>
#include <vector>
using namespace std;

// https://www.nowcoder.com/practice/5164f38b67f846fb8699e9352695cd2f?tpId=295&tags=&title=&difficulty=0&judgeStatus=0&rp=0&sourceUrl=%2Fexam%2Foj

class LISSolution {
public:
	/**
	 * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
	 *
	 * 给定数组的最长严格上升子序列的长度。
	 * @param arr int整型vector 给定的数组
	 * @return int整型
	 */
	int LIS(vector<int>& arr) {
		// write code here
		int ret = 0;
		if (arr.empty()) {
			return ret;
		}
		vector<int> dp(arr.size(), 1);
		ret = 1;
		for (size_t i = 1; i < arr.size(); i++) {
			for (size_t j = 0; j < i; j++) {
				if (arr[i] > arr[j] && dp[i] < dp[j] + 1) {
					dp[i] = dp[j] + 1;
					ret = max(ret, dp[i]);
				}
			}
		}
		return ret;
	}
};