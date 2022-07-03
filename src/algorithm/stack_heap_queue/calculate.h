#pragma once
#include <ctype.h>
#include <limits.h>
#include <stack>
#include <string>
using namespace std;

// https://www.nowcoder.com/practice/c215ba61c8b1443b996351df929dc4d4?tpId=295&tags=&title=&difficulty=0&judgeStatus=0&rp=0&sourceUrl=%2Fexam%2Foj

class Calculate {
public:
	/**
	 * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
	 * 返回表达式的值
	 * @param s string字符串 待计算的表达式
	 * @return int整型
	 */
	int solve(string s) {
		// write code here
		int ret = 0;
		stack<int> stk;
		char flag = '+';
		int num = 0;
		for (size_t i = 0; i < s.size(); i++) {
			char c = s[i];
			if (c <= '9' && c >= '0') {
				num = num * 10 + (c - '0');
			}
			if (c == '(') {
				int j = i + 1;
				int count = 1;
				while (count > 0) {
					if (s[j] == '(') {
						count++;
					} else if (s[j] == ')') {
						count--;
					}
					j++;
				}
				num = solve(s.substr(i + 1, j - i - 1));
				i = j - 1;
			}
			if (i == s.size()-1 || c == '+' || c == '-' || c == '*') {
				if (flag == '+') {
					stk.emplace(num);
				} else if (flag == '-') {
					stk.emplace(-num);
				} else if (flag == '*') {
					stk.top() *= num;
				}
				flag = c;
				num = 0;
			}
		}

		while (!stk.empty()) {
			ret += stk.top();
			stk.pop();
		}
		return ret;
	}
};