#pragma once
#include <algorithm>
#include <unordered_map>
#include <vector>
using namespace std;

// https://www.nowcoder.com/practice/20ef0972485e41019e39543e8e895b7f?tpId=295&tags=&title=&difficulty=0&judgeStatus=0&rp=0&sourceUrl=%2Fexam%2Foj

class Solution {
public:
	/**
	 *
	 * @param numbers int整型vector
	 * @param target int整型
	 * @return int整型vector
	 */
	vector<int> twoSum(vector<int>& numbers, int target) {
		// write code here
		unordered_map<int, int> mp;
		vector<int> ret_vec;
		for (size_t i = 0; i < numbers.size(); i++) {
			int tmp = target - numbers[i];
			if (mp.find(tmp) != mp.end()) {
				ret_vec.emplace_back(mp[tmp]);
				ret_vec.emplace_back(i + 1);
				break;
			}
			mp.emplace(numbers[i], i + 1);
		}
		std::sort(ret_vec.begin(), ret_vec.end());
		return ret_vec;
	}
};