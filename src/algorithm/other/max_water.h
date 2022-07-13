#pragma once
#include <algorithm>
#include <unordered_set>
#include <vector>
using namespace std;

// https://www.nowcoder.com/practice/3d8d6a8e516e4633a2244d2934e5aa47?tpId=295&tags=&title=&difficulty=0&judgeStatus=0&rp=0&sourceUrl=%2Fexam%2Foj

class Solution {
public:
	/**
	 * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
	 *
	 *
	 * @param height int整型vector
	 * @return int整型
	 */
	int maxArea(vector<int>& height) {
		// write code here
		if (height.size() <= 1) {
			return 0;
		}

		int left = 0;
		int right = height.size() - 1;
		int ret = 0;
		while (left < right) {
			int area = min(height[left], height[right]) * (right - left);
			ret = max(ret, area);
			if (height[left + 1] > height[left]) {
				left++;
			} else if (height[right - 1] > height[right]) {
				right--;
			} else {
				left++;
			}
		}
        return ret;
	}
};