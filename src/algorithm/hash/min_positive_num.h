#pragma once
#include <algorithm>
#include <unordered_map>
#include <vector>
using namespace std;

// https://www.nowcoder.com/practice/50ec6a5b0e4e45348544348278cdcee5?tpId=295&tqId=2188893&ru=/exam/oj&qru=/ta/format-top101/question-ranking&sourceUrl=%2Fexam%2Foj

class MinPositive {
public:
	/**
	 * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
	 *
	 *
	 * @param nums int整型vector
	 * @return int整型
	 */
	int minNumberDisappeared(vector<int>& nums) {
		// write code here
		int n = nums.size();
		if (nums.empty()) {
			return n + 1;
		}
		for (size_t i = 0; i < n; i++) {
			if (nums[i] <= 0) {
				nums[i] = n + 1;
			}
		}

		for (size_t i = 0; i < n; i++) {
			if (abs(nums[i]) <= n) {
				nums[abs(nums[i]) - 1] = -1 * abs(nums[abs(nums[i]) - 1]);
			}
		}

		for (size_t i = 0; i < n; i++) {
			if (nums[i] > 0) {
				return i + 1;
			}
		}
		return n + 1;
	}
};