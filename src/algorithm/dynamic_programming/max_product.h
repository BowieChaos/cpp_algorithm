#pragma once

#include <algorithm>
#include <limits.h>
#include <stack>
#include <string>
#include <vector>
using namespace std;

// NC83 连续子数组的最大乘积
// https://www.nowcoder.com/practice/abbec6a3779940aab2cc564b22d36859?tpId=117&tqId=37785&rp=1&ru=/exam/oj&qru=/exam/oj&sourceUrl=%2Fexam%2Foj%3FjudgeStatus%3D3%26page%3D1%26pageSize%3D50%26search%3D%26tab%3D%25E7%25AE%2597%25E6%25B3%2595%25E7%25AF%2587%26topicId%3D117&difficulty=undefined&judgeStatus=3&tags=&title=

class Solution {
public:
	/**
	 * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
	 *
	 *
	 * @param nums int整型vector
	 * @return int整型
	 */
	int maxProduct(vector<int>& nums) {
		// write code here
		if (nums.empty()) {
			return 0;
		}
		vector<int> dp_min(nums.size(), INT_MAX);
		vector<int> dp_max(nums.size(), INT_MIN);
		dp_min[0] = nums[0];
		dp_max[0] = nums[0];
		int ret = dp_max[0];
		for (int i = 1; i < nums.size(); i++) {
			if (nums[i] > 0) {
				dp_max[i] = std::max(nums[i], dp_max[i - 1] * nums[i]);
				dp_min[i] = std::min(nums[i], dp_min[i - 1] * nums[i]);
			} else {
				dp_min[i] = std::min(nums[i], dp_max[i - 1] * nums[i]);
				dp_max[i] = std::max(nums[i], dp_min[i - 1] * nums[i]);
			}
			if (dp_max[i] > ret) {
				ret = dp_max[i];
			}
		}
		return ret;
	}
};