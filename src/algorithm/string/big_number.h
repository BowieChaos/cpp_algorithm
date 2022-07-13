#pragma once

#include <algorithm>
#include <deque>
#include <set>
#include <stack>
#include <string>
#include <vector>
using namespace std;

// https://www.nowcoder.com/practice/11ae12e8c6fe48f883cad618c2e81475?tpId=295&tags=&title=&difficulty=0&judgeStatus=0&rp=0&sourceUrl=%2Fexam%2Foj

class BigNumber {
public:
	/**
	 * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
	 * 计算两个数之和
	 * @param s string字符串 表示第一个整数
	 * @param t string字符串 表示第二个整数
	 * @return string字符串
	 */
	string solve(string s, string t) {
		// write code here
		deque<char> dq1(s.begin(), s.end());
		deque<char> dq2(t.begin(), t.end());

		deque<char> ret_dq;

		int carry = 0;
		while (!dq1.empty() && !dq2.empty()) {
			int left = dq1.back() - '0';
			int right = dq2.back() - '0';
			int sum = left + right + carry;
			carry = sum / 10;
			char c = (sum % 10) + '0';
			ret_dq.emplace_front(c);
			dq1.pop_back();
			dq2.pop_back();
		}

		while (!dq1.empty()) {
			int sum = (dq1.back() - '0') + carry;
			dq1.pop_back();
			carry = sum / 10;
			char c = (sum % 10) + '0';
			ret_dq.emplace_front(c);
		}

		while (!dq2.empty()) {
			int sum = (dq2.back() - '0') + carry;
			dq2.pop_back();
			carry = sum / 10;
			char c = (sum % 10) + '0';
			ret_dq.emplace_front(c);
		}

		if (carry != 0) {
			ret_dq.emplace_front(carry + '0');
		}
		string ret(ret_dq.begin(), ret_dq.end());
		return ret;
	}
};