#pragma once

#include <algorithm>
#include <deque>
#include <set>
#include <stack>
#include <string>
#include <vector>
using namespace std;

// NC100 把字符串转换成整数(atoi)
// https://www.nowcoder.com/practice/d11471c3bf2d40f38b66bb12785df47f?tpId=117&tqId=37822&rp=1&ru=%2Fexam%2Foj&qru=%2Fexam%2Foj&sourceUrl=%2Fexam%2Foj%3FjudgeStatus%3D3%26page%3D1%26pageSize%3D50%26search%3D%26tab%3D%25E7%25AE%2597%25E6%25B3%2595%25E7%25AF%2587%26topicId%3D117&difficulty=undefined&judgeStatus=3&tags=&title=

class Solution {
public:
	/**
	 * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
	 *
	 *
	 * @param s string字符串
	 * @return int整型
	 */
	int StrToInt(string s) {
		// write code here
		if (s.empty()) {
			return 0;
		}

		auto i = s.find_first_not_of(" ");
		if (i == string::npos) {
			return 0;
		}
		bool minus = false;
		long long ret = 0;
		for (; i < s.size(); i++) {
			if (s[i] == '-' || s[i] == '+') {
				minus = (s[i] == '-');
				continue;
			}
			if (!isdigit(s[i])) {
				break;
			}

			ret = ret * 10 + (s[i] - '0');
			if ((minus && -ret < INT_MIN)) {
				return INT_MIN;
			}
			if (!minus && ret > INT_MAX) {
				return INT_MAX;
			}
		}

		return minus ? -ret : ret;
	}
};