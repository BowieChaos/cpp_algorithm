#pragma once

#include <algorithm>
#include <limits.h>
#include <stack>
#include <string>
#include <vector>
using namespace std;

// https://www.nowcoder.com/practice/45fd68024a4c4e97a8d6c45fc61dc6ad?tpId=295&tqId=2294660&ru=%2Fexam%2Foj&qru=%2Fta%2Fformat-top101%2Fquestion-ranking&sourceUrl=%2Fexam%2Foj

class Solution {
public:
	/**
	 *
	 * @param s string字符串
	 * @return int整型
	 * https://blog.csdn.net/qq_41033011/article/details/108436108
	 */
	int longestValidParentheses(string s) {
		if (s.empty()) {
			return 0;
		}
		vector<int> dp(s.size(), 0);
        int ret = 0;
		for (size_t i = 1; i < s.size(); i++) {
			if (s[i] == ')') {
				int pre = i - dp[i - 1] - 1;
				if (s[pre] == '(') {
					dp[i] = dp[i - 1] + 2;
					if (pre - 1 >= 0 && s[pre - 1] == ')') {
						dp[i] += dp[pre - 1];
					}
                    ret = max(ret, dp[i]);
				}
			}
		}
        return ret;
	}

	int longestValidParentheses_stk(string s) {
		// write code here
		if (s.empty()) {
			return 0;
		}

		stack<int> stk;
		stk.emplace(-1);
		int ret = 0;
		for (int i = 0; i < s.size(); i++) {
			if (s[i] == '(') {
				stk.emplace(i);
			} else {
				if (stk.size() > 1) {
					stk.pop();
					ret = max(ret, i - stk.top());
				}
			}
		}
		return ret;
	}
};