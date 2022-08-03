#pragma once
#include <algorithm>
#include <unordered_set>
#include <vector>
using namespace std;

// NC10 大数乘法
// https://www.nowcoder.com/practice/c4c488d4d40d4c4e9824c3650f7d5571?tpId=117&tqId=37824&rp=1&ru=%2Fexam%2Foj&qru=%2Fexam%2Foj&sourceUrl=%2Fexam%2Foj%3FjudgeStatus%3D3%26page%3D1%26pageSize%3D50%26search%3D%26tab%3D%25E7%25AE%2597%25E6%25B3%2595%25E7%25AF%2587%26topicId%3D117&difficulty=undefined&judgeStatus=3&tags=&title=

class BNMultiply {
public:
	/**
	 * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
	 *
	 * @param s string字符串 第一个整数
	 * @param t string字符串 第二个整数
	 * @return string字符串
	 */
	string solve(string s, string t) {
		// write code here
		if (s.empty() || t.empty()) {
			return 0;
		}
		int zeros = 0;
		string ret = "0";
		for (int i = t.size() - 1; i >= 0; i--, zeros++) {
			string tmp_str = multiply(s, t[i], zeros);
			ret = add(tmp_str, ret);
		}

		while (*ret.begin() == '0') {
			ret.erase(ret.begin());
		}
		if (ret.empty()) {
			return "0";
		}

		return ret;
	}

	string multiply(string& s, char c, int zeros) {
		int carry = 0;
		string ret;
		for (int i = s.size() - 1; i >= 0; i--) {
			int tmp = s[i] - '0';
			int res = tmp * (c - '0') + carry;
			carry = res / 10;
			res = res % 10;
			ret.push_back(res + '0');
		}
		if (carry != 0) {
			ret.push_back(carry + '0');
		}
		reverse(ret.begin(), ret.end());
		for (int i = 0; i < zeros; i++) {
			ret.push_back('0');
		}
		return ret;
	}

	string add(string& left, string& right) {
		int carry = 0;
		string ret;
		ret.reserve(left.size());
		while (!left.empty() && !right.empty()) {
			int l = left.back() - '0';
			int r = right.back() - '0';
			left.pop_back();
			right.pop_back();
			int sum = l + r + carry;
			carry = sum / 10;
			sum = sum % 10;
			ret.push_back(sum + '0');
		}
		while (!left.empty()) {
			int l = left.back() - '0';
			left.pop_back();
			int sum = l + carry;
			carry = sum / 10;
			sum = sum % 10;
			ret.push_back(sum + '0');
		}

		while (!right.empty()) {
			int r = right.back() - '0';
			right.pop_back();
			int sum = r + carry;
			carry = sum / 10;
			sum = sum % 10;
			ret.push_back(sum + '0');
		}

		if (carry != 0) {
			ret.push_back(carry + '0');
		}

		reverse(ret.begin(), ret.end());
		return ret;
	}
};