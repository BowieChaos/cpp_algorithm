#pragma once

#include <algorithm>
#include <deque>
#include <set>
#include <string>
#include <vector>
using namespace std;

// https://www.nowcoder.com/practice/28eb3175488f4434a4a6207f6f484f47?tpId=295&tqId=44664&ru=%2Fexam%2Foj&qru=%2Fta%2Fformat-top101%2Fquestion-ranking&sourceUrl=%2Fexam%2Foj

class CommonPrefix {
public:
	/**
	 *
	 * @param strs string字符串vector
	 * @return string字符串
	 */
	string longestCommonPrefix(vector<string>& strs) {
		// write code here
		string ret;
		if (strs.empty() || strs[0].empty()) {
			return ret;
		}
		int index = 0;
		while (index < strs[0].size()) {
			for (int i = 1; i < strs.size(); i++) {
				if (index == strs[i].size() ||
				    strs[i][index] != strs[0][index]) {
					return strs[0].substr(0, index);
				}
			}
			index++;
		}

		return strs[0];
	}
};