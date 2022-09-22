#pragma once
#include <limits.h>
#include <stack>
#include <string>
using namespace std;

// NC52 有效括号序列
// https://www.nowcoder.com/practice/37548e94a270412c8b9fb85643c8ccc2?tpId=295&tags=&title=&difficulty=0&judgeStatus=0&rp=0&sourceUrl=%2Fexam%2Foj

class Bracket {
public:
	/**
	 *
	 * @param s string字符串
	 * @return bool布尔型
	 */
	bool isValid(string s) {
		stack<char> stk;
		for (int i = 0; i < s.size(); i++) {
			switch (s[i]) {
			case '(':
			case '[':
			case '{':
				stk.push(s[i]); //当前字符为'(','{','['时，元素入栈
				break;
			case ')':
				if (stk.empty() ||
				    stk.top() !=
				        '(') //栈空或者括号栈顶字符与当前字符不匹配，则序列为不合法序列
					return false;
				stk.pop(); //匹配的栈顶元素出栈
				break;
			case ']':
				if (stk.empty() || stk.top() != '[')
					return false;
				stk.pop();
				break;
			case '}':
				if (stk.empty() || stk.top() != '{')
					return false;
				stk.pop();
				break;
			}
		}
		return stk.empty() ? true
		                   : false; //当括号以正确顺序关闭时则最后的栈为空
	}
};