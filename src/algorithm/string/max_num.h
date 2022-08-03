#pragma once

#include <algorithm>
#include <deque>
#include <string>
#include <vector>
using namespace std;

// NC111 最大数
// https://www.nowcoder.com/practice/fc897457408f4bbe9d3f87588f497729?tpId=117&tqId=37824&rp=1&ru=%2Fexam%2Foj&qru=%2Fexam%2Foj&sourceUrl=%2Fexam%2Foj%3FjudgeStatus%3D3%26page%3D1%26pageSize%3D50%26search%3D%26tab%3D%25E7%25AE%2597%25E6%25B3%2595%25E7%25AF%2587%26topicId%3D117&difficulty=undefined&judgeStatus=3&tags=&title=

class CMP {
public:
	bool operator()(const string& left, const string& right) {
		if (left.size() == right.size()) {
			for (int i = 0; i < left.size(); i++) {
				if (left[i] != right[i]) {
					return left[i] > right[i];
				}
			}
			return false;
		} else {
			string tmp_left = left + right;
			string tmp_right = right + left;
			for (int i = 0; i < tmp_left.size(); i++) {
				if (tmp_left[i] != tmp_right[i]) {
					return tmp_left[i] > tmp_right[i];
				}
			}
			return false;
		}
	}
};

class Solution {
public:
	/**
	 * 最大数
	 * @param nums int整型vector
	 * @return string字符串
	 */
	string solve(vector<int>& nums) {
		// write code here
		if (nums.empty()) {
			return "";
		}

		vector<string> vec_str(nums.size());
		for (int i = 0; i < nums.size(); i++) {
			vec_str[i] = to_string(nums[i]);
		}

		sort(vec_str.begin(), vec_str.end(), CMP());
		if (vec_str[0] == "0") {
			return "0";
		}

		string ret;
		for (string& s : vec_str) {
			ret += s;
		}
		return ret;
	}
};