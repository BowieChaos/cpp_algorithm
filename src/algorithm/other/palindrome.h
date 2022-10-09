#pragma once
#include <string>
using namespace std;

// NC141 判断是否为回文字符串
// https://www.nowcoder.com/practice/e297fdd8e9f543059b0b5f05f3a7f3b2?tpId=295&tags=&title=&difficulty=0&judgeStatus=0&rp=0&sourceUrl=%2Fexam%2Foj

class Solution {
public:
	/**
	 * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
	 *
	 * @param str string字符串 待判断的字符串
	 * @return bool布尔型
	 */
	bool judge(string str) {
		// write code here
		if (str.empty()) {
			return true;
		}
		int len = str.size();
		int l, r;
		if (len % 2 == 0) {
			l = len / 2 - 1;
			r = len / 2;
		} else {
			l = r = len / 2;
		}
		while (l >= 0) {
			if (str[l--] != str[r++]) {
				return false;
			}
		}
		return true;
	}
};