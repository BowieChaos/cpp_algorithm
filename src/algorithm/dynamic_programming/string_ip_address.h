#pragma once

#include <algorithm>
#include <limits.h>
#include <unordered_map>
#include <vector>
using namespace std;

// NC20 数字字符串转化成IP地址
// https://www.nowcoder.com/practice/ce73540d47374dbe85b3125f57727e1e?tpId=295&tags=&title=&difficulty=0&judgeStatus=0&rp=0&sourceUrl=%2Fexam%2Foj

class StringToIP {
public:
	/**
	 *
	 * @param s string字符串
	 * @return string字符串vector
	 */

	string nums;
	vector<string> ret;
	string s;
	vector<string> restoreIpAddresses(string s) {
		// write code here
		this->s = s;
		dfs(0, 0);
		return ret;
	}

	void dfs(int step, int index) {
		string cur = "";
		if (step == 4) {
			if (index != s.length()) {
				return;
			}
			ret.emplace_back(nums);
			return;
		}
		for (size_t i = index; i < index + 3 && i < s.length(); i++) {
			cur.push_back(s[index]);

			int num = stoi(cur);
			string tmp = nums;

			if (num <= 255 && (cur.size() == 1 || cur[0] != '0')) {
				if (step < 3) {
					nums.append(cur);
					nums.append(".");
				} else {
					nums.append(cur);
				}
				dfs(step + 1, i + 1);
				nums = tmp;
			}
		}
	}
};